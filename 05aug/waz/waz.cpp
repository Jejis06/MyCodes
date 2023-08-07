#include <bits/stdc++.h>
using namespace std;

constexpr int M_S = 510;
constexpr int L = 5e5 + 10;

int board[M_S][M_S];
int mvs[L];

	/* x, y */
map<char,pair<int,int>> coordinates = {
	{'N', { 0,-1}},
	{'W', {-1, 0}},
	{'S', { 0, 1}},
	{'E', { 1, 0}},
};


/* waz.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	/* wymiary planszy */
	int w,h;

	cin >> h >> w;
	for (int i=1; i<=h; i++)
		for (int j=1; j<=w; j++)
			cin >> board[i][j];

	/* ruchy weza, dlugosc */
	int n,m;
	cin >> n >> m;

	int x=1, y=1;
	char a;

	if (board[y][x] <= m) mvs[board[y][x] - 1]++;

	for (int mv=1; mv<=n; mv++) {
		cin >> a;
		auto& [dx, dy] = coordinates.at(a);
		y += dy;
		x += dx;

		if (board[y][x] <= m && mv + board[y][x] - 1 <= n) 
			mvs[mv + board[y][x] - 1]++;
		cout << mvs[mv] << ' ';
	}
}
