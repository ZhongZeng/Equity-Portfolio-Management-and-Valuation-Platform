#ifndef _riskmatric_H
#define _riskmatric_H

#include<vector>
#include<string>
#include <algorithm> 
#include "quote.h"
#include "asset.h"
using namespace std;

class riskmatric {
protected:
	double value;
	string lookback_period;
	asset* assetone;

public:
	virtual double calValue() { return 0.0; }

};

#endif
