#include <bits/stdc++.h>
using namespace std;

/* code from leetcode */
class Solution {
private:
	static const int L = 2000;
	vector<int> graph[L];
	int parents[L];

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	    vector<int> out;

	    for (auto& preq : prerequisites) {
		    graph[preq[1]].push_back(preq[0]);
		    parents[preq[0]]++;
	    }

	    queue<int> q;

	    for (int i=0; i<numCourses; i++) 
		    if (parents[i] == 0)
			    q.push(i);

	    if (q.empty()) return out;
	    while (q.size()) {
		   int node = q.front();
		   q.pop();

		   out.push_back(node);

		   for (int& child : graph[node]) {
			   parents[child]--;
			   if (parents[child] == 0)
				   q.push(child);
		   }
	    }
	    if (out.size() != numCourses) 
		    return vector<int>();
	    return out;
    }
};
