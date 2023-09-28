//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
     int bfs(vector<vector<int>> &grid,vector<vector<int>> &visited,int m,int n){
        
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;++j){
                
                if(grid[i][j] == 2) {q.push({{i,j},0});
                visited[i][j]=1;}
            }
        }
        
        int a[4]={-1,0,1,0};
        int b[4]={0,-1,0,1};
        
        
        
        int res=0;
        while(!q.empty()){
            
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            res=t;
            q.pop();
            // cout<<r<<" "<<c<<" "<<t<<endl;
            
            for(int i=0;i<4;++i){
                
                int newRow=r+a[i];
                int newCol=c+b[i];
                
                if(newRow>=0 && newRow<m && newCol>=0 && newCol < n){
                    // cout<<grid[newRow][newCol]<<" "<<visited[newRow][newCol]<<endl;
                    if(!visited[newRow][newCol] && grid[newRow][newCol]==1){
                        // cout<<newRow<<" "<<newCol<<endl;
                        grid[newRow][newCol]=2;
                        q.push({{newRow,newCol},t+1});
                    }
                }
            }
        }
        return res;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int res=bfs(grid,visited,m,n);
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;++j){
                
                if(grid[i][j] == 1)  return -1;
            }
            // cout<<endl;
        }
        return res;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends