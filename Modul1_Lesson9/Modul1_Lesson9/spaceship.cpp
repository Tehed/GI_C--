#include "Vector3.h"
#include "spaceship.h"
#include <string>
#include <iostream>

Spaceship::Spaceship()
{
    mName = "DefaultName"; 
    mPosition = Vector3(0.0f, 0.0f, 0.0f); 
    mVelocity = Vector3(0.0f, 0.0f, 0.0f); 
    mFuelLevel = 100; 
    mDamage = 0; 
}

Spaceship::Spaceship(
    const std::string& name,
    const Vector3& pos,
    const Vector3& vel,
    int fuel,
    int damage)
{
    mName = name;
    mPosition = pos;
    mVelocity = vel;
    mFuelLevel = fuel;
    mDamage = damage;
}

void Spaceship::fly()
{
    std::cout << "Spaceship flying" << std::endl; 
} 

void Spaceship::printStats()
{
    // Print out ship statistics. 
    std::cout << "==========================" << std::endl; 
    std::cout << "Name = " << mName << std::endl; 
    std::cout << "Position = " << mPosition << std::endl; 
    std::cout << "Velocity = " << mVelocity << std::endl; 
    std::cout << "FuelLevel = " << mFuelLevel << std::endl; 
    std::cout << "Damage = " << mDamage << std::endl; 
}


FighterShip::FighterShip(
    const std::string& name,
    const Vector3& pos,
    const Vector3& vel,
    int fuel,
    int damage,
    int numMissiles)
    : Spaceship(name, pos, vel, fuel, damage)
{
    mNumMissiles = numMissiles;
}

void FighterShip::fireLaserGun()
{
    std::cout << "Firing laser gun... pew pew!" << std::endl;
}

void FighterShip::fireMissile()
{
    if(mNumMissiles > 0)
    {
        std::cout << "Firing missiles..." << std::endl;
        mNumMissiles--;
    }
    else
    {
        std::cout << "out of missiles" << std::endl;
    }
}

void FighterShip::printStats()
{
    Spaceship::printStats();
    std::cout << "Missiles = " << mNumMissiles << std::endl;;
}

BomberShip::BomberShip(
    const std::string& name, 
    const Vector3& pos, 
    const Vector3& vel, 
    int fuel, 
    int damage, 
    int numBombs) 
    // Call spaceship constructor to initialize "Spaceship" part. 
    : Spaceship(name, pos, vel, fuel, damage),
    // Initialize "BomberShip" part (alternative syntax)
    mNumBombs(numBombs)
{ 
} 

void BomberShip::dropBomb()
{
    if(mNumBombs > 0)
    {
        std::cout << "Dropping bomb..." << std::endl;
        mNumBombs--;
    }
    else
    {
        std::cout << "out of bombs" << std::endl;
    }
}