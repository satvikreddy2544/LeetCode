//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isPossible(int A[],int n,int m,int mid){
        
        int total=0, count=1;
        
        for(int i=0;i<n;i++){
            
            if(A[i] > mid) 
                return false;
            if(total + A[i] > mid) {
                
                count++;
                total=A[i];
                if(count > m) return 0;
            }
            else{
                total+=A[i];
            }
        }
        return 1;
        
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        if(M>N) return -1;
        
        int high=accumulate(A,A+N,0);
        int low=0;
        int res=-1;
        while(low <= high){
            
            int mid=low+(high-mid)/2;
            
            if(isPossible(A,N,M,mid)){
                
                res=mid;
                high=mid-1;
            }
            else 
                low=mid+1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends