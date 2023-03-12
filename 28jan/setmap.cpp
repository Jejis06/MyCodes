#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n,it;

/* set */
	set<int> track;

	cin >> n;

	while(n--){
		cin >> it;
	       	track.insert(it);

		cout << track.size() << '\n';
	}
/* map 
	map<int,bool> track;
	
	cin >> n;

	while(n--){
		cin >> it;
		track[it];

		cout << track.size() << '\n';

	}
*/
}
