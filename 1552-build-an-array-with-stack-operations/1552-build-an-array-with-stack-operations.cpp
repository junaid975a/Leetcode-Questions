class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int i=0;
        int cur = 1;
        while(i<target.size() && cur<=n) {
            ans.push_back("Push");
            if(target[i]==cur) {
                i++;
                cur++;
            } else {
                ans.push_back("Pop");
                cur++;
            }
        }
        return ans;
    }
};