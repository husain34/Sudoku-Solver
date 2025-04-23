#include <iostream>
#include <map>
using namespace std;

// Class to represent a node in the grid
class Node {
    public:
    bool isempty = true;

    int num;
};

map<pair<int, int>, Node> grid;

void Display();
bool CheckSudoku();
bool SolveSudoku(int row, int col);
bool isLegal(pair<int,int> cor,int num);
void StartSudoku();

int main()
{
    cout << "Sudoku Solver:" << endl;
    
    pair<int, int> current;
    Node node[9*9];

    //Creates a grid
    int count = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[{i, j}] = node[count];
            grid[{i,j}].num = 0;
            count++;
        }
        cout << endl;
    }

    //Initializes an example sudoku to solve
    StartSudoku();

    //Assigns Empty Cells with boolean value
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(grid[{i,j}].num != 0){
                grid[{i,j}].isempty = false;
            }
        }
        cout << endl;
    }

    //Checks Valid Sudoku
    if(CheckSudoku()){
        cout<<"Started: "<<endl;

        //Displays the Example Sudoku
        Display();
    
        SolveSudoku(0,0);
    
        //Displays the Solved Sudoku
        Display();
    }
    else{

        cout<<"Enter Valid Sudoku"<<endl;
    }
    

    cout << endl;
    return 0;
}

bool CheckSudoku(){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(!grid[{i,j}].isempty){
                grid[{i, j}].isempty = true;
                if(!isLegal({i,j},grid[{i,j}].num)){
                    cout<<"Invalid at : ["<<i<<"]["<<j<<"] : "<<grid[{i,j}].num<<endl;
                    return false;
                }
                grid[{i, j}].isempty = false;
            }
                
        }
    }
    return true;
}

bool SolveSudoku(int row, int col){
    if(row == 9){
        cout<<"Completed"<<endl;
        return true;
    }
    if(col == 9){
        return SolveSudoku(row+1,0);
    }
    if(!grid[{row,col}].isempty)
    {
        return SolveSudoku(row,col+1);
    }
    
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if(isLegal({row,col},i)){
                grid[{row,col}].num = i;
                grid[{row, col}].isempty = false;
                if(SolveSudoku(row,col+1)){
                    return true;
                }
                grid[{row,col}].num = 0;
                grid[{row, col}].isempty = true;
            }
        }
        return false;
    }
    
}

bool isLegal(pair<int,int> cor,int num){
    
    //Checking for the row and column
    for (int i = 0; i < 9; i++)
    {
        if(!grid[{i,cor.second}].isempty && num == grid[{i,cor.second}].num){
            return false;
        }
        if(!grid[{cor.first,i}].isempty && num == grid[{cor.first,i}].num){
            return false;
        }
    }

    //Gets Top left Corner of the 3x3 grid

    int startrow = (cor.first/3)*3;
    int startcol = (cor.second/3)*3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int r = startrow + i;
            int c = startcol + j;
            if(!grid[{r,c}].isempty && num == grid[{r,c}].num){
                return false;
            }
        }
        
    }
    
    return true;
}

void StartSudoku()
{
    cout<<"Enter values from left to right \n Enter 0 for emoty cell : "<<endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << "[" <<i<<"]["<<j<<"] : "<< endl;
            cin>>grid[{i, j}].num;
        }
    }
}




void Display()
{
    cout<<endl;
    for (int i = 0; i < 9; i++)
    {
        cout << "|";
        for (int j = 0; j < 9; j++)
        {
            cout << grid[{i, j}].num << "|";
        }
        cout << endl;
    }
}
