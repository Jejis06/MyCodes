#include <bits/stdc++.h>
using namespace std;

typedef unsigned short us;


constexpr int L = 5'001;
constexpr short inf = 30'000;

/* csacademy - graph editor */

us dis[L][L][2];
vector<us> graph[L];
queue<pair<us,bool>> q;

void bfs(us v){

	dis[v][v][0] = 0;
	q.push({v,0});

	while(!q.empty()){
		auto w = q.front();
		q.pop();

		for (auto &u : graph[w.first]){
			if(dis[v][u][!w.second] > dis[v][w.first][w.second] + 1){
				dis[v][u][!w.second] = dis[v][w.first][w.second] + 1;
				q.push({u, !w.second});
			}
		}

	}

}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	/* ilosc portow , ilosc szlakow , ilosc opowiesci */
	int n , m , k;
	cin >> n >> m >> k;

	/* zaladowywanie grafow */
	while(m--){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	/* polaczenia */
	for(int i=1; i<=n; i++) 
		for(int j=1; j<=n; j++) 
			dis[i][j][0] = dis[i][j][1] = inf;

	for(int i=1; i<=n; i++) 
		if(graph[i].size())
		       	bfs(i);

	/* zapytania */
	while(k--){
		int s, e, l;
		cin >> s >> e >> l;
		if(graph[s].size() && graph[e].size() && (int)dis[s][e][l%2] <= l && dis[s][e][l%2] != inf){
			cout << "TAK\n";
		} else cout << "NIE\n";
	}


}
