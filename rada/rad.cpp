#include <iostream>
using namespace std;

const int S = 5e4;

int input[S+7];

bool possible(int n, int sum){

	if(!sum%360) return 1;
	if(sum%2) return 0;


	bool** arr = new bool*[361];
	for(int i=0; i<361; i++)
		arr[i] = new bool[n+2];
	arr[0][0] = 1;

	for(int i=1; i<=n; i++){
		for(int j=0; j<361; j++){
			if(arr[j][i-1]){
				//We operate on a circle so negative numbers wrap around as numbers exceeding 360
				int j1 = (j + input[i-1]) % 360,
				    j2 = (j - input[i-1] + 360) % 360;

				//exit if already found answer
				if((!j2 || !j1) && !(n-i)){
					delete[] arr;
					return 1;
				} 

				arr[j1][i] = true;
				arr[j2][i] = true; 
			}

		}
	}
	bool ans = (arr[0][n] || arr[360][n]);
	delete[] arr;

	return ans;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n, sum=0;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> input[i];
		sum += input[i];
	}

	if(possible(n,sum))
		cout << "TAK\n";
	else cout << "NIE\n";
}


