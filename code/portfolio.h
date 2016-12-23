#ifndef _portfolio_H
#define _portfolio_H

#include "quote.h"
#include "asset.h"
using namespace std;

class quote;

class asset;

// Struct
struct component {
	asset *pAssetone;
	double holdings;
	component(asset *pAssetone1, double holdings1) {pAssetone = pAssetone1; holdings = holdings1;}
	// The following line is to reload operator== in the struct
	bool operator==(const asset *right) { return pAssetone == right; } 
	//bool operator==(const component& right) { return pAssetone == right.pAssetone; }
};

/*struct find_asset : unary_function <component, bool> {
asset * assetone;
find_asset(asset * assetone) : assetone(assetone) { }
bool operator() (component & m) const { return m.assetone == assetone; }
};
struct find_asset : unary_function <component, bool>;*/

class portfolio {

private:
	vector<component> components;
	double balance;
	quote quote_port;
	void combineQuote();

public:
	// Constructor
	portfolio();
	portfolio(int initial_balance);

	// Member Functions
	// See Portfolio
	void seeComponents(); // see (cout) all components of the portfolio
	void seeCash(); // see (cout) the cash in the portfolio
	void seeCurrentValue(); //see (cout) the curretn value of the portfolio
	void seeQuote(); // see the combined quote of the portfolio

	// Change Portfolio
	void buy(asset *asset1, int amount1); // buy amount1 of asset1
	void sell(asset *asset1, int amount1); // sell amount1 of asset1
	void addCash(double addCashAmount); // add cash to the portfolio 
	void withdrawCash(double withdrawCashAmount);// withdraw cash from the portfolio

}; 

#endif
