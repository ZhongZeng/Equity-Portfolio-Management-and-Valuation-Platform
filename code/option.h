#ifndef _option_H
#define _option_H
#include "asset.h"
#include "quote.h"

using namespace std;

class option : public asset {
private:
	asset *underlying; // underlying asest
	double impliedVol;

public:
	// Constructor
	option(asset *asset1);	

	// Member Functions
	double getImpliedVol();
	double calImpliedVol();
	double calCurPrice();
};

#endif
