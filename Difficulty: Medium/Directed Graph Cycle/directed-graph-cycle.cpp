//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(int i,vector<int> arr[],vector<int> &visited,vector<int> &path,int nodes){
        visited[i] =  1;
        path[i] = 1;
        for(int j=0;j<arr[i].size();j++){
            if(!visited[arr[i][j]]){
                if(dfs(arr[i][j],arr,visited,path,nodes)) return true;
                
            }  
            else if(path[arr[i][j]]) return true;      
        }
        path[i] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> arr[]) {
        // code here
        
        vector<int> visited(n,0);
        vector<int> path(n,0);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(i,arr,visited,path,n)) return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends