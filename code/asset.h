#ifndef _asset_H
#define _asset_H

#include<string>
#include<vector>
#include<iostream>
#include "quote.h"
using namespace std;

class quote;

class asset {

protected:
	quote *His_p;
	double Cur_p; //Current Price
	string ticker;

public:
	// Constructor

	// Member Functions

	// Set Functions
	void setQuote(quote *His_p0);

	// Get Functions
	string getTicker(); // get ticker 
	double getCurPrice(); // get current price 
	vector<double> * getPHisPrice(); // return a pointer pointing at historical price 
	vector<string> * getPHisDate(); // return a pointer pointing at historical date
	vector<double> getHisPrice(); // get historical price
	vector<string> getHisDate(); // get historical date
	double getReturn(); // get asset return 

	// Performance Parameters


	// Distructor


}; 

#endif