//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int lowerbound(vector<int> &arr,int n,int x){
        int left=0;
        int right=n-1;
        int ans=n;
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]>=x){
                ans = mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return ans;
    }
    int upperbound(vector<int> &arr,int n,int x){
        int left=0;
        int right=n-1;
        int ans=n;
        while(left<=right){
            int mid=(left+right)/2;
            
            if(arr[mid]>x){
                ans = mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return ans;
    }
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        vector <int> v; 
        int lb=lowerbound(arr,n,x);
        if(lb==n || arr[lb]!=x){
            v.push_back(-1);
            return v;
        }
        v.push_back(lb);
        v.push_back(upperbound(arr,n,x)-1);
        return v;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}

// } Driver Code Ends