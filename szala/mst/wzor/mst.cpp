#include <bits/stdc++.h>
using namespace std;

struct EDGE{
    int a, b, c;

    bool operator<(const EDGE& x) const{
        return c < x.c;
    }

};

int n, m;

vector< int > p;
vector< EDGE > edge;

int get(int a){
    return p[ a ] = (p[ a ] == a ? a : get(p[ a ]));
}

int main(){

    cin >> n >> m;

    p.resize(n + 1);

    for(int i = 0; i <= n; ++i){
        p[ i ] = i;
    }

    for(int i = 0; i < m; ++i){
        int a, b, c; cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }

    sort(edge.begin(), edge.end());

    int suma = 0;

    for(auto [a, b, c] : edge){
        int A = get(a);
        int B = get(b);

        if(A == B){
            continue;
        }

        p[ A ] = B;
        suma += c;
    }

    cout << suma << '\n';

    return 0;
}

