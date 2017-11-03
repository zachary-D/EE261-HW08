#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fileIn;
ofstream fileOut;

char Rot13(char letter)
{
	if ('a' <= letter && letter <= 'z')
	{
		if (letter <= 'm') return letter + 13;
		else return letter - 13;
	}
	else if ('A' <= letter && letter <= 'Z')
	{
		if (letter <= 'M') return letter + 13;
		else return letter - 13;
	}
}

void WriteTranslatedChar(char letter, std::ofstream & outputFile)
{
	outputFile << letter;
}

int main()
{
	string filename;
	cout << "Please enter a source filename" << endl;
	getline(cin, filename);
	
	fileIn.open(filename);
	fileOut.open("output.rot13");

	do
	{
		char letter;
		fileIn >> letter;
		WriteTranslatedChar(Rot13(letter), fileOut);

	} while (fileIn.eof() == false);

	fileIn.close();
	fileOut.close();


	return 0;
}