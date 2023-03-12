#include <bits/stdc++.h>
using namespace std;

const int S = 1e6;

bool kupiony[S+5];
bool bon[S+5];
int ostatni[S+5];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int m,k,dni,kupione;
	long long klient=0;
	vector<long long> wygrani; 

	cin >> m;
	while(m--){
		cin >> k;
		bon[k] = 1;
	}


	cin >> dni;

	while(dni--){
		cin >> k;
		kupione = 0;

		while(kupione < k){
			ostatni[k] += k;
			if(ostatni[k] > S) break;
			if(kupiony[ostatni[k]]) continue;

			kupiony[ostatni[k]] = 1;
			kupione++; klient++;


			if(bon[ostatni[k]])
				wygrani.push_back(klient);
		}
		klient += k - kupione;


	}
	cout << wygrani.size() << '\n';
	for(auto w : wygrani)
	       	cout << w << '\n';


	
}
