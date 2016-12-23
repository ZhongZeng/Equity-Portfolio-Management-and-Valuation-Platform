#ifndef _Volatility_H
#define _Volatility_H

#include <iostream>
#include <cmath>
#include "asset.h" 
#include "Performance_para.cpp"
using namespace std;

class Volatility :public Performance_para {

	/*pPrice = pAsset->getPHisPrice();
	lookback_period = pPrice -> size();*/
public:
	Volatility(asset* a)
	{
		pAsset = a;
		pPrice = pAsset->getPHisPrice();
		lookback_period = pPrice->size();
	}

	double my_std()

	{

		double ave = 0.0;
		double avg = 0.0;
		double std = 0.0;
		double std1 = 0.0;

		for (int i = 0; i < lookback_period; ++i) {
			ave += (*pPrice)[i];
			avg = ave / lookback_period;
		}
		for (int j = 0; j < lookback_period; ++j) {

			std = pow(((*pPrice)[j] - avg), 2);

			std1 = std1 + std;
		}

		return sqrt(std1 / (lookback_period - 1));

	}

	//~Volatility() { delete[] pAsset; 
	//delete[] pPrice; }
};

#endif
