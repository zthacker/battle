//
// Created by zthacker on 3/11/2024.
//

#include "Character.h"

Character::Character(string name, int hp, int speed, string type) {
    this->name = name;
    this->hp = hp;
    this->speed = speed;
    this->type = type;
}

Character::~Character() {

}

