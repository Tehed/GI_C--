#ifndef WEAPON_H
#define WEAPON_H

#include "range.h"
#include <string>

struct Weapon
{
    std::string mName;
    Range mDamageRange;
}

#endif