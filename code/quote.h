#ifndef _quote_H
#define _quote_H

using namespace std;

class asset;

class quote {
private:
	asset *assetone; // asset pointer
	string ticker;// asset ticker
	vector<string> date; //hitorical dates
	vector<double> price; //historical prices
	int len; // numbers of dates/prices

public:
	// Constructor
	quote() {};

	// Member Functions
	// Set Value Functions
	void setAsset(asset* asset1); // make asset1 point to an asset
	void setTicker(string ticker1); // set the ticker of the quote
	void setHisPrice(vector<string> date1, vector<double> price1); // store historical dates and prices into a quote object
	void setHisPrice(vector<double> price1, vector<string> date1); // 
	void addQuote(quote* quote1); // combine two quote objects together 
	void addQuote(string date1, double price1); // add a combination of date and price to quote 
	void addQuote(double price1, string date1); // add a combination of date and price to quote  

	// Get Valule Functions
	asset* getAsset(); // get asset pointer
	string getTicker(); // get asset ticker
	string getDate(int i); // get date at ith position (the first is 1 not 0) 
	double getPrice(int i); // get price at ith position (the first is 1 not 0) 
	double getCurPrice(); // get current price
	vector<double> * getPHisPrice(); // return a pointer pointing at historical price 
	vector<string> * getPHisDate(); // return a pointer pointing at historical date
	vector<double> getHisPrice(); // get historical price 
	vector<string> getHisDate(); // get historical price 
	void seeHisPrice(); // see all historical price
	double getOnePrice(string date1); // get the price give a specific date 
	int getLen(); //

	// Calculate Functions
	double getReturn();

	// Distructor
	~quote();

};

#endif