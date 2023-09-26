#include<iostream>            // LIBRARY USED FOR INPUT & OUTPUT 

#include<fstream>            // LIBRARY USED FOR FILE HANDLING

using namespace std;

const int rows = 11;          // NUMBER OF ROWS FOR ARRAY 

const int cols = 17;          // NUMBER OF COLS FOR ARRAY  

char arr[rows][cols];         // ARRAY 

char pacman = 'P';       // PACMAN USED IN THE GAME

int x = 2, y = 10;       // PLACE OF PACMAN IN THE ARRAY

int count_dot = 0, final_score = 0;

int life = 3;                // LIVES OF PACMAN

void map(char arr[][17], int rows)                           // FUNCTION USED FOR PRINTING THE MAP
{
	cout << "**************************************************************" << endl;

	cout << ".................MAP OF THE GAME..................." << endl;

	for (int i = 0; i < rows; i++)          // ROWS FOR PRINTING THE MAP
	{
		cout << "\t\t";

		for (int j = 0; j < cols; j++)         // COLS FOR PRINTING THE MAP
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}
void displaymenu()                           // FUNCTION FOR DISPLAYING INSTRUCTIONS
{
	cout << "\n'''''''''''''''INSTRUCTIONS FOR USER'''''''''''''''''\n" << endl;

	cout << "PRESS w FOR MOVING THE PACMAN IN UPWARD" << endl;

	cout << "PRESS s FOR MOVING THE PACMAN IN DOWNWARD" << endl;

	cout << "PRESS a FOR MOVING THE PACMAN IN LEFT" << endl;

	cout << "PRESS d FOR MOVING THE PACMAN IN RIGHT" << endl;

	cout << "**************************************************************" << endl;

	cout << "PRESS e FOR EXIT THE GAME AT ANY TIME" << endl;                  // e USED FOR EXIT THE GAME ANY TIME

	cout << "**************************************************************" << endl;

}
void move(char key)                   // FUNCTION USED FOR MOVING PACMAN
{
	switch (key)                  // SWITCH CASE 
	{
	case 'w':                // CONDITION FOR W
	{
		if ((arr[x - 1][y]) == '0')       // IF THE CHARACTER w INDEX WILL EQUAL TO ZERO(0)
		{
			arr[x][y] = arr[x][y];       // NO MOVEMENT
		}
		else
		{
			if ((arr[x - 1][y]) == '.')      // IF THE CHARACTER w INDEX WILL EQUAL TO DOT(.)
			{
				count_dot = count_dot + 10;   // THEN ADDING SCORE 10 
			}
			else if ((arr[x - 1][y]) == 'L')   // IF THE CHARACTER w INDEX WILL EQUAL TO (L)
			{
				count_dot = count_dot + 20;    // THEN ADDING SCORE 20
			}
			else if ((arr[x - 1][y]) == 'M')  // IF THE CHARACTER w INDEX WILL EQUAL TO M
			{
				life = life - 1;         // Decrease in lives
			}
			arr[x][y] = ' ';     // ENTERED CHARACTER WILL BECOME SPACE
			x--;                 // DECREASE IN ROW
		}

		break;
	}
	case 's':
	{
		if ((arr[x + 1][y]) == '0')                // IF THE CHARACTER s INDEX WILL EQUAL TO ZERO(0)
		{
			arr[x][y] = arr[x][y];                // NO MOVEMENT
		}
		else
		{
			if ((arr[x + 1][y]) == '.')           // IF THE CHARACTER s INDEX WILL EQUAL TO DOT(.)
			{
				count_dot = count_dot + 10;       // THEN ADDING SCORE 10
			}
			else if ((arr[x + 1][y]) == 'L')      // IF THE CHARACTER s INDEX WILL EQUAL TO (L)
			{
				count_dot = count_dot + 20;       // THEN ADDING SCORE 20
			}
			else if ((arr[x + 1][y]) == 'M')      // IF THE CHARACTER s INDEX WILL EQUAL TO M
			{
				life = life - 1;                   // Decrease in lives
			}
			arr[x][y] = ' ';                       // ENTERED CHARACTER WILL BECOME SPACE
			x++;                                   // INCREASE IN ROW
		}
		break;
	}
	case 'a':
	{
		if ((arr[x][y - 1]) == '0')            // IF THE CHARACTER a INDEX WILL EQUAL TO ZERO(0)
		{
			arr[x][y] = arr[x][y];            // NO MOVEMENT
		}
		else
		{
			if ((arr[x][y - 1]) == '.')        // IF THE CHARACTER a INDEX WILL EQUAL TO DOT(.)
			{
				count_dot = count_dot + 10;    // THEN ADDING SCORE 10
			}
			else if ((arr[x][y - 1]) == 'L')   // IF THE CHARACTER a INDEX WILL EQUAL TO (L)
			{
				count_dot = count_dot + 20;    // THEN ADDING SCORE 20
			}
			else if ((arr[x][y - 1]) == 'M')   // IF THE CHARACTER a INDEX WILL EQUAL TO M
			{
				life = life - 1;               // Decrease in lives
			}
			arr[x][y] = ' ';                   // ENTERED CHARACTER WILL BECOME SPACE
			y--;                               // DECREASE IN column
		}
		break;
	}

	case 'd':
	{


		if ((arr[x][y + 1]) == '0')           // IF THE CHARACTER d INDEX WILL EQUAL TO ZERO(0)
		{
			arr[x][y] = arr[x][y];            // NO MOVEMENT
		}
		else
		{
			if ((arr[x][y + 1]) == '.')       // IF THE CHARACTER a INDEX WILL EQUAL TO DOT(.)
			{
				count_dot = count_dot + 10;   // THEN ADDING SCORE 10
			}
			else if ((arr[x][y + 1]) == 'L')  // IF THE CHARACTER a INDEX WILL EQUAL TO (L)
			{
				count_dot = count_dot + 20;   // THEN ADDING SCORE 20
			}
			else if ((arr[x][y + 1]) == 'M')   // IF THE CHARACTER a INDEX WILL EQUAL TO M
			{
				life = life - 1;              // Decrease in lives
			}
			arr[x][y] = ' ';                  // ENTERED CHARACTER WILL BECOME SPACE
			y++;                              // INCREASE IN column
		}
		break;
	}
	case 'e':                  // e will be exit the game at any moment
	{
		system("cls");    // CLEAR SCREEN
		cout << "\t\t...........GAME OVER............" << endl;
		exit(0);
	}
	}
	arr[x][y] = pacman; // NEW PLACE OF PACMAN
}
void ScorePrint(int final_score)   // FUNCTUION USING FOR SCORE IN SORTING ORDER.
{
	ifstream fin;   //READ THE FILE

	ofstream fout;  // WRITE THE FILE

	int s = 0, i = 0;    // VARIABLE USED FOR SORTING

	int arr1[5];             // ARRAY 1 USED FOR SORTING AND WRITING THE SCORE IN FILE

	fin.open("scores.txt", ios::in);

	while (fin >> s) // READ THE FILE WHILE s

	{
		arr1[i] = s;

		i++;
	}

	fin.close();

	arr1[5] = final_score; // STORE THE SCORE AT LAST INDEX.

	int temp;     // CODE FOR SORTING.

	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (arr1[i] < arr1[j])
			{
				temp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = temp;
			}
		}
	}

	fout.open("scores.txt"); // FOR WRITING THE SCORE UPTO FIVE USERS.

	cout << "HIEHEST SCORES IN THE FILE IN DECENDING ORDER" << endl << endl;

	for (int i = 0; i < 5; i++)
	{

		fout << arr1[i] << endl;

		cout << arr1[i] << "  ";
	}
}
int main()
{
	ifstream read; // READING THE FILE 

	char str;

	int option; // OPTION FOR CONTINUE OR EXIT OF THE GAME.

	cout << "--------------------------------------WELCOME TO THE GAME OF PACMAN-----------------------------------------" << endl;

	cout << "Press 1 For Continue The Game " << endl;

	cout << "Press 2 For Exit The Game" << endl;

	cout << "Enter The Option" << endl;

	cin >> option;

	if (option == 1)
	{
		read.open("pacman.txt"); // READ THE FILE 

		if (!(read.is_open()))
		{
			cout << "File Cannot Be Open!" << endl;
			return 0;
		}
		while (!read.eof())
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					read >> str; // READ THE CHARACTER 

					if (!read.eof())
					{
						arr[i][j] = str; //AND STORE THE CHARACTER INTO THE ARRAY
					}
				}
			}
		}

		arr[x][y] = pacman; // PLACE OF THE PACMAN

		read.close(); //  FILE CLOSE

		map(arr, rows); // CALLING OF THE FUNCTION

		displaymenu(); // DISPLAYING MENU 

		cout << "Total Lives Of Pacman = " << life << endl; // DISPLAYING LIVES

		cout << "Current Score of Player : " << count_dot << endl; //DISPLAYING SCORES

		cout << "**************************************************************" << endl;

		char key;

		while (1)
		{
			cout << "Enter The Movement Key" << endl;

			cin >> key; // ENTER FROM THE USER TOTHE MOVEMENT OF THE PACMAN

			move(key); // CALLING OF THE FUNCTION

			system("cls"); // CLEARSCREEN

			map(arr, rows); // CALLING OF THE FUNCTION

			displaymenu(); // CALLING OF THE FUNCTION

			cout << "Current Lives Of Pacman : " << life << endl;  // DISPLAYING LIVES

			cout << "Current Score of Player : " << count_dot << endl; //DISPLAYING SCORES

			cout << "**************************************************************" << endl;

			final_score = count_dot;

			if (life == 0) // IF THE USER EAT ALL THE MINES 
			{
				system("cls");
				cout << "\t\t...........YOU LOSE THE GAME............" << endl;
				cout << "THANK YOU FOR PLAYING THE GAME" << endl;
				cout << "**************************************************************" << endl;
				cout << "Your Score are : " << final_score << endl;
				cout << "**************************************************************" << endl;
				ScorePrint(final_score);
				break;
			}
			else if (count_dot == 1020) // IF THE USER WIN THE GAME
			{
				system("cls");
				cout << "\t\t...........YOU WIN THE GAME............" << endl;

				cout << "Your Current Lives Are : " << life << endl;

				cout << "THANK YOU FOR PLAYING THE GAME" << endl;

				cout << "**************************************************************" << endl;
				cout << "Your Score are : " << final_score << endl;
				cout << "**************************************************************\n" << endl;
				ScorePrint(final_score);
				break;
			}
		}
	}
	else if (option == 2) // FOR EXIT THE GAME FROM THE MENU
	{
		exit(0);
	}
	return 0;
}