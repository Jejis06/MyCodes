#include <bits/stdc++.h>
#define pb push_back
using namespace std;


/* 				wynik to liczba spojnych 		*/

constexpr int L = 1e6 + 10;
struct node{
	bool vis=0;
	vector<int> conn;
} graph[L];


void dfs(int v){
	graph[v].vis = 1;
	for (int child : graph[v].conn){
		if (graph[child].vis) continue;
		dfs(child);
	}
}


/* skar.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,b;
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> b;
		graph[b].conn.pb(i);
		graph[i].conn.pb(b);
	}
	int res = 0;
	for (int i=1; i<=n; i++){
		if (!graph[i].vis) {
			dfs(i);
			res++;
		}
	}
	cout << res << '\n';

}
	
