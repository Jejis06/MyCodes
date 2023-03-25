#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;


void can(int a){
	for(size_t i=0; i<vctr.size(); i++){
		for(size_t j= i+1; j< vctr.size(); j++){
			if(2 * max({vctr[i],vctr[j],a}) < a + vctr[i] + vctr[j]){
				cout << vctr[i] << ' ' << vctr[j] << ' ' << a << '\n';
				exit(0);
			}

		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int a;
	
	while(1){
		cin >> a;
		if(!a) break;

		can(a);
		vctr.push_back(a);
	}
	
	cout << "NIE\n";
}
