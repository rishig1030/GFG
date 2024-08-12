//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int i = 0;
        int j = 0;
        int k = (arr1.size()+arr2.size())/2;
        int a = 0;
        int b = 0;
        int count = 0;
        
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<arr2[j]){
                count++;
                i++;
                if(count==k){
                    a = arr1[i-1];
                }
                else if(count==k+1){
                    b = arr1[i-1];
                    return a+b;
                }
            }
            else{
                count++;
                j++;
                if(count==k){
                    a = arr2[j-1];
                }
                else if(count==k+1){
                    b = arr2[j-1];
                    return a+b;
                }
            }
        }
        while(i<arr1.size()){
            count++;
            i++;
            if(count==k){
                a = arr1[i-1];
                }
            else if(count==k+1){
                b = arr1[i-1];
                return a+b;
            }
        }
        while(j<arr2.size()){
            count++;
                j++;
                if(count==k){
                    a = arr2[j-1];
                }
                else if(count==k+1){
                    b = arr2[j-1];
                    return a+b;
                }
        }
        return a+b;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends