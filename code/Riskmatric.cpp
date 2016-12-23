#ifndef _Riskmatric_H
#define _Riskmatric_H

using namespace std;

class Riskmatric
{
public:
	virtual double calValue() = 0;
	virtual ~Riskmatric() {};
};

#endif