#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;


int id[10];
int conn[10];

int find(int x){
	if (id[x] == x) return x;
	return id[x] = find(id[x]);
}
int Union(int a, int b){
	a = find(a); b = find(b);
	if (conn[a] > conn[b])
		swap(a,b);
}


/* wzor.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

}
	
