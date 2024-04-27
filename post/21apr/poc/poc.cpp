#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e6 + 10;

int surowce[N];
int wymagania[N];

/* poc.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int miasta, okrazenia, sur, last_c;

	cin >> miasta;
	for (int i=1; i<=miasta; i++)
		cin >> surowce[i];
	for (int i=1; i<=miasta; i++) {
		cin >> sur;
		wymagania[sur] = i;
	}

	int cel;
	okrazenia = 1;
	last_c = 0;

	for (int i=miasta; i>=2; i--) {
		cel = wymagania[ surowce[i] ];
		if (cel < last_c) okrazenia++;
		last_c = cel;
	}
	cel = wymagania[ surowce[1] ];
	if (cel < last_c && cel > 1)
		okrazenia++;

	cout << okrazenia << '\n';
}
	
