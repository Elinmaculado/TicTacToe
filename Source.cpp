#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

void instructions();
char PlayerSymbol(string question);
char Opponent(char a);
char winner(const vector<char>& board);
void displayBoard(vector <char>& board);
int playerMove(vector <char>& board);
int askNumber(string question, int high, int low);

const int NUM_SQUARES = 9;
const char EMPTY = '.';

const char X = 'X';
const char O = 'O';
const char NO_ONE = 'N';
const char TIE = 'T';

int main()
{
	vector<char> board(NUM_SQUARES, EMPTY);
	int move = 0;
	char player = X;
	char ai = O;
	char turn = player;
	instructions();
	displayBoard(board);
	cout << endl;
	player = PlayerSymbol("deseas ir primero? ");
	cout << player << endl;
	ai = Opponent(player);
	cout << ai << endl;

	while (winner(board) == NO_ONE)
	{

		if (turn == player)
		{
			playerMove(board);
		}
		else
		{
			playerMove(board);
		}
		displayBoard(board);
		system("pause");
	}
}


int playerMove(vector <char>& board)
{
	int choice;
	do{
	choice = askNumber("Elija un espacio vacio", 0, 9);
	} while (board[choice] == '.');
	return choice;
}

int askNumber(string question, int high, int low)
{
	string input;
	bool isValid;

	//int number = 0;

	do {
		cout << question << "entre " << low << " y " << high << endl;
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, input);


		isValid = false;

		for (char c : input)
		{
			if (!isdigit(c))
			{
				cout << endl << "elige un numero" << endl;
				isValid = false;
				break;
			}
		}

		if (stoi(input) < low || stoi(input) > high)
		{
			cout << "elige un numero valido" << endl;
			isValid = false;
		}

	} while (!isValid || input.empty() || stoi(input) > high || stoi(input) < low);

	return stoi(input);
}

void displayBoard(vector <char>& board)
{
	cout << "Bienvenido a tic tac toe, elije una posicion entre el 0 y el 8" << endl;

	cout << board[0] << " " << board[1] << " " << board[2] << endl;
	cout << board[3] << " " << board[4] << " " << board[5] << endl;
	cout << board[6] << " " << board[7] << " " << board[8] << endl;
}

void instructions()
{
	char boardoptions[3][3] = { {'0', '1', '2'},
										 {'3', '4', '5'},
										 {'6', '7', '8'} };

	cout << "Bienvenido a un nuevo TicTacToe" << endl;
	cout << "En este juego te enfrentaras a una IA basica" << endl;
	cout << "El tablero siguiente representa tus controles, recuerdalos bien" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << boardoptions[i][j];
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

char winner(const vector<char>& board)
{

	//This are the posibilities to win
	const int WINNING_POS[8][3] = { {0, 1, 2}, //Horizontal
									{3, 4, 5}, //Horizontal
									{6, 7, 8}, //Horizontal
									{0, 3, 6}, //Vertical
									{1, 4, 7}, //Vertical
									{2, 5, 8}, //Vertical
									{2, 4, 6}, //Horizontal
									{0, 4, 8} }; //Horizontal
	const int TOTAL_ROWS = 8;

	//Return the winner
	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		if ((board[WINNING_POS[row][0]] != EMPTY) &&
			(board[WINNING_POS[row][0]] == board[WINNING_POS[row][1]]) &&
			(board[WINNING_POS[row][1]] == board[WINNING_POS[row][2]]))
		{
			return board[WINNING_POS[row][0]];
		}
	}

	//Return a Tie
	if (count(board.begin(), board.end(), EMPTY) == 0) {
		return TIE;
	}

	//Return that no one is the winner yet
	return NO_ONE;
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