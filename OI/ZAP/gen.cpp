#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> para;


bool comp(para a, para b){
	return a.second > b.second;
}
bool comp2(para a, para b){
	return a.first < b.first;
}

int main(){
	int n;
	cin >> n;
	int a,b;
	vector<pair<int,int>> vec;

	for (int i=0; i<n; i++){
		cin >> a >> b;
		vec.push_back({b,a});
	}

	sort(vec.begin(), vec.end(), comp);
	sort(vec.begin(), vec.end(), comp2);

	for (int i=0; i<vec.size(); i++){

		auto pr = vec[i];
		for (int j=1; j<=vec.back().first; j++){
			if (pr.second <j && pr.first >= j ) cout << '_';
			else cout << ' ';
		}
		cout << pr.second << ' ' << pr.first;
		cout << '\n';
	}


}
