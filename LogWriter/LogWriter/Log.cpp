#include"Log.h"

void Log::printSelectedFile(std::string FileName)
{
	// Prints selected File
	std::cout << "Selected File: ";
	if (FileName != "")
	{
		std::cout << FileName << "\n\n";
	}
	else
	{
		std::cout << "No selected file!\n\n";
	}
}

std::string Log::SelectLogFile()
{
	std::string FileName;
	char input;

	// MAIN LOOP
	while (true)
	{
		// 1) Create new log file 2) Select existing log file
		system("cls");

		// Prints selected File
		Log::printSelectedFile(FileName);

		//SETUP FOR UI
		lMenu.printMenu("Log Writer Log Selector", "Go back", SelectorOptions);
		std::cout << "\n\nInsert Action: ";
		std::cin >> input;
		if (input == '2')
		{
			return FileName;
		}
		else if (input == '0')
		{
			// Create new log
			system("cls");
			FileName = lWrite.CreateLogTXT();
		}
		else if(input == '1')
		{
			
			// Opens existing log
			std::cout << "\nStart with LogsBackslash and then Insert logfile.txt Path: ";
			std::cin >> FileName;
			std::ifstream in(FileName);
			// Checks if logfile exists or not
			if (in.is_open())
			{
				std::cout << "\n\nFile was found, now writing in " << FileName << "\n\nPress any key to continue";
				
				_getch();
				
			}
			else
			{
				std::cout << "\n\nFile was not found!\n\nPress any key to continue!";
				FileName = "";
				_getch();
				
			}
			in.close();
		}
		else if (input == '2')
		{
			// Closes currently opened file
			
		}
		else
		{
			std::cout << "\n\nInvalid input, pls try again!\n\n";
			_getch();
		}
	}
	return FileName;
}

bool Log::FunctionSelecter()
{
	// 0)Select Log File 1)Print hole Log 2)New log entry 3)Delete Last Log entry 4) END
	
	char input;
	std::cout << "\n\nInsert Action: ";
	std::cin >> input;

	if (input == '4')
	{
		return true;
	}
	else if (input == '0')
	{
		MainLogFileName = Log::SelectLogFile();
		return false;
	}
	else if (input == '1')
	{
		lRead.printLog(MainLogFileName);
		_getch();
		return false;
	}
	else if (input == '2')
	{
		lWrite.WriteInLog(MainLogFileName);
		return false;
	}
	else if (input == '3')
	{
		lRead.printLog(MainLogFileName);
		lDelete.DeleteLine(MainLogFileName);
		return false;
	}
	else
	{
		std::cout << "\n\nInvalid input, pls try again!\n\n";
		_getch();
		return false;
	}
}

void Log::Run()
{
	/*
	std::string LogFileName;
	LogFileName = lWrite.CreateLogTXT();
	lWrite.WriteInLog(LogFileName);
	*/
	bool end = false;
	Log_Menu lMenu;
	do
	{
		system("cls");
		printSelectedFile(MainLogFileName);
		lMenu.printMenu("Log Writer Main Menu", "End", MainMenuOptions);
		end = Log::FunctionSelecter();
	} while (end != true);
}
