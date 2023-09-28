//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],int n,int src,int visited[],int restack[]){
        
        visited[src]=1;
        restack[src]=1;
        
        for(auto x:adj[src]){
            
            if(!visited[x] && dfs(adj,n,x,visited,restack)) return 1;
            else if(restack[x] == 1) return 1;
        }
        restack[src]=0;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        int visited[V]={0},restack[V]={0};
        for(int i=0;i<V;++i){
            
            if(dfs(adj,V,i,visited,restack)) return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends