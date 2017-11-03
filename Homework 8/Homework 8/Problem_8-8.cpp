#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//The directory file should be formatted as "first last phone"
ifstream fileIn;
const string directoryFileName = "directory.dat";


//The first and last name being searched for
string first;
string last;


//Converts 'data' to lowercase
string toLower(string data)
{
	for (int i = 0; i < data.size(); i++)
	{
		data[i] = tolower(data[i]);
	}
	return data;
}

//Checks 'line' to see if it's the line for the person being searched for.  Returns the phone number if it is, returns "not found" if not.
string checkLine(string line)
{
	if (line.size() == 0) return "not found";	//Skip blank lines

	string name;
	string phone;

	int secondSpaceAt = line.find(' ', line.find(' ') + 1);

	name = line.substr(0, secondSpaceAt);	//Get the string from the beginning to the second space
	phone = line.substr(secondSpaceAt + 1);		//Get the string from the second space to the end

	if (toLower(name) == toLower(first) + " " + toLower(last))	//If the names match
	{
		return phone;
	}
	else return "not found";

}


//Checks the directory for a name matching 'first' and 'last'
void searchFor()
{
	fileIn.open(directoryFileName);
	string line;
	string ret;

	do
	{
		getline(fileIn, line);
		ret = checkLine(line);
		if (ret != "not found")
		{
			cout << "Match found!" << endl;
			cout << "Results for " << first << " " << last << ": " << ret << endl;
			break;
		}
	} while (!fileIn.eof());
	if (ret == "not found") cout << "I'm sorry, no entry for that name was found." << endl;
	fileIn.close();
}

int main()
{
	while (true)
	{
		cout << "Please enter a first and last name to search for" << endl;
		cin >> first;
		cin >> last;
		
		searchFor();
		
		cout << endl << "Would you like to search again? <y/n?>" << endl;
		char ans;
		cin >> ans;
		cout << endl;
		if (tolower(ans) == 'n') break;
		else if (tolower(ans) != 'y') cout << "Invalid response.  Assuming response to be yes." << endl << endl;
	}
	return 0;
}