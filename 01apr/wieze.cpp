#include <bits/stdc++.h>
using namespace std;

/* slowo i jego ilosc w tekscie */
map<string,int> mapa;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	int n;
	size_t ans=0;

	cin >> n;
	while(n--){
		cin >> input;
		mapa[input]++;
	}

	/* maksymalnie O(n * log(n)) operacji */
	/* laczenie wszystkich par takich samych slow  na raz */
	for(auto &it : mapa){
		ans = max(ans, it.first.size());
		if(it.second > 1){
			mapa[it.first + it.first] += it.second/2;
			it.second %= 2;
		}
	}
	cout << ans << '\n';
}	
