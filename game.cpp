#include <iostream>
using namespace std;

// We want three space and three columns(working with rows and column numbers of the spaces)
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'X';
string n1 = "";
string n2 = "";
bool same = false;
int digit;

void functionOne()
{

    cout << "   |   |   \n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << "\n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << "\n";
    cout << "___|___|___\n";
    cout << "   |   |    \n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << "\n";
    cout << "   |   |    \n";
}

void functionTwo()
{

    if (token == 'X')
    {
        
        cout << n1 << " please enter a digit from 1-9: \n";
        cin >> digit;
    }

    if (token == '0')
    {
        cout << n2 << " please enter a digit from 1-9: \n";
        cin >> digit;
        
    }


    if (digit == 1)
    {
        row = 0;
        column = 0;
    }

    else if (digit == 2)
    {
        row = 0;
        column = 1;
    }

    else if (digit == 3)
    {
        row = 0;
        column = 2;
    }

    else if (digit == 4)
    {
        row = 1;
        column = 0;
    }

    else if (digit == 5)
    {
        row = 1;
        column = 1;
    }

    else if (digit == 6)
    {
        row = 1;
        column = 2;
    }

    else if (digit == 7)
    {
        row = 2;
        column = 0;
    }

    else if (digit == 8)
    {
        row = 2;
        column = 1;
    }

    else if (digit == 9)
    {
        row = 2;
        column = 2;
    }

    else
    {
        cout << "Invalid input. Please enter a digit from 1-9: \n";
        functionTwo();
    }

    if (token == 'X' && space[row][column] != 'X' && space[row][column] != '0')
    {
        space[row][column] = 'X';
        token = '0';
    }

    else if (token == '0' && space[row][column] != 'X' && space[row][column] != '0')
    {
        space[row][column] = '0';
        token = 'X';
    }

    else
    {
        cout << "This space is already taken. Please try again.\n";
        functionTwo();
    }

    cin.ignore();

    functionOne();
}

bool functionThree()
{

    for (int i = 0; i < 3; i++)
    {
        // row and column check
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2] || space[0][i] == space[1][i] && space[1][i] == space[2][i])
        {
            return true;
        }
    }

    // diagonal check
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != '0')
            { // game not finished yet
                return false;
            }
        }
    }

    // game is a tie
    same = true;
    return false;
}

int main()
{
    cout << "Enter the name of the first player: \n";
    getline(cin, n1);

    cout << "Enter the name of the second player: \n";
    getline(cin, n2);

    cout << "Welcome " << n1 << " and " << n2 << " to the game of Tic Tac Toe!\n";
    cout << n1 << " is player one so they will play first.\n";
    cout << n2 << " is player two so they will play second.\n";

    while (!functionThree())
    {
        functionOne();
        functionTwo();
        functionThree();
    }

    if (token == 'X' && same == false)
    {
        cout << n2 << " wins!\n";
    }

    else if (token == '0' && same == false)
    {
        cout << n1 << " wins!\n";
    }

    else
    {
        cout << "It's a tie!\n";
    }
}