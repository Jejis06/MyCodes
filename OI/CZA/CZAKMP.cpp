#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int alphabet[26];

string getSuf(string S, int k){
	string out = "";
	for (int i=S.size()-k; i<S.size(); i++)
		out += S[i];
	return out;

}
vector<int> generateLps(string suf){
	vector<int> lps(suf.size());

	int prev=0, i=1;
	while (i < suf.size()) {
		if (suf[i] == suf[prev]){
			prev++;
			lps[i] = prev;
			i++;
		} 
		else if(!prev){
			lps[i] =0;
			i++;
		}
		else {
			prev = lps[prev-1];
		}
	}
	return lps;
}

map<string,char> save = {};
constexpr int L = 1e6;

int main(){
	/* ios_base::sync_with_stdio(0);
	cin.tie(0); */

	string S, Suf;
	int k;
	unsigned long long a,b;
	unsigned long long n;

	cin >> n >> k >> a >> b >> S;
	bool patternFound = false;

	n = S.size();

	string pattern = "";
	string patternBuffer = "";
	string temp = "";
	int patternCounter = 0;


	S.reserve(L);
	Suf.reserve(L);
	pattern.reserve(n);
	patternBuffer.reserve(L);

	int starter;
	vector<int> lps;

	int minPat = 1e6 + 10;

	for (int counter=1; counter <= b; counter++) {
		// get suffix
		Suf = getSuf(S, k);
		starter = 0;


		// use saved values
		if (!save.count(Suf)) {
			lps = generateLps(Suf);

			// find all patterns in string
			int patternInd = 0,
			    strInd = starter;

			while (strInd < S.size()) {
				if (S[strInd] == Suf[patternInd]) {
					patternInd++;
					strInd++;
				}
				if (patternInd == k) {
					int occ = strInd - k;
					if (occ >= S.size() - k) continue;
					alphabet[S[occ+k] - 97]++;
					minPat = min(minPat, occ);

					patternInd = lps[patternInd-1];
				}
				else if (strInd < S.size()) {
					if (S[strInd] != Suf[patternInd]){
						if (patternInd != 0) patternInd = lps[patternInd-1];
						else strInd++;
					}
				}
			}

			// calculate what letter to add
			int maxC = alphabet[0], maxI = 0;
			for (int i=1; i<26; i++) {
				if (alphabet[i] > maxC){
					maxI = i;
					maxC = alphabet[i];
				}
			}
			// clear the table
			for (int i=0; i<26;i++) alphabet[i] = 0;
			save[Suf] = char(97 + maxI);
		}
		// add chosen letter to the new string
		S += save[Suf];
		cout << counter << "/" << b << " + " << save[Suf] << " PAT : " << pattern<< '\n';


		// find pattern O(finalPattern)

		if (counter > n || counter <= k) continue;
		pattern += save[Suf];
		if (pattern.size()%2 != 0 || pattern.size() < k) continue;

		for (int i=0, j=pattern.size()/2; i<pattern.size()/2; i++, j++)
			if (pattern[i] != pattern[j])
				goto bad;
		patternFound = 1;
		break;
		bad:;


		/*
		patternBuffer += save[Suf];

		if (patternBuffer.size() < pattern.size()) continue;
		else if (pattern.size() < patternBuffer.size()){
			int i;
			for (i=0; i < (patternBuffer.size() - pattern.size()) ; i++) pattern += patternBuffer[i];
			temp = patternBuffer;

			i++;
			patternBuffer = "";
			for (;i<temp.size();i++) patternBuffer += temp[i];
		} 
		else if (patternBuffer.size() > k && patternBuffer.size() == pattern.size() && pattern == patternBuffer) {
			patternFound = true;
			break;
		}
		else {
			pattern += patternBuffer[0];
			temp = patternBuffer;
			patternBuffer = "";
			for (int i=1;i<temp.size();i++) patternBuffer += temp[i];
		}
		*/

	}

	if (patternFound) {
		a -= (n+1); b -= (n+1);
		while (a<=k) {
			cout << S[a+n+1];
			a++;
		}
		for (int i=a; i<=b; i++) 
			cout << pattern[i%pattern.size()];
		cout << '\n';
		return 0;
	}
	a -= 1; b -= 1;
	for (int i=a; i<=b; i++) 
		cout << S[i];
	cout << '\n';


}
	


