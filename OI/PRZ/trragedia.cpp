#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int L_N = 1e5 + 7;
constexpr int L_M = 5e5 + 19;

struct button{
	int x,y;
	int nr;

	bool operator<(const button& a) const {
		if (y == a.y) 
			return x < a.x;
		return y < a.y;
	}
} przyciski[L_M];

// y -> x
map<pair<int,int>, pair<int,int>> saved;

/* PRZ.cpp */
int main(){
	/* ios_base::sync_with_stdio(0);
	cin.tie(0); */

	int n,m,x,y;
	cin >> n >> m;

	for (int i=0; i<m; i++){
		cin >> y >> x;

		przyciski[i].y = y;
		przyciski[i].x = x;
		przyciski[i].nr = i + 1;

	}
	sort(przyciski, przyciski+m);
	for (int i=0; i<m; i++) {
		int j=1;
		cout << przyciski[i].y<< ' ' << przyciski[i].x << '\n';
		int kol = i;
		i++;
		while ( i < m && przyciski[i].y == przyciski[kol].y){ 
			cout << '\t'<< przyciski[i].y<< ' ' << przyciski[i].x << '\n';
			pair<int,int> check_saved = {przyciski[kol].x, przyciski[i].x};
			if (saved.find(check_saved) != saved.end()) {
				cout << "TAK\n4\n";
				cout << saved[check_saved].first << ' '<< saved[check_saved].second << ' ' << przyciski[i].nr << ' ' << przyciski[i+j].nr << '\n';
				system(0);
			}
			saved[check_saved] = {przyciski[i].nr, przyciski[kol].nr};
			i++;
		}

	}
	cout << "NIE\n";


}
	
