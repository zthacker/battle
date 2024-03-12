//
// Created by zthacker on 3/8/2024.
//

#ifndef BATTLE_BATTLE_H
#define BATTLE_BATTLE_H

#include <bits/stdc++.h>
#include<iostream>
#include <vector>
#include "Player.h"

using namespace std;

enum
{
    BATTLE_STATE_SETUP,
    BATTLE_STATE_ENEMY_TURN,
    BATTLE_STATE_PLAYER_TURN,
    BATTLE_STATE_WAITING_FOR_TURN,
    BATTLE_STATE_BATTLE_OVER

} BATTLE_STATE;

enum
{
    BATTLE_RESULT_PLAYER_WIN,
    BATTLE_RESULT_ENEMY_WIN,
    BATTLE_RESULT_STREAM_CLOSED
}BATTLE_RESULT;

class Battle {
public:
    Battle(vector<Character*>* battleCharacters);
    ~Battle();
    //Does this need to go into Private?
    void BattleStart();
    int GetBattleResult();
    void Initialize();

private:
    void SetupBattle();
    void CheckBattleResult();
    void UpdateEnemiesAndPlayers();
    int m_result;
    int m_state;
    vector<Character*>* battleCharacters;
    void sortBattleQueue(vector<Character*>* characters, int n);
    vector<Character*>* enemies;
    vector<Character*>* playerCharacters;

};


#endif //BATTLE_BATTLE_H
