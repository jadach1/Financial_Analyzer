#pragma once
#include "CSV.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

class IncomeStatement {
		
	int flagfulllYear;
	int flagquarter;
	int year;
	int quarter;
	std::vector<int>revenue;
	std::vector<int>cogs;
	std::vector<int>grossprofit;
	std::vector<int>sga;
	std::vector<int>otheroperatingexpenses;
	std::vector<int>operatingincome;
	std::vector<int>nonoperatingincome;
	std::vector<int>interestexpense;
	std::vector<int>unusualexpense;
	std::vector<int>pretaxincome;
	std::vector<int>incometaxes;
	std::vector<int>equityinearningsofaffiliatesincome;
	std::vector<int>otheraftertaxadjustments;
	std::vector<int>consolodatednetincome;
	std::vector<int>minorityinterestexpense;
	std::vector<int>netincomecontinuingoperations;
	std::vector<int>preferreddividends;
	std::vector<int>netincomeavailabletocommonbasicshares;
	std::vector<float>epsdilutedbeforeunusualexpense;
	std::vector<float>EPSbasicBeforeExtraordinaries;
	std::vector<float>EPSFullyDiluted;
public:
	IncomeStatement() { flagfulllYear = 0; flagquarter = 0; quarter = 0; year = 0; }

};
