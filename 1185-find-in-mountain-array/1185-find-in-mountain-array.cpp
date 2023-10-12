/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // binary search to find peak
        int start = 0;
        int end = mountainArr.length()-1;
        int mid = start + (end-start)/2;
        while(start<end) {
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) {
                start = mid+1;
            } else {
                end = mid;
            }
            mid = start + (end-start)/2;
        }
        // now mid is the position for peak.
        // cout<<mountainArr.get(mid);
        int peak = mid;
        int left = -1, right = -1;

        // to find the left index
        start = 0;
        end = peak;
        mid = start + (end-start)/2;
        while(start<=end) {
            if(mountainArr.get(mid)==target) {
                left = mid;
            }  
            if(mountainArr.get(mid)<target)
                start = mid+1;
            else end = mid-1;
            mid = start + (end-start)/2;
        }
        start = peak;
        end = mountainArr.length()-1;
        mid = start + (end-start)/2;
        // to find the right index
        while(start<=end) {
            if(mountainArr.get(mid)==target)
                right = mid;
            if(mountainArr.get(mid)>target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        // cout<<left<<" "<<right;
        if(left==right) return left;
        if(left!=-1) return left;
        return right;
    }
};