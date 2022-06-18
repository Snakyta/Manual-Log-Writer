#include"Log_Delete.h"

void Log_Delete::DeleteLastLine(std::string FileName, int i, std::string lines[], int DeleteCount)
{
	int tmp = i - DeleteCount;
	//	DELETE CONTENT OUT OF FILE
	std::ofstream out;
	out.open(FileName, std::ofstream::trunc);
	out.close();
	//	Write content back into the file
	out.open(FileName, std::ofstream::app);
	for (i = 0; i < tmp; i++)
	{
		out << lines[i] << "\n";
	}
	out.close();
}

void Log_Delete::DeleteSpecificLine(std::string FileName, int i, std::string lines[], int DeleteCount)
{
	int linesToDeleteBeginning, linesToDeleteEnd;
	std::cout << "\n\nWhich lines do you like to delete?\nFirst write the furthest up line, then the lowest line\n\nInput: ";
	std::cin >> linesToDeleteBeginning >> linesToDeleteEnd;
	int tmp = i - 1;
	if (i == linesToDeleteEnd)
	{
		tmp = 1;
	}
	for (i = 0; i < tmp; i++)
	{
		lines[linesToDeleteBeginning] = lines[linesToDeleteEnd + 1];
		linesToDeleteBeginning++;
		linesToDeleteEnd++;
	}
	Log_Delete::DeleteLastLine(FileName, i, lines, DeleteCount);
}

void Log_Delete::DeleteLine(std::string FileName)
{	
	//	WRITE FILE CONTENT INTO ARRAY
	int i = 0;
	std::string lines[100];
	std::ifstream in;
	in.open(FileName);
	while (getline(in, lines[i]))
	{
		i++;
	}
	in.close();
	//	GET DELETE OPTION
	int input;
	std::cout << "\n\n(1) Delete Last Line \n(2) Delete upwards from Last Line \n(3) DELETE SPECIFIC LINES\n(4) Go back\n\nInput: ";
	std::cin >> input;
	if (input == 4)
		return;
	else if(input == 1) //	DELETES LAST LINE
	{
		Log_Delete::DeleteLastLine(FileName, i, lines, 1);
	}
	else if (input == 2) // DELETES LINES COUNTING FROM BOTTOM TO TOP FROM USER INPUT
	{
		std::cout << "\n\nHow many like from the end upward do you want to delete?\n\nInput: ";
		std::cin >> input;
		Log_Delete::DeleteLastLine(FileName, i, lines, input);
	}
	else if (input == 3)
	{
		// FUNCITON DESCRIPTION:
			//	FIRST GET LINES THAT SHOULD BE DELETED
			//	STARTING FROM DELETING LINES, OVERWRITING THE LINES TO DELETE WITH THE CONTENT ABOVE IT
			//	DONT PRINT THE AMOUNT OF LINES THAT GOT DELETED
		Log_Delete::DeleteSpecificLine(FileName, i, lines, input);
	}
	else
	{
		std::cout << "\n\nInvalid input, pls try again!\n\n";
		_getch();
	}
}