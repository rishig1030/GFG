//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        int count = 0;
        
        for(int i=0;i<str.size();i++){
            if(str[i]>='a' && str[i]<='z') count++;
        }
        
        if(count<26) return false;
        vector<int> hash(26,0);
        count = 0;
        for(int i=0;i<str.size();i++){
            if(str[i]>='a' && str[i]<='z') {
                if(hash[str[i]-'a'] == 0) count++;
                
                hash[str[i]-'a']++;
            }
        }
        
        if(count+k>=26) return true;
        else return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends