#include <bits/stdc++.h>
using namespace std;

/* code from leetcode */ class Solution { private:
	static const int L = 5e4 + 10;
	vector<int> graph[L];
	int maxPendingTime[L], parents[L];

public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& localTime) {

	    for (auto& preq : relations) {
		    graph[preq[0]].push_back(preq[1]);
		    parents[preq[1]]++;
	    }
	    queue<int> q;

	    for (int i=1; i<=n; i++) 
		    if (parents[i] == 0) 
			    q.push(i);

	    int maxTime = 0;
	    while (q.size()) {
		    int node = q.front(); 
		    q.pop();

		    int ind = node - 1;
		    ind = (ind > 0)? ind : 0;

		    localTime[ind] += maxPendingTime[ind];
		    maxTime = max(localTime[ind], maxTime);

		    for (int& child : graph[node]) {
			    parents[child]--;
			    maxPendingTime[child - 1] = max(maxPendingTime[child - 1], localTime[ind]);

			    if (parents[child] == 0) 
				    q.push(child);
		    }

	    }
	    return maxTime;
    }
};
