//
// Created by jaden on 09/04/2023.
//

#ifndef PLATFORMERSFML_ENEMY_H
#define PLATFORMERSFML_ENEMY_H

#include "GameObject.h"

class Enemy : public GameObject
{
 public:
  Enemy();
  ~Enemy();
  bool init(sf::RenderWindow& window);
  void getPos(int enemy_no, sf::RenderWindow& window);
  void update(int enemy_no, sf::RenderWindow& window, float dt);
  bool grounded = false;

 private:
  sf::Texture texture;
  int steps_taken = 0;
};

#endif // PLATFORMERSFML_ENEMY_H
