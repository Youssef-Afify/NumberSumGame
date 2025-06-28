#pragma once
#include<iostream>
#include<time.h>

class NumberPair
{
private:
	int number;
	int key;
	bool IsChosen;
	bool IsRemoved;
public:
	NumberPair(int = rand() % 9 + 1, int = rand() % 2, bool = false, bool = false);
	int GetNumber() const;
	int GetKey() const;
	bool AlreadyChosen() const;
	bool AlreadyRemoved() const;
	void Choose();
	void Remove();
	bool Restore();
};