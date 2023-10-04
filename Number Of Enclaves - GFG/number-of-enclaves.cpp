//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &grid,int row,int col,int m,int n,vector<vector<int>> &visited){
        
        visited[row][col]=1;
        
        int a[4]={-1,0,1,0};
        int b[4]={0,-1,0,1};
        
        
        for(int i=0;i<4;++i){
            
            int newRow=row+a[i];
            int newCol=col+b[i];
            
            if(newRow >=0 && newRow < m && newCol >=0 && newCol <n){
                
                if(!visited[newRow][newCol] && grid[newRow][newCol]==1)
                    dfs(grid,newRow,newCol,m,n,visited);
            }
        }
        
    }
    int canMove(vector<vector<int>> &grid){
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            
            if(!visited[0][i] && grid[0][i] == 1){
                dfs(grid,0,i,m,n,visited);
            }
            if(!visited[m-1][i] && grid[m-1][i]==1)
                 dfs(grid,m-1,i,m,n,visited);
        }
        for(int i=0;i<m;i++){
            
            if(!visited[i][0] && grid[i][0] == 1){
                dfs(grid,i,0,m,n,visited);
            }
            if(!visited[i][n-1] && grid[i][n-1]==1)
                 dfs(grid,i,n-1,m,n,visited);
        }
        // for(int i=0;i<m;i++){
            
        //     for(int j=0;j<n;j++){
                
        //         cout<<visited[i][j]<<" ";
               
        //     }
        //      cout<<endl;
        // }
        int count=0;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(!visited[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
        
        
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        return canMove(grid);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends