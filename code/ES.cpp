#ifndef _ES_H
#define _ES_H
#include<vector>
#include<string>
#include <algorithm> 
#include "Riskmatric.cpp"
#include "asset.h"
using namespace std;

class ES : public Riskmatric
{// Input: price, alpha (i.e. 1 - significance level)
 // Output: Expected Shortfall (measured by value)
private:
	double m_dAlpha;
	std::vector<double> m_vPrice;
public:
	explicit ES(std::vector<double> &vPrice, double alpha): m_dAlpha(alpha), m_vPrice(vPrice){}

	ES(asset * asset1, double m_dAlpha1) {
		m_vPrice = asset1->getHisPrice();
		m_dAlpha = m_dAlpha1;
	}

	ES(vector<double> m_vPrice1, double m_dAlpha1) {
		m_vPrice = m_vPrice1;
		m_dAlpha = m_dAlpha1;
	}
	
	void see() { for (int i = 1; i != m_vPrice.size() - 1; ++i) { cout << m_vPrice[i] << endl; } }

	virtual double calValue()
	{
		vector<double> changeOfPrice;
		for (int i = 1; i != m_vPrice.size(); ++i) {
			changeOfPrice.push_back(m_vPrice[i] - m_vPrice[i - 1]);
		}
		int pos = m_dAlpha * changeOfPrice.size() + 1;
		sort ( changeOfPrice.begin(), changeOfPrice.end());

		double tmpSum = 0.0;
		for (int i = 0; i != pos; i++)
			tmpSum = tmpSum + changeOfPrice[i];
		return tmpSum / pos;
	}
};

#endif