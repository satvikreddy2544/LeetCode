//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(vector<int> adj[],int n,int color[],int src){
        
        queue<int> q;
        q.push(src);
        color[src]=0;
        while(!q.empty()){
            
            int ele=q.front();
            q.pop();
            
            for(auto x:adj[ele]){
                
                if(color[x] == -1){
                    color[x]=!color[ele];
                    q.push(x);
                }
                else{
                    if(color[x] == color[ele]) return 0;
                }
            }
        }
        
        return 1;
    }
   
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0;i<V;i++) color[i]=-1;
	   
	  for(int i=0;i<V;i++){
	      if(color[i] == -1){
	          if(!bfs(adj,V,color,i))  return 0;
	      }
	  }
	   // for(int i=0;i<V;i++) cout<<color[i]<<" ";
    //     cout<<endl;
        return 1;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends