#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

bool vis[1003];
int sp[1003];
vector<int> post;
vector<int> graf[1003], grafRev[1003];

void dfs1(int v){
	vis[v] = 1;
	for (int child : graf[v]) 
		if (!vis[child]) 
			dfs1(child);
	post.pb(v);
}
void dfs2(int v, int org) {
	vis[v] = 0;
	sp[v] = org;
	for (int child : grafRev[v]) 
		if (vis[child])
			dfs2(child, org);

}

/* sss.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	int color = 0;
	cin >> n >> m;
	for (int i=1; i<=m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		grafRev[b].pb(a);
	}
	for (int i=1; i<=n; i++) 
		if (!vis[i])
			dfs1(i);
	for (int i=post.size()-1; i>=0; i--) 
		if (vis[post[i]])
			dfs2(post[i], ++color);
	cout << "ilosc spojnych " << color << '\n';

}
	
