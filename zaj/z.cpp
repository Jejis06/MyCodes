#include <bits/stdc++.h>
using namespace std;

#define COMPARE(a,b)\
	(a.first == b.first && a.second == b.second)

#define ADD_TO_PAIR(p,x,y)\
	{p.first + x, p.second + y}

typedef pair<int,int> ipair;

const int N = 1e3;
const int WAYS = 8;
const int ways[WAYS][2] = {
	{1,2}, //x+1 y+2
	{-1,2}, //x-1 y+2

	{1,-2}, //x+1 y-2
	{-1,-2}, //x-1 y-2
	
	{-2,1}, //x-2 y+1
	{2,1}, //x+2 y+1

	{-2,-1}, //x-2 y-1
	{2,-1}, //x+2 y-1
};

int n,m;


struct node{
	int dis=0;
	bool kopiec=false;
}arr[N][N];



bool confirm(ipair coords){

	return !(
		coords.first < 0 || 
		coords.second < 0 ||
		coords.first >= m || 
		coords.second >= n || 
		arr[coords.second][coords.first].kopiec ||
		arr[coords.second][coords.first].dis 
	); 
}


void BFS(ipair start, ipair end){

	if(COMPARE(start,end)){
		cout << 0 << '\n';
		return;
	}

	queue<ipair> q;
	ipair parent ,child;


	q.push(start);

	while(!COMPARE(parent,end) && !q.empty()){
		parent = q.front();
		q.pop();
		
		//check all children of parent
		for(int it=0;it < WAYS;it++){
			child = ADD_TO_PAIR(parent,ways[it][0],ways[it][1]);
			//validate if a child is 
			if(confirm(child)){
				q.push(child);
				arr[child.second][child.first].dis = arr[parent.second][parent.first].dis + 1;
			}

		}


	}

	if(!arr[end.second][end.first].dis) {
		cout << "NIE\n";
		return;
	}
	cout << arr[parent.second][parent.first].dis << '\n';
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	char c;

	ipair start,end;

	cin >> n >> m;

	for(int y=0;y<n;y++){
		for(int x=0;x<m;x++){
			cin >> c;
			if(c == 'x') arr[y][x].kopiec=true;
			else if(c == 'z'){
				start.first = x;
			       	start.second = y;
			}
			else if(c == 'n'){
				end.first = x;
				end.second = y;
			}
		}
	}

	BFS(start, end);

}

/*
      a8"  ad888888b,
    a8"   d8"     "88
  a8"             a8P
a8"            aad8"
"8a            ""Y8,
  "8a             "8b
    "8a   Y8,     a88
      "8a  "Y888888P'   <--- Serduszko dla ciebie <33333
*/
