#include<bits/stdc++.h>

typedef long long int ll;

#define pp pair<int,int>
#define N 1001

using namespace std;

int n,m ;
string s[N];
bool vis[N][N],vis2[N][N];
int dist[N][N];

int dfs(int i,int j)
{
    if((vis[i][j] && s[i][j]=='.') || i<0 || j<0 ||  i>=n || j>=m)
        return 0;

    if(s[i][j]=='*')
    {
        vis[i][j]=1;
        return 1;
    }

    int cnt=0;

    vis[i][j]=1;

    cnt+=dfs(i+1,j);
    cnt+=dfs(i-1,j);
    cnt+=dfs(i,j+1);
    cnt+=dfs(i,j-1);

    return cnt;
}

void dfs2(int i,int j,int c)
{
    if(vis2[i][j] || i<0 || j<0 ||  i>=n || j>=m || s[i][j]=='*')
        return ;

    vis2[i][j]=1;
    dist[i][j]=c;

    dfs2(i+1,j,c);dfs2(i-1,j,c);
    dfs2(i,j+1,c);dfs2(i,j-1,c);
}

int main()
{

    int i,j,k;
    int x,r,c;

    cin >> n >> m >> k;
    for(i=0;i<n;i++)
        cin>>s[i];

    memset(vis,0,sizeof(vis));
    memset(vis2,0,sizeof(vis2));
    memset(dist,0,sizeof(dist));

    while(k--)
    {
	cin >> r >> c;

        r--;c--;
        if(vis2[r][c])
		cout << dist[r][c] << '\n';
	

        else
        {
            x=dfs(r,c);
            dfs2(r,c,x);

	    cout << x << '\n';
        }
    }

    return 0;
}
