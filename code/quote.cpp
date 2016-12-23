#include<string>
#include<vector>
#include<iostream>
#include <algorithm> 
#include "asset.h"
#include "quote.h"
using namespace std;

// Constructor

// Member Functions
// Set Value Functions
void quote::setAsset(asset *asset1) {
	assetone = asset1;
}

void quote::setTicker(string ticker1) {
	ticker = ticker1;
}

void quote::setHisPrice(vector<string> date1, vector<double> price1) {
	date = date1;
	price = price1;
	len = price.size();
}

void quote::setHisPrice(vector<double> price1, vector<string> date1) {
	date = date1;
	price = price1;
	len = price.size();
}

void quote::addQuote(quote* quote1) {
	date.insert ( date.end(), quote1-> date.begin(), quote1->date.end() );
	price.insert( price.end(), quote1->price.begin(), quote1->price.end() );
}

void quote::addQuote(string date1, double price1) {
	date.push_back(date1);
	price.push_back(price1);
	len++;
}

void quote::addQuote(double price1, string date1) {
	date.push_back(date1);
	price.push_back(price1);
	len++;
}

//Get Valule Functions
asset* quote::getAsset() { return assetone; }

string quote::getTicker() { return ticker; }

string quote::getDate(int i) { return date[i-1];}

double quote::getPrice(int i) { return price[i-1]; }

double quote::getCurPrice() { return price[len-1]; };

vector<double> * quote::getPHisPrice() {
	vector<double> * HisPirce = &price;
	return HisPirce;
};

vector<string> * quote::getPHisDate() {
	vector<string> * HisDate = &date;
	return HisDate;
};

vector<double> quote::getHisPrice() {
	vector<double> HisPirce = price;
	return HisPirce;
};

vector<string> quote::getHisDate() {
	vector<string> HisDate = date;
	return HisDate;
};

void quote::seeHisPrice() {
	for (int i = 0; i != date.size(); ++i) {
		cout << "The price on " << date[i] << ": $" << price[i] << ". " << endl;
	}
}

double quote::getOnePrice(string date1) {
	int position = find( date.begin(), date.end(), date1) - date.begin();
	if (position != len)
		return price[position];
}

int quote::getLen() { return len; }

// Calculation Function
double quote::getReturn() {
	return price[len - 1] / price[0] - 1;
}

//distructor
quote::~quote() {};
