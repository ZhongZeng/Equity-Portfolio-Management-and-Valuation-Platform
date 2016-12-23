#include <iostream>
#include <cmath>
#include "asset.h"  
#include "Performance_para.cpp"


class Beta : public Performance_para {
	asset *pIndex;
	double rf = 0.01;
public:
	void setPointer2(asset* b) {
		pIndex = b;

	}
	double calBeta()
	{
		//double tem1 = pAsset->getReturn;
		//double tem2 = pIndex->getReturn;
		//double beta = (tem1 - rf) / (tem2 - rf);
		double beta=((pAsset->getReturn())- rf) / ((pIndex->getReturn()) - rf);
	return beta; 
}

	

	//~Beta() { delete[] pAsset; }
	~Beta() {}
};
