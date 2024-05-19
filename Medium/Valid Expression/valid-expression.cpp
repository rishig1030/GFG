//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string s)
{
    // code here 
    stack<char> s1;
    for(int i=0;i<s.size();i++){
        
        //if opening bracket, then push it into the stack 
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            s1.push(s[i]);
        }
        //if closing bracket check the top, and pop
        else{
            if(!s1.empty()){
                if(s[i] == ']' && s1.top() == '['){
                    s1.pop();
                }
                else if(s[i] == '}' && s1.top() == '{'){
                    s1.pop();
                }
                else if(s[i] == ')' && s1.top() == '('){
                    s1.pop();
                }
                else return false;
            }
            else return false;
        }
    }
    return s1.empty();
}