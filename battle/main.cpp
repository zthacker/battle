#include <iostream>
#include "Player.h"
#include "Battle.h"

using namespace std;

int main() {

    Character* player1 = new Character("Player1", 10, 10, "player");
    Character* player2 = new Character("Player2", 10, 2, "player");
    Character* player3 = new Character("Player3", 10, 1, "player");
    Character* enemy1 = new Character("Enemy1", 10, 1, "enemy");
    Character* enemy2 = new Character("Enemy2", 10, 4, "enemy");
    Character* enemy3 = new Character("Enemy3", 10, 2, "enemy");
    vector<Character*>* battleCharacters = new vector<Character*>;
    battleCharacters->resize(0);

    //Players are inserted first so in the event of a speed-tie, the Players will be first in over the enemies
    battleCharacters->push_back(player1);
    battleCharacters->push_back(player2);
    battleCharacters->push_back(enemy1);
    battleCharacters->push_back(enemy2);
    battleCharacters->push_back(enemy3);
    battleCharacters->push_back(player3);


    Battle* battle = new Battle(battleCharacters);
    battle->BattleStart();



    if(battle->GetBattleResult() == BATTLE_RESULT_PLAYER_WIN) {
        cout<<"Player won the battle\n";
    }
    if(battle->GetBattleResult() == BATTLE_RESULT_ENEMY_WIN) {
        cout<<"Enemy won the battle\n";
    }
    if(battle->GetBattleResult() == BATTLE_RESULT_STREAM_CLOSED) {
        cout<<"Input stream closed\n";
    }

    return battle->GetBattleResult();

}
