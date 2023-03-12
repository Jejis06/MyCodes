#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n, input;
	cin >> n;

	bool** arr = new bool*[361];
	for(int i=0; i<361; i++)
		arr[i] = new bool[n+2];
	arr[0][0] = 1;

	for(int i=1; i<=n; i++){
		cin >> input;
		for(int j=0; j<361; j++){
			if(arr[j][i-1]){
				//We operate on a circle so negative numbers wrap around as numbers exceeding 360
				int j1 = (j + input) % 360,
				    j2 = (j - input + 360) % 360;

				//exit if already found answer
				if((!j2 || !j1) && !(n-i)){
					goto possible;
				} 

				arr[j1][i] = true;
				arr[j2][i] = true; 
			}

		}
	}

	if(arr[0][n]) goto possible;
	else cout << "NIE\n";

	delete[] arr;
	return 0;

	possible:
		cout << "TAK\n";
		delete[] arr;
}


