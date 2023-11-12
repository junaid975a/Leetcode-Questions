class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map< int, vector<int> > graph;

        int n = routes.size();
        for(int i=0;i<n;i++) {
            for(int& stop: routes[i]) {
                graph[stop].push_back(i);
            }
        }
        
        vector<int> vis(n,0);
        queue < int > q;
        q.push(source);
        int buses = 0;

        while(!q.empty()) {
            int size = q.size();

            for(int i=0;i<size;i++) {
                int curCity = q.front();
                q.pop();

                if(curCity==target) return buses;

                for (int i: graph[curCity]) {
                    if(!vis[i]) {
                        vis[i] = 1;
                        for(int next: routes[i]) {
                            q.push(next);
                        }
                    }
                }
            }
            buses++;
        }

        return -1;
    }
};