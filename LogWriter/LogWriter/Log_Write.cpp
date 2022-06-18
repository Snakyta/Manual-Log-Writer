#include"Log_Write.h"


std::string Log_Write::CreateLogTXT()
{
	system("cls");
	std::string input;
	std::cout << "Enter the name for your new log file!\n\n";
	std::cout << "log.txt will be automatically added to the end of your name!\n\n";
	std::cout << "Input: ";
	std::cin >> input;
	input =  input + "_log.txt";
	std::ofstream out;
	out.open(input, std::ofstream::app);
	out << "Log file: '" << input << "'\n";
	out << "Was created on: ";
	out << getCurrentTime();
	out.close();
	return input;
}

void Log_Write::WriteInLog(std::string LogFileName)
{
	system("cls");
	std::string input;
	std::ofstream out; //Output file stream
	out.open(LogFileName, std::fstream::app); // Für absoluten Pfad : C:\\... // app für hinten ranschreiben anstatt überschreiben
	out << "\nNEW LOG ENTRY: " << getCurrentTime();
	while (true)
	{
		system("cls");
		std::cout << "Writing in Log\n\nType 'x' to leave editor!\n\nInsert new entry: ";
		std::getline(std::cin,input);
		if (input == "x")
			break;
		out << input << "\n";
	}
	out.close();
}