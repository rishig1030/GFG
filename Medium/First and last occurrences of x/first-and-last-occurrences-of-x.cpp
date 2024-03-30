//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    // by using lower bound and upper bound concept
    int lowerbound(int arr[],int n,int target){
        int left=0;
        int right = n-1;
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]==target){
                ans=mid;
                right=mid-1;
            }
            else if(arr[mid]<target){
                left=mid+1;
            }
            else {
                right= mid-1;
            }
        }
        return ans;
    }
    int upperbound(int arr[],int n,int target){
        int left=0;
        int right = n-1;
        int ans =n;
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]>target){
                ans=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return ans;
        
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector <int> v;
        int lp=lowerbound(arr,n,x);
        if(lp == -1){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        else{
            v.push_back(lp);
            v.push_back(upperbound(arr,n,x)-1);
            return v;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends