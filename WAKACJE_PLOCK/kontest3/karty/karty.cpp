#include <bits/stdc++.h>
#define pb push_back
using namespace std;


/* karty.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	char mode;
	queue<int> q;
	stack<int> s, temp;

	cin >> n >> k;

	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i=1; i<=n; i++){
		q.push(i);
	}

	while (k--) {
		cin >> mode;
		int f = q.front(); q.pop();
		if (mode == 'A') {
			s.push(f);
		}
		else {
			s.push(q.front());
			q.pop();
			q.push(f);
		}
		if (q.size() <= 1) {
			while (s.size()) {
				int t = s.top(); s.pop();
				temp.push(t);
			}
			while (temp.size()) {
				q.push(temp.top());
				temp.pop();
			}
		}
		
	}
	cout << q.front();

}
	
