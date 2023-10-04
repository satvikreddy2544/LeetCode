//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &grid,int row,int col,int m,int n,vector<vector<int>> &visited,pair<int,int> base,set<vector<pair<int,int>>> &st,vector<pair<int,int>> &v){
        visited[row][col]=1;
        
        int a[4]={-1,0,1,0};
        int b[4]={0,-1,0,1};
        
        for(int i=0;i<4;i++){
            
            int newRow=row+a[i];
            int newCol=col+b[i];
            if(newRow>=0 && newRow<m && newCol>=0 && newCol <n ){
                
                if(!visited[newRow][newCol] && grid[newRow][newCol]==1){
                   
                    int r=newRow-base.first;
                    int c=newCol-base.second;
                    v.push_back({r,c});
                   
                     dfs(grid,newRow,newCol,m,n,visited,base,st,v);
                }
            }
        }
    }
    int countIslands(vector<vector<int>> &grid){
        
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;++j){
                vector<pair<int,int>> v={{0,0}};
                if(grid[i][j]== 1 && !visited[i][j]){
                    dfs(grid,i,j,m,n,visited,{i,j},st,v);
                    st.insert(v);
                    
                }
            }
        }
        // for(auto x:st){
        //     for(auto y:x) cout<<y.first<<" "<<y.second<<" ";
        //     cout<<endl;
        // }
        return st.size();
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        return countIslands(grid);
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends