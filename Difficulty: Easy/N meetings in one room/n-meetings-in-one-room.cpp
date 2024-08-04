//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool customComp(pair<int,int> a,pair<int,int> b){
    
    if(a.second==b.second) return a.first<b.first;
    
    return a.second<b.second;
}
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        if(n==0) return 0;
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end(),customComp);
        
        int endtime = v[0].second;
        int count = 1;
        for(int i=0;i<v.size();i++){
            if(v[i].first>endtime){
                count++;
                endtime = v[i].second;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends