//
// Created by jaden on 08/04/2023.
//

#include "Platform.h"


Platform::Platform() {}

Platform::~Platform() {}

bool Platform::init(sf::RenderWindow& window)
{
  initialiseSprite(floor_texture, "Data/Images/floor_placeholder.png");

  return true;
}
void Platform::getPos(int plat_no, sf::RenderWindow& window)
{
  switch (plat_no)
  {
    case 0:
      getSprite()->setScale(0.35, 0.1);
      getSprite()->setPosition(0,200);
      break;
    case 1:
      getSprite()->setScale(0.25, 0.1);
      getSprite()->setPosition(window.getSize().x - getSprite()->getGlobalBounds().width,
                               200);
      break;
    case 2:
      getSprite()->setScale(0.3, 0.1);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2,
                               300);
      break;
    case 3:
      getSprite()->setScale(0.03, 1.2);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2,
                               0);
      break;
    case 4:
      getSprite()->setScale(0.05, 0.1);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2 - 250,
                               400);
      break;
    case 5:
      getSprite()->setScale(0.05, 0.1);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2 - 350,
                               500);
      break;
    case 6:
      getSprite()->setScale(0.35, 0.1);
      getSprite()->setPosition(0,600);
      break;
    case 7:
      getSprite()->setScale(0.35, 0.1);
      getSprite()->setPosition(600,600);
      break;
    case 8:
      getSprite()->setScale(0.05, 0.1);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2 + 250,
                               400);
      break;
    case 9:
      getSprite()->setScale(0.05, 0.1);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2 + 350,
                               500);
      break;
    case 10:
      getSprite()->setScale(0.3, 0.1);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2,
                               700);
      break;
    case 11:
      getSprite()->setScale(0.03, 1.6);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2,
                               702);
      break;
    case 12:
      getSprite()->setScale(0.25, 0.1);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2 - 250,
                               800);
      break;
    case 13:
      getSprite()->setScale(0.25, 0.1);
      getSprite()->setPosition(0,900);
      break;
    case 14:
      getSprite()->setScale(0.25, 0.1);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2 - 150,
                               1000);
      break;
    case 15:
      getSprite()->setScale(0.25, 0.1);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2 - 250,
                               1100);
      break;
    case 16:
      getSprite()->setScale(0.05, 0.1);
      getSprite()->setPosition(window.getSize().x / 2 - getSprite()->getGlobalBounds().width / 2,
                               1200);
      break;
    case 17:
      getSprite()->setScale(0.15, 0.1);
      getSprite()->setPosition(0,1200);
      break;
    case 18:
      getSprite()->setScale(1, 0.3);
      getSprite()->setPosition(0,1300);
      break;

    default:
      getSprite()->setScale(1, 0.1);
      getSprite()->setPosition(0,-200);
      break;
  }
}
