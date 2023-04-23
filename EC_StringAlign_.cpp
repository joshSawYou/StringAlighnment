#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {

	string userInput;
	//prompts user to enter string
	cout << "Enter your string: ";
	//gets users input
	cin >> userInput;

	//gets height of console
	HANDLE heightOfConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//gets console information
	CONSOLE_SCREEN_BUFFER_INFO consoleInformation;
	GetConsoleScreenBufferInfo(heightOfConsole, &consoleInformation);

	// console width
	int widthOfConsole = consoleInformation.dwSize.X; 

	// Calculating width of user's input
	int widthOfInput = userInput.length(); 

	//calculates the padding needed to center
	int pad = (widthOfConsole - widthOfInput) / 2; 

	// Setting cursor position to beginning of pad
	COORD cPosition;
	cPosition.X = pad;
	cPosition.Y = consoleInformation.dwCursorPosition.Y;
	SetConsoleCursorPosition(heightOfConsole, cPosition);

	//printing centered version of user's input
	cout << userInput << endl; 
	return 0;
}
