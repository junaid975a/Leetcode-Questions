class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n,0);

        // element, index
        priority_queue< pair<int,int>> pq;

        for(int i=0;i<n;i++) {
            while(!pq.empty() && i-pq.top().second>k) {
                pq.pop();
            }
            int mx = 0;
            if(!pq.empty()) mx = max(mx,pq.top().first);
            dp[i] = nums[i] + mx;
            pq.push({dp[i],i});
        }
        int mx = *max_element(dp.begin(),dp.end());
        return mx; 
    }
};