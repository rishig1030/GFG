//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

void queuereversal(queue<int> &q){
    if(q.empty()){
            return ;
        }
        
    else{
        int a=q.front();
        q.pop();
        queuereversal(q);
        q.push(a);
    }
}
//Function to reverse the queue.
class Solution
{
    public:
    queue<int> rev(queue<int> &q)
    {
        // add code here.
        queuereversal(q);
        return q;
        
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends