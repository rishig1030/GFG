//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int n = arr.size();
        int countN = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                countN++;
            }
        }
        long long product = 1;
        if(countN%2 == 0) {
            for(int i=0;i<n;i++){
                if(arr[i]!=0) product = (product*arr[i])%1000000007;
            }
        }
        
        else if(countN%2 != 0 && countN != 1){
            int maxN = INT_MIN;
            for(int i=0;i<n;i++){
                if(arr[i]<0) maxN = max(maxN,arr[i]);
            }
            for(int i=0;i<n;i++){
                if(arr[i]!=maxN && arr[i]!=0){
                    product = (product*arr[i])%1000000007;
                }
                else if(arr[i] == maxN){
                    maxN = INT_MIN;
                }
            }
        }
        
        else{
            int zero = 0;
            for(int i=0;i<n;i++){
                if(arr[i] == 0){
                    zero++;
                }
            }
            if(zero == n-1) return 0;
            else{
                for(int i=0;i<n;i++){
                    if(arr[i] > 0 && arr[i] != 0){
                        product = (product*arr[i])%1000000007;
                    }
                }
            }
        }
        
        return product;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends