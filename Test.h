#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class ME {
	std::vector<std::string> A;
	char* B[4] = {"ace","base", "case", "dam" };
	char* ace[2] = { "ace 1", "ace 2" };
	char* base[2] = { "base 1", "base 2" };
	char* casse[2] = { "casse 1", "casse 2" };
	char* dam[2] = { "dam 1", "dam 2" };
	std::vector<std::string> list;
public:
	ME() {
		//start();
		grabList();
	}
	void start()
	{
		std::cout << "===========================\nEntering Case off\n\n\n";

		for (int i = 0; i < 4; i++)
		{
			std::string name = B[i];

			for (int k = 0; k < 2; k++)
			{
				std::cout << "\n";
			}
		}
	}

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
				list.push_back(line);
			}
		}   
		else 
			 std::cout << "Unable to open file";

		file.close();

		std::cout << "print file\n";

		if (list.size() > 0)
		{
			for (int i = 0; i < list.size(); i++)
				std::cout << list[i] << "\n";
		}
	}
};

