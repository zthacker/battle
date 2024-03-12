//
// Created by zthacker on 3/8/2024.
//

#include "Battle.h"

//Constructor
Battle::Battle(vector<Character*>* battleCharacters) {
    m_state = BATTLE_STATE_SETUP;
    this->battleCharacters = battleCharacters;
    this->enemies = new vector<Character*>;
    this->playerCharacters = new vector<Character*>;
}

Battle::~Battle() {
    m_state = BATTLE_STATE_SETUP;
}

void Battle::Initialize() {
    m_result = BATTLE_RESULT_STREAM_CLOSED;
    SetupBattle();
}

void Battle::SetupBattle() {
    cout<<"Doing setup battle stuff\n";

    cout<<"unsorted battle order"<<endl;
    for(auto b : *battleCharacters) {
        cout << b->name << " " << b->speed << " " << b->hp << endl;
    }

    //Sort the Battle Order
    sortBattleQueue(battleCharacters, battleCharacters->size());
    cout<<"sorted battle order"<<endl;
    for(auto b : *battleCharacters) {
        cout << b->name << " " << b->speed << " " << b->hp << endl;
    }

    for(auto b : *battleCharacters) {
        if(b->type == "enemy") {
            enemies->push_back(b);
        }
        if(b->type == "player") {
            playerCharacters->push_back(b);
        }
    }

    if(battleCharacters[0][0]->type == "player") {
        m_state = BATTLE_STATE_PLAYER_TURN;
    }
    if(battleCharacters[0][0]->type == "enemy") {
        m_state = BATTLE_STATE_ENEMY_TURN;
    }
}

void Battle::BattleStart() {
    while (m_state != BATTLE_STATE_BATTLE_OVER) {
        switch (m_state) {
            case BATTLE_STATE_SETUP:
            {
                cout<<"BATTLE_STATE_SETUP\n";
                Initialize();
            }
            break;
            case BATTLE_STATE_PLAYER_TURN:
            {
                cout<<"BATTLE_STATE_PLAYER_TURN\n";
                //"kill" the first enemy in the enemy list;
                enemies[0][0]->hp = enemies[0][0]->hp - enemies[0][0]->hp;

                //move the current player character to the back of the queue
                battleCharacters[0].push_back(battleCharacters[0][0]);

                //scrub them from the front to the next character is first
                battleCharacters[0].erase(battleCharacters[0].begin());

                //set the state
                if(battleCharacters[0][0]->type == "player") {
                    m_state = BATTLE_STATE_PLAYER_TURN;
                }
                if(battleCharacters[0][0]->type == "enemy") {
                    m_state = BATTLE_STATE_ENEMY_TURN;
                }

                //do checks
                UpdateEnemiesAndPlayers();
                CheckBattleResult();

            }
            break;
            case BATTLE_STATE_ENEMY_TURN:
            {
                cout<<"BATTLE_STATE_ENEMY_TURN\n";

                //"kill" the first enemy in the enemy list;
                playerCharacters[0][0]->hp = playerCharacters[0][0]->hp - 1;

                //move the current player character to the back of the queue
                battleCharacters[0].push_back(battleCharacters[0][0]);

                //scrub them from the front to the next character is first
                battleCharacters[0].erase(battleCharacters[0].begin());

                //set the state
                if(battleCharacters[0][0]->type == "player") {
                    m_state = BATTLE_STATE_PLAYER_TURN;
                }
                if(battleCharacters[0][0]->type == "enemy") {
                    m_state = BATTLE_STATE_ENEMY_TURN;
                }
                //do checks
                UpdateEnemiesAndPlayers();
                CheckBattleResult();
            }
            break;
            case BATTLE_STATE_BATTLE_OVER:
            {
                //do things with battle, like updating the character's state (levels, xp, etc)
                cout<<"BATTLE_STATE_BATTLE_OVER\n";
                return;


            }
            break;
            case BATTLE_STATE_WAITING_FOR_TURN:
            {
                //cout<<"BATTLE_STATE_WAITING_FOR_TURN\n";
                //check a queue of player and enemy that are ready to do an action
            }
            break;
        }
    }
    return;
}

int Battle::GetBattleResult() {
    return m_result;
}

void Battle::CheckBattleResult() {
    if(playerCharacters->empty()) {
        m_result = BATTLE_RESULT_ENEMY_WIN;
        m_state = BATTLE_STATE_BATTLE_OVER;
    }
    if(enemies->empty()) {
        m_result = BATTLE_RESULT_PLAYER_WIN;
        m_state = BATTLE_STATE_BATTLE_OVER;
    }

    if(playerCharacters->empty() && enemies->empty()) {
        m_result = BATTLE_RESULT_ENEMY_WIN;
        m_state = BATTLE_STATE_BATTLE_OVER;
    }
}

void Battle::sortBattleQueue(vector<Character*> *characters, int n) {

    //Not sure why I have to state the Vector to be characters[0] to access the vector -- maybe this is wrong to do?
    int i, j;
    Character* temp;
    for(i = 1; i < n; i++) {
        temp = characters[0][i];
        j = i - 1;

        while(j > -1 && characters[0][j]->speed > temp->speed) {
            characters[0][j + 1]= characters[0][j];
            j = j -1;
        }
        //edge case for have least value at the end of the array and needs to go to front
        characters[0][j + 1] = temp;
    }
}

void Battle::UpdateEnemiesAndPlayers() {

    //Apparently you can't erase from a vector like you do in Golang -- https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
    //Also we're removing from 3 vectors, probably better to do it some other way
    enemies->erase(remove_if(
            enemies->begin(),
            enemies->end(),
            [](Character* val) {return val->hp == 0;}), enemies->end());

    playerCharacters->erase(remove_if(
            playerCharacters->begin(),
            playerCharacters->end(),
            [](Character* val){return val->hp == 0;}),playerCharacters->end());

    battleCharacters->erase(remove_if(
            battleCharacters->begin(),
            battleCharacters->end(),
            [](Character* val) {return val->hp == 0;}),
                            battleCharacters->end());

    cout<<"UPDATED QUEUE"<<endl;
    for(auto b : *battleCharacters) {
        cout << b->name << " " << b->speed << " " << b->hp << endl;
    }
    cout<<"UPDATED ENEMIES"<<endl;
    for(auto b : *enemies) {
        cout << b->name << " " << b->speed << " " << b->hp << endl;
    }
    cout<<"UPDATED PLAYERS"<<endl;
    for(auto b : *playerCharacters) {
        cout << b->name << " " << b->speed << " " << b->hp << endl;
    }

}
