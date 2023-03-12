#include <bits/stdc++.h>
using namespace std;

const int S = 2e5 + 10;

struct node{
	int id=0;// -1 - szefc |  1 - krawiec | 0 -empty
	vector<int> sasiedzi;
}arr[S];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n,m;
	cin >> n >> m;

	for(int i=0; i<m; i++){
		int in,out;
		cin >> in >> out;
		arr[in].sasiedzi.push_back(out);
		arr[out].sasiedzi.push_back(in);
	}

	for(int i=1; i<=n; i++){
		if(arr[i].sasiedzi.empty()){
			cout << "NIE\n";
			return 0;
		} 
		if(arr[i].id != 0) continue; //juz ustawione 
		arr[i].id = 1;

		for(auto sasiad : arr[i].sasiedzi){
			if(arr[sasiad].id != 0) continue; //juz ustawione
			arr[sasiad].id = -arr[i].id;
		}
	}
	
	cout << "TAK\n";
	for(int i=1; i<=n;i++){
		if(arr[i].id == -1) cout << 'S';
		else cout << 'K';
		cout<< '\n';
	}
}
