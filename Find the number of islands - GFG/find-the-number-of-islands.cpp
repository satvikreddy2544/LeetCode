//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>> grid,vector<vector<int>> &visited,int row,int col,int m,int n){
        
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col]=1;
        while(!q.empty()){
            
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=-1;i<=1;i++){
                
                for(int j=-1;j<=1;j++){
                    
                    int newRow=r+i;
                    int newCol=c+j;
                    if(newRow>=0 && newRow<m && newCol>=0 && newCol<n ){
                        if(!visited[newRow][newCol] && grid[newRow][newCol]=='1'){
                            visited[newRow][newCol]=1;
                            q.push({newRow,newCol});
                        }
                    }
                }
            }
        }
    }
    // void dfs(vector<vector<char>> grid,vector<vector<int>> &visited,int row,int col,int m,int n){
        
    //     int a[4]={-1,0,1,0};
    //     int b[4]={0,-1,0,1};
    //     visited[row][col]=1;
    //     for(int i=0;i<4;i++){
            
    //         int newRow=row+a[i];
    //         int newCol=col+b[i];
            
    //         if(newRow>=0 && newRow<m && newCol>=0 && newCol < n ){
    //             if(grid[newRow][newCol]=='1' && !visited[newRow][newCol]){
    //             dfs(grid,visited,newRow,newCol,m,n);
    //             }
    //         }
    //     }
    // }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    // for(auto x:visited){
                    //     for(auto y:x) cout<<y<<" ";
                    //     cout<<endl;
                    // }
                    bfs(grid,visited,i,j,m,n);
                    
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends