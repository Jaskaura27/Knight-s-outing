// Lab04.cpp : This file contains the 'main' function. Program execution begins and ends there.

//Jaspreet Singh(100345381)

/*the program first ask user to entre the strating row, Starting column, finishing row, finishing column, and number of moves can be made respectively.
then  computer call the method can_reach("---") which take the above input values as the parameters.
there Are 8 ways a knight can move.
the can_reach method checks the starting and final positions if there are same it return true,
else it tries the eigth if statements which call themselves with same changes to parameters and one subtracted from the num_moves,
if any if statement return true it means the knigth is on final position in the number of moves enteed by the user.
else if none of the if statements return true ther method return false which means knight could not do it.
*/

#include <iostream>
using namespace std;
int getInput() {
	int value;
	int a = 0;
	while (a == 0) {
		cin >> value;
		if (value >= 0 && value <= 7) {
			a++;
		}
		else
			cout << "Entre a value between 0-7" << endl;
	}
	return value;
}
bool can_reach(int sc, int sr, int fc, int fr, int num_moves ){
	if (num_moves == 0) {
		if (sc == fc && sr == fr) {
			return true;
		}
		return false;
	}
	if (sc < 0 || sc>7 || sr < 0 || sr>7) {
		return false;
	}
	//#1
	if (can_reach(sc - 1, sr + 2, fc, fr, num_moves-1)) {
		return true;
	}
	//#2
	if (can_reach(sc + 1, sr + 2, fc, fr, num_moves-1)) {
		return true;
	}
	//#3
	if (can_reach(sc - 2, sr + 1, fc, fr, num_moves-1)) {
		return true;
	}
	//#4
	if (can_reach(sc + 2, sr + 1, fc, fr, num_moves-1)) {
		return true;
	}
	//#5
	if (can_reach(sc - 1, sr - 2, fc, fr, num_moves-1)) {
		return true;
	}
	//#6
	if (can_reach(sc + 1, sr - 2, fc, fr, num_moves-1)) {
		return true;
	}
	//#7
	if (can_reach(sc - 2, sr - 1, fc, fr, num_moves-1)) {
		return true;
	}
	//#8
	if (can_reach(sc + 2, sr - 1, fc, fr, num_moves-1)) {
		return true;
	}

	return false;
}
int main()
{	
	int start_c, start_r, finish_c, finish_r, num_moves;
	cout << "Please entre the Starting row number between 0-7" << endl;
	start_r = getInput();
	cout << "Please entre the Starting column number between 0-7" << endl;
	start_c = getInput();
	cout << "Please entre the finishing row number between 0-7" << endl;
	finish_r = getInput();
	cout << "Please entre the finishing column number between 0-7" << endl;
	finish_c = getInput();
	cout << "Please entre the number of moves the player can make";
	cin>>num_moves;
	int e = 0;
	if (can_reach(start_c, start_r, finish_c, finish_r, num_moves)) {
		cout << "Knigth can do it" << endl;
	}
	else
		cout << "Knigth could not do it" << endl;

	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
