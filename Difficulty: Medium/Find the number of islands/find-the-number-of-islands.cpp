//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
    
    void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>>&grid,int n,int m){
        
        visited[i][j] = 1;
        int row[] = {-1,0,1,0,1,-1,-1,1};
        int col[] = {0,-1,0,1,1,-1,1,-1};
        for(int k=0;k <8;k++){
            if((i+row[k])<n && (j+col[k])<m && (i+row[k])>=0 && (j+col[k])>=0 && visited[i+row[k]][j+col[k]]==0 && grid[i+row[k]][j+col[k]]=='1'){
                dfs(i+row[k],j+col[k],visited,grid,n,m);
            }
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        // to find the number of island using dfs
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    dfs(i,j,visited,grid,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends