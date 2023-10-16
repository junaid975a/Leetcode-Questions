class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>pascal;
        for(int i=0;i<=rowIndex;i++) {
            vector<int>row;
            row.push_back(1);
            if(i>=2) {
                vector<int> prev = pascal[i-1];
                for(int j=0;j<prev.size()-1;j++) {
                    row.push_back(prev[j]+prev[j+1]);
                }
            }
            if(i>=1) row.push_back(1);
            pascal.push_back(row);
        }
        return pascal[rowIndex];
    }
};