//  main.cpp
//  TicTacToe
//
//  Created by mlopez96 on 1/2/23
//  Credit to DRH

#include <iostream>

char board [3][3] = {{'1', '2', '3',}, {'4', '5', '6',}, {'7', '8', '9',}};
char currentMarker;
int currentPlayer;

void drawBoard()
{
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] <<
        std::endl;
    std::cout << "----------\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] <<
        std::endl;
    std::cout << "----------\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] <<
        std::endl;
    std::cout << "----------\n";
}

bool placeMarker (int slot)
{
    int row = slot/3;
    int column;
    
    if (slot % 3 ==0)
    {
        row = row - 1;
        column = 2;
    }
    else column = (slot % 3) - 1;
    if (board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = currentMarker;
        return true;
    }
    else return false;
}


int winner()
{
    for(int i = 0; i < 3; i++)
    {
        //Rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
            
        //columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;
    
    return 0;

}

void swapPlayerAndMarker()
{
    if (currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';
    
    if (currentPlayer == 1) currentPlayer = 2;
    else currentPlayer = 1;
}

void game()
{
    std::cout << "Player one, please select either an O or an X : ";
    char playerOneMarker;
    std::cin >> playerOneMarker;
    
    //Validiation
    while (playerOneMarker != 'O' && playerOneMarker != 'X')
    {
        std::cout << "That is an invalid value, please select either an 0 or an X : ";
        std::cin >> playerOneMarker;
    }
    
    currentPlayer = 1;
    currentMarker = playerOneMarker;
    
    drawBoard();
    
    int playerWon;
    
    for (int i =0; i < 9; i++)
    {
        std::cout<< "It is player " << currentPlayer << "'s turn. Please enter your move : ";
        int slot;
        std::cin >> slot;
        if (slot < 1 || slot > 9)
        {
            std::cout << "This particular move is outside of the accepted parameters and as a result is invalid.  Please try another move. ";
            i--;
            continue;
        }
        if (!placeMarker(slot))
        {
            std::cout << "That is an invalid move as that particular spot has already been taken. Please try another move.";
            i--;
            continue;
        }
        
        drawBoard();
        
        playerWon = winner();
        if (playerWon == 1)
        {
            std::cout << "Player one has one! You killed it";
            break;
        }
        if (playerWon == 2)
        {
            std::cout << "Player two has one! Congratulations, you killed it";
            break;
        }
        
        swapPlayerAndMarker();
    }
    if (playerWon == 0) std::cout<< "It appears that player one and player two have tied!";
}

int main() {
    game();
    return 0;
}

