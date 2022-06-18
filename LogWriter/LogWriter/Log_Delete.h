#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>

class Log_Delete
{
private:
	int deletecounter = 0;
public:
	void DeleteLastLine(std::string FileName, int i, std::string lines[], int DeleteCount);
	void DeleteSpecificLine(std::string FileName, int i, std::string lines[], int DeleteCount);
	void DeleteLine(std::string FileName);
};