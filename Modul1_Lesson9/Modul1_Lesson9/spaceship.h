#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Vector3.h"
#include <string>

class Spaceship
{
public:
    Spaceship();
    Spaceship(
        const std::string& name,
        const Vector3& pos,
        const Vector3& vel,
        int fuel,
        int damage);

    void fly();
    void printStats();

protected:
    std::string mName;
    Vector3 mPosition;
    Vector3 mVelocity;
    int mFuelLevel;
    int mDamage;
};


class FighterShip : public Spaceship
{
public:
    FighterShip(
        const std::string& name,
        const Vector3& pos,
        const Vector3& vel,
        int fuel,
        int damage,
        int numMissiles);

    void fireLaserGun();
    void fireMissile();
    void printStats();

private:
    int mNumMissiles;
};

class BomberShip : public Spaceship
{
public:
    BomberShip(
        const std::string& name,
        const Vector3& pos,
        const Vector3& vel,
        int fuel,
        int damage,
        int numBombs);

    void dropBomb();

private: 
    int mNumBombs;
};

#endif