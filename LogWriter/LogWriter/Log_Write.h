#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

class Log_Write
{
private:

public:

	std::string getCurrentTime()
	{
		std::string Date, time;
		Date = __DATE__;
		time = __TIME__;
		return "\nDATE: " + Date + "\nTIME: " + time + "\n";
	}

	std::string CreateLogTXT();
	void WriteInLog(std::string LogFileName);
};
