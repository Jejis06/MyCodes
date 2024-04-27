#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e6;
int kaf[N + 1];
int wyk[N + 1];

int nwd(int a, int b) {
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

/* kaf.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, in;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> in;
		kaf[in]++;
	}
	for (int i=1; i <= N; i++)  {
		if (!kaf[i]) continue;
		for (int j = i; j <= N; j += i) 
			wyk[j] += kaf[i];
	}
	int a, b;
	while(m--) {
		cin >> a >> b;
		cout << wyk[nwd(a, b)] << '\n';
	}
	

}
	
