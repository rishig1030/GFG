//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
   vector<int> nextminimumindex(long long arr[],int n){
        vector<int> v(n);
        stack<long long> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> prevminimumindex(long long arr[],int n){
        vector<int> v;
        stack<long long> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!= -1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            v.push_back(st.top());
            st.push(i);
        }
        return v;
    }
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int> next;
        next = nextminimumindex(arr,n);
        
        vector<int> prev;
        prev = prevminimumindex(arr,n);
        
        long long area = -1;
        for(int i=0;i<n;i++){
            long long length = arr[i];
            
            if(next[i] == -1) next[i] = n;
            long long breath = next[i]-prev[i]-1;
            
            area = max(area,length*breath);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends