#include <iostream>
#include <fstream>
#include <string>

#define INPUT_LENGTH 1025
#define MAX_LENGTH 200000

int main(int args, char* argc)
{
	std::cout << "Let's save christmas\n";

	std::ifstream input("input.data");
	int intInput[INPUT_LENGTH];
	int count = 0;
	int output = 0;

	int duplicateList[MAX_LENGTH];
	duplicateList[0] = 0;
	int di = 1;
	int duplicateFreq;
	bool duplicateFound = false;

	if (input.is_open())
	{
		std::string currLine;

		while (std::getline(input, currLine))
		{
			output += intInput[count++] = std::stoi(currLine);

			if (!duplicateFound && di < MAX_LENGTH)
			{
				for (int i = 0; i < di; i++)
				{
					if (output == duplicateList[i])
					{
						duplicateFound = true;
						duplicateFreq = output;
					}
				}
				duplicateList[di++] = output;
			}
		}
		int output2 = output;
		while (!duplicateFound && di < MAX_LENGTH)
		{
			for (int i = 0; i < INPUT_LENGTH && (!duplicateFound && di < MAX_LENGTH); i++)
			{
				output2 += intInput[i];
				for (int j = 0; j < di && (!duplicateFound && di < MAX_LENGTH); j++)
				{
					if (output2 == duplicateList[j])
					{
						duplicateFound = true;
						duplicateFreq = output2;
					}
				}
				duplicateList[di++] = output2;
			}
		}
	}
	else
	{
		std::cerr << "Oh no, couldn't find input file!\nNo christmas for us\n";
		return -1;
	}

	std::cout << "Looks like the frequency should be:\n" << output << std::endl;
	if (duplicateFound)
		std::cout << "Seems like we found the duplicate frequency!\n" << duplicateFreq << std::endl;
	else
		std::cout << "No duplicate found? Maybe increase the MAX_LENGTH?\n";

	std::cin.ignore();
	return 0;
}