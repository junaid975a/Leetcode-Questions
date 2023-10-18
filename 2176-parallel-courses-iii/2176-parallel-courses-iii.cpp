class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>>graph;
        vector<int>indegree(n+1,0);

        for(auto& relation: relations) {
            graph[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }

        vector<int>dist = time;
        dist.insert(dist.begin(),0);
        queue<int> q;
	    for(int i = 1; i <= n; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }

        while(!q.empty()) {
            int cur_course = q.front();
            q.pop();

            for(int next_course: graph[cur_course]) {
                dist[next_course] = max(dist[cur_course]+time[next_course-1], dist[next_course]);
                indegree[next_course]--;
                if(indegree[next_course]==0) {
                    q.push(next_course);
                }
            }
        }
	    

	    
	    return *max_element(dist.begin(),dist.end());
    }
};