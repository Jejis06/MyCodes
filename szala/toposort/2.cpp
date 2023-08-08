#include <bits/stdc++.h>
/* code from leetcode */

class Solution {
private:
    static const int L = 2e3 + 10;
    std::vector<int> graph[L];
    int parents[L];

public:
    bool canFinish(int nc, std::vector<std::vector<int>>& preq) {

        for (auto& x: preq) {
            graph[x[1]].push_back(x[0]);
            parents[x[0]]++;
        }

	std::queue<int> q;

        int vis=0;
        for (int i=0; i<nc; i++){
            if (parents[i] == 0) {
                q.push(i);
                vis++;
            }
        }
        
        if (q.empty()) return false;
        while (q.size()) {
            int node = q.front();
            q.pop();

            for (int& children : graph[node]) {
                parents[children]--;

                if (parents[children] == 0){
                    q.push(children);
                    vis++;
                }
            }
        }

        return (vis == nc);
    }
};
