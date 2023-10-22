class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k;
        int right = k;
        int minVal = nums[k];
        int maxScore = minVal;

        while(left>0 || right<nums.size()-1) {
            if(left == 0 || (right < nums.size()-1 && nums[right+1] > nums[left-1]))
                right++;
            else 
                left--;
            minVal = min(minVal, min(nums[left], nums[right]));
            maxScore = max(maxScore, minVal*(right-left+1));
        }
        return maxScore;
    }
};