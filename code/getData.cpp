#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include "quote.h"
#include "asset.h"
#include "stock.h"
// #include "portfolio.h"

// -------------- added from Niclas -------------

#include <fstream> // needed for the file stream
#include <sstream> // needed for the string stream
#include <iomanip> // needed; code won't be executed withou
#include <stdlib.h> // code runs withouht; not sure whether needed or not

// -------------- added from Niclas -------------

using namespace std;



// -------------- added from Niclas ----------------------------------------------------



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

class niclas{

void niclas::getData(){
	// -------------- added from Niclas ----------------------------------------------------

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

	/*
	for (auto const& e : stock_list)
	{
	cout << e << " ";
	}

	cout << endl << endl;
	*/


	// 2) Read every stock's csv file into C++

	for (auto const& i : stock_list)
	{
		// cout << i << " ";

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
		// vector <string> DateDummy;
		// vector <double> PriceDummy;

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

		/*
		for (auto const& e : DataDummy[0])
		{
		cout << e << ",";
		}

		cout << endl << endl;

		for (auto const& e : PriceDummy)
		{
		cout << e << ",";
		}

		cout << endl << endl;
		*/


		// ------------------- Nilas new part -----------------------------------

		// Create Quote objects
		// (tickers need to be in C++ since  C++ has no mechanism to create objects whose types are determined at runtime

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



		// for (int i = 1; i < 5; i++)
		// {

		// cout << GE.getPrice(1) << endl << endl;
		// }




		// ------------------- Nilas new part -----------------------------------

	}

	cout << "Run successfully" << endl << endl;


	// -------------- added from Niclas ----------------------------------------------------

}

};