#include <iostream>
using namespace std;

char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row;
int col;
bool draw = false;

void displayGrid() {

  cout << "\t\t Tic-Tac-Toe\n" << endl;
  cout << "\tPLayer 1 [X]\t\tPlayer 2 [0]\n\n" << endl;

  cout << "\n   |   |   \n";
  cout << " " << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2]
       << " \n";
  cout << "___|___|___\n";
  cout << "   |   |   \n";
  cout << " " << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2]
       << " \n";
  cout << "___|___|___\n";
  cout << "   |   |   \n";
  cout << " " << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2]
       << " \n";
  cout << "   |   |   \n";
}

void PlayerTurn() {

  int input;

  if (turn == 'X') {
    cout << "\n\tPlayer 1 [X] turn:";
  }

  if (turn == '0') {
    cout << "\n\tPlayer 2 [0] turn:";
  }
  cin >> input;

  switch (input) {
  case 1:
    row = 0;
    col = 0;
    break;
  case 2:
    row = 0;
    col = 1;
    break;
  case 3:
    row = 0;
    col = 2;
    break;
  case 4:
    row = 1;
    col = 0;
    break;
  case 5:
    row = 1;
    col = 1;
    break;
  case 6:
    row = 1;
    col = 2;
    break;
  case 7:
    row = 2;
    col = 0;
    break;
  case 8:
    row = 2;
    col = 1;
    break;
  case 9:
    row = 2;
    col = 2;
    break;

  default:
    cout << "Invalid choice";
    break;
  }

  if (turn == 'X' && grid[row][col] != 'X' && grid[row][col] != '0') {
    grid[row][col] = 'X';
    turn = '0';
    
  } else if (turn == '0' && grid[row][col] != 'X' && grid[row][col] != '0') {
    grid[row][col] = '0';
    turn = 'X';
  }
    
  else{
    cout<<"\tBox already filled !!\n\t Please chose another grid\n";
    PlayerTurn();
    
  }
  displayGrid();

}


bool gameOver(){
  //check who won
  for(int i=0; i<3; i++){
    //for row and column
    if((grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) || (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]))
      return false;
    
    //for diagonal
    if((grid[0][0] == grid[1][1] && grid[0][0]
      == grid[2][2]) || (grid[0][2] == grid[1][1] && grid[0][2] == grid [2][0]))
      return false;
      }
 
  
  

  //if there is any box not filled
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++){
      if(grid[i][j] != 'X' && grid[i][j] != '0')
        return true;
    }

  //game draw
  
 draw = true;
  return false;

  
  
}


int main() {
  displayGrid();
  while (gameOver()) {
    PlayerTurn();
  }

  if(turn == 'X' && draw == false)
    cout<<"\n\tPlayer 2 [0] wins!!";
  else if(turn == '0' && draw == false)
    cout<<"\n\tPlayer 1 [X] wins!!";
  else
    cout<<"\n\tGAME DRAW!!\n";
}