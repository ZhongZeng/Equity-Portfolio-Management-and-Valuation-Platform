#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include "quote.h"
#include "asset.h"
#include "portfolio.h"
using namespace std;

// Private Member
void portfolio::combineQuote() {
	vector<string> date_port;
	vector<double> price_port;
	vector<component>::iterator it = components.begin();
	date_port = it -> pAssetone -> getHisDate();
	price_port = it -> pAssetone -> getHisPrice();

	for (vector<component>::iterator it = components.begin()+1; it != components.end(); ++it) {
		double holdingsi = it->holdings;		
		vector<double> price_porti = it -> pAssetone -> getHisPrice();

		vector<double> pricei_m;
		for (int i = 0; i != price_porti.size(); ++i) {
			pricei_m.push_back ( price_porti[i] * holdingsi);
		}
		
		for (int j = 0; j != price_porti.size(); ++j) {
			price_port[j] = price_port[j] + pricei_m[j];
		}
	}

	quote_port.setHisPrice( date_port, price_port);
}

// Public Members
// Constructor
portfolio::portfolio() {}

portfolio::portfolio(int initial_balance) {
	balance = initial_balance;
}

// Member Functions
// See Portfolio
void portfolio::seeComponents() {
	for (vector<component>::iterator it = components.begin(); it != components.end(); ++ it) {
		component componenti = *it;
		double current_position = componenti.pAssetone->getCurPrice() * componenti.holdings;
		cout << componenti.pAssetone -> getTicker() << ": " << componenti.holdings << " shares, "
			<< "current price: $ " << componenti.pAssetone -> getCurPrice() 
			<< ", current position: $ " << current_position <<endl;
	}
};

void portfolio::seeCash() {
	cout << "The current balance of the portfolio is "<< balance << ". " << endl << endl;
}

void portfolio::seeCurrentValue() {
	double current_position = 0.0;
	for (vector<component>::iterator it = components.begin(); it != components.end(); ++it) {
		component componenti = *it;
		current_position = current_position + componenti.pAssetone->getCurPrice() * componenti.holdings;
		cout << "The current value of the portfolio is $ " << current_position << ". " << endl;
	}
}

void portfolio::seeQuote() {
	quote_port.seeHisPrice();
}

// Change Portfolio
void portfolio::buy(asset* pAsset1, int amount1) {
	if (balance >= pAsset1->getCurPrice() * amount1) {
		// if the balabce is enough, reduce the amount from the balance
		balance = balance - pAsset1->getCurPrice() * amount1;

		// check whether the asset is already in the portfolio
		vector<component>::iterator it;
		it = find(components.begin(), components.end(), pAsset1);

		if (it != components.end()) {
			// The asset is already in the portfolio.  
			it->holdings = it->holdings + amount1;
			cout << "The asset is already in the portfolio. " << endl;
			cout << "You have bought " << amount1 << " shares of " << pAsset1->getTicker() << ". " << endl;
			cout << "You now have " << it->holdings << " shares of " << pAsset1->getTicker()
				<< " in your portfolio. " << endl;
		}
		else {
			// The asset wasn't in the portfolio. 
			component componentnew(pAsset1, amount1);
			components.push_back(componentnew);
			cout << "The asset wasn't in the portfolio. " << endl;
			cout << "You have bought " << amount1 << " shares of " << pAsset1->getTicker() << ". " << endl;
			cout << "You now have " << amount1 << " shares of " << pAsset1->getTicker()
				<< " in your portfolio. " << endl;
		}
		
		this -> combineQuote();
	}
	else {
		cout << "Your current balance is not sufficient to buy this amount of asset. " << endl;
	}
	cout << endl;
}

void portfolio::sell(asset* pAsset1, int amount1) {
	// check whether the asset is already in the portfolio
	vector<component>::iterator it;
	it = find(components.begin(), components.end(), pAsset1);

	if (it != components.end()) {
		// The asset is already in the portfolio.  
		if ( it->holdings >= amount1) {
			it->holdings = it->holdings - amount1;
			balance = balance + pAsset1->getCurPrice() * amount1;
			cout << "You have sold " << amount1 << " shares of " << pAsset1->getTicker() << ". " << endl;
			if (it->holdings == 0) {
				components.erase(it);
				cout << "You don't have " << pAsset1->getTicker() << " in your portfolio anymore. " << endl;
			}else {
				cout << "You now have " << it->holdings << " shares of " << pAsset1->getTicker()
					<< " in your portfolio. " << endl;			
			}
			this->combineQuote();
		}
		else {
			cout << "You don't have sufficient amount of this asset in your portfolio to sell, so you can't sell it. " << endl;
		}
	}
	else {
		cout << "You don't have this asset in your portfolio, so you can't sell it. " << endl;
	}
	cout << endl;
}

void portfolio::addCash(double addCashAmount) { balance = balance + addCashAmount; }

void portfolio::withdrawCash(double withdrawCashAmount) { 
	if (balance >= withdrawCashAmount) {
		balance = balance + withdrawCashAmount;
	}
	else {
		cout << "You don't have sufficient amount of cash to withdraw. " << endl
			<< "You only have $" << balance << " in your portfolio. " <<endl;
	}
}

