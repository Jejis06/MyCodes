#include <bits/stdc++.h>
using namespace std;

const int ARR_SIZE = 1e6;
int n, m;

struct node {
  vector<int> edges;
  int dis = 0;
  bool visited = false;

} board[ARR_SIZE];

int fun(int x, int y) { return x + y * m; }

bool confirm_edge(int x) {
  if (x < 0 || x >= m)
    return false;
  return true;
}
//
void make_edges(int x, int y) {
  int coords = fun(x, y);
  int x1, y1;

  y1 = y + 2;
  if (!(y1 < 0 || y1 >= n)) {
    x1 = x + 1;

    if (confirm_edge(x1)) {
      board[coords].edges.push_back(fun(x1, y1));
    }

    x1 = x - 1;

    if (confirm_edge(x1)) {
      board[coords].edges.push_back(fun(x1, y1));
    }
  }

  // secondi
  y1 = y - 2;
  if (!(y1 < 0 || y1 >= n)) {

    x1 = x + 1;

    if (confirm_edge(x1)) {
      board[coords].edges.push_back(fun(x1, y1));
    }

    x1 = x - 1;

    if (confirm_edge(x1)) {
      board[coords].edges.push_back(fun(x1, y1));
    }
  }
  // thirdi
  y1 = y + 1;
  if (!(y1 < 0 || y1 >= n)) {
    x1 = x + 2;

    if (confirm_edge(x1)) {
      board[coords].edges.push_back(fun(x1, y1));
    }

    x1 = x - 2;

    if (confirm_edge(x1)) {
      board[coords].edges.push_back(fun(x1, y1));
    }
  }
  // quatri
  y1 = y - 1;
  if (!(y1 < 0 || y1 >= n)) {
    x1 = x + 2;

    if (confirm_edge(x1)) {
      board[coords].edges.push_back(fun(x1, y1));
    }

    x1 = x - 2;

    if (confirm_edge(x1)) {
      board[coords].edges.push_back(fun(x1, y1));
    }
  }
}

void BFS(int s, int e) {
  queue<int> q;
  q.push(s);
  board[s].visited = true;

  int parent;
  while (!q.empty() && parent != e) {
    parent = q.front();
    q.pop();

    for (int i = 0; i < board[parent].edges.size(); i++) {
      int child = board[parent].edges[i];

      if (!board[child].visited) {
        q.push(child);
        board[child].visited = true;
        board[child].dis = board[parent].dis + 1;
      }
    }
  }
  if (e != s && board[e].dis == 0) {
    cout << "NIE\n";
    return;
  }
  cout << board[e].dis << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  int current;
  int goal;
  char c;

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {

      cin >> c;

      int pole = fun(x, y);

      if (c == 'x')
        continue;
      else
        make_edges(x, y);

      if (c == 'n')
        goal = pole;
      else if (c == 'z')
        current = pole;
    }
  }

  BFS(current, goal);
}