#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

constexpr int L = 1 << 17;
int tree[L << 1];

int base = 1;
constexpr int inf = 1e9 + 1e3;


void add(int v, int x) {
	v += base;

	tree[v] += x;
	v /= 2;
	while (v) {
		tree[v] = tree[v * 2];
		tree[v] += tree[v * 2 + 1];
		v /= 2;
	}

}

int query(int a, int b) {
	a += base -1;
	b += base +1;

	int res = 0;

	while (b - a > 1) {
		if (a%2 == 0) res += tree[a + 1];
		if (b%2 != 0) res += tree[b - 1];
		a /= 2;
		b /= 2;
	}
	return res;
}

void display(){
    int lim = 0;
    int x = 1;
    for (int i=1; i< base* 2; i++) {

        cout << tree[i] << ' ';
        lim++;
        if (lim == x){
            x*=2;
            lim=0;
            cout << '\n';
        }
    }
}

/* kon.cpp */
int main(){
	/* ios_base::sync_with_stdio(0);
	cin.tie(0); */

	int n, a, b, x;
	cin >> n;
	while (base < n) base <<= 1;
	display();
	bool q;
	while(1) {
		cin >> q;
		if (q) {
			cout << "dodaj w punkcie\n";
			cin >> a >> x;
			a--;
			add(a, x);
			display();
		}
		else {
			cout << "summa na przedziale\n";
			cin >> a >> b;
			a--;
			cout << query(a,b) << '\n';
			display();
		}

	}


}
	

