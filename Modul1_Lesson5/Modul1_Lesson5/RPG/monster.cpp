
#include "monster.h"
#include "random.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

Monster::Monster(const string& name, int hp, int acc, 
        int xpReward, int armor, const string& weaponName, 
        int lowDamage, int highDamage)
{
    mName = name;
    mHitPoints = hp;
    mAccuracy = acc;
    mExpReward = xpReward;
    mArmor = armor;

    mWeapon.mName = weaponName;
    mWeapon.mDamageRange.mLow = lowDamage;
    mWeapon.mDamageRange.mHigh = highDamage;
}

bool Monster::isDead()
{
    return (mHitPoints <= 0);
}

int Monster::getXPReward()
{
    return mExpReward;
}

string Monster::getName()
{
    return mName;
}

int Monster::getArmor()
{
    return mArmor;
}

void Monster::attack(Player& player)
{
    cout << "A " << mName << " attacks you with a " << mWeapon.mName << endl;

    if(Random(0,20) < mAccuracy)
    {
        // D20 -> hit -> calculate damage
        int damage = Random(mWeapon.mDamageRange);
        int totalDamage = damage - player.getArmor();

        if(totalDamage <= 0)
        {
            cout << "The monster's attack failed to penetrate your armor." << endl;
        }
        else
        {
            cout << "You are hit for " << totalDamage << " damage!" << endl;
            player.takeDamage(totalDamage);
        }
    }
    else
    {
        cout << "The " << mName << " missed!" << endl;
    }
}

void Monster::takeDamage(int damage)
{
    mHitPoints -= damage;
}

void Monster::displayHitPoints()
{
    cout << mName << "'s hitpoints = " << mHitPoints << endl;
}
