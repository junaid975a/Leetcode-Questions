//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&grid, int i, int j, int n, int m, vector<vector<bool>>&mark) {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || mark[i][j]==true) return ;

        mark[i][j]=true;
        dfs(grid,i+1,j,n,m,mark);
        dfs(grid,i-1,j,n,m,mark);
        dfs(grid,i,j+1,n,m,mark);
        dfs(grid,i,j-1,n,m,mark);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        // Code here
        int n = grid.size();
        int m = grid[0].size();


        vector<vector<bool>>mark(n,vector<bool>(m,false));

        for(int i=0;i<n;i++) {
            if(grid[i][0]==1 && mark[i][0]==false) {
                dfs(grid,i,0,n,m,mark);
            }
            if(grid[i][m-1]==1 && mark[i][m-1]==false) {
                dfs(grid,i,m-1,n,m,mark);
            }
        }

        for(int i=0;i<m;i++) {
            if(grid[0][i]==1 && mark[0][i]==false) {
                dfs(grid,0,i,n,m,mark);
            }
            if(grid[n-1][i]==1 && mark[n-1][i]==false) {
                dfs(grid,n-1,i,n,m,mark);
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) 
            {
                if(grid[i][j]==1 && mark[i][j]==false) {
                    ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends