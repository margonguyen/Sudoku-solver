/*
 Sudoku solver
 *
 */

#include <iostream>
#include <vector>

using namespace std;

const int M = 9;
const int N = 9;

char num = '1';
void input(char  box[][N]);
void output(char box[][N]);
void solve(char box[][N]);
bool solve(char box[][N] , int row , int column);


void checkColumn(char box[][N], int row , char num, bool & checked);
void checkRow(char box[][N], int column , char num, bool & checked);
void checkBox(char box[][N], int row , int column, char num, bool & checked);
bool findEmpty(char box[][N] , int &row , int &column);

int main()
{
    char box [M][N];

    for (int i = 0; i < 9 ; i++)
    {
        for(int j = 0; j < 9 ; j++)
        {
            box[i][j] = '.' ;
        }
    }
    input(box);
    cout << " unsolved sudoku" << endl;
    output(box);
    solve(box);
    cout << endl;
    cout << "solved sudoku" << endl;
    output(box);
    
}

void input(char  box[][N])
{
    string line;
    int i, j;
    
    i = 0 ;
    j = 0;
    
    cout << "Enter the soduku to solve" << endl;
    cout << " Each line is in the bracket ()" << endl;
    cout << " each number is seperate by a comma " << endl;
    getline(cin, line);
   
    for ( char& c : line)
    {
        if ( c != '(' && c != ')' && c != ',')
        {   if(j < 9)
            {
                box[i][j] = c;
                j++;
            }
            if( j ==  9)
            {
                i++;
                j = 0;
            }
        }
    }
}

void output(char  box[][N])
{
    for (int i = 0; i < 9 ; i++)
    {
        for(int j = 0; j < 9 ; j++)
        {
            cout << box[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(char box[][N])
{   int row;
    int column;
    row = 0;
    column = 0;
    bool solved;
    solved = solve(box,row,column);
    if(solved)
        cout << "solved" << endl;
    
}

bool solve(char box[][N] , int row , int column)
{   vector<char> choices{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool empty = false;
    bool checked = true;
    int r,c;
    //output(box);

    
    r = 0 ;
    for(int i = 0; i < 9 ; i++)
    {
        c = 0;
        for (int j = 0; j < 9 ; j++)
        {
            if(box[i][j] == '.')
            {
                empty = true;
                break;
            }
            c++;
        }
        if(empty == true)
        {
            break;
        }
        r++;
    }

    if(!empty)
        return true;
    
    for(auto val : choices)
    {   checked = true;
        
       // cout << val << endl;

        checkColumn(box ,r ,val, checked);
        checkRow(box ,c ,val, checked);
        checkBox(box ,r , c ,val, checked);
        if(checked)
        {
           // cout << val << endl;
            box[r][c] = val;
            if(solve(box,row,column ))
                return true;
        }


    }
 //   box[r][c] = '.';

    return false;
    
}


void checkColumn(char box[][N], int row , char num, bool & checked)
{
    
    
  //  bool found = false;
    for(int i = 0 ; i < 9 ; i++)
    {
        if( box[row][i] == num )
        {
            checked = false;
        }
    }


}

void checkRow(char box[][N], int column , char num, bool & checked)
{
    for(int i = 0 ; i < 9 ; i++)
    {
        if( box[i][column] == num )
        {
            checked = false;
        }
    }
 
}

void checkBox(char box[][N], int row , int column, char num, bool & checked)
{
    int r = row - row %3;
    int c = column - column %3;
    
    for(int i = r; i < r+3 ; i++)
    {
        for(int j = c; j < c+3; j++)
        {
            if(box[i][j] == num)
                checked = false;
        }
    }
}
