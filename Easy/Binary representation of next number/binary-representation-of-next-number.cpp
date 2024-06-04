//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        string ans="";
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(i!=0 || s[i]=='1'){
                st.push(s[i]);
            }
        }
        while(!st.empty() && st.top()=='1'){
            st.top()='0';
            ans=ans+st.top();
            st.pop();
        }
        if(!st.empty() && st.top()=='0') st.top()='1';
        else st.push('1');
        
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans[0] == '0') {
            for(int i=1;i<s.size();i++){
                ans[i-1]=ans[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends