class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k==1) return max(arr[0],arr[1]);
        int mx = *max_element(arr.begin(),arr.end());
        if(k>=arr.size()) return mx;
        int winner = arr[0];
        int count = 0;
        int n = arr.size();
        
        for(int i=1;i<n;i++) {
            if(winner > arr[i])
                count++;
            else {
                winner = arr[i];
                count = 1;
            }
            if(count==k)
                return winner;
        }
        return winner;
    }
};