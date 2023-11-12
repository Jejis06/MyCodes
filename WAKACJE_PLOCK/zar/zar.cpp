#include <bits/stdc++.h>
#define pb push_back
using namespace std;


typedef long long ll;

/*
ZAchlan goddemit


pokoje -> queue
do-poprawy -> vector
need-change -> queue

*/

stack<int> rooms;
stack<int> needChange;
vector<int> repairable;

constexpr int L = 5e5 + 10;
ll zar[L];
ll pok[L];

void PrintStack(stack<int> s)
{
	if (s.empty())
		return;
	int x = s.top();
	s.pop();
	PrintStack(s);
	cout << x << " ";
	s.push(x);
}

/* zar.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> zar[i];

	for (int i=0; i<n; i++)
		cin >> pok[i];

	sort(pok, pok+n);
	sort(zar, zar+n);

	ll repl = 0;
	ll room;
	ll sum = 0;
	int ind=0;

	for (int i=0; i<n; i++){
		room = pok[i];
		while (ind < n && pok[ind] <= zar[i]) {
			rooms.push(pok[ind]);
			ind++;
		}

		if (!rooms.empty()){
			room = rooms.top(); rooms.pop();
			repairable.pb(zar[i] - room);
		} else {
			needChange.push(zar[i]);
		}
		sum += zar[i];
	}
	while (ind < n) {
		rooms.push(pok[ind]);
		ind++;
	}
	
	
	if (needChange.size() > k) {
		cout << "NIE\n";
		return 0;
	}

	sort(repairable.begin(), repairable.end(), greater<int>());

	while (needChange.size() && rooms.size()) {
		ll l = needChange.top(); needChange.pop();
		ll ex = rooms.top(); rooms.pop();

		sum += ex - l;
		k--;
	}
	if (k > 0) {
		for (int i : repairable){
			sum -= i;
			k--;
			if (k <= 0) break;
		}
	}
	cout << sum << '\n';
}
	
