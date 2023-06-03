#include <bits/stdc++.h>
using namespace std;

struct query{
	int s,e,c;
};
constexpr int L = 1e5 + 10;
map<int,int> px;

vector<int> queries;
vector<query> inter;



/* deszcz.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	/* dni, miasta, liczba zapytan */
	int n,k,q;
	cin >> n >> k >> q;

	/* pocz przedzialu, koniec przedzialu, wartosc do dodania */
	int a,b,c;
	for (int i=0; i<n; i++) {
		cin >> a >> b >> c;
		px[a] += c;
		px[b+1] -= c;

		inter.push_back({a,b,c});
	}
	/* wyszukiwana wartosc */
	while (q--) {
		cin >> a;
		px[a];
		queries.push_back(a);
	}

	int prev = 0;
	for (auto i = px.begin(); i != px.end(); i++) {
		i->second += prev;
		prev = i->second;
	}

	for (auto& x : queries) cout << px[x] << '\n';

}
	
