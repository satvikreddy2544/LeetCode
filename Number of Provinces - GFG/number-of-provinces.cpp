//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfs(vector<int> adj[],int n,int src,int visited[]){
        
        queue<int> que;
        que.push(src);
        visited[src]=1;
        
        while(!que.empty()){
            
            int ele=que.front();
            que.pop();
            
            for(auto x:adj[ele]){
                
                if(!visited[x]){
                    visited[x]=1;
                    que.push(x);
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> v, int V) {
        
        
        // code here
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            
            for(int j=0;j<V;++j){
                
                if(v[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int visited[V]={0};
        int count=0;
        for(int i=0;i<V;i++){
            
            if(!visited[i]){
                count++;
                bfs(adj,V,i,visited);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends