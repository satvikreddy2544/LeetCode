//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[],int n,int src,int visited[],int parent){
        
        visited[src]=1;
        for(auto x:adj[src]){
            
            if(!visited[x] ){
                
                if(dfs(adj,n,x,visited,src)) return 1;
            } 
            else if(x != parent) return 1;
        }
        return 0;
    }
    bool bfs(vector<int> adj[],int n,int src,int visited[]){
        
        visited[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()){
            
            int ele=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto x:adj[ele]){
                
                if(!visited[x]){
                    
                    visited[x]=1;
                    q.push({x,ele});
                }
                else if(x!=parent) return 1;
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[V]={0};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                
                if(dfs(adj,V,i,visited,-1)) return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends