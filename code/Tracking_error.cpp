#include <iostream>
#include <cmath>
#include "asset.h"  
#include "Performance_para.cpp"
using namespace std;



class Tracking_error : public Performance_para {


	asset *pIndex;

protected:
	double Tracking_error1;

public:
	/*void setPointer2(asset* b) {
		pIndex = b;
	}*/
	
	double calTrack(asset* pIndex) {

		
		Tracking_error1 = pAsset->getReturn() - pIndex->getReturn();

		return Tracking_error1;
	}



	//~Tracking_error() { delete[] pAsset; }
	~Tracking_error() { }

};
