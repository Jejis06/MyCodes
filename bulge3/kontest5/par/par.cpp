#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int N = 1e5 + 10;
bool arr1[N],
    arr2[N];

int mostleft_0_1[N],
    mostleft_1_1[N],
    mostright_0_1[N],
    mostright_1_1[N];

int mostleft_0_2[N],
    mostleft_1_2[N],
    mostright_0_2[N],
    mostright_1_2[N];

int pref1[N],
    pref2[N];


void solve() {
	int n, m, x;
	cin >> n >> m;
	for (int i=1; i<=n; i++)  {
		cin >> x;
		x %= 2;

		arr1[i] = x;
		pref1[i] = (pref1[i - 1] + x) ;
		if (x == 1) {
			mostleft_0_1[i] = mostleft_0_1[i-1];
			mostleft_1_1[i] = i;
		} else {
			mostleft_0_1[i] = i;
			mostleft_1_1[i] = mostleft_1_1[i-1];
		}

	}
	for (int i=1; i<=m; i++)  {
		cin >> x;
		x %= 2;

		arr2[i] = x;
		pref2[i] = (pref2[i - 1] + x) ;

		if (x == 1) {
			mostleft_0_2[i] = mostleft_0_2[i-1];
			mostleft_1_2[i] = i;
		} else {
			mostleft_0_2[i] = i;
			mostleft_1_2[i] = mostleft_1_2[i-1];
		}
	}

	mostright_0_1[n+1] = 0;
	mostright_1_1[n+1] = 0;

	mostright_0_2[m+1] = 0;
	mostright_1_2[m+1] = 0;

	for (int i=n; i>=1; i--) {
		if (arr1[i] == 1) {
			mostright_0_1[i] = mostright_0_1[i + 1];
			mostright_1_1[i] = i;
		} else {
			mostright_1_1[i] = mostright_1_1[i + 1];
			mostright_0_1[i] = i;
		}
	}
	for (int i=m; i>=1; i--) {
		if (arr2[i] == 1) {
			mostright_0_2[i] = mostright_0_2[i + 1];
			mostright_1_2[i] = i;
		} else {
			mostright_1_2[i] = mostright_1_2[i + 1];
			mostright_0_2[i] = i;
		}

	}

	bool* A;
	bool* B;

	int* prefA;
	int* prefB;

	int* mostLeft_0_A;
	int* mostLeft_1_A;
	int* mostRight_0_A;
	int* mostRight_1_A;

	int* mostLeft_0_B;
	int* mostLeft_1_B;
	int* mostRight_0_B;
	int* mostRight_1_B;

	if (n < m) {
		swap(n, m);
		A = &arr2[0];
		B = &arr1[0];

		prefA = &pref2[0];
		prefB = &pref1[0];

		mostLeft_0_A = &mostleft_0_2[0];
		mostLeft_1_A = &mostleft_1_2[0];
		mostRight_0_A = &mostright_0_2[0];
		mostRight_1_A = &mostright_1_2[0];

		mostLeft_0_B = &mostleft_0_1[0];
		mostLeft_1_B = &mostleft_1_1[0];
		mostRight_0_B = &mostright_0_1[0];
		mostRight_1_B = &mostright_1_1[0];

	} else {
		A = &arr1[0];
		B = &arr2[0];

		prefA = &pref1[0];
		prefB = &pref2[0];

		mostLeft_0_A = &mostleft_0_1[0];
		mostLeft_1_A = &mostleft_1_1[0];
		mostRight_0_A = &mostright_0_1[0];
		mostRight_1_A = &mostright_1_1[0];

		mostLeft_0_B = &mostleft_0_2[0];
		mostLeft_1_B = &mostleft_1_2[0];
		mostRight_0_B = &mostright_0_2[0];
		mostRight_1_B = &mostright_1_2[0];
	}
	// solve
	int res = 0;
	for (int i=1; i<=n-m+1; i++) {
		int s = i,
		    e = i + m - 1,
		    len = m;
		if ((prefA[e] - prefA[s-1]) % 2 == (prefB[m] - prefB[0]) % 2) {
			res = max(res, len); // atutaj chyba mozna zroic brake
			cout << res << '\n';
			return;
		}
		if (A[s] != B[1] || A[s] != B[m] || A[e] != B[1] || A[e] != B[m]) {
			res = max(res, len-1);
			continue;
		}
		int x = 1 - A[s];

		pair<int,int> i1 = {0, 0};
		pair<int,int> i2 = {0, 0};
		pair<int,int> i3 = {0, 0};
		pair<int,int> i4 = {0, 0};
		// duzy blad ale coz
		if (x == 1) {
			if (mostLeft_1_A[e] > s)  i1 = {mostLeft_1_A[e], e - mostLeft_1_A[e]};
			if (mostRight_1_A[s] < e) i2 = {mostRight_1_A[s],mostRight_1_A[s] - s};

			if (mostLeft_1_B[m] > 1)  i3 = {mostLeft_1_B[m], m - mostLeft_1_B[m]};
			if (mostRight_1_B[1] < m) i4 = {mostRight_1_B[1],mostRight_1_B[1] - 1};
		} else {
			if (mostLeft_0_A[e] > s)  i1 = {mostLeft_0_A[e], e - mostLeft_0_A[e]};
			if (mostRight_0_A[s] < e) i2 = {mostRight_0_A[s],mostRight_0_A[s] - s};

			if (mostLeft_0_B[m] > 1)  i3 = {mostLeft_0_B[m], m - mostLeft_0_B[m]};
			if (mostRight_0_B[1] < m) i4 = {mostRight_0_B[1],mostRight_0_B[1] - 1};
		}
		if (i1.second > i2.second) swap(i1, i2);
		if (i3.second > i4.second) swap(i3, i4);
		if (i1.second > i3.second) swap(i1, i3);
		if (i2.second > i4.second) swap(i2, i4);
		if (i2.second > i3.second) swap(i2, i3);

		if (i4.first != 0) {
			int ans = len - min(i4.first, len-i4.first);
			if (A[i+i4.first-1] == B[i4.first])
				res = max(res, ans);
			else res = max(res, ans-1);

		}

	}
	cout << res << '\n';

}


/* par.cpp */
int main(){
	/* ios_base::sync_with_stdio(0);
	cin.tie(0); */

	int q;
	cin >> q;
	while (q--) {
		solve();
	}

}
	
