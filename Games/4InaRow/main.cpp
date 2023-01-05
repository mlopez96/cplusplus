

#include "main.hpp"
int main()
{
Gameboard board;
int row, column;
char user;
while(true)
{
cout << "Enter row, column, and character for next move (e.g. 0 1 x): ";
cin >> row >> column >> user;
board.setGameSpace(row, column, user);
board.printInfo();
if(board.fourInRow() == 1)
{
cout << "Player X wins!" << endl;
break;
}
cout << "Enter row, column, and character for next move (e.g. 0 1 o): ";
cin >> row >> column >> user;
board.setGameSpace(row, column, user);
board.printInfo();
if(board.fourInRow() == 1)
{
cout << "Player O wins!" << endl;
break;
}
}
return 0;
}

/* 
#include "main.hpp"


int main()
{
    Gameboard game1;
    game1.setGameSpace(0,0,'x');
    game1.setGameSpace(0,1,'x');
    game1.setGameSpace(0,2,'x');
    game1.setGameSpace(0,3,'y');
    game1.setGameSpace(1,0,'x');
    game1.setGameSpace(2,0,'x');
    game1.setGameSpace(3,0,'x');
    game1.setGameSpace(3,1,'x');
    game1.setGameSpace(3,2,'x');
    game1.setGameSpace(3,3,'x');

    if(game1.fourInRow() == 1)
    {
        cout<<"X got four in a row!\n\n";
    }
    else
    {
        cout<<"X did not get four in a row :(\n\n";
    }
    game1.printInfo();
    return 0;
}
*/