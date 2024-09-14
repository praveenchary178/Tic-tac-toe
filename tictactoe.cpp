#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<char>>&board,int a,int b,char player)
{
    //for checking row
    bool row=true;
    for(int i=0;i<3;i++)
    {
       if(board[a][i]!=player)
       {
        row=false;
        break;
       }
    }
    //for checking coloumn
   bool col=true;
      for(int i=0;i<3;i++)
    {
       if(board[i][b]!=player)
       {
        col=false;
        break;
       }
    }
    //for main diagonal
    bool maindia=true;
        if(a==b)
        {
            for(int i=0;i<3;i++){
                if(board[i][i]!=player)
                {
                    maindia=false;
                    break;
                }
            }
        }
         else {
                maindia=false;
            }
    //for 2 nd diagonal
    bool secdia=true;
        if(a+b==2)
        {
            for(int i=0;i<3;i++)
            {
                if(board[i][2-i]!=player)
                {
                    secdia=false;
                    break;
                }
            }
        }
        else secdia=false;
    return row || col || maindia || secdia;
    
}
bool draw(vector<vector<char>>&board)
{
   for(int i=0;i<3;i++)
   {
    for(int j=0;j<3;j++)
    {
        
        if(board[i][j]==' '){
        return false;
        }
    }
   }
   return true;
}
void printboard(vector<vector<char>>&board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
void tictactoe(vector<vector<char>>&board)
{
    char player='X';
    bool over=false;
    while(!over)
    {
        int a,b;
        cout<<"Enter the row and coloumn of player ("<<player<<")\n";
        cin>>a>>b;
         if (cin.fail()) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter numbers between 0 and 2." << endl;
        continue; 
    }
         if (a < 0 || a >= 3 || b < 0 || b >= 3 || board[a][b] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }
        board[a][b]=player;
        printboard(board);
        if(check(board,a,b,player))   //this function rerurns who wins the game
        {
            cout<<"--------------\n--------------\n";
            printboard(board);
            cout<<"Player ("<<player<<") Wins the game\n";   
            over=true;
        }
        else if(draw(board))
        {
            cout<<"Game is drawn!!!";
            cout<<"--------------\n--------------\n";
            printboard(board);
            over=true;
        }
        if(player=='X') player='O';
        else player='X';
    }
}
bool playagain()
{
    cout<<"Do you want to play again\n";
    cout<<"Y (or) N\n";
    char ch;
    cin>>ch;
    if(ch=='Y') return true;
    else return false;
}
void reset(vector<vector<char>> & board)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]=' ';
        }
    }
}
int main()
{
    vector<vector<char>> board={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    bool play=true;
    while(play)
    {
      tictactoe(board);

      play=playagain();
      if(play)
      {
        reset(board);
      }

    }
     cout<<"Thank you.....!!!";
}