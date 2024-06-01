//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        int x= 0; int y = 0;
        map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            if(mpp[s[i]]){
                mpp[s[i]]++;
            }
            else mpp[s[i]]=1;
        }
        for(int i=0;i<s.size();i++){
            if(mpp[s[i]]%2 == 0 && int(s[i])%2 == 0){
                mpp[s[i]] = 1;
                x++;
            }
            else if(mpp[s[i]]%2 != 0 && int(s[i])%2 != 0){
                mpp[s[i]] = 0;
                y++;
            }
        }
        
        if((x+y)%2 == 0) return "EVEN";
        else return "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends