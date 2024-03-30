#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

typedef pair<ll, int> para;

para operator+ (const para& a, const para& b) {
	return {a.first + b.first, a.second + b.second};
}

struct Tree {
	// max size of the tree >= 1e9
	static const int Base = 1 << 30;

	struct Node {
		Node* left;
		Node* right;

		ll sum;
		int amm;
		Node() : left(), right(), sum(), amm(){}
		~Node() {
			delete left;
			delete right;
		}

		Node* Left() {
			if (!left) left = new Node;
			return left;
		}
		Node* Right() {
			if (!right) right= new Node;
			return right;
		}
	} root;

	void insert(Node* curr, int v, ll Dsum, int Damm, int l=0, int r=Base-1) {
		int mid = (l + r) / 2;

		curr->amm += Damm;
		curr->sum += Dsum;

		if (l == r) return;
		if (v > mid) insert(curr->Right() , v, Dsum, Damm, mid+1, r); // right
		else insert(curr->Left() , v, Dsum, Damm, l, mid); // left
	}

	pair<ll, int> query(const Node* curr, int p, int k, int l=0, int r=Base-1){
		if (l > k || r < p || !curr) return {0ll, 0};
		else if (l >= p && r <= k) return {curr->sum, curr->amm};
		else {
			int mid = (r + l) / 2;
			return query(curr->left, p, k, l, mid) + query(curr->right, p, k, mid+1, r);
		}
	}
} tree;

constexpr int N = 1e6 + 10;
int mileage[N];

/* log.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) mileage[i] = -1;

	int active = 0;
	char mode;
	int a,b;

	while (m--) {
		cin >> mode >> a >> b;
		if (mode == 'U') {
			if (mileage[a] != -1) tree.insert(&tree.root ,mileage[a], ll(-mileage[a]), -1);
			if (mileage[a] == -1) active++;

			mileage[a] = b;
			tree.insert(&tree.root, b, ll(b), 1);
		}
		else {
			auto [sum, amm] = tree.query(&tree.root, 0, b);
			
			ll had = sum + (active - amm) * ll(b);
			ll needed = ll(b) * ll(a);

			cout << ( (had >= needed) ? "TAK\n" : "NIE\n" );
		}

	}


}

