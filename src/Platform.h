//
// Created by jaden on 08/04/2023.
//

#ifndef PLATFORMERSFML_PLATFORM_H
#define PLATFORMERSFML_PLATFORM_H

#include "GameObject.h"


class Platform : public GameObject
{
 public:
  Platform();
  ~Platform();
  bool init(sf::RenderWindow& window);
  void getPos(int plat_no, sf::RenderWindow& window);

 private:
  sf::Texture floor_texture;
};

#endif // PLATFORMERSFML_PLATFORM_H
