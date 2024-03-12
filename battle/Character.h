//
// Created by zthacker on 3/11/2024.
//

#ifndef BATTLE_CHARACTER_H
#define BATTLE_CHARACTER_H

#include <iostream>
#include <vector>

using namespace std;

class Character {
public:
    Character(string name, int hp, int speed, string type);
    ~Character();
    string name;
    int hp;
    int speed;
    string type;

private:
};


#endif //BATTLE_CHARACTER_H
