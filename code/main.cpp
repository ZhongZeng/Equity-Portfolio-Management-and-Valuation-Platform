#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include "quote.h"
#include "asset.h"
#include "stock.h"
#include "portfolio.h"
#include "Performance_para.cpp"
#include "Historical_return.cpp"
#include "Beta.cpp"
#include "Tracking_error.cpp"
#include "Volatility.cpp"
#include "Sharp_ratio.cpp"
#include "Riskmatric.cpp"
#include "VaR.cpp"
#include "ES.cpp"
using namespace std;

#include <fstream> 
#include <sstream> 
#include <iomanip> 

// -------------- added from Niclas -------------

class MyDate
{
public:
	int mm;
	int dd;
	int yyyy;

	MyDate(int m, int d, int y)
	{
		mm = m;
		dd = d;
		yyyy = y;
	}
};

class HistData
{
public:
	MyDate date;
	vector <double> price; // Open, Hi,Low, Close (multidimensional vector)

	HistData(MyDate d, vector <double> p) : date(d), price(p) {};

	// overwritting operator << (declaration)
	friend ostream& operator<<(ostream& os, const HistData& hd);
};

// overwritting operator << (implementation)
ostream& operator<<(ostream& os, const HistData& hd)
{
	os << setw(2) << hd.date.mm << "/"
		<< setw(2) << hd.date.dd << "/"
		<< hd.date.yyyy << ","
		<< fixed << setprecision(2)
		<< hd.price[0] << endl;
	return os;
}

// parser function
HistData parser(stringstream& ss, const char& dlm)
{
	string datestring;
	getline(ss, datestring, dlm);
	stringstream dss(datestring);
	string a;
	vector <int> dd;
	vector <double> pp;

	while (getline(dss, a, '/'))
	{
		if (isdigit(a[0]))
		{
			dd.push_back(stoi(a));
		}
		else
		{
			a = "-1";
			dd.push_back(stoi(a));
		}
	}

	while (getline(ss, a, dlm))
	{
		if (isdigit(a[0]))
		{
			pp.push_back(stof(a));
		}
		else
		{
			a = "-1";
			pp.push_back(stof(a));
		}
	}

	HistData hd(MyDate(dd[0], dd[1], dd[2]), pp);

	return hd;
}

int main() {


	// Transfer data from a csv file to C++ file

	// 1) Read stock list into C++

	string readticker; // read every line in as a string
	vector <string> stock_list;

	ifstream infile_list("stock_list.csv");

	if (infile_list.fail())
	{
		cerr << "fail to open file stock_list.csv for reading" << endl;
		return -1;
	}

	while (getline(infile_list, readticker, ','))
	{
		stock_list.push_back(readticker);
	}

	infile_list.close();

	ofstream outfile_list("stock_list.out");

	if (outfile_list.fail())
	{
		cerr << "fail to open file stock_list.out for writing" << endl;
		return -1;
	}

	for (auto const& e : stock_list)
	{
		outfile_list << e << ",";
	}

	outfile_list.close();


	// 2) Read every stock's csv file into C++

	quote GSPC;
	quote AAPL;
	quote IBM;
	quote GS;
	quote JPM;
	quote MCD;
	quote CAT;
	quote WMT;
	quote MSFT;
	quote GE;

	quote *pGSPC = &GSPC;
	quote *pAAPL = &AAPL;
	quote *pIMB = &IBM;
	quote *pGS = &GS;
	quote *pJPM = &JPM;
	quote *pMCD = &MCD;
	quote *pCAT = &CAT;
	quote *pWMT = &WMT;
	quote *pMSFT = &MSFT;
	quote *pGE = &GE;


	for (auto const& i : stock_list)
	{
		string tickername = i;

		string readline;
		vector <HistData> dummy; // have a vector of class HistData

		ifstream infile(tickername + ".csv");

		if (infile.fail())
		{
			cerr << "fail to open file " << tickername << ".csv for reading" << endl;
			return -1;
		}

		char const dlm = ','; // specify the deliminater 
		getline(infile, readline);

		while (getline(infile, readline))
		{
			stringstream ss(readline);
			dummy.push_back(parser(ss, dlm));
		}

		infile.close();

		// Read the data into vectors to be used in other classes

		string readinput;
		string b;
		vector<vector<string>>DataDummy(2);

		ifstream infile2(tickername + ".csv");

		if (infile2.fail())
		{
			cerr << "fail to open file " << tickername << ".csv for reading" << endl;
			return -1;
		}

		getline(infile2, readinput);

		while (getline(infile2, readinput))
		{
			int i = 0;
			stringstream ss2(readinput);
			while (getline(ss2, b, ','))
			{
				DataDummy[i].push_back(b);
				++i;
			}
		}

		infile2.close();


		vector <string> DateDummy;

		for (auto const& e : DataDummy[0])
		{
			DateDummy.push_back(e);
		}

		vector <double> PriceDummy;

		for (auto const& e : DataDummy[1])
		{
			PriceDummy.push_back(stod(e));
		}

		// Create Quote objects
		// (tickers need to be in C++ since  C++ has no mechanism to create objects whose types are determined at runtime


		if (tickername == "GSPC")
		{
			GSPC.setTicker(tickername);
			GSPC.setHisPrice(DateDummy, PriceDummy);
		}

		if (tickername == "AAPL")
		{
			AAPL.setTicker(tickername);
			AAPL.setHisPrice(DateDummy, PriceDummy);
		}

		if (tickername == "IBM")
		{
			IBM.setTicker(tickername);
			IBM.setHisPrice(DateDummy, PriceDummy);
		}

		if (tickername == "GS")
		{
			GS.setTicker(tickername);
			GS.setHisPrice(DateDummy, PriceDummy);
		}

		if (tickername == "JPM")
		{
			JPM.setTicker(tickername);
			JPM.setHisPrice(DateDummy, PriceDummy);
		}

		if (tickername == "MCD")
		{
			MCD.setTicker(tickername);
			MCD.setHisPrice(DateDummy, PriceDummy);
		}

		if (tickername == "CAT")
		{
			CAT.setTicker(tickername);
			CAT.setHisPrice(DateDummy, PriceDummy);
		}

		if (tickername == "WMT")
		{
			WMT.setTicker(tickername);
			WMT.setHisPrice(DateDummy, PriceDummy);
		}

		if (tickername == "MSFT")
		{
			MSFT.setTicker(tickername);
			MSFT.setHisPrice(DateDummy, PriceDummy);
		}

		if (tickername == "GE")
		{
			GE.setTicker(tickername);
			GE.setHisPrice(DateDummy, PriceDummy);
		}

	}

	cout << GE.getPrice(1) << endl << endl;
	cout << GE.getTicker() << endl << endl;
	GE.seeHisPrice();


	//cout << "Run successfully" << endl << endl;

	// -------------- added from Niclas ------------


	asset GSPC_a;
	asset AAPL_a;
	asset IBM_a;
	asset GS_a;
	asset JPM_a;
	asset MCD_a;
	asset CAT_a;
	asset WMT_a;
	asset MSFT_a;
	asset GE_a;

	asset * pGSPC_a = &GSPC_a;
	asset * pAAPL_a = &AAPL_a;
	asset * pIBM_a = &IBM_a;
	asset * pGS_a = &GS_a;
	asset * pJPM_a = &JPM_a;
	asset * pMCD_a = &MCD_a;
	asset * pCAT_a = &CAT_a;
	asset * pWMT_a = &WMT_a;
	asset * pMSFT_a = &MSFT_a;
	asset * pGE_a = &GE_a;

	GSPC_a.setQuote( &GSPC );
	AAPL_a.setQuote( &AAPL );
	IBM_a.setQuote( &IBM );
	GS_a.setQuote( &GS );
	JPM_a.setQuote( &JPM );
	MCD_a.setQuote( &MCD );
	CAT_a.setQuote( &CAT );
	WMT_a.setQuote( &WMT );
	MSFT_a.setQuote( &MSFT );
	GE_a.setQuote( &GE );

	/*
	GSPC_a.setQuote( pGSPC );
	AAPL_a.setQuote( pAAPL );
	IBM_a.setQuote(pIBM );
	GS_a.setQuote( pGS );
	JPM_a.setQuote( pJPM );
	MCD_a.setQuote( pMCD );
	CAT_a.setQuote( pCAT );
	WMT_a.setQuote( pWMT );
	MSFT_a.setQuote( pMSFT );
	GE_a.setQuote( pGE );*/

	/*
	quote app_q;
	quote *pApp_q = &app_q;
	app_q.setTicker("AAPL");
	app_q.setHisPrice({ "20161020", "20161021"} , {20.2, 20.3});
	quote app_q1;
	app_q1.setHisPrice({ "20161022", "20161023" }, { 25, 23 });
	app_q.addQuote(&app_q1);
	app_q.addQuote("20161024", 24.3);
	app_q.seeHisPrice();

	cout << app_q.getPrice(1) << endl;
	cout << app_q.getDate(1) << endl;
	cout << app_q.getLen() << endl;
	cout << app_q.getReturn() << endl;
	vector<double> * hisprice;
	hisprice = app_q.getPHisPrice();
	cout << "The size of historical price " << hisprice -> size() << endl;
	cout << "The first element in price " << hisprice -> front() << endl;
	cout << "The second element in price " << (*hisprice)[1] << endl;
	(*hisprice)[0] = 10;
	string date1 = "20161022";
	cout << "The price on " << date1 << " is " << app_q.getOnePrice(date1) << endl;

	cout << "Following is related the asset class. " << endl;
	asset app_asset;
	asset *papp_asset = &app_asset;
	app_asset.setQuote(pApp_q);
	cout << app_asset.getTicker() << endl;
	vector<double> * asset_hp;
	asset_hp = app_asset.getPHisPrice();
	cout << "The size of historical price is " << asset_hp -> size() << endl;
	cout << "The first element in price is " << asset_hp -> front() << endl;
	cout << "The first element in price is " << (*asset_hp)[0] << endl;
	cout << "The return is " << papp_asset -> getReturn() << endl;

	quote dell_quote;
	dell_quote.setTicker("DELL");
	quote * pDell_quote = & dell_quote;
	dell_quote.setHisPrice({ "20161020", "20161021", "20161022", "20161023", "20161024" }, { 10, 9.4, 9.7, 9.4, 12 });
	dell_quote.seeHisPrice();

	asset dell_asset;
	asset * pdell_asset = & dell_asset;
	dell_asset.setQuote(pDell_quote); */

	portfolio port(100000);
	port.buy(pGE_a, 10);
	port.buy(pGE_a, 1000);
	port.buy(pGE_a, 5);
	port.buy(pGS_a, 20);
	port.sell(pGS_a, 10000);
	port.sell(pGS_a, 20);
	port.buy(pGS_a, 11);
	port.seeCash() ;
	port.seeComponents() ;
	port.seeQuote();
	port.withdrawCash(1000000000);

/* TJ Performance Parameters*/
	
	quote app_q;
	quote *pApp_q = &AAPL;
	
	quote ind_q;//GSPC
	quote *pInd_q = pGSPC;

	asset ind_asset;
	ind_asset.setQuote(pInd_q);
	// cout << ind_asset.getTicker() << endl;
	vector<double> * ind_hp;
	ind_hp = ind_asset.getPHisPrice();

	asset app_asset;
	app_asset.setQuote(pApp_q);

	Historical_return Historreturn;
	Beta Mybeta;
	Tracking_error TE;
	Sharp_ratio sharp;
	Volatility Vol( &ind_asset);
	
	cout << endl << endl;
	cout << "The performance parameters of " << app_asset.getTicker() << " are as following. " << endl;
	Historreturn.setPointer(&app_asset);
	double hisreturn = Historreturn.Hreturn();
	cout << "The historical return is " << hisreturn << endl;

	Mybeta.setPointer(&app_asset);
	Mybeta.setPointer2(&ind_asset);
	double thebeta = Mybeta.calBeta();
	cout << "The beta is " << thebeta << endl;

	TE.setPointer(&app_asset);
	double myte = TE.calTrack(&ind_asset);
	cout << "The Tracking error is " << myte << endl;

	Vol.setPointer(&app_asset);

	double myVol = Vol.my_std();
	cout << "The Volatility is " << myVol << endl;

	sharp.setPointer(&app_asset);
	double Mysharpratio = sharp.calSharp(myVol);
	cout << "The sharpe ratio is " << Mysharpratio << endl;

	VaR var_aapl( &app_asset, 0.05);
	cout << "5% VaR of "<< app_asset.getTicker() << "'s stock price is $ "<<var_aapl.calValue() << endl;

	ES es_aapl(&app_asset, 0.05);
	cout << "5% Expected Shortfall of " << app_asset.getTicker() << "'s stock price is $ " <<es_aapl.calValue() << endl;

	int a;
	cin >> a;

	return 0;
}