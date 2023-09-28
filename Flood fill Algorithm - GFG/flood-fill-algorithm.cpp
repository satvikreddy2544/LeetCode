//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void bfs(vector<vector<int>> image,int row,int col,int newColor,int color,int m,int n,vector<vector<int>> &visited,vector<vector<int>> &res){
        
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            res[r][c]=newColor;
            
            int a[4]={-1,0,1,0};
            int b[4]={0,-1,0,1};
            
            for(int i=0;i<4;++i){
                
                int newRow=r+a[i];
                int newCol=c+b[i];
                
                if(newRow>=0 && newRow < m && newCol>=0 && newCol < n){
                    
                    if(!visited[newRow][newCol] && image[newRow][newCol]==color){
                        visited[newRow][newCol]=1;
                        q.push({newRow,newCol});
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int m=image.size(),n=image[0].size();
        vector<vector<int>> res=image;
        
        int c=image[sr][sc];
        vector<vector<int>> visited(m,vector<int>(n,0));
        bfs(image,sr,sc,newColor,c,m,n,visited,res);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends