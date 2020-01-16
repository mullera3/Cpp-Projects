//*******************************//
// Created by Amani Muller      //
// Date: 01/11/2020             //
// Tic Tac Toe                  //
//******************************//


#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <stdlib.h>

// Array handling position on board
char position[10] = {'0','1','2','3','4','5','6','7','8','9'};

using namespace std;

void board();

int checkforwin(char player);

char flip_player(char player);

int main()
{
 // Variable for current player
 char current_player = 'X';

 // Variable marking spot
 int mark;

 //Variable managing winner
 int winner;

do
{

//Function displaying board
board();

cout << current_player << "'s turn" << endl;

label:
cout << "\nPick a location between 1 - 9: ";
cin >> mark;

// If input isn't a char break out of infinite loop
if(cin.fail())
{
    break;

}
else
    {
    // Marking position on board if position is empty and player enters position
    if(mark == 1 && position[1] == '1')

        position[1] = current_player;

    else if(mark == 2 && position[2] == '2')

        position[2] = current_player;

    else if(mark == 3 && position[3] == '3')

        position[3] = current_player;

    else if(mark == 4 && position[4] == '4')

        position[4] = current_player;

    else if(mark == 5 && position[5] == '5')

        position[5] = current_player;

    else if(mark == 6 && position[6] == '6')

        position[6] = current_player;

    else if(mark == 7 && position[7] == '7') 

        position[7] = current_player;

    else if(mark == 8 && position[8] == '8')

        position[8] = current_player;

    else if(mark == 9 && position[9] == '9')

        position[9] = current_player;
    else

    {   // Displaying invalid move if position out or range of array or if already taken
        cout << "Not a valid move! Try again!" << endl;
        goto label;
    }

    } // end of marking position

//Setting winner equal to result of function to check for win
winner = checkforwin(current_player);

// Breaking out of loop
if (winner == 1)
    break;
else if (winner == -1 )
    break;


// Switching player 
if (current_player == 'X')
        current_player = 'O';

else if (current_player == 'O')
    current_player = 'X';

}
while(winner != -1 or winner != 1);

// Showing final board at end of game
board();

// Displaying winner of Game
if (winner == -1)
{
    cout << "\nWinner: " << current_player << endl;
    cout << "Congrats!!" << endl;
}

// Displaying Game was a tie
if(winner == 1)
    cout << "Game Tie " << endl;
  
cout << endl; return 0;
}//main

void board()
{ 
    //Clears screen after full play through
    system("clear");

    cout << setw(20) << right << "Tic-Tac-Toe Game" << endl << endl;
    
   // Function for displaying board on screen
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;

    cout << " " << position[1] << " | " << position[2] << " | " << position[3] << endl;
    cout << "----------" << endl;

    cout << " " << position[4] << " | " << position[5] << " | " << position[6] << endl;

    cout << "----------" << endl;

    cout << " " << position[7] << " | " << position[8] << " | " << position[9] <<  endl;

    cout << "\n";
}

int checkforwin(char player)
{   
    // Checking for win across top of board
    if(player == position[1] && player == position[2] && player == position[3])

        return -1;

    // Checking for win across middle of board
    else if(player == position[4] && player == position[5] && player == position[6])

        return -1;

    // Checking for win across bottom of board
    else if(player == position[7] && player == position[8] && player == position[9])

        return -1;

    // Checking for win in vertical left
    else if(player == position[1] && player == position[4] && player == position[7])

        return -1;  

    // Checking for win in vertical middle of board
    else if(player == position[2] && player == position[5] && player == position[8])

        return -1;

    // Checking for win in vertical right of board
    else if(player == position[3] && player == position[6] && player == position[9])

        return -1;

    // Checking for win in diagonal
    else if(player == position[1] && player == position[5] && player == position[9])

        return -1;

    // Checking for win in diagonal
    else if(player == position[3] && player == position[5] && player == position[7])

        return -1;

    // Checking if no moves available in board
    else if(position[1] != '1' && position[2] != '2' && position[3] != '3' && position[4] != '4' && 
            position[5] != '5' && position[6] != '6' && position[7] != '7' && position[8] != '8' &&
            position[9] != '9')


        return 1;
    else
        return 0;
    
}
