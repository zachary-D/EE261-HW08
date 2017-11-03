#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string fileInName = "exams.dat";
string fileOutName = "scores.dat";

ifstream fileIn;
ofstream fileOut;	

bool isValidAnswer(char answer)
{
	return 'a' <= answer && answer <= 'f';
}

//Grades the answers in 'test' using 'key'
void gradeTest(string key, string test)
{
	if (key.size() > test.size())
	{
		fileOut << "Too few answers" << endl;
		return;
	}

	if (key.size() < test.size())
	{
		fileOut << "Too many answers" << endl;
		return;
	}

	int numRight = 0;
	for (int i = 0; i < key.size(); i++)
	{
		if (isValidAnswer(test[i]))
		{
			if (key[i] == test[i]) numRight++;
		}
		else
		{
			fileOut << "Invalid answers" << endl;
			return;
		}
	}
	fileOut << numRight << endl;
	
}

//Compares the key with the data provided in 'line', composed of the student number and exam responses
void processLine(string key, string line)
{
	if (line.size() == 0) return;	//Skip blank lines

	int spacePos = line.find(' ');

	string studentID = line.substr(0, spacePos);
	string test = line.substr(spacePos + 1);

	fileOut << studentID << " ";

	gradeTest(key, test);
}

void gradeExams()
{
	string key;
	
	string line;

	getline(fileIn, key);	//Load the answer key

	cout << "Answer key loaded.  Key length: " << key.size() << endl;

	do
	{
		getline(fileIn, line);
		processLine(key, line);
	} while (!fileIn.eof());
}

int main()
{
	fileIn.open("exams.dat");
	fileOut.open("scores.dat");

	gradeExams();

	fileIn.close();
	fileOut.close();

	cout << "Grading complete" << endl;
	cin.get();

	return 0;
}