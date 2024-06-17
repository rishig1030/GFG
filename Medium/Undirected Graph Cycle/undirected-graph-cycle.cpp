//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detect(int node,vector<int> adj[],vector<int> &visited){
    visited[node] = 1;
    queue<pair<int,int>> q;
    q.push({node,-1});  
    while(!q.empty()){
        int n = q.front().first;
        int src = q.front().second;
        q.pop();
        for(int i = 0;i<adj[n].size();i++){
            if(!visited[adj[n][i]]){
                q.push({adj[n][i],n});
                visited[adj[n][i]] = 1;
            }
            else if(src != adj[n][i]){
                return true;
            }
        }
    }
    return false;
}
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code 
        vector<int> visited(V,0);
    
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detect(i,adj,visited))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends