#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;


constexpr int L = 1e5 + 10;
int id[L];

int find(int x) {
	if (id[x] == x) return x;
	return id[x] = find(id[x]);
}

void Union(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	id[b] = a;
}

/* A.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	for (int i=0; i<n; i++){
		id[i] = i;
	}
	string inst;
	int a,b;
	for (int i=0; i<m; i++){
		cin >> inst >> a >> b;
		if (inst[0] == 'u') 
			Union(a,b);
		else {
			if (find(a) == find(b))
				cout << "YES\n";
			else cout << "NO\n";

		}

	}

}
	
