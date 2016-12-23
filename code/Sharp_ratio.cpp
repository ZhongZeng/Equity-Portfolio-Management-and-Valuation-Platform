#ifndef _Sharp_ratio_H
#define _Sharp_ratio_H

#include <iostream>
#include <cmath>
#include "asset.h"  
#include "Performance_para.cpp"
//#include "Volatility.cpp"
using namespace std;


class Sharp_ratio : public Performance_para {
	
  public: 
	//Volatility sigma;

	double calSharp(double a)
	{
		double sharp = (pAsset->getReturn() - rf) / (a);
		//double sharp = (pAsset->getReturn() - rf) / (sigma.my_std());
		return sharp; 
	}


	//~Sharp_ratio() { delete[] pAsset; }
	
};
#endif

