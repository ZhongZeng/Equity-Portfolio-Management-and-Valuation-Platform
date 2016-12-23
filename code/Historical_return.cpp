#include <iostream>
#include <cmath>
#include "asset.h"  
#include "Performance_para.cpp"
using namespace std;


class Historical_return: public Performance_para {
public:
	
	double Hreturn(){
		double ret = pAsset->getReturn();
		return ret; 
	}

	//~Historical_return() { delete[] pAsset; }
	
};

