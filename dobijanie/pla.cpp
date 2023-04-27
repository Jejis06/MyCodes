/* plakat konczy sie kiedy trafi na sciane - to znaczy od samego dolu nie mozemy zwiekszyc danej warstwy */
#include <iostream>
#include <stack>
using namespace std;


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n,w,h,res=0;

	cin >> n;
	stack<int> plakaty;
	plakaty.push(0);

	while (n--) {
		cin >> w >> h;


		while (plakaty.top() > h) {
			plakaty.pop();
			res++;
		}
		if (plakaty.top() < h) {
			plakaty.push(h);
		}

	}
	while (!plakaty.empty()) {
		res++;
		plakaty.pop();
	}

	cout << res - 1<< '\n';

}


