#ifndef PLAYER_H
#define PLAYER_H

#include "monster.h"
#include "weapon.h"
#include <string>

class Player
{
public:
    Player();

    bool isDead();

    std::string getName();
    int getArmor();

    void takeDamage(int damage);

    void createClass();

    /*
     * returns true, if the player chose to run away
     */
    bool attack(Monster& monster);

    void levelUp();
    void rest();
    void viewStats();
    void victory(int xp);
    void gameOver();
    void displayHitpoints();

private:
    std::string mName; 
    std::string mClassName; 
    int mAccuracy; 
    int mHitPoints; 
    int mMaxHitPoints; 
    int mExpPoints; 
    int mNextLevelExp; 
    int mLevel; 
    int mArmor; 
    Weapon mWeapon; 
};

#endif