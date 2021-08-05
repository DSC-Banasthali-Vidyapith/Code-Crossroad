//EXPLAINATION:
/* The naive approach used here is to generate all possible configurations of numbers from 1 to 9 to fill the empty cells. Try every configuration one by one until the correct configuration is found, i.e. for every unassigned position fill the position with a number from 1 to 9.
   After filling all the unassigned position check if the matrix is safe or not. If safe print else recurs for other cases.*/


   #include <bits/stdc++.h>
   using namespace std;

   bool canPlace(int mat[][9], int i, int j, int n, int number)
   {

     //Check for row and column
     for (int k = 0; k < n; k++)
     {
        if (mat[i][k] == number || mat[k][j] == number)
        {
            return false;
        }
     }
     //Check for Subgrid

     //For checking subgrid we need to find the starting index of the subgrid
     int sqn = sqrt(n);
     int sx = (i / sqn) * sqn;
     int sy = (j / sqn) * sqn;
     for (int row = sx; row < sx + sqn; row++)
     {
        for (int col = sy; col < sy + sqn; col++)
        {
            if (mat[row][col] == number)
            {
                return false;
            }
        }
     }

     return true;
  }

  bool solveSudoku(int mat[][9], int i, int j, int n)
  {
    //Base Case
    //We have iterated over all rows and reach final row
    if (i == n)
    {
        //Printing matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }

            cout << endl;
        }

        return true;
    }

    //We have reached end of row,so we switch to next row.
    if (j == n)
    {
        return solveSudoku(mat, i + 1, 0, n);
    }

    //If cell is pre-filled we skip to next cell

    if (mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j + 1, n);
    }
    //Rec Case
    //Now we try to fill the current position with possible options
    for (int number = 1; number <= n; number++)
    {
        if (canPlace(mat, i, j, n, number))
        {
            //Assume this is correct number
            mat[i][j] = number;
            //Call on remaining matrix
            bool couldWeSolve = solveSudoku(mat, i, j + 1, n);
            if (couldWeSolve == true)
            {
                return true;
            }
        }
    }
    //Backtrack here,since all options for the given number have been used
    
    mat[i][j] = 0;
    return false; 
    //Sudoku couldnt be solved in this case.
  }
 
   int main()
  {
    int grid[9][9];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>grid[i][j];
        }
    }
    solveSudoku(grid, 0, 0, 9);
    return 0;
  }
  //EXAMPLE:
  /* 
  Input:
  grid = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} }
  Output:
          3 1 6 5 7 8 4 9 2
          5 2 9 1 3 4 7 6 8
          4 8 7 6 2 9 5 3 1
          2 6 3 4 1 5 9 8 7
          9 7 4 8 6 3 1 2 5
          8 5 1 7 9 2 6 4 3
          1 3 8 9 4 7 2 5 6
          6 9 2 3 5 1 8 7 4
          7 4 5 2 8 6 3 1 9
   Explanation: Each row, column and 3*3 box of the output matrix contains unique numbers.

  Time complexity: O(9^(n*n)). 
  For every unassigned index there are 9 possible options so the time complexity is O(9^(n*n)).
  Space Complexity: O(n*n). 
  To store the output array a matrix is needed.
 
*/
