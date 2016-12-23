#include<string>
#include<vector>
#include<iostream>
#include <algorithm> 
#include "asset.h"
#include "quote.h"
#include "option.h"
using namespace std;

option::option(asset *asset1) { underlying = asset1; }

double option::getImpliedVol() { return impliedVol; }

double option::calImpliedVol() {
	return 0;
};

double option::calCurPrice() {
	return 0;
}