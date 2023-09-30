//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void modify(vector<vector<int> > &matrix, int i, int j, int n, int m) {
        int r = i, c = j;
        // col first
        while(r<n) {
            matrix[r][c] = 1;
            r++;
        }
        r = i;
        while(r>=0) {
            matrix[r][c] = 1;
            r--;
        }
        // row
        r = i;
        while(c<m) {
            matrix[r][c] = 1;
            c++;
        }
        c = j;
        while(c>=0) {
            matrix[r][c] = 1;
            c--;
        }
    }
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        vector<vector<int> >dummy = matrix;
        int n = dummy.size();
        int m = dummy[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(dummy[i][j]==1) {
                    modify(matrix,i,j,n,m);
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends