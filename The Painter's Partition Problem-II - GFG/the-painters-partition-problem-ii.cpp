//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(int a[],int n,long long  mid,int k){
        
        int part=1;
        long long int sum=0;
        for(int i=0;i<n;i++){
            
            if(a[i] > mid) return 0;
            
            if(sum + a[i] > mid){
                
                part++;
                sum=a[i];
                if(part > k) return 0;
            }
            else {
                
                sum+=a[i];
            }
        }
        return 1;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long int low=0,high=0;
        for(int i=0;i<n;i++) high+=arr[i];
        long long int ans=-1;
        // if(k > n) return ans;
        while(low <=  high){
            
            long long int mid=low+(high-low)/2;
            
            if(isPossible(arr,n,mid,k)){
                
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends