#include"NumberPair.h"

NumberPair::NumberPair(int num, int k, bool ch, bool re) : IsChosen(ch), IsRemoved(re)
{
	number = num;
	key = k;
}

int NumberPair::GetNumber() const
{
	return number;
}

int NumberPair::GetKey() const
{
	return key;
}

bool NumberPair::AlreadyChosen() const
{
	return IsChosen;
}

bool NumberPair::AlreadyRemoved() const
{
	return IsRemoved;
}

void NumberPair::Choose()
{
	IsChosen = true;
}

void NumberPair::Remove()
{
	IsRemoved = true;
}

bool NumberPair::Restore()
{
	bool result = IsChosen || IsRemoved;
	IsChosen = false;
	IsRemoved = false;
	return result;
}