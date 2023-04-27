#include <iostream>
using namespace std;

typedef long long ll;

int ans = 0;
ll n;

void gen(ll num=0, int remainder=13, bool e13=false){
	if(num > n) return;
	if(remainder < 0) return;

	if(remainder == 0 && e13) ans++;
	for (int dig=!num; dig<=9; dig++) {

		bool found13 = e13;
		if(num%10 == 1 && dig == 3) found13=true;

		gen(num * 10 + dig, remainder - dig, found13);
	} 

}


int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	cin >> n;
	gen();
	cout << ans << '\n';

}
