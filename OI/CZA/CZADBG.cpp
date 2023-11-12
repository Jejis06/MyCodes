#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
 
string getSuf(const string &S, const int &k){
	string out = "";
	for (int i=S.size()-k; i<S.size(); i++)
		out += S[i];
	return out;
 
}
 
struct Char {
	int code = 0;
	bool vis=false;
	ll ind = -1;
};
 
map<string, int[26]> inputMap;
map<string, Char> sub;
 
int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
 
	string S;
	int k;
	ll a,b, n;
 
	ll bestCurrent, bestSaved;
	string substring = "",
	       suf = "";
	int c;
 
	cin >> n >> k >> a >> b >> S;
 
	for (int i=0; i<n-k; i++) {
		substring = "";
		for (int j=0; j<k; j++) substring += S[i + j];
 
		c = S[i + k] - 97;
 
		bestCurrent = ++inputMap[substring][c];
		bestSaved = inputMap[substring][sub[substring].code];
 
		if ((bestSaved < bestCurrent) || (bestSaved == bestCurrent && sub[substring].code > c))
			sub[substring].code = c;
 
 
	}
 
 
	ll ind=0;
	int cnt = 0;
	string pat = "";
	int ps,pe;
 
	cout << S << '\n';
	for (; ind < b - n; ind++) {
		suf = getSuf(S, k);
 
		S += char(sub[suf].code + 97);
 
		if (sub[suf].vis && cnt == 0) {
			for (int i=sub[suf].ind + n; i<=ind +n -1; i++)
				pat += S[i];
			ps = sub[suf].ind + n;
			pe = ind - 1 + n;
			cnt++;
		}
		sub[suf].vis = 1;
		sub[suf].ind = ind;
	}
	cout << S << '\n';
	for (int i=0;i<S.size();i++){
		if (i == a-1 || i == b-1)  cout << "*";
		else if (i == ps|| i ==pe)  cout << "^";
		else cout << "-";
	}
	cout << '\n';
 
	cout << "PAT " << pat << '\n';
 
 
 
	int ta = a, tb =b;
	a--;
	b--;
	while (a <= b/* && a < ind*/) {
		cout << S[a++];
	}
	cout << "\ngenerated\n";
 
	int base = ps;//sub[suf].ind;
	a = ta -1;
	b = tb -1;
 
	for (int i=a-base; i<=b-base; i++){
		cout << S[ps + i % (pe - ps + 1)];
	}
 
	cout << '\n';
}
