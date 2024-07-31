//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string ans = "";
        
        for(int i=0;i<arr[0].size();i++){
            bool istrue = true;
            
            for(int j=0;j<arr.size();j++){
                if(arr[j].size()<i || arr[j][i] != arr[0][i] ){
                    istrue = false;
                    break;
                }
            }
            if(!istrue) break;
            else ans += arr[0][i];
        }
        
        if(ans.size()==0) return "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends