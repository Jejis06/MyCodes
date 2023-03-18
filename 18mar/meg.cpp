#include <bits/stdc++.h>
using namespace std;

constexpr int L = 250000 + 10;
//constexpr int treeSize = 1 << 19;
int treeSize=1;

struct Node{
	int len=0;
	vector<int> kids;
	int pre;
	int post;
} graph[L];
//int tree[2 * treeSize];
int* tree = nullptr;

int n;
int t = 0;

void DFS(int ind, int dis=0){
	graph[ind].pre = ++t;
	graph[ind].len= dis;

	for(int j=0; j<graph[ind].kids.size(); j++)
		DFS(graph[ind].kids[j], dis+1);
	graph[ind].post = ++t;
	
	return;
}

void add(int a, int b){
	a += treeSize - 1;
	b += treeSize + 1;

	while(a/2 != b/2){
		if(a%2==0) tree[a+1] += 1;
		if(b&2!=0) tree[b-1] += 1;

		a/=2; b/=2;
	}
}

int get(int a){
	int out = 0;
	a += treeSize;
	while(a){
		out+=tree[a];
		a/=2;
	}
	return out;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a,b,m;
	char Q;
	cin >> n;


	for(int i=0; i<n-1; i++){
		cin >> a >> b;
		graph[a].kids.push_back(b);
	}

	while(treeSize < 2*n) treeSize <<= 1;
	tree = new int[treeSize*2];

	DFS(1);
	cin >> m;

	for(int i=0; i<n+m-1; i++){
		cin >> Q >> a;
		if(Q == 'A'){
			cin >> b;
			if(graph[a].pre > graph[b].pre)
				add(graph[a].pre, graph[a].post);
			else add(graph[b].pre, graph[b].post);
		}
		else{
			cout << graph[a].len - get(graph[a].pre) << '\n';
		}
	}
	delete[] tree;

}
