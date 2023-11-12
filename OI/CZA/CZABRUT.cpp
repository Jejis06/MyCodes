#include <bits/stdc++.h>
#define pb push_back
typedef long long ull;
using namespace std;

int alphabet[26];

string getSuf(string S, int k){
	string out = "";
	for (int i=S.size()-k; i<S.size(); i++)
		out += S[i];
	return out;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string S, Suf;
	int k;
	ull a,b,n;
	bool found = 1;

	cin >> n >> k >> a >> b >> S;


	string add = "";
	for (int counter=0; counter <= b-n; counter++) {
		Suf = getSuf(S, k);

		for (int i=0; i<S.size()-k; i++){
			found = true;
			for (int j=0; j<k; j++) 
				if (S[j+i] != Suf[j]) 
					found = false;
			if (found) alphabet[S[i+k] - 97]++;

		}

		// calculate what letter to add
		int maxC = alphabet[0], maxI = 0;
		for (int i=1; i<26; i++) {
			if (alphabet[i] > maxC){
				maxI = i;
				maxC = alphabet[i];
			}
		}

		// add chosen letter to the new string
		S += char(97 + maxI);
		add += char(97 + maxI);

		// cout << S << ' ' << S[S.size() -1] << '\n';
		// cout <<  add << ' ' << add[add.size() - 1] << '\n';

		// clear the table
		for (int i=0; i<26;i++) alphabet[i] = 0;
	}
	a-=1; b-=1;
	for (int i=a; i<=b; i++) 
		cout << S[i];
	cout << '\n';

}
	
