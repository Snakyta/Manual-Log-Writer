#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>

#include"Log_Write.h"
#include"Log_Menu.h"
#include"Log_Read.h"
#include"Log_Delete.h"

/*	To - do list:
	1)	Select log file DONE
	2)	Read the log and print it DONE
	3)	New log entrys DONE
	4)	Delete log entrys ALMOST PERFECT
	5)	Date and time in front of each log entry NEEDS IMPROVEMENT!
	END
*/	

class Log
{
private:
	Log_Delete lDelete;
	Log_Menu lMenu;
	Log_Write lWrite;
	Log_Read lRead;
	std::string SelectorOptions[3] = { "Create new log", "Select existing log file"};
	std::string MainMenuOptions[5] = { "Select Log File","Print hole Log", "New log entry", "Delete options"};
	std::string MainLogFileName;
public:

	void printSelectedFile(std::string FileName);
	std::string SelectLogFile();

	bool FunctionSelecter();
	void Run();
};