#define PDC_DLL_BUILD 1



#include "curses.h"
#include "panel.h"
#include "curspriv.h"

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>



using namespace std;

unsigned char border_char = 219;

int main(void) {

	WINDOW* main_window = nullptr;
	int num_rows = 0;
	int num_cols = 0;

	//initialize screen, begin curses mode
	main_window = initscr();

	// take up most of the screen
	getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);
	getmaxyx(main_window, num_rows, num_cols);

	//turn off key echo
	noecho();

	//nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	curs_set(0);

	//FUN STUFF HAPPENS HERE

	/*
	for (int i = 0; i < num_cols; i++) {

		//top border
		mvaddch(0, i, 218);

		//bottom border
		mvaddch(num_rows-1, i, ACS_LARROW);

	}
	for (int i = 0; i < num_rows; i++) {
		//left column


		//adds corner bullet (NOT WORKING CURRENTLY)
		if (i == 0 || i == num_rows-1) {
			mvaddch(i, 0, ACS_BULLET);

		}
		mvaddch(i, 0, ACS_UARROW);

		//right column

		//adds corner bullet
		if (i == 0 || i == num_rows-1) {
			mvaddch(i, num_cols - 1, ACS_BULLET);

		}
		else {  
			mvaddch(i, num_cols - 1, ACS_DARROW);
		}
		
		
	}*/
	//opens file
	string line;
	ifstream myfile("test.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << mvaddch(0, 0, 124) << '\n';
			
		}
		myfile.close();
	}

	else cout << mvaddch(0, 0, 23);

	
	




	//tells curses to draw
	refresh();
	char result = getch();

	//revert back to normal console mode
	nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	mvaddstr(0, 0, "Press any key to continue...");
	result = getch();
	endwin();

}