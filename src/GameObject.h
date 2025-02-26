//
// Created by jaden on 02/03/2023.
//

#ifndef SPACEINVADERS_GAMEOBJECT_H
#define SPACEINVADERS_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"


class GameObject
{
 public:
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();
  bool visible = true;
  Vector2 direction;
  float speed = 600;
  int wallCollision(sf::Sprite object, sf::Sprite wall);
  bool floorCollision(sf::Sprite object, sf::Sprite floor);
  bool totalCollision(sf::Sprite object1, sf::Sprite object2);

 protected:
  sf::Sprite* sprite = nullptr;
  float gravity = 98;

};


#endif // SPACEINVADERS_GAMEOBJECT_H
