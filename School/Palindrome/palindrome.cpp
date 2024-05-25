//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

bool palindrome(string str,int left,int right){
    if(right<left){
        return true;
    }
    else {
        if(str[left] != str[right-1]){
            return false;
        }
        palindrome(str,left+1,right-1);
    }
}

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		    string str = to_string(n);
		    int right = str.size();
		    int left = 0;
		    if(palindrome(str,left,right)){
		        return "Yes";
		    }
		    else{
		        return "No";
		    }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends