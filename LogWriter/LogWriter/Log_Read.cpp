#include"Log_Read.h"

void Log_Read::printLog(std::string LogFileName)
{
	std::ifstream myFile;
	myFile.open(LogFileName);
	if (myFile.is_open())
	{
		int lineNum = 0;
		std::string line;
		std::cout << "\n\nLines: \n";
		while (getline(myFile, line))
		{
			std::cout <<lineNum<<") "<< line << "\n";
			lineNum++;
		}
		myFile.close();
	}
}