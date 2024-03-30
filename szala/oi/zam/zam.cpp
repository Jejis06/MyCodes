#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

struct Ver {
	int pocz, kon, id;
};
struct Bounds {
	int x1, y1, x2, y2;
};
struct Rect {
	Ver right, bottom;
	Bounds bounds;
	int id;
};

constexpr int M = 1e9 + 10;
constexpr int N = 1e6 + 10;

vector<int> graph[N];
bool vis[N];
int dis[N];

unordered_map<int, vector<Ver>> 
	bottomSlices,
	rightSlices;

vector<Rect> boxes;
vector<Ver> traps;
vector<pair<int,int>> trapX, trapY;


bool cmp_Ver(const Ver& a, const Ver& b) {
	if (a.kon == b.kon) return a.pocz < b.pocz;
	return a.kon < b.kon;
}

bool check(const int& x, const Ver& v) {
	return (v.pocz <= x && x <= v.kon);
}


int bs_start(const vector<Ver>& arr, const int& x) {
	int l = 0, r = arr.size() - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (x <= arr[mid].kon) 
			r = mid;
		else l = mid + 1;
	}
	while (l > 0 && arr[l].kon > x)
		l--;
	while (l+1 < arr.size() && x >= arr[l+1].pocz) 
		l++;
	return l;
}
int bs_end(vector<Ver>& arr, int x) {
	int l = 0, r = arr.size() - 1;

	while (l < r) {
		int mid = (l + r) / 2;
		if (x <= arr[mid].pocz) 
			r = mid - 1;
		else l = mid + 1;
	}
	while (l > 0 && arr[l].pocz > x)
		l--;
	while (l+1 < arr.size() && x >= arr[l+1].pocz) 
		l++;
	return l;
}




bool inBounds(const Bounds& bounds, int x, int y) {
	return (bounds.x1 <= x && x <= bounds.x2) &&
		(bounds.y1 <= y && y <= bounds.y2);
}

int checkId(int x, int y) {
	for (Rect box : boxes) {
		if (inBounds(box.bounds, x, y)) {
			// cout << x << '='<<y <<')' << box.bounds.x1 << '_' << box.bounds.y1 << '_' <<box.bounds.x2 << '_' << box.bounds.y2<<'|';
			// cout << "ret";
			return box.id;
		}
	}
	return -1;
}


bool in(int v) {
	auto it1D = upper_bound(trapX.begin(), trapX.end(), make_pair(boxes[v].bounds.x1, -M));
	auto it2D = upper_bound(trapX.begin(), trapX.end(), make_pair(boxes[v].bounds.x2, -M));
	auto it1l = upper_bound(trapY.begin(), trapY.end(), make_pair(boxes[v].bounds.y1, -M));
	auto it2l = upper_bound(trapY.begin(), trapY.end(), make_pair(boxes[v].bounds.y2, -M));

	if (it2D - it1D > it2l - it1l) {
		for (auto it = it1l; it < it2l; it++) {
			if (inBounds(boxes[v].bounds, traps[it->second].pocz ,it->first))
				return 1;
		}

	}
	else {
		for (auto it = it1D; it < it2D; it++) {
			if (inBounds(boxes[v].bounds, it->first, traps[it->second].kon))
				return 1;
		}

	}
	return 0;
}

int bfs(int s, int e) {
	queue<int> q;
	q.push(s);

	while (q.size()) {
		int v = q.front(); q.pop();
		if (v == e) return dis[e];
		vis[v] = 1;

		for (int child : graph[v]) {
			if (vis[child] || in(child)) continue;
			dis[child] = dis[v] + 1;
			vis[child] = 1;
			q.push(child);
		}
	}
	return -1;

}

/* zam.cpp */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, w, h;
	int px, py,
	    sx, sy,
	    x1, y1, x2, y2;

	cin >> w >> h >> n >> m; /* komnaty , niebezpieczne */

	cin >> px >> py;
	cin >> sx >> sy;

	// komnaty
	for (int i=0; i<n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2) swap(x1, x2); // crossed
		if (y1 > y2) swap(y1, y2); // crossed mirrored

		Ver right, bottom;
		Bounds bounds = {x1, y1, x2, y2};

		right = {y1, y2, i};
		bottom = {x1, x2, i};

		Rect box = {right, bottom, bounds, i};

		bottomSlices[y1].pb(bottom);
		rightSlices[x2].pb(right);

		boxes.pb(box);
	}

	// niebezpieczne
	for (int i=0; i<m; i++) {
		cin >> x1 >> y1;
		traps.pb({x1, y1, -1});

		trapX.pb({x1, i});
		trapY.pb({y1, i});
	}


	for (auto& key : bottomSlices) 
		sort(key.second.begin(), key.second.end(), cmp_Ver);

	for (auto& key : rightSlices) 
		sort(key.second.begin(), key.second.end(), cmp_Ver);
	
	sort(trapX.begin(), trapX.end());
	sort(trapY.begin(), trapY.end());


	// connecting the graph
	int Start, End;
	for (int i=0; i<n; i++) {
		Rect box = boxes[i];


		// connecting top & bottom
		if (bottomSlices[box.bounds.y2].size()) {
			Start = bs_start(bottomSlices[box.bounds.y2], box.bounds.x1);
			End = bs_end(bottomSlices[box.bounds.y2], box.bounds.x2);
			
			for (; Start <= End; Start++) {
				graph[box.id].pb(bottomSlices[box.bounds.y2][Start].id);
				graph[bottomSlices[box.bounds.y2][Start].id].pb(box.id);
			}

		}

		// connecting left & right
		if (rightSlices[box.bounds.x1].size()) {
			Start = bs_start(rightSlices[box.bounds.x1], box.bounds.y1);
			End = bs_end(rightSlices[box.bounds.x1], box.bounds.y2);

			for (; Start <= End; Start++) {
				graph[box.id].pb(rightSlices[box.bounds.x1][Start].id);
				graph[rightSlices[box.bounds.x1][Start].id].pb(box.id);
			}
		}
	}
	Start = checkId(px, py);
	End = checkId(sx, sy);

	cout << bfs(Start, End) + 1 << '\n';
	/* cout << Start << "_" << End << "[]";
	for (auto trap : traps) {
		for (auto box : boxes) {
			if (inBounds(box.bounds, trap.pocz, trap.kon))
				cout << box.id << '_';
		}
	}

	cout << "[]";
	for (int i=1; i<=n; i++)  
		for (auto x : graph[i]) 
			cout << i << '_' << x << '|'; */
}
	
