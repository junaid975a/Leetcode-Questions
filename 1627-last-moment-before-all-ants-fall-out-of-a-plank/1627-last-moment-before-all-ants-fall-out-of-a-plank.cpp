class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int x = 0;
        int y = 0;
        if(left.size()==0) {
            x = *min_element(right.begin(), right.end());
            return n-x;
        } else if(right.size()==0) {
            y = *max_element(left.begin(), left.end());
            return y;
        }
        y = *max_element(left.begin(), left.end());
        x = *min_element(right.begin(), right.end());
        return max({y-x, n-x, y});
    }
};