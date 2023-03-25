#include <bits/stdc++.h>
using namespace std;


constexpr int N = 200 + 5;
int desc[N][N];
int n;

bool edge(int a, int b){
	for(int c=1; c<=n; c++){
		if(c==a||c==b) continue;
		if(desc[a][c] + desc[c][b] == desc[a][b]) return false;
	}
	return true;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> desc[i][j];
		}

	}

	for(int i=1; i<=n; i++){
		for(int j=i + 1; j<=n; j++){
			if(edge(i,j)) cout << i << ' '<< j << '\n';
		}

	}

}
