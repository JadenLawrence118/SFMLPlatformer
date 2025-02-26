
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Platform.h"
#include "StarPiece.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  bool menuInit();
  bool gameplayInit();
  bool instrInit();
  bool controlInit();
  bool overInit();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);

 private:
  sf::RenderWindow& window;

  enum game_states { menu, instructions, controls, main, game_over };
  game_states current_state = menu;

  sf::Font font;
  sf::Text title_text;
  sf::Text play_text;
  sf::Text instr_text;
  sf::Text controls_text;
  sf::Text star_text;

  sf::Sprite background;
  sf::Texture menu_bg;
  sf::Texture instr_bg;
  sf::Texture main_bg;

  Player player;
  sf::Sprite lives_image[3];
  sf::Texture lives_texture;

  int no_of_stars = 5;
  StarPiece star_piece[5];
  sf::Sprite star_image[5];
  sf::Texture star_texture;

  int no_of_enemies = 4;
  Enemy enemy[4];

  int no_of_floors = 19;
  Platform floor[19];

  bool player_win = false;
  sf::Sprite over_image;
  sf::Texture over_texture;

  sf::View follow_cam;
  sf::View menu_cam;
};

#endif // PLATFORMER_GAME_H
