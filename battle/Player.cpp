//
// Created by zthacker on 3/8/2024.
//



#include "Player.h"


Player::Player() {

}

Player::~Player() {

}

void Player::SetParty(vector<Character*>* party) {
    this->currentParty = party;
}
