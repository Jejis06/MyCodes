#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>tab;
int n,o1,o2;
bool cmp(pair<int,int>a, pair<int,int>b)
{
    return tab[a.first].first<tab[b.first].first;
}
bool CzyNakladaja(pair<int,int>xd1, pair<int,int>xd2)
{
    return max(xd1.first,xd2.first)<min(xd1.second,xd2.second);
}
int NieWiem(vector<pair<int,int>>&U, int x)
{
    int l=0,p=U.size()-1;
    while(l<p)
    {
        const int mid=(l+p+1)>>1;
        if(tab[U[mid].first].first<=x)
        {
            l=mid;
        }
        else
        {
            p=mid-1;
        }
    }
    return l;
}
void CzyPoprawny(vector<pair<int,int>>U)
{
    sort(U.begin(),U.end(),cmp);
    vector<bool>zaj(n+1);
    for(int i=0;i<U.size();i++)
    {
        if(U[i].first<1||n<U[i].first||U[i].second<1||n<U[i].second)
        {
            cout<<"Index spoza zakresu"<<endl;
            exit(0);
        }
        if(zaj[U[i].first])
        {
            cout<<"Powtorzenie indexu"<<endl;
            exit(0);
        }
        zaj[U[i].first]=1;
    }
    for(int i=0;i<U.size();i++)
    {
        if(zaj[U[i].second]||U[i].first==U[i].second)
        {
            cout<<"Powtorzenie indexu"<<endl;
            exit(0);
        }
    }
    for(int i=1;i<U.size();i++)
    {
        if(tab[U[i-1].first].second>tab[U[i].first].first)
        {
            cout<<"Wyklady normalne sie nakladaja"<<endl;
            exit(0);
        }
    }
    for(int i=0;i<U.size();i++)
    {
        int ind1,ind2;
        ind1=NieWiem(U,tab[U[i].second].first);
        ind2=min((int)U.size()-1,ind1+1);
        ind1=U[ind1].first;
        ind2=U[ind2].first;
        if(ind1!=U[i].first)
        {
            if(CzyNakladaja(tab[ind1],tab[U[i].second]))
            {
                cout<<"Zastepczy wyklad sie naklada z normalnym wykladem"<<endl;
                exit(0);
            }
        }
        if(ind2!=U[i].first)
        {
            if(CzyNakladaja(tab[ind2],tab[U[i].second]))
            {
                cout<<"Zastepczy wyklad sie naklada z normalnym wykladem"<<endl;
                exit(0);
            }
        }
    }
}
int main()
{ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ifstream out("test.out");
    ifstream outb("testb.out");
    ifstream test("test.in");
    out>>o1;
    outb>>o2;
    if(o1!=o2){cout<<"wczytano "<<o2<<", oczekiwano "<<o1<<endl;return 0;}
    test>>n;
    tab.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        test>>tab[i].first>>tab[i].second;
    }
    vector<pair<int,int>>U;
    for(int i=1;i<=o1;i++)
    {
        int a,b;
        outb>>a>>b;
        U.push_back({a,b});
    }
    CzyPoprawny(U);
    cout<<"OK"<<'\n';
    return 0;
}
