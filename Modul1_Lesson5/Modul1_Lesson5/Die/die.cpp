#include "die.h"
#include <cstdlib>

Die::Die()
{
    mSides = 6;
}

Die::Die(int sides)
{
    mSides = sides;
}

int Die::roll()
{
    return (rand() % mSides) + 1;
}

Die::~Die()
{

}
