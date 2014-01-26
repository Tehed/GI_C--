#include "map.h"
#include "player.h"
#include "monster.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/*
 * returns true, if player survived the combat
 */
bool combat(Player* player, Monster* monster)
{
    bool playerSurvived = true;

    while(true)
    {
        player->displayHitpoints();
        monster->displayHitPoints();

        bool runAway = player->attack(*monster);

        if(runAway) 
        {
            break;
        }

        if(monster->isDead())
        {
            player->victory(monster->getXPReward());
            player->levelUp();
            break;
        }

        monster->attack(*player);

        if(player->isDead())
        {
            player->gameOver();
            playerSurvived = false;
            break;
        }
    }

    return playerSurvived;
}

int main()
{
    // init random thingy
    srand(time(0));

    Map map;
    Player player;

    player.createClass();

    bool running = true;
    while(running)
    {
        map.printPlayerPos();

        int selection = 0;
        cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: ";
        cin >> selection;

        Monster* monster = 0;

        switch(selection)
        {
        case 1: 
            map.movePlayer();
            monster = map.checkRandomEncounter();
            if(monster > 0)
            {
                bool survived = combat(&player, monster);
                if(!survived)
                {
                    running = false;
                }
            }

            delete monster;
            monster = 0;

            break;

        case 2:
            player.rest();
            break;

        case 3:
            player.viewStats();
            break;

        case 4:
            running = false;
            break;
        }
    }

    cout << endl << "Thanks for playing" << endl;

    cin.get();
    cin.get();
}