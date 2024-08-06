//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        int a=0,b=0,c=0,d=0;
        bool visit1 = false,visit2 = false,visit3 = false,visit4 = false;
        int i = 0;
        while(str[i]!='.' && i<str.size()){
            if(!visit1 && str[i]=='0' && (i+1!=str.size() && str[i+1]!='.') ) return false;  
            visit1 = true;
            int n = str[i]-'0';
            a = a*10 + n;
            i++;
        }
        i++;
        while(str[i]!='.' && i<str.size() ){
            if(!visit2 && str[i]=='0' && (i+1!=str.size() && str[i+1]!='.')) return false;  
            visit2 = true;
            int n = str[i]-'0';
            b = b*10 + n;
            i++;
        }
        i++;
        while(str[i]!='.' && i<str.size()){
            if(!visit3 && str[i]=='0' && (i+1!=str.size() && str[i+1]!='.')) return false;  
            visit3 = true;
            int n = str[i]-'0';
            c = c*10 + n;
            i++;
        }
        i++;
        while(str[i]!='.' && i<str.size()){
            if(!visit4 && str[i]=='0' && (i+1!=str.size() && str[i+1]!='.')) return false;  
            visit4 = true;
            int n = str[i]-'0';
            d = d*10 + n;
            i++;
        }
        if(i!=str.size()) return false;
        
        if(a>=0 && a<=255 && b>=0 && b<=255 && c>=0 && c<=255 && d>=0 && d<=255 && visit1 && visit2 && visit3 && visit4) return 1;
        
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends