#include <iostream>
using namespace std;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n,a,o=0;
	cin >> n;

	while(n--){
		cin >> a;
		if(a==1) o++;
	}

	/* koszt */
	cout << max(0, 2-o) << '\n';
	/* opis drzewa */
	cout << 2 << '\n' << 1 << ' ' << 2 << '\n';
	
}
