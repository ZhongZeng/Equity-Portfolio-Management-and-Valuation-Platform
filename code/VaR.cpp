#ifndef _VaR_H
#define _VaR_H
#include<vector>
#include<string>
#include <algorithm> 
#include "Riskmatric.cpp"
#include "asset.h"
using namespace std;

class VaR : public Riskmatric
{// Input: price, alpha (i.e. 1 - significance level)
 // Output: Value at Risk (measured by value)
private:
	double m_dAlpha;
	vector<double> m_vPrice;

public:
	// explicit VaR(std::vector<double> &vPrice, double alpha): m_dAlpha(alpha), m_vPrice(vPrice){	}
	VaR(asset * asset1, double m_dAlpha1) {
		m_vPrice = asset1->getHisPrice();
		m_dAlpha = m_dAlpha1;
	}

	VaR(vector<double> m_vPrice1, double m_dAlpha1) {
		m_vPrice = m_vPrice1;
		m_dAlpha = m_dAlpha1;
	}

	// void see() {for (int i = 1; i != m_vPrice.size() - 1; ++i) {cout << m_vPrice[i] << endl;}}

	virtual double calValue() {
		vector<double> changeOfPrice;
		for (int i = 1; i != m_vPrice.size(); ++i) {
			changeOfPrice.push_back( m_vPrice[i] - m_vPrice[i - 1]);
		}
		int pos = m_dAlpha * changeOfPrice.size();
		sort ( changeOfPrice.begin(), changeOfPrice.end());
		return changeOfPrice[pos];
	}
};

/*
class var : public Riskmatric {

public:
double calValue() {
vector<double> * pPrice = assetone -> getPHisPrice();
// enter your quote as following
}
};
*/

#endif