#pragma once
#include "CSV.h"
#include "IncomeStatement.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

class Company {
	std::string name;
	std::string symbol;
	std::vector<IncomeStatement*> IS;
	std::vector<std::string> date;
	std::vector<std::string> incomestatement;
	std::vector<std::string> balancesheet;
	std::vector<std::string> cfo;
	std::vector<std::string> cfi;
	std::vector<std::string> cff;
public:
	Company(){}
	~Company() {
		date.clear();
		incomestatement.clear();
		balancesheet.clear();
		cfo.clear();
		cfi.clear();
		cff.clear();
	}

	/******************************************************************************************
	saveVlue -> THIS FUNCTION WILL SAVE A STRING TO A VECTOR WHICH WE WILL LATER PASS INTO A CLASS
	*******************************************************************************************/

	void saveValue(std::string wheretosave, std::string temp)
	{

		if (wheretosave == "name")
			for (int i = 0; i < temp.size(); i++)
				name += temp[i];

		if (wheretosave == "symbol")
			for (int i = 0; i < temp.size(); i++)
				symbol += temp[i];

		if (wheretosave == "date")
			if ( temp != "Date" )
				date.push_back(temp);

		if (wheretosave == "incomestatement")
			if (temp != "Income Statement")
				incomestatement.push_back(temp);

		if (wheretosave == "balancesheet")
			if (temp != "Balance Sheet")
				balancesheet.push_back(temp);

		if (wheretosave == "cfo")
			if (temp != "Cash Flows From Operating Activities" ) 
				cfo.push_back(temp);

		if (wheretosave == "cfi")
			if (temp != "Cash Flows From Investing Activities")
				cfi.push_back(temp);

		if (wheretosave == "cff")
			if (temp != "Cash Flows From Financing Activities")
				cff.push_back(temp);

	}

	/******************************************************************************************
	createClass -> Takes a vector and pushes the elements into a class
	*******************************************************************************************/
	/*void createClasses()
	{
		for ( int i = 0; i < incomestatement.size(); i++ )
		{
			for ( int k = 0; k < date.size(); k++ )
			{
				if (incomestatement[i] == "Revenue")
				{
					IncomeStatement* is = new IncomeStatement;
				}
			}
		}
	}*/

	/******************************************************************************************
	genericprint -> THIS FUNCTION WILL PRINT ALL THE ARRAYS
	*******************************************************************************************/

	void genericprint()
	{
		std::cout << "inside print\n\n";

		std::cout << "COMPANY :: " << name << " | SYMBOL :: " << symbol << "\n\n";

		for (std::vector<std::string>::iterator it = date.begin(); it != date.end(); it++)
		{
			std::cout << *it << "\n";
		}

		std::cout << "====================\n\n";

		for (std::vector<std::string>::iterator iit = incomestatement.begin(); iit != incomestatement.end(); iit++)
		{
			std::cout << *iit << "\n";
		}

		std::cout << "====================\n\n";

		for (std::vector<std::string>::iterator iit = balancesheet.begin(); iit != balancesheet.end(); iit++)
		{
			std::cout << *iit << "\n";
		}

		std::cout << "====================\n\n";

		for (std::vector<std::string>::iterator iit = cfo.begin(); iit != cfo.end(); iit++)
		{
			std::cout << *iit << "\n";
		}

		std::cout << "====================\n\n";

		for (std::vector<std::string>::iterator iit = cfi.begin(); iit != cfi.end(); iit++)
		{
			std::cout << *iit << "\n";
		}

		std::cout << "====================\n\n";

		for (std::vector<std::string>::iterator iit = cff.begin(); iit != cff.end(); iit++)
		{
			std::cout << *iit << "\n";
		}
	}

	/******************************************************************************************
	formattedprint -> THIS FUNCTION WILL PRINT ALL THE ARRAYS IN A FORMATTED MANNER
	*******************************************************************************************/

	void formattedprint()
	{
		// counter used to format elements
		int counter = 0;

		// flag used to determine if this is the first element we are printing, ie the description, like revenue
		int flag = 0;


		std::cout << "COMPANY :: " << name << " | SYMBOL :: " << symbol << "\n\n";

		// PRINT OUT THE DATES
		std::cout << std::setw(43) << std::left << "DATE:";
		for (std::vector<std::string>::iterator it = date.begin(); it != date.end(); it++)
		{
			std::cout << std::setw(12) << std::right << *it;
		}

		// PRINT OUT THE INCOME STATEMENT
		std::cout << "\n====================\n\n";
		std::cout << std::setw(43) << std::left << "Income Statement\n";
		for (std::vector<std::string>::iterator iit = incomestatement.begin(); iit != incomestatement.end(); iit++)
		{
			if ( counter < 5 )
			{
				if (flag == 0)
				{

					std::cout << "\n" << std::setw(43) << std::left << *iit;
					flag = 1;
					counter++;
				}
				else
				{
					std::cout << std::setw(12) << std::setfill(' ') << std::right << *iit;
					counter++;
				}
			}
			else
			{
				std::cout << "\n" << std::setw(43) << std::left << *iit;
				counter = 1;
			}
				
		}

		// PRINT FOR BALANCE SHEET
		flag = 0; 
		counter = 0;
		std::cout << "\n====================\n\n";
		std::cout << std::setw(43) << std::left << "Balance Sheet \n";
		for (std::vector<std::string>::iterator iit = balancesheet.begin(); iit != balancesheet.end(); iit++)
		{
			if (counter < 5)
			{
				if (flag == 0)
				{

					std::cout << "\n" << std::setw(43) << std::left << *iit;
					flag = 1;
					counter++;
				}
				else
				{
					std::cout << std::setw(12) << std::setfill(' ') << std::right << *iit;
					counter++;
				}
			}
			else
			{
				std::cout << "\n" << std::setw(43) << std::left << *iit;
				counter = 1;
			}
		}

		// PRINT FOR CASH FLOWS FROM OPERATIONS
		flag = 0;
		counter = 0;
		std::cout << "\n====================\n\n";
		std::cout << std::setw(43) << std::left << "Cash Flows From Operations \n";
		for (std::vector<std::string>::iterator iit = cfo.begin(); iit != cfo.end(); iit++)
		{
			if (counter < 5)
			{
				if (flag == 0)
				{

					std::cout << "\n" << std::setw(43) << std::left << *iit;
					flag = 1;
					counter++;
				}
				else
				{
					std::cout << std::setw(12) << std::setfill(' ') << std::right << *iit;
					counter++;
				}
			}
			else
			{
				std::cout << "\n" << std::setw(43) << std::left << *iit;
				counter = 1;
			}
		}

		// PRINT FOR CASH FLOWS FROM INVESTING
		flag = 0;
		counter = 0;
		std::cout << "\n====================\n\n";
		std::cout << std::setw(43) << std::left << "Cash Flows From Investing \n";

		for (std::vector<std::string>::iterator iit = cfi.begin(); iit != cfi.end(); iit++)
		{
			if (counter < 5)
			{
				if (flag == 0)
				{

					std::cout << "\n" << std::setw(43) << std::left << *iit;
					flag = 1;
					counter++;
				}
				else
				{
					std::cout << std::setw(12) << std::setfill(' ') << std::right << *iit;
					counter++;
				}
			}
			else
			{
				std::cout << "\n" << std::setw(43) << std::left << *iit;
				counter = 1;
			}
		}

		// PRINT FOR CASH FLOWS FROM INVESTING
		flag = 0;
		counter = 0;
		std::cout << "\n====================\n\n";
		std::cout << std::setw(43) << std::left << "Cash Flows From Financing \n";
		for (std::vector<std::string>::iterator iit = cff.begin(); iit != cff.end(); iit++)
		{
			if (counter < 5)
			{
				if (flag == 0)
				{

					std::cout << "\n" << std::setw(43) << std::left << *iit;
					flag = 1;
					counter++;
				}
				else
				{
					std::cout << std::setw(12) << std::setfill(' ') << std::right << *iit;
					counter++;
				}
			}
			else
			{
				std::cout << "\n" << std::setw(43) << std::left << *iit;
				counter = 1;
			}
		}

		// reset the line or else everything will be ugly
		std::cout << "\n=============================================================================="
				"\n==============================================================================\n\n";

	}  // formatted print function end

	void formattedPrintWithMargins()
	{
		std::cout << "COMPANY :: " << name << " | SYMBOL :: " << symbol << "\n\n";

		// PRINT OUT THE DATES
		std::cout << std::setw(43) << std::left << "DATE:";
		for (std::vector<std::string>::iterator it = date.begin(); it != date.end(); it++)
		{
			std::cout << std::setw(12) << std::right << *it;
		}

		
		printVector("Income Statement", incomestatement);

		
		printVector("Balance Sheet" , balancesheet);
		

		printVector("Cash Flows From Operations" , cfo);
		

		printVector("Cash Flows From Investing" , cfi);


		printVector("Cash Flows From Financing" , cff);
		
		// reset the line or else everything will be ugly
		std::cout << "\n==============================================================================================="
			"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
			"===============================================================================================\n\n";
	}

	void printVector(std::string nameOfStatement, std::vector<std::string> tempArray )
	{
		// LAMBDA function to calculate margine change % between quarters/years
		auto calculateMargin = [](std::string firstNumber, std::string secondNumber) -> float {			
			std::string::size_type sz;

			float one = std::stof(firstNumber, &sz);
			float two = std::stof(secondNumber, &sz);

			float calculation = ( (one / two ) - 1 ) * 100 ;

			return calculation;
		};


		// counter used to format elements
		int counter = 0;
		// flag used to determine if this is the first element we are printing, ie the description, like revenue
		int flag = 0;
		//
		float marginChange = 0;

		// PRINT OUT THE INCOME STATEMENT
		std::cout << "\n\n\n====================================================\n"
		          << std::setw(43) << std::left << nameOfStatement 
		          << "\n====================================================\n";

		for ( int iterator = 0; iterator < tempArray.size(); iterator++ )
		{
			if (counter < 5)
			{
				if (flag == 0)
				{			
					std::cout << "\n" << std::setw(43) << std::left  << tempArray[iterator];
					flag = 1;
					counter++;
				}
				else
				{
					// we cannot calculate this for last element of the array
					if (counter != 4)
					{
						marginChange = calculateMargin(tempArray[iterator], tempArray[iterator + 1]);
						std::cout << "(" << std::setw(7) << std::left << marginChange << ") ";
					}
					std::cout << std::setw(6) << std::setfill(' ') << std::left << tempArray[iterator] << " | ";
					counter++;
				}
			}
			else
			{
				std::cout << "\n--------------------------------------------------------------------------"
					          "------------------\n" << std::setw(43) << std::left << tempArray[iterator];
				counter = 1;
			}

		}
	}
};
