#include <iostream>
#include <vector>
using namespace std;

void instructions();
char PlayerSymbol(string question);
char Opponent(char a);
char winner();

const int NUM_SQUARES = 9;
const char EMPTY = '.';
const vector<char> board(NUM_SQUARES, EMPTY);
const char X = 'X';
const char O = 'O';
const char NO_ONE = 'N';

int main()
{
	char player = X;
	char ai = O;
	char turno = X;
	instructions();
	cout << endl;
	player = PlayerSymbol("deseas ir primero? ");
	cout << player << endl;
	ai = Opponent(player);
	cout << ai << endl;
}

void instructions()
{
	cout << "Bienvenido a tic tac toe, elije una posicion entre el 0 y el 8" << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[j];
		}
		cout << endl;
	}
}

char PlayerSymbol(string question)
{
	char answer;

	do {
		cout << "\n" << question << "(y/n)" << endl;
		cin >> answer;
	} while (answer != 'y' && answer != 'n');

	if (answer == 'y')
	{
		return X;
	}

	return O;
}

char Opponent(char a)
{
	char opponent;

	if (a == X)
	{
		opponent = O;
	}
	else
	{
		opponent = X;
	}

	return opponent;
}

char winner()
{
	//tarea adaptar victoria a win que reciba board y que return X, O, Tie o NoONe
}

/*
const int COLUMNS = 3;
const int  ROWS = 3;
void TicTacToe();
bool win (int input, char board[COLUMNS][ROWS]);


void main()
{
	TicTacToe();
}

void TicTacToe()
{
	int x;
	int y;
	int z;
	bool turnx = true;
	bool turno = false;
	bool draw = false;
	int turn = 1;
	char player;
	//declaras la matriz
	char board[ROWS][COLUMNS] = { { '0', '1', '2' },
								 { '3', '4', '5' },
								 { '6', '7', '8' } };

	char PlayBoard[ROWS][COLUMNS] = { { '.', '.', '.' },
									  { '.', '.', '.' },
									  { '.', '.', '.' } };

	cout << "TicTacToe" << endl;


	do {
		//Turno de jugador X
		do {
			do {
				turnx = true;
				player = 'X';
				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLUMNS; j++)
					{
						cout << board[i][j];
					}
					cout << endl;
				}

				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLUMNS; j++)
					{
						cout << PlayBoard[i][j];
					}
					cout << endl;
				}
				cout << "turno del jugador X, elija el espacio que quiere ocupar" << endl;
				cin >> z;
				x = z / 3;
				y = z % 3;

				system("cls");
			} while (PlayBoard[x][y] != '.');

			PlayBoard[x][y] = 'X';
			turnx = false;
		} while (turnx == true);

		
		if (win(z, PlayBoard))
		{
			break;
		}

		//Comprueba sin no hay empate
		if (turn == 5)
		{
			draw = true;
			break;
		}

		//Turno del jugador O
		do {
			do {
				turno = true;
				player = 'O';
				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLUMNS; j++)
					{
						cout << board[i][j];
					}
					cout << endl;
				}

				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLUMNS; j++)
					{
						cout << PlayBoard[i][j];
					}
					cout << endl;
				}
				cout << "turno del jugador O, elija el espacio que quiere ocupar" << endl;
				cin >> z;
				x = z / 3;
				y = z % 3;

				system("cls");
			} while (PlayBoard[x][y] != '.');

			PlayBoard[x][y] = 'O';
			turno = false;
			turn++;
		} while (turno == true);

		
		if (win(z, PlayBoard))
		{
			break;
		}

	} while (draw == false || !win);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << PlayBoard[i][j];
		}
		cout << endl;
	}

	if (draw == true)
	{

		cout << "empate " << endl;

	}
	else if (win(z, PlayBoard))
	{
		cout << player << " es el ganador" << endl;
	}
}

bool win(int input, char board[COLUMNS][ROWS])
{
	int x = input / 3;
	int y = input % 3;
	bool victory = false;

	if (board[x][0] == board[x][1] && board[x][0] == board[x][2]) {
		victory = true;
	}
	if (board[0][y] == board[1][y] && board[0][y] == board[2][y]) {
		victory = true;
	}
	if (input == 0 || input == 4 || input == 8) {
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
			victory = true;
		}
	}
	if (input == 2 || input == 4 || input == 6) {
		if (board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
			victory = true;
		}
	}

	return victory;
}
*/