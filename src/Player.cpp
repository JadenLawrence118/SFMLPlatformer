//
// Created by jaden on 08/04/2023.
//

#include "Player.h"


Player::Player() {}

Player::~Player() {}

bool Player::init(sf::RenderWindow& window)
{
  initialiseSprite(texture, "Data/Images/female_walk2.png");
  getSprite()->setScale(0.5, 0.5);
  speed = 200;
  getSprite()->setPosition(50,100);
  direction.y = gravity;

  return true;
}

void Player::update(sf::RenderWindow& window, float dt)
{
  // edge of screen
  if (getSprite()->getPosition().x <= 0)
  {
    direction.x = 0;
    getSprite()->move(1, 0);
  }
  else if (
    getSprite()->getPosition().x >=
    window.getSize().x - getSprite()->getGlobalBounds().width)
  {
    direction.x = 0;
    getSprite()->move(-1, 0);
  }

  // damage

  if (damaged)
  {
    // flash
    if (visible)
    {
      visible = false;
    }
    else
    {
      visible = true;
    }

    elapsed_secs = clock.getElapsedTime();

    if (elapsed_secs.asSeconds() >= 1)
    {
      if (i_frames < 2)
      {
        i_frames++;
        clock.restart();
      }
      else
      {
        i_frames = 0;
        visible = true;
        damaged = false;
      }
      }
  }

  switch (player_now)
  {
    case grounded:
      if (!touchdown)
      {
        direction.y = gravity;
        direction.x = 0;
        touchdown = true;
      }
      getSprite()->move(direction.x * speed * dt, 0);
      break;

    case falling:
      touchdown = false;
      direction.y *= 1.005;
      getSprite()->move(direction.x * speed * dt, direction.y * dt);
      break;

    case jumping:
      if (jump_y >= 0 && jump_y < max_jump_height)
      {
        jump_y += jump_per_frame;
        getSprite()->move(direction.x * speed * dt, -jump_per_frame * dt);
      }
      else
      {
        jump_y = 0;
        player_now = falling;
      }
      break;
  }
}

void Player::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::A)
  {
    // mirror sprite
    getSprite()->setTextureRect(sf::IntRect(
      getSprite()->getLocalBounds().width,
      0,
      -getSprite()->getLocalBounds().width,
      getSprite()->getLocalBounds().height));
    direction.x = -1;
  }
  if (event.key.code == sf::Keyboard::D)
  {
    // mirror sprite
    getSprite()->setTextureRect(sf::IntRect(
      0,
      0,
      getSprite()->getLocalBounds().width,
      getSprite()->getLocalBounds().height));

    direction.x = 1;
  }
  if (event.key.code == sf::Keyboard::Space)
  {
    switch (player_now)
    {
      case grounded:
        player_now = jumping;
    }
  }
}

void Player::keyReleased(sf::Event event)
{
    switch (player_now)
    {
      case grounded:
        if (
          event.key.code == sf::Keyboard::A ||
          event.key.code == sf::Keyboard::D)
        {
          direction.x = 0;
          speed = 200;
        }
        break;
      case jumping:
        if (event.key.code == sf::Keyboard::Space)
        {
          jump_y = 0;
          player_now = falling;
        }
        break;
    }
}

void Player::damageTaken()
{
  damaged = true;
  lives--;
}
