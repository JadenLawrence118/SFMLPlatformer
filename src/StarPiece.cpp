//
// Created by jaden on 09/04/2023.
//

#include "StarPiece.h"


StarPiece::StarPiece() {}

StarPiece::~StarPiece() {}

bool StarPiece::init(sf::RenderWindow& window)
{
  initialiseSprite(texture, "Data/Images/starPiece.png");
  getSprite()->setScale(0.15, 0.15);

  return true;
}

void StarPiece::getPos(int star_no, sf::RenderWindow& window)
{
  switch (star_no)
  {
    case 0:
      getSprite()->setPosition(50, 300);
      break;
    case 1:
      getSprite()->setPosition(
        window.getSize().x - 100,
        window.getSize().y / 10 + getSprite()->getGlobalBounds().height / 2);
      break;
    case 2:
      getSprite()->setPosition(50, 825);
      break;
    case 3:
      getSprite()->setPosition(window.getSize().x / 2 + 200, 900);
      break;
    case 4:
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2,
                               1150);
      break;
    default:
      getSprite()->setPosition(0,0);
  }
}
