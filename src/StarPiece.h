//
// Created by jaden on 09/04/2023.
//

#ifndef PLATFORMERSFML_STARPIECE_H
#define PLATFORMERSFML_STARPIECE_H

#include "GameObject.h"


class StarPiece : public GameObject
{
 public:
  StarPiece();
  ~StarPiece();
  bool init(sf::RenderWindow& window);
  void getPos(int star_no, sf::RenderWindow& window);

 private:
  sf::Texture texture;
};

#endif // PLATFORMERSFML_STARPIECE_H
