//
// Created by zthacker on 3/8/2024.
//

#ifndef BATTLE_PLAYER_H
#define BATTLE_PLAYER_H

#include <iostream>
#include <vector>
#include "string"
#include "Character.h"
using namespace std;

class Player {
public:
     Player();
    ~Player();
    void SetParty(vector<Character*>* party);

private:

    vector<Character*>* currentParty;
};


#endif //BATTLE_PLAYER_H
