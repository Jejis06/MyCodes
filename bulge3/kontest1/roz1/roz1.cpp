#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

constexpr int N = 1e6 + 10;
ll tree[N];
int m;
int last = 0,
    added = 0;

void update(long long val, int ind) {
	while (ind <= m) {
		tree[ind] += val;
		ind += (ind & (-ind));
	}
}
long long query(int ind) {
	long long sum = 0;
	while (ind > 0) {
		sum += tree[ind];
		ind -= (ind & (-ind));
	}
	return sum;
}
long long sum(int a, int b) {
	return query(b) - query(a - 1);
}

void inicjuj(int x) {
	m = x;
	// inicjacja
	return;
}
void dodaj(int k) {
	if (last == -1) {
		last = 1;
		update((long long)k, 1);
		added++;
		return;
	}
	last++;
	added = min(m, added+1);

	if (last > m) last = 1;

	int lastSum = sum(last, last);
	update(uint64_t(k - lastSum), last);
	return;
}

void koryguj(int i, int k) {
	int ind = last - i + 1;
	if (ind < 1) ind += m;
	update((long long)k, ind);
}

long long suma(int i) {
	long long res = 0;
	int ind = last - i + 1;
	if (ind > 0) {
		return sum(ind, last);
	} else if (m + ind == last) {
		return query(m);
	} else {
		return query(last) + sum(m + ind, m);
	}
}
