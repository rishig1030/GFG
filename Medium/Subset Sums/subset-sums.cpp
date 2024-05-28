//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void f(int i,vector<int> arr,int n,int sum,vector<int> &v){
        if(i==n){
            v.push_back(sum);
            return ;
        }
        else{
            sum= sum+arr[i];
            f(i+1,arr,n,sum,v);
            sum=sum-arr[i];
            f(i+1,arr,n,sum,v);
        }
        
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> v;
        int sum=0;
        f(0,arr,n,sum,v);
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends