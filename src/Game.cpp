#include "Game.h"
#include "Player.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game() {}

bool Game::init()
{
  window.clear(sf::Color::Black);

  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }

  // init backgrounds
  if (!menu_bg.loadFromFile("Data/Images/celestial_bg.png"))
  {
    std::cout << "menu background texture did not load \n";
  }
  background.setTexture(menu_bg);

  if (!instr_bg.loadFromFile("Data/Images/celestial_instr_bg.png"))
  {
    std::cout << "instructions background texture did not load \n";
  }
  background.setTexture(instr_bg);
  if (!main_bg.loadFromFile("Data/Images/celestial_gameplay_bg.png"))
  {
    std::cout << "main game background texture did not load \n";
  }
  background.setTexture(main_bg);
  main_bg.setRepeated(true);
  background.setTextureRect(sf::IntRect(0, 0, main_bg.getSize().x, main_bg.getSize().y * 2));

  over_image.setScale(0.5, 0.5);

  // menu camera
  menu_cam.setCenter(window.getSize().x / 2, window.getSize().y / 2);
  menu_cam.setSize(window.getSize().x, window.getSize().y);

  menuInit();

  return true;
}

bool Game::menuInit()
{
  // init title text
  title_text.setString("Celestial");
  title_text.setFont(font);
  title_text.setCharacterSize(100);
  title_text.setFillColor(sf::Color(255, 255, 255, 255));
  title_text.setPosition(
    window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 - title_text.getGlobalBounds().height / 2);

  // init play text (how to start)
  play_text.setString("Press Enter to Play");
  play_text.setFont(font);
  play_text.setCharacterSize(50);
  play_text.setFillColor(sf::Color(255, 255, 255, 255));
  play_text.setPosition(
    window.getSize().x / 2 - play_text.getGlobalBounds().width / 2,
    window.getSize().y / 5 * 2 - play_text.getGlobalBounds().height / 2);

  // init instructions text (open instructions)
  instr_text.setString("Press I for Instructions");
  instr_text.setFont(font);
  instr_text.setCharacterSize(50);
  instr_text.setFillColor(sf::Color(255, 255, 255, 255));
  instr_text.setPosition(
    window.getSize().x / 2 - instr_text.getGlobalBounds().width / 2,
    window.getSize().y / 5 * 3 - instr_text.getGlobalBounds().height / 2);

  // init background
  background.setTexture(menu_bg);
  return true;
}

bool Game::instrInit()
{
  title_text.setString("Instructions");
  title_text.setFillColor(sf::Color(255, 255, 255, 255));
  title_text.setPosition(
    window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 - title_text.getGlobalBounds().height / 2);

  play_text.setString("- Esther has lost her star! It appears to have been\n  split "
                      "into 5 pieces and scattered across space!\n- Help her collect"
                      " all the pieces and rebuild her star\n- Be careful of the"
                      " space zombies who want to\n  eat her brains!");
  play_text.setCharacterSize(35);
  play_text.setFillColor(sf::Color(0, 0, 0, 255));
  play_text.setPosition(
    window.getSize().x / 2 - play_text.getGlobalBounds().width / 2,
    window.getSize().y / 5 * 3 - play_text.getGlobalBounds().height / 2);

  instr_text.setString("Esc to go back");
  instr_text.setCharacterSize(50);
  instr_text.setFillColor(sf::Color(0, 0, 0, 255));
  instr_text.setPosition(15,window.getSize().y - instr_text.getGlobalBounds().height - 25);

  controls_text.setString("C for Controls");
  controls_text.setFont(font);
  controls_text.setCharacterSize(50);
  controls_text.setFillColor(sf::Color(0, 0, 0, 255));
  controls_text.setPosition(window.getSize().x - controls_text.getGlobalBounds().width - 25,
                            instr_text.getPosition().y);

  // init background
  background.setTexture(instr_bg);

  return true;
}

bool Game::controlInit()
{
  title_text.setString("Controls");
  title_text.setFillColor(sf::Color(255, 255, 255, 255));
  title_text.setPosition(
    window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 - title_text.getGlobalBounds().height / 2);

  play_text.setString("Left\nRight\nJump");
  play_text.setCharacterSize(50);
  play_text.setFillColor(sf::Color(0, 0, 0, 255));
  play_text.setPosition(
    150,window.getSize().y / 5 * 3 - play_text.getGlobalBounds().height / 2);

  controls_text.setString("A\nD\nSpace");
  controls_text.setFont(font);
  controls_text.setCharacterSize(50);
  controls_text.setFillColor(sf::Color(0, 0, 0, 255));
  controls_text.setPosition(window.getSize().x - controls_text.getGlobalBounds().width - 150,
                            play_text.getPosition().y);

  instr_text.setString("Esc to go back");
  instr_text.setCharacterSize(50);
  instr_text.setFillColor(sf::Color(0, 0, 0, 255));
  instr_text.setPosition(15,window.getSize().y - instr_text.getGlobalBounds().height - 25);

  // init background
  background.setTexture(instr_bg);
  return true;
}

bool Game::overInit()
{
  if (player_win)
  {
    title_text.setString("You Won!");
    title_text.setFillColor(sf::Color(255, 255, 255, 255));

    play_text.setString("Press Enter to play again");
    play_text.setFillColor(sf::Color(255, 255, 255, 255));

    instr_text.setFillColor(sf::Color(255, 255, 255, 255));

    over_texture.loadFromFile("Data/Images/fullStar.png");
  }
  else
  {
    title_text.setString("You Died");
    title_text.setFillColor(sf::Color(255, 0, 0, 255));

    play_text.setString("Press Enter to try again");
    play_text.setFillColor(sf::Color(255, 0, 0, 255));

    instr_text.setFillColor(sf::Color(255, 0, 0, 255));

    over_texture.loadFromFile("Data/Images/skull.png");
  }

  title_text.setPosition(
    window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 - title_text.getGlobalBounds().height / 2);

  over_image.setTexture(over_texture);
  over_image.setPosition(window.getSize().x / 2 - over_image.getGlobalBounds().width / 2,
                        window.getSize().y / 4 * 3 - over_image.getGlobalBounds().height / 2);

  play_text.setPosition(
    window.getSize().x / 2 - play_text.getGlobalBounds().width / 2,
    window.getSize().y / 5 * 2 - play_text.getGlobalBounds().height / 2);

  instr_text.setString("Or press Esc to return to the menu");
  instr_text.setCharacterSize(25);
  instr_text.setPosition(
    window.getSize().x / 2 - instr_text.getGlobalBounds().width / 2,
    play_text.getPosition().y + 100);

  background.setTexture(menu_bg);

  return true;
}

bool Game::gameplayInit()
{

  // reset variables
  player_win = false;
  player.stars_collected = 0;
  player.lives = 3;

  // player
  player.init(window);

  // lives UI
  for (int i = 0; i <= player.lives - 1; i++)
  {
    lives_texture.loadFromFile("Data/Images/pixelHeart.png");
    lives_image[i].setTexture(lives_texture);
    lives_image[i].setScale(0.1, 0.1);
    lives_image[i].setPosition(5,5);
    if (i > 0)
    {
      lives_image[i].setPosition(
        lives_image[i-1].getPosition().x + lives_image[i].getGlobalBounds().width + 5,
        lives_image[i-1].getPosition().y);
    }
  }

  // star piece UI
  for (int i = 0; i < 5; i++)
  {
    star_texture.loadFromFile("Data/Images/starPiece.png");
    star_image[i].setTexture(star_texture);
    star_image[i].setScale(0.17, 0.17);
    star_image[i].setPosition(window.getSize().x - star_image[i].getGlobalBounds().width - 5,5);
    if (i > 0)
    {
      star_image[i].setPosition(
        star_image[i-1].getPosition().x - star_image[i].getGlobalBounds().width - 5,
        star_image[i-1].getPosition().y);
    }
  }

  // enemies
  for (int i = 0; i < no_of_enemies; i++)
  {
    enemy[i].init(window);
    enemy[i].getPos(i, window);
  }

  // background
  background.setTexture(main_bg);

  // floor
  for (int i = 0; i < no_of_floors; i++)
  {
    floor[i].init(window);
    floor[i].getPos(i, window);
  }

  // star pieces
  for (int i = 0; i < no_of_stars; i++)
  {
    star_piece[i].init(window);
    star_piece[i].getPos(i, window);
    star_piece[i].visible = true;
  }

  // camera
  follow_cam.setCenter(window.getSize().x / 2, window.getSize().y / 2);
  follow_cam.setSize(window.getSize().x, window.getSize().y);

  return true;
}

void Game::update(float dt)
{
  switch (current_state)
  {
    case main:

      // camera

      if (player.getSprite()->getPosition().y > window.getSize().y / 2 && player.getSprite()->getPosition().y < 1000)
      {
        follow_cam.setCenter(window.getSize().x / 2, player.getSprite()->getPosition().y);
      }

      // UI

      for (int i = 0; i < 3; i++) // lives
      {
        lives_image[i].setPosition(5,follow_cam.getCenter().y - follow_cam.getSize().y / 2 + 5);
        if (i > 0)
        {
          lives_image[i].setPosition(
            lives_image[i-1].getPosition().x + lives_image[i].getGlobalBounds().width + 5,
            lives_image[i-1].getPosition().y);
        }
      }

      for (int i = 0; i < 5; i++) // star pieces
      {
        star_image[i].setPosition(window.getSize().x - star_image[i].getGlobalBounds().width - 5,
                                 follow_cam.getCenter().y - follow_cam.getSize().y / 2 + 5);
        if (i > 0)
        {
          star_image[i].setPosition(
            star_image[i-1].getPosition().x - star_image[i].getGlobalBounds().width - 5,
            star_image[i-1].getPosition().y);
        }
      }

      //player

      player.update(window, dt);

      // floor collision

      for (int i = 0; i < no_of_floors; i++)
      {
        if (GameObject().floorCollision(
              *player.getSprite(), *floor[i].getSprite()))
        {
          player.player_now = Player::grounded;
          break;
        }
        else if (player.player_now != Player::jumping)
        {
          player.player_now = Player::falling;
        }
      }

      // wall collision

      for (int i = 0; i < no_of_floors; i++)
      {
        if (GameObject().wallCollision(*player.getSprite(), *floor[i].getSprite()) == 1)
        {
          player.direction.x = 0;
          player.getSprite()->move(-1 * player.speed * dt, 0);
          break;
        }
        else if (GameObject().wallCollision(*player.getSprite(), *floor[i].getSprite()) == 2)
        {
          player.direction.x = 0;
          player.getSprite()->move(1 * player.speed * dt, 0);
        }
      }

      // collision with enemy
      for (int i = 0; i < no_of_enemies; i++)
      {
        if (GameObject().totalCollision(*player.getSprite(), *enemy[i].getSprite()))
        {
          if (!player.damaged)
          {
            player.damageTaken();
          }
        }
      }

      // collision with star piece
      for (int i = 0; i < no_of_stars; i++)
      {
        if (star_piece[i].visible && GameObject().totalCollision(*player.getSprite(), *star_piece[i].getSprite()))
        {
          star_piece[i].visible = false;
          player.stars_collected++;
        }
      }

      for (int i = 0; i < no_of_enemies; i++)
      {
        // enemy
        enemy[i].update(i, window, dt);

        // floor collision
        for (int j = 0; j < no_of_floors; j++)
        {
          if (GameObject().floorCollision(
                *enemy[i].getSprite(), *floor[j].getSprite()))
          {
            enemy[i].grounded = true;
            break;
          }
          else
          {
            enemy[i].grounded = false;
          }
        }

        for (int j = 0; j < no_of_floors; j++)
        {
          if (GameObject().wallCollision(*enemy[i].getSprite(), *floor[j].getSprite()) == 1)
          {
            enemy[i].direction.x = -1;
            break;
          }
          else if (GameObject().wallCollision(*enemy[i].getSprite(), *floor[j].getSprite()) == 2)
          {
            enemy[i].direction.x = 1;
          }
        }
      }

      // win/lose conditions
      if (player.lives <= 0)
      {
        overInit();
        current_state = game_over;
      }

      if (player.stars_collected >= no_of_stars)
      {
        player_win = true;
        overInit();
        current_state = game_over;
      }
      break;
  }
}

void Game::render()
{
  switch (current_state)
  {
    case menu:
      window.setView(menu_cam);
      window.draw(background);
      window.draw(title_text);
      window.draw(play_text);
      window.draw(instr_text);
      break;
    case instructions:
    case controls:
      window.setView(menu_cam);
      window.draw(background);
      window.draw(title_text);
      window.draw(play_text);
      window.draw(instr_text);
      window.draw(controls_text);
      break;
    case main:
      window.setView(follow_cam);
      window.draw(background);
      if (player.visible)
      {
        window.draw(*player.getSprite());
      }
      for (int i = 0; i < no_of_enemies; i++)
      {
        if (enemy[i].visible)
        {
          window.draw(*enemy[i].getSprite());
        }
      }
      for (int i = 0; i < no_of_floors; i++)
      {
        window.draw(*floor[i].getSprite());
      }
      for (int i = 0; i <= player.lives - 1; i++)
      {
        window.draw(lives_image[i]);
      }
      for (int i = 0; i < player.stars_collected; i++)
      {
        window.draw(star_image[i]);
      }
      for (int i = 0; i < no_of_stars; i++)
      {
        if (star_piece[i].visible)
        {
          window.draw(*star_piece[i].getSprite());
        }
      }
      break;
    case game_over:
      window.setView(menu_cam);
      if (player_win)
      {
        window.draw(background);
      }
      window.draw(title_text);
      window.draw(play_text);
      window.draw(instr_text);
      window.draw(over_image);
      break;
  }
}

void Game::mouseClicked(sf::Event event)
{
  // get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
}

void Game::keyPressed(sf::Event event)
{
  switch (current_state)
  {
    case menu:
      if (event.key.code == sf::Keyboard::Enter)
      {
        current_state = main;
        gameplayInit();
      }
      if (event.key.code == sf::Keyboard::I)
      {
        current_state = instructions;
        instrInit();
      }
      break;

    case instructions:
      if (event.key.code == sf::Keyboard::Escape)
      {
        current_state = menu;
        menuInit();
      }
      if (event.key.code == sf::Keyboard::C)
      {
        current_state = controls;
        controlInit();
      }
      break;

    case controls:
      if (event.key.code == sf::Keyboard::Escape)
      {
        current_state = instructions;
        instrInit();
      }
      break;

    case main:
      player.keyPressed(event);
      break;

    case game_over:
      if (event.key.code == sf::Keyboard::Enter)
      {
        current_state = main;
        gameplayInit();
      }
      if (event.key.code == sf::Keyboard::Escape)
      {
        current_state = menu;
        menuInit();
      }
      break;
  }
}

void Game::keyReleased(sf::Event event)
{
  switch (current_state)
  {
    case main:
      player.keyReleased(event);
      break;
  }
}