#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include "quote.h"
#include "asset.h"
using namespace std;

// Constructor

// Set Functions

void asset::setQuote(quote *His_p0) {
	His_p = His_p0;
	ticker = His_p0 -> getTicker();
}

// Get Functions

string asset::getTicker() {
	return His_p -> getTicker();
}

double asset::getCurPrice() {
	return His_p -> getCurPrice();
}

vector<double> * asset::getPHisPrice() {
	return His_p -> getPHisPrice();
}

vector<string> * asset::getPHisDate() {
	return His_p->getPHisDate();
}

vector<double> asset::getHisPrice() {
	return His_p->getHisPrice();
}

vector<string> asset::getHisDate() {
	return His_p->getHisDate();
}

double asset::getReturn() {
	return His_p -> getReturn();
}
