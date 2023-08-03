#include <bits/stdc++.h>
using namespace std;


template <typename T>
class Array{
	private:
		int id;
		vector<T> vals;
		vector<int> ids;
	public:
		Array(int n) : id(0) , vals(n) , ids(n) {}

		T& operator[] (int ind) {
			if (ids[ind] != id){
				vals[ind] = 0;
				ids[ind] = id;
			} 
			return vals[ind];
		}
		void clear(){ id++; } /* super szybkie czyszczenie tablice B) */
};

constexpr int L = 1e6 + 10;
bool sito[L];
vector<int> pola;
vector<int> pierwsze;

/* klasy.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	char a;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> a;
		if (a == '#') pola.push_back(i);
	}

	if (pola.size() < 2) {
		cout << pola.size() << '\n';
		return 0;
	}


	int res=0, max_res=0;

	for (int i=2; i<=n; i++) {
		if (sito[i]) continue;
		pierwsze.push_back(i);
		for (int j=2*i; j<=n; j+=i) 
			sito[j] = 1;
	}

	Array<int> skoki(pierwsze.back());

	for (int& prop : pierwsze) {

		if (prop > 2*n/pola.size()) break;
		res = 0;
		skoki.clear();
		for (int& pole: pola){
			skoki[pole % prop]++;
			res = max(res, skoki[pole % prop]);
		}
		max_res = max(res, max_res);
	}
	cout << max(1,max_res) << '\n';
}
	
