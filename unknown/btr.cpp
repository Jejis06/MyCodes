#include <bits/stdc++.h>
using namespace std;
 
int n, m;
const int ARR_SIZE = 1e3;
 
 
struct node {
    int dis = 0;
    bool kopiec = false;
} arr[ARR_SIZE][ARR_SIZE];
 
 
/* 
 
    y1 = y + 2;
    x1 = x + 1;
 
    y1 = y - 2;
    x1 = x + 1;
 
    y1 = y + 2;
    x1 = x - 1;
 
    y1 = y - 2;
    x1 = x - 1;
 
    y1 = y + 1;
    x1 = x + 2;
 
    y1 = y - 1;
    x1 = x + 2;
 
    y1 = y + 1;
    x1 = x - 2;
 
    y1 = y - 1;
    x1 = x - 2;
 */        
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(); 
 
    // wymiary planszy
    cin >> n >> m;
    
    int start, end;
    char c;
 
    // input
    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            cin >> c;
        	if(c == 'x') arr[y][x].kopiec =  true;			
           
        }
    }
 
 
}
