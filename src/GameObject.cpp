//
// Created by jaden on 02/03/2023.
//

#include "GameObject.h"

GameObject::GameObject()
{
  direction.x = 0;
  direction.y = 0;
}

GameObject::~GameObject()
{

}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
  sprite = new sf::Sprite();
  texture.loadFromFile(filename);
  sprite->setTexture(texture);
  return true;
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}

int GameObject::wallCollision(sf::Sprite object, sf::Sprite wall)
{
  if (
    object.getPosition().x + object.getGlobalBounds().width >=
      wall.getPosition().x &&
    object.getPosition().x + object.getGlobalBounds().width <=
      wall.getPosition().x + 2 &&
    object.getPosition().y + object.getGlobalBounds().height >=
      wall.getPosition().y &&
    object.getPosition().y <=
      wall.getPosition().y + wall.getGlobalBounds().height)
  {
    return 1;
  }
  else if (
    object.getPosition().x <=
      wall.getPosition().x + wall.getGlobalBounds().width &&
    object.getPosition().x >=
      wall.getPosition().x + wall.getGlobalBounds().width - 2 &&
    object.getPosition().y + object.getGlobalBounds().height >=
      wall.getPosition().y &&
    object.getPosition().y <=
      wall.getPosition().y + wall.getGlobalBounds().height)
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

bool GameObject::floorCollision(sf::Sprite object, sf::Sprite floor)
{
  if (
    object.getPosition().x + object.getGlobalBounds().width >=
      floor.getPosition().x && object.getPosition().x <=
      floor.getPosition().x + floor.getGlobalBounds().width &&
    object.getPosition().y + object.getGlobalBounds().height >=
      floor.getPosition().y &&
    object.getPosition().y + object.getGlobalBounds().height <=
      floor.getPosition().y + 10)
  {
    return true;
  }
  return false;
}
bool GameObject::totalCollision(sf::Sprite object1, sf::Sprite object2)
{
  if (object1.getPosition().x + object1.getGlobalBounds().width >= object2.getPosition().x &&
      object1.getPosition().x <= object2.getPosition().x + object2.getGlobalBounds().width &&
      object1.getPosition().y + object1.getGlobalBounds().height >= object2.getPosition().y &&
      object1.getPosition().y <= object2.getPosition().y + object2.getGlobalBounds().height)
  {
    return true;
  }
  return false;
}
