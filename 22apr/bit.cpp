#include <iostream>
#include <queue>
using namespace std;

constexpr int L = 182 + 4;
constexpr int inf = 33124 + 5; // 182 ^ 2 + 5 
bool bitmap[L][L];
int dis[L][L];

queue<pair<int,int>> q;

pair<int,int> pos[4] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0},
};

void bfs(int n, int m){

	while (q.size()) {
		auto [y,x] = q.front();
		q.pop();

		for (int i=0; i<4; i++) {
			auto [y1,x1] = make_pair(y + pos[i].first, x + pos[i].second);
			if (y1 < 0 || x1 < 0  || y1 >= n || x1 >= m) continue;

			if (dis[y1][x1] > dis[y][x] + 1) {
				dis[y1][x1] = dis[y][x] + 1;
				q.push({y1,x1});
				
			}

		}
		
	}

}


int main(){
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n,m;
	char c;
	cin >> n >> m;


	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> c;
			bitmap[i][j] = c - '0';
			if(bitmap[i][j]){
				q.push({i,j});
			} else dis[i][j] = inf;

		}
	}
	bfs(n,m);

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) 
			cout << dis[i][j] << ' ';
		cout << '\n';
		
	}


}
