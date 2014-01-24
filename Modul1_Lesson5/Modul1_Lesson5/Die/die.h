
#ifndef DIE_H
#define DIE_H

class Die
{
public:
    // constructors
    Die();
    Die(int sides);

	// destructor
	~Die();

    int roll();

private: 
    int mSides;
};
#endif  // DIE_H