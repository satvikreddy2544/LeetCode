//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(vector<int> stalls,int n,int k,int mid){
        
        
        int minPo=0,cow=1;
        for(int i=1;i<n;i++){
            
            if(stalls[i]-stalls[minPo] >= mid) {
                cow++;
                minPo=i;
            }
            if(cow == k) return 1;
        }
        return 0;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        // int n=stalls.size();
        // if(k > n) return -1;
        sort(stalls.begin(),stalls.end());
        
        int low=0,ans=-1;
        int maxPo=*max_element(stalls.begin(),stalls.end());
        int minPo=*min_element(stalls.begin(),stalls.end());
        int high=maxPo-minPo;
        // cout<<"pos"<<" "<<high<<endl;
        
        while(low <= high){
            
            int mid=low+(high-low)/2;
            
            if(isPossible(stalls,n,k,mid)){
                
                ans=mid;
                low=mid+1;
            }
            else 
                high=mid-1;
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends