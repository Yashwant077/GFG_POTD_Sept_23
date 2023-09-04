/*
Problem Descritption: Replace O's with X's

Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

Example 1:

Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix. 
Example 2:

 

Input: 
n = 5, m = 4
mat = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix.
Your Task:
You do not need to read input or print anything. Your task is to complete the function fill() which takes N, M and mat as input parameters ad returns a 2D array representing the resultant matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
*/

class Solution{
public:
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    bool isValid(int ii, int jj, int& n, int& m){
        return (ii>=0 && jj>=0 && ii<n && jj<m);
    }
    
    bool isBoundary(int i, int j, int& n, int& m){
        return (i==0|| j==0 || i==n-1 || j==m-1);
    }
    
    void setNotClosed(int i, int j, int& n, int& m, 
    vector<vector<char>>& mat){
        mat[i][j]='N';
        
        for(int d =0; d<4; d++){
            int ii = dx[d]+i;
            int jj = dy[d]+j;
            
            if(isValid(ii, jj, n, m) && mat[ii][jj]=='O')
                setNotClosed(ii, jj, n, m, mat);
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isBoundary(i,j,n,m) && mat[i][j]=='O')
                    setNotClosed(i,j,n,m,mat);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]=='O')
                    mat[i][j]='X';
                else if(mat[i][j]=='N')
                    mat[i][j]='O';
            }
        }
        
        return mat;
    }
};
