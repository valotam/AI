#pragma once
#include "BlackboardType.h"

class BlackboardInt : public BlackboardType
{

public:
	
	explicit BlackboardInt(const int &value) : value(value) {}
	~BlackboardInt() {}

	int getValue() const { return value; }
	void setValue(const int &value) { this->value = value; }

private:
	
	int value;
};

