#ifndef _Performance_para_H
#define _Performance_para_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "asset.h" 
#include "quote.h" 
using namespace std;

class quote;
class asset;

class Performance_para {

protected:
  asset *pAsset;
  vector<double> *pPrice;
  string AssetType;
  double value;
  int lookback_period; 
  double rf = 0.01;
     
  ~Performance_para() { 
  }
public:
  void setPointer(asset* a) {

	  pAsset = a;
	  pPrice = a->getPHisPrice();

  }


 /* Performance_para(asset *pAsset1)
  {
	  pPrice = pAsset->getPHisPrice();
	 lookback_period = pPrice->size();


  }*/

  


};

#endif