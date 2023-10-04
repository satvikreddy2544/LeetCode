//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>> &mat,int row,int col,int n,int m,vector<vector<int>> &visited){
        
        int a[4]={-1,0,1,0};
        int b[4]={0,-1,0,1};
        visited[row][col]=1;
        
        for(int i=0;i<4;++i){
            
            int newRow=a[i]+row;
            int newCol=b[i]+col;
            
            if(newRow>=0 && newRow < n && newCol >=0 && newCol <m){
                
                if(!visited[newRow][newCol] && mat[newRow][newCol] == 'O'){
                    // visited[newRow][newCol]=1;
                    dfs(mat,newRow,newCol,n,m,visited);
                }
            }
        }
        
    }
    void canVisit(vector<vector<char>> &mat,int n,int m){
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            
            if(!visited[0][i] && mat[0][i] == 'O'){
                dfs(mat,0,i,n,m,visited);
            }
            if(!visited[n-1][i] && mat[n-1][i] == 'O'){
                dfs(mat,n-1,i,n,m,visited);
            }
        }
        
        for(int i=0;i<n;i++){
            
            if(!visited[i][0] && mat[i][0] == 'O'){
                dfs(mat,i,0,n,m,visited);
            }
            
            if(!visited[i][m-1] && mat[i][m-1] == 'O'){
                dfs(mat,i,m-1,n,m,visited);
            }
        }
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;++j){
                
                if(!visited[i][j] && mat[i][j] == 'O') mat[i][j]='X';
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        canVisit(mat,n,m);
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends