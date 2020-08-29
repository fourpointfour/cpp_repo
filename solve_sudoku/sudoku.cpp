#include<bits/stdc++.h>
using namespace std;
#define N 9
bool SolveSudoku(int grid[N][N]);
void printGrid(int grid[N][N]);
int main(){
    int grid[N][N];
    for(int r = 0; r < N; ++r){
        for(int c = 0; c < N; ++c){
            cin>>grid[r][c];
        }
    }
    if(SolveSudoku(grid))
        printGrid(grid);
    else
    {
        cout<<"No solution exists!";
    }
    
    return 0;
}

bool UsedInRow(int grid[N][N], int row, int num)
{
    for(int col = 0; col < N; ++col)
        if(grid[row][col] == num)
            return true;
    return false;
}
bool UsedInCol(int grid[N][N], int col, int num)
{
    for(int row = 0; row < N; ++row)
        if(grid[row][col] == num)
            return true;
    return false;
}
bool UsedInBox(int grid[N][N], int rowStart, int colStart, int num)
{
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
            if(grid[i+rowStart][j+colStart] == num)
                return true;
    }
    return false;
}
bool isSafe(int grid[N][N], int num, int row, int col)
{
    return(!UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) &&
            !UsedInBox(grid, row - (row%3), col-(col%3), num) && grid[row][col] == 0);
}

bool findUnassigned(int grid[N][N], int &row, int &col)
{
    for(row = 0; row < N; ++row)
    {
        for(col = 0; col < N; ++col)
        {
            if(grid[row][col] == 0)
                return true;
        }
    }
    return false;
}
bool SolveSudoku(int grid[N][N])  
{ 
    int row, col;
    if(!findUnassigned(grid, row, col))
        return true;
    for(int n = 1; n <= 9; ++n)
    {
        if(isSafe(grid, n, row, col))
        {
            grid[row][col] = n;
            if(SolveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid (int grid[N][N]) 
{
    // Your code here 
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            cout<<grid[i][j]<<' ';
        cout<<'\n';
    }
}
