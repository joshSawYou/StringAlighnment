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
	//cout << "heightOfConsole";
	//cout << heightOfConsole;
	//cout << "\n";
	//gets console information
	CONSOLE_SCREEN_BUFFER_INFO consoleInformation;
	GetConsoleScreenBufferInfo(heightOfConsole, &consoleInformation);

	// console width
	int widthOfConsole = consoleInformation.dwSize.X; 
	//cout << "widthofConsole";
	//cout << widthOfConsole;
	//cout << "\n";
	// Calculating width of user's input
	int widthOfInput = userInput.length(); 
	//cout << "widthOfInput";
	//cout << widthOfInput;
	//cout << "\n";
	//calculates the padding needed to center
	int pad = (widthOfConsole - widthOfInput) / 2; 
	//cout << "pad";
	//cout << pad;
	//cout << "\n";
	// Setting cursor position to beginning of pad
	COORD cPosition;
	cPosition.X = pad;
	cPosition.Y = consoleInformation.dwCursorPosition.Y;
	SetConsoleCursorPosition(heightOfConsole, cPosition);
	//cout << "cPosition";
	//cout << cPosition.Y;
	//cout << "\n";
	//printing centered version of user's input
	cout << userInput << endl; 
	return 0;
}
