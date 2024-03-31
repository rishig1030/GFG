//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        long long n = v.size();
        long long left = 0;
        long long right = n-1;
        long long lower = -1;
        while(left<=right){
            long long mid = (left+right)/2;
            if(v[mid]==x){
                lower=mid;
                right = mid-1;
            }
            else if(v[mid]<x){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        left = 0;
        right = n-1;
        long long upper = -1;
        while(left<=right){
            long long mid = (left+right)/2;
            if(v[mid]==x){
                upper=mid;
                left = mid+1;
            }
            else if(v[mid]<x){
                left=mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return {lower,upper};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends