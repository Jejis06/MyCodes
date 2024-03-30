#include <bits/stdc++.h>
using namespace std;

string a, b;
bool czyRow(const int& s, const int& e, const int& s1, const int& e1) {
	bool same = true;
	if (s == e) {
		if (a[s] == b[s1]) return 1;
		return false;
	}
	for (int i = 0; i<=(e - s); i++) {
		if (a[s + i] != b[s1 + i]) {
			same = false;
			break;
		}
	}
	if (same) return 1;
	if ((e - s + 1) % 2 != 0) return same;

	int mid1 = (s + e)   / 2,
	    mid2 = (s1 + e1) / 2;

	return (
			(czyRow(s, mid1, s1, mid2) && czyRow(mid1+1, e, mid2+1, e1)) ||
			(czyRow(mid1+1, e, s1, mid2) && czyRow(s , mid1, mid2+1, e1))
       );
}

/* rte1.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	if (a.size() != b.size()) cout << "NIE\n";
	else cout << ((czyRow(0, a.size()-1, 0, b.size()-1)) ? "TAK\n" : "NIE\n");

}
	
