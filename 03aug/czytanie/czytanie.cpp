#include <bits/stdc++.h>
using namespace std;


/* czytanie.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, ans=0;
	float d;
	cin >> n;

	while (n--) {
		cin >> d;
		if (d > 10) 
			ans += ceil(d/10) - 1;
	}
	cout << ans << '\n';


}
	
