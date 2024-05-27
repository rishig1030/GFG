//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int subtracting(vector<int> &v,int N){
        if(N<=0) {
            return N;
        }
        else{
            v.push_back(N);
            subtracting(v,N-5);
        }
        
    }
    
    void adding(vector<int> &v,int N){
        if(N == v[0]) {
            v.push_back(N);
            return;
        }
        else{
            v.push_back(N);
            adding(v,N+5);
        }
    }
    
    void f(vector<int> &v,int N){
        N=subtracting(v,N);
        
        adding(v,N);
    }
    vector<int> pattern(int N){
        // code here
        
        vector<int> v;
        if(N<=0){
            v.push_back(N);
            return v;
        }
        f(v,N);
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends