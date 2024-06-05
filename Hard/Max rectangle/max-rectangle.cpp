//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  vector<int> nextminimumindex(int arr[],int n){
        vector<int> v(n);
        stack<int> st;
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
    vector<int> prevminimumindex(int arr[],int n){
        vector<int> v;
        stack<int> st;
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
    
    
    //Function to find largest rectangular area possible in a given histogram.
    int getMaxArea(int arr[], int n)
    {
        // Your code here
        vector<int> next;
        next = nextminimumindex(arr,n);
        
        vector<int> prev;
        prev = prevminimumindex(arr,n);
        
        int area = -1;
        for(int i=0;i<n;i++){
            int length = arr[i];
            
            if(next[i] == -1) next[i] = n;
            int breath = next[i]-prev[i]-1;
            
            area = max(area,length*breath);
        }
        return area;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int area = getMaxArea(M[0],m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                else{
                    M[i][j] = 0;
                }
            }
            area = max(area,getMaxArea(M[i],m));
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends