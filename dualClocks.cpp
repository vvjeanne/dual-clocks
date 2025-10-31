// AvaLindgren_ProjectOne.cpp 
// Ava Lindgren - Project One
// 9.10.2025
// This program outputs two clocks, 12-hour and 24-hour, and allows the user to
// manipulate the clocks by adding increments of hours, minutes, and seconds.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// declare function for both clock borders
void printClockBorder() {
	// for loop that prints space padding
	for (int i = 0; i < 1; ++i) {
		cout << " ";
	}
	// for loop that prints dashes for the 12hr clock border
	for (int i = 0; i < 27; ++i) {
		cout << "-";
	}
	// for loop that prints space padding between the clocks
	for (int i = 0; i < 5; ++i) {
		cout << " ";
	}
	//for loop that prints dashes for the 24hr clock border
	for (int i = 0; i < 27; ++i) {
		cout << "-";
	}
	cout << endl;
}

// declare function that outputs both clocks while converting the 24hr clock to 12hr
void printClocks(int hours, int min, int sec) {

	// hour conversion
	int hourConv;
	// minute conversion
	int minConv;
	// second conversion
	int secConv;
	// AM or PM
	string amPm = "AM";

	// convert the 24hr clock to 12hr clock with AM and PM
	if (hours == 0) {
		hourConv = 12;
	}
	else if (hours == 12) {
		hourConv = hours;
		amPm = "PM";
	}
	else if (hours > 12) {
		hourConv = hours - 12;
		amPm = "PM";
	}
	else {
		hourConv = hours;
	}
	
	// create the titles and formatting for the clocks
	cout << " |      " << "12-Hour Clock" << "      |"
		<< "     " << "|      " << "24-Hour Clock" << "      |" << endl;
	cout << " |                         |" << "     "
		<< "|                         |" << endl;

	// 12hr clock
	cout << " |\t ";
	// format 12hr clock
	cout << setw(2) << setfill('0') << hourConv << ":";
	cout << setw(2) << min << ":";
	cout << setw(2) << sec;
	cout << " " << amPm;
	cout << "\t   |";

	// 24hr clock
	cout << "\t |" << "\t  ";
	cout << setw(2) << setfill('0') << hours << ":";
	cout << setw(2) << min << ":";
	cout << setw(2) << sec;
	cout << "\t   |" << endl;
}

// declare function take input initial time from user
void inputInitialTime(int& setHour, int& setMin, int& setSec) {

	// holds initual input
	string inputString;
	// validation of user time input
	string tempString;
	// time toggle for while statement
	bool validTime = false;
	// find the first colon in inputString
	int firstColonPos;
	// find the second colon in inputString
	int secondColonPos;

	// while statement for time
	while (!validTime) {
		// ask user to input initial time
		cout << "Please enter the time in 24-hour format ( HH:MM:SS ): ";
		// assign user input
		getline(cin, inputString);
		cout << "\n";

		// find first colon
		firstColonPos = inputString.find(':');
		// find second colon
		secondColonPos = inputString.find(':', firstColonPos + 1);

		// try to assign and convert each section of the clock only if integers
		try
		{
			// takes first section and converts to integer
			setHour = stoi(inputString.substr(0, firstColonPos));
			// takes second section and converts to integer
			setMin = stoi(inputString.substr(firstColonPos + 1, secondColonPos));
			// takes third section and converts to integer
			setSec = stoi(inputString.substr(secondColonPos + 1, inputString.size() - 1));
		}
		catch (const std::exception&)
		{
			// not using this exception
		}
		
		// check for proper char length input
		if (inputString.size() != 8) {
			cout << "Invalid time" << endl;
			!validTime;
		}
		// check for setHour number not between 0 and 23
		else if (setHour < 0 || setHour > 23) {
			cout << "Invalid hours" << endl;
			!validTime;
		}
		// check for setMin number not between 0 and 59
		else if (setMin < 0 || setMin > 59) {
			cout << "Invalid minutes" << endl;
			!validTime;
		}
		// check for setSec number not between 0 and 59
		else if (setSec < 0 || setSec > 59) {
			cout << "Invalid seconds" << endl;
			!validTime;
		}
		// else the time is valid
		else {
			validTime = true;
		}
	}
}

// declare function for the main menu options
void printMainMenu() {
	cout << endl;
	cout << "\n *********************" << endl;
	cout << " * 1: Add One Hour   *" << endl;
	cout << " * 2: Add One Minute *" << endl;
	cout << " * 3: Add One Second *" << endl;
	cout << " * 4: Exit\t     *" << endl;
	cout << " *********************" << endl;
	cout << endl;
}

// declare function process and validate the user inputs
void processUserInput(int& userChoice, int& setHour, int& setMin, int& setSec) {
	
	// ask user to input the chosen option
	cout << "Select option ( 1-4 ): ";

	// verify user input then check that input is an integer
	if (!(cin >> userChoice)) {
		cin.clear();
		// ignore any non-numeric values
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		userChoice = 0;
	}

	// use the switch statement for different user input choices
	switch (userChoice) {
	case 1:
		cout << "1 hour added\n" << endl;
		// create increments of one hour until 24 hours is reached
		if (setHour < 23) {
			++setHour;
		}
		// else reset the hour to 00hrs
		else {
			setHour = 00;
		}
		break;
	case 2:
		cout << "1 minute added\n" << endl;
		// create increments of one minute until 59 mins is reached
		if (setMin < 59) {
			++setMin;
		}
		// else reset the minute to 00mins
		else {
			setMin = 00;
		}
		break;
	case 3:
		cout << "1 second added\n" << endl;
		// create increments of one second until 59 secs is reached
		if (setSec < 59) {
			++setSec;
		}
		// else reset the second to 00secs
		else {
			setSec = 00;
		}
		break;
	case 4:
		// end the program if this choice is selected
		cout << "\nGoodbye..." << endl;
		break;
	default:
		cout << "\nInvalid choice. Please enter a number between 1 and 4.\n" << endl;
		cin.clear();
		break;
	}
}

// declare the main function of the program
int main() {
	// declare global properties
	// initial user choice
	int userChoice = 0;
	// initialize the clock set to midnight 00:00
	int setHour = 0;
	int setMin = 0;
	int setSec;

	// ask user to input initial time by calling inputInitialTime(setHour, setMin, setSec) function
	inputInitialTime(setHour, setMin, setSec);

	// begin the while loop
	while (userChoice != 4) {
		// call clock functions
		printClockBorder();
		printClocks(setHour, setMin, setSec);
		printClockBorder();
		printMainMenu();
		processUserInput(userChoice, setHour, setMin, setSec);
	}
	// end the program
	return 0;
}