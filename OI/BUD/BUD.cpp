#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

constexpr int L = 1504;
struct Stripe{
	int x, y;
	int len;
};

int col[L];
int wier{};

Stripe maxWier[2];
Stripe maxCol[2];

void insert(int& l, int x, int y, Stripe *arr) {
	if (l > arr[0].len) {
		arr[1] = arr[0];
		arr[0] = {x, y, l};
	}
	else if (l > arr[1].len)
		arr[1] = {x, y, l};
}

bool czyPok(Stripe& wier, Stripe& kol) {
	return (
		wier.y >= (kol.y - kol.len + 1) &&
		wier.y <= kol.y &&
		kol.x >= (wier.x - wier.len + 1) &&
		kol.x <= wier.x
	);
}

int maxResFromSlices(Stripe& wier, Stripe& col) {

	int wierA = wier.x - col.x;
	int wierB = wier.len - wierA - 1;

	int colA = col.y - wier.y;
	int colB = col.len - colA - 1;

	return max({
			min(wierA+wierB+1, max(colA, colB)),
			min(colA+colB+1, max(wierA, wierB)),
			min(max(wierA, wierB),max(colA, colB))
	});

}

int maxPair(Stripe& A, Stripe& B, int res){
	if (A.len == B.len) return max(res, A.len);
	return max(
		res,
		max(
			max(A.len, B.len)/2,
			min(A.len, B.len)
		)
	);
}


/* BUD.cpp */
int main(){
	/* ios_base::sync_with_stdio(0);
	cin.tie(0); */
	
	int n,m;
	char c;
	cin >> n >> m;


	for (int y=1; y<=n; y++) {
		for (int x=1; x<=n; x++) {
			cin >> c;
			if (c == '.') {
				col[x]++;
				wier++;
			} else {
				insert(col[x],x,y-1,maxCol);
				insert(wier,x-1,y,maxWier);

				wier = 0;
				col[x] = 0;
			} 
			if (x == n) insert(wier,x,y,maxWier);
			if (y == n) insert(col[x],x,y,maxCol);
		}
		wier = 0;
	}

	int res = 0;
	int tableMax = max({
			maxWier[0].len,
			maxWier[1].len,
			maxCol[0].len,
			maxCol[1].len
		}
	);


	if (m == 1) {
		cout << tableMax << '\n';
		return 0;
	}

	res = maxPair(maxWier[0], maxWier[1], res);
	res = maxPair(maxCol[0], maxCol[1], res);


	if (res == tableMax) {
		cout << res << '\n';
		return 0;
	}
	if (!czyPok(maxWier[0], maxCol[0])) res = maxPair(maxWier[0], maxCol[0], res);
	else res = max(res, maxResFromSlices(maxWier[0], maxCol[0]));

	cout << res << '\n';
}
	
