#include <bits/stdc++.h>
using namespace std;

/* optimiznig for fun */
class Array{
	private:
		int id;
		int* ids;
		int* content;

	public:
		Array(int n) : id(0) {
			ids = new int[n];
			content = new int[n];
		}
		~Array() {
			delete[] ids;
			delete[] content;
		}

		int& operator[] (int ind) {
			if (id != ids[ind]) {
				content[ind] = 0;
				ids[ind] = id;
			}
			return content[ind];
		}

		void clear() {id++;}
};


/* code from leetcode */ 
class Solution {
private:
	static const int L = 1e5 + 10;
	bool vis[L];

public:
	int longestCycle(vector<int>& graph) {
		int gc = -1;
		Array candidate(graph.size());

		for (int i=0; i<graph.size(); i++) {
			if (vis[i]) continue;

			
			int cl = 0;
			int j = i;
			int candidateSize=0;

			for (; j != -1 && !vis[j]; j = graph[j]){
				vis[j] = 1;
				candidate[candidateSize] = j;
				candidateSize++;
			}
			if (j == -1) continue;

			for (int jj=0; jj<candidateSize; jj++){
				if (candidate[jj] == j) {
					gc = max(candidateSize - jj, gc);
					break;
				}
			}

		}
		return gc;
	}
};
