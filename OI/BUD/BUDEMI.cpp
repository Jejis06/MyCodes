#include <bits/stdc++.h>
using namespace std;

struct cords {
    int length=0, x=0, y=0;
};

constexpr int N = 1500 + 10;

cords max_row[2], max_col[2];
int count_col[N];

bool parallel(int max_length) {
    if (max_row[0].length == max_row[1].length && max_row[0].length == max_length) return true; 
    else if (max_col[0].length == max_col[1].length && max_col[0].length == max_length) return true;
    else return false;
}

int two_colums() {
    return max(max_col[0].length / 2, max_col[1].length);
}

int two_rows() {
    return max(max_row[0].length / 2, max_row[1].length);
}

bool overlap(cords column, cords row) {
    int row_start = row.x - row.length + 1;
    int column_start = column.y - column.length + 1;

    if (row_start <= column.x && row.x >= column.x && column_start <= row.y && column.y >= row.y) 
        return true;
    return false;
}

int two_best() {
    int res; 
    if (!overlap(max_col[0], max_row[0]))
        res = min(max_col[0].length, max_row[0].length);

    else if (overlap(max_col[0], max_row[0])) {
        int row1 = max_col[0].x - (max_row[0].x - max_row[0].length);
        int row2 = max_row[0].length - row1 + 1;

        int col1 = max_row[0].y - (max_col[0].y - max_col[0].length);
        int col2 = max_col[0].length - col1 + 1;

        int case1 = min(row1 + row2 -1, max(col1-1, col2-1));
        int case2 = min(col1 + col2 -1, max(row1-1, row2-1));

        res = max(case1, case2);
    }

    return res;
}

int is_x(char c) {
    if (c == '.') return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m,
        count_row = 0;
    string inp;

    cin >> n >> m;

    for (int y=1; y<=n; y++) {
        cin >> inp;

        for (int x=1; x<=n; x++) {
            if (inp[x-1] == '.') {
                count_row++;
                count_col[x]++;
            }

            cords curr_col = {count_col[x], x, y - is_x(inp[x-1])};
            cords curr_row = {count_row, x - is_x(inp[x-1]), y};

            if (inp[x-1] != '.' || x == n) {
                // rzedy
                if (curr_row.length > max_row[1].length) {
                    if (curr_row.length > max_row[0].length) {
                        max_row[1] = max_row[0];
                        max_row[0] = curr_row;
                    }
                    else {
                        max_row[1] = curr_row;
                    }
                }
                count_row = 0;
            }

            if (inp[x-1] != '.' || y == n) {
                // kolumny
                if (curr_col.length > max_col[1].length) {
                    if (curr_col.length > max_col[0].length) {
                        max_col[1] = max_col[0];
                        max_col[0] = curr_col;
                    }
                    else {
                        max_col[1] = curr_col;
                    }
                }
                count_col[x] = 0;
            }
        }
    }

    // cout << "max_col " << max_col[0].length << " max_row " << max_row[0].length << endl;
    // wynik
    int max_length = max(max_col[0].length, max_row[0].length);

    if (m == 1 || parallel(max_length)) {
        cout << max_length << '\n';
        return 0;
    }

    int out = 0;
    out = max({out, two_rows(), two_colums(), two_best()});
    cout << out << '\n';
}


