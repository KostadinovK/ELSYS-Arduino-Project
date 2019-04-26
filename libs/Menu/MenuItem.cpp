#include <MenuItem.h>

MenuItem::MenuItem(){}
MenuItem::MenuItem(String name, GameEngine* gameEngine)
{
    this->name = name;
    this->gameEngine = gameEngine;
}
