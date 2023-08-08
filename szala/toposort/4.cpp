#include <bits/stdc++.h>
using namespace std;

/* code from leetcode */ 
class Solution {
private:
	static const int L = 1e4 + 10;
	vector<int> graph[L];
	int parents[L];
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& preGraph) {

	    for (int parent=0; parent<preGraph.size(); parent++) {
		    for (int& child : preGraph[parent]){
			    graph[child].push_back(parent);
			    parents[parent]++;
		    }
	    }

	    queue<int> q;

	    for (int i=0; i<preGraph.size(); i++)
		    if (parents[i] == 0)
			    q.push(i);

	    vector<int> res;

	    if (q.empty()) return vector<int>();
	    while (q.size()) {
		    int node = q.front();
		    res.push_back(node);
		    q.pop();

		    for (int& child : graph[node]) {
			    parents[child]--;
			    if (parents[child] == 0) {
				    q.push(child);
			    }
		    }
	    }

	    sort(res.begin(), res.end());
	    return res;
        
    }
};
