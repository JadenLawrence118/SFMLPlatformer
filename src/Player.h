//
// Created by jaden on 08/04/2023.
//

#ifndef PLATFORMERSFML_PLAYER_H
#define PLATFORMERSFML_PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
 public:
  Player();
  ~Player();
  bool init(sf::RenderWindow& window);
  void update(sf::RenderWindow& window, float dt);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  void damageTaken();
  enum player_states { grounded, jumping, falling };
  player_states player_now;
  bool damaged = false;
  int lives = 3;
  int stars_collected = 0;

 private:
  sf::Texture texture;

  bool touchdown = false;

  int jump_y = 0;
  int max_jump_height = 10000;
  int jump_per_frame = 400;

  sf::Clock clock;
  sf::Time elapsed_secs = clock.getElapsedTime();
  int i_frames = 0;
};

#endif // PLATFORMERSFML_PLAYER_H
