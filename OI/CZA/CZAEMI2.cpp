#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int N = 1e6 + 10;
constexpr int MUL = 31;
constexpr ll MOD = 1e16 +61;
ll MUL_POW[N];

int n, k;

unordered_map<ll, int[27]> letter;
unordered_map<ll, bool> visited;

int to_letter(int x) { return x - 96; }

void set_MUL_POW() {
    MUL_POW[0] = 1;

    for (int i=1; i<N; i++)
        MUL_POW[i] = (MUL_POW[i-1] * MUL) % MOD;
}

ll make_hash(const string& s, int start, int end) {
    ll res = 0;

    for (int i=start; i<=end; i++)
        res += ( MUL_POW[i-start] * to_letter(s[i]) ) % MOD;

    return res;
}

void set_letter(const string& s) {
    for (int i=0; i<n-k; i++) {
        ll hash = make_hash(s, i, i+k-1);
        int next = to_letter(s[i+k]); 

        letter[hash][next-1] += 1;
        int ind_best = letter[hash][26];

        if (letter[hash][next-1] > letter[hash][ind_best]) 
            letter[hash][26] = next-1;
        else if (letter[hash][next-1] == letter[hash][ind_best]) 
            letter[hash][26] = min(next-1, ind_best);
    }
}

void find_pattern(ll a, ll b, string suf) {
    a = a - n; 
    b = b - n;
    ll it = n - n, hash;

    while (it<=b) {
        hash = make_hash(suf, 0, suf.size()-1);
        int next = letter[hash][26];
        
        if (visited[hash]) break;

        // poczatek sufiksu
        visited[hash] = true;

        // nowy sufiks
        suf.erase(0, 1);
        suf += char(next+97);

        if (it >= a) cout << char(next + 97);
        if (it == b) return;

        it++;
    }

    // zlicz pattern
    string pattern = "";
    pattern.reserve(1e6);
    ll wanted = hash;

    do {
        int next = letter[hash][26];

        suf.erase(0, 1);
        suf += char(next+97);

        hash = make_hash(suf, 0, suf.size()-1);

        pattern += char(next+97);
    } while (hash != wanted);

    ll pattern_start = it - pattern.size();
    a = max(a, it) - pattern_start;
    b -= pattern_start;

    while (a <= b) {
        cout << pattern[a % pattern.size()];
        a++;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set_MUL_POW();

    ll a, b;
    string s;
    cin >> n >> k >> a >> b >> s;
    a -= 1; b -= 1; 

    set_letter(s);

    string suf = "";
    for (int i=s.size()-k; i<s.size(); i++)
        suf += s[i];

    find_pattern(a, b, suf);

    cout << '\n';
}


