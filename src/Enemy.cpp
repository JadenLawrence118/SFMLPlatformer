//
// Created by jaden on 09/04/2023.
//

#include "Enemy.h"
Enemy::Enemy() {}

Enemy::~Enemy() {}

bool Enemy::init(sf::RenderWindow& window)
{
  initialiseSprite(texture, "Data/Images/zombie_walk1.png");
  getSprite()->setScale(0.5, 0.5);
  speed = 50;
  steps_taken = 0;
  direction.x = 1;
  direction.y = gravity;

  return true;
}

void Enemy::update(int enemy_no, sf::RenderWindow& window, float dt)
{
  // reverse x direction if hit wall
  if (getSprite()->getPosition().x <= 0 ||
      getSprite()->getPosition().x >=
        window.getSize().x - getSprite()->getGlobalBounds().width)
  {
    direction.x = -direction.x;
  }

  // face sprite in direction of movement
  if (direction.x > 0)
  {
    getSprite()->setTextureRect(sf::IntRect(
      0,
      0,
      getSprite()->getLocalBounds().width,
      getSprite()->getLocalBounds().height));
  }
  else
  {
    getSprite()->setTextureRect(sf::IntRect(
      getSprite()->getLocalBounds().width,
      0,
      -getSprite()->getLocalBounds().width,
      getSprite()->getLocalBounds().height));
  }

  if (!grounded)
  {
    direction.y *= 1.005;
    getSprite()->move(direction.x * speed * dt, direction.y * dt);
  }
  else
  {
    direction.y = gravity;
    getSprite()->move(direction.x * speed * dt, 0);
  }

  switch (enemy_no)
  {
    case 0:
      if (steps_taken < 380)
      {
        steps_taken++;
      }
      else
      {
        direction.x = -direction.x;
        steps_taken = 0;
      }
      break;
    case 1:
      if (steps_taken < 200)
      {
        steps_taken++;
      }
      else
      {
        direction.x = -direction.x;
        steps_taken = 0;
      }
      break;
  }
}
void Enemy::getPos(int enemy_no, sf::RenderWindow& window)
{
  switch (enemy_no)
  {
    case 0:
      getSprite()->setPosition(600,500);
      break;
    case 1:
      getSprite()->setPosition(
        window.getSize().x - 250,100);
      break;
    case 2:
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2 - 50,
                               200);
      direction.x = -1;
      break;
    case 3:
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2 + 50,
                               200);
      break;
    default:
      getSprite()->setPosition(0,0);
      break;
  }
}
