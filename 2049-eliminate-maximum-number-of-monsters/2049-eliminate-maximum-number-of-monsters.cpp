class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // time = dist / speed;
        priority_queue<double, vector<double>, greater<double> > pq;
        int n = dist.size();

        for(int i=0;i<n;i++) {
            pq.push(double(dist[i])/speed[i]);
        }

        int time = 0;
        while(!pq.empty()) {
            if(pq.top()<=time)
                return time;
            time++;
            pq.pop();
        }
        return n;
    }
};