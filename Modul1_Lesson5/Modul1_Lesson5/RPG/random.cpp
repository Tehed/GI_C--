#include "range.h"
#include "random.h"
#include <cstdlib>

int Random(Range r)
{
    return r.mLow + rand() % ((r.mHigh + 1) + r.mLow);
}

int Random(int low, int high)
{
    return low + rand() % ((low + 1) + high);
}