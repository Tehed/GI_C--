
#include "monster.h"
#include "random.h"
#include <iostream>
#include <string>



Monster::Monster(const std::string& name, int hp, int acc, 
        int xpReward, int armor, const std::string& weaponName, 
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

std::string Monster::getName()
{
    return mName;
}

int Monster::getArmor()
{
    return mArmor;
}

void Monster::attack(Player& player)
{
    if(Random(0,20) < mAccuracy)
    {
        // D20 -> hit -> calculate damage
        int damage = Random(mWeapon.mDamageRange);
        int totalDamage = damage - player.getArmor();
    }
}

void Monster::takeDamage(int damage)
{
    mHitPoints -= damage;
}

void Monster::displayHitPoints()
{
}
