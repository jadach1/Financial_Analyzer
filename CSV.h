#pragma once
#include "CompanyProfile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class CSV {
	std::vector<Company*> companies;
	std::vector<std::string> listOfFiles;
public:
	CSV() {  }
	~CSV() {  
			for (int i = 0; i < companies.size(); i++)
				delete companies[i];

			companies.clear(); 
			std::cout << "death\n"; 
	}

/******************************************************************************************
GRABS A LIST OF COMPANY NAMES FROM A FILE AND STORES THEM INTO AN ARRAY, CALLS THE NEXT 
FUNCTION TO START GRABBING DATA FROM EACH FILE IN THE LIST
*******************************************************************************************/
	void grabList()
	{
		std::ifstream file;
		std::string line;

		file.open("myList.txt");

		if (file.is_open())
		{
			while (!file.eof())
			{
				getline(file, line);
				listOfFiles.push_back(line);
			}
		}
		else
			std::cout << "Unable to open file";

		file.close();

		std::cout << "print file\n";

		if (listOfFiles.size() > 0)
		{
			for (int i = 0; i < listOfFiles.size(); i++)
				grabCompanyData(listOfFiles[i]);		
		}
	}

/******************************************************************************************
STARTS THE RUN , AFTER GRABBING THE LIST OF FILES, WILL GRAB THE DATA IN EACH FILE AND 
SEND IT TO ANOTHER FUNCTION TO CREATE AN OBJECT WITH THAT DATA
*******************************************************************************************/
	void grabCompanyData(std::string fileName) {

		int counter = 0;
		// Temporary holding vector
		std::vector<std::string> hold;
		std::string dirOfFiles = "E:\\Personal-Projects\\ExcelCSV\\ExcelCSV\\companies\\" + fileName + ".csv";
		std::ifstream is;

		is.open(dirOfFiles);

		if (is.is_open())
		{
			while (!is.eof())
			{
				
				std::string line;
				getline(is, line);
				std::stringstream ss(line);

				while (getline(ss, line, ','))
				{
					if (line != "" && line != " ")
					{

						if (line == "-")
								line = "0";

						hold.push_back(line);
					}
				}
			}
		}	else {
			std::cout << "failed to open file\n";
		}

		createCompany(hold);
		is.close();

	} // start

/******************************************************************************************
THIS FUNCTION WILL PARSE A VECTOR OF STRINGS AND SAVE THE RESULTS IN A NEW COMPANY OBJECT
*******************************************************************************************/

	void createCompany(std::vector<std::string> temp )
	{
		// Create a new company object
		Company* company = new Company();
		
		// flag
		int flag = 0;

		// Save the Name and Symbol of the Company
		company->saveValue("name", temp[0]);
		company->saveValue("symbol", temp[1]);

		// Start at 2 because 0 and 1 are the name and symbol of the company
		for (int i = 2; i < temp.size(); i++)
		{
			if (flag == 0)
			{
				if (temp[i] == "Income Statement")
					flag++;
				else
					company->saveValue("date", temp[i]);
			}

			if (flag == 1)
			{
				if (temp[i] == "Balance Sheet")
					flag++;
				else
					company->saveValue("incomestatement", temp[i]);
			}

			if (flag == 2)
			{
				if (temp[i] == "Cash Flows From Operating Activities")
					flag++;
				else
					company->saveValue("balancesheet", temp[i]);
			}

			if (flag == 3)
			{
				if (temp[i] == "Cash Flows From Investing Activities")
					flag++;
				else
					company->saveValue("cfo", temp[i]);
			}

			if (flag == 4)
			{
				if (temp[i] == "Cash Flows From Financing Activities")
					flag++;
				else
					company->saveValue("cfi", temp[i]);
			}

			if (flag == 5)
				company->saveValue("cff", temp[i]);
		}

		// debug
		company->formattedPrintWithMargins();

		// Push new company object into vector
		companies.push_back(company);
}
	
};