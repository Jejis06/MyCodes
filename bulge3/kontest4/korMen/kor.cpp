#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 200002;
constexpr int mod = 1000037;
int base[MAX_N];
int n, ans, acu, fstkey, seckey, k, curr_ans, ind;
int ciag[MAX_N];
unordered_map<int, bool> mapa;

void get_base()
{
    base[0] = 1;
    base[1] = 31;
    for (int i = 2; i < n; ++i)
    {
        base[i] = (31 * base[i - 1]) % mod;
    }
}

void hash_key()
{
    fstkey = 0;
    seckey = 0;
    // cout << "\n\nHASH\n";
    for (int i = 0; i < k; ++i)
    {
        // cout << "at [ " << ind + i << " ] = " << ciag[ind + i] << " += " << ciag[ind + i] << " * " << base[i] << "\n";
        // cout << " at [ " << ind + k - i - 1 << " ] = " << ciag[ind + k - i] << " += " << ciag[ind + k - i] << " * " << base[i] << "\n\n";
        fstkey += (ciag[ind + i] * base[i]) % mod;
        seckey += (ciag[ind + k - i - 1] * base[i]) % mod;
    }
    // cout << " hash: ind = " << ind << " seckey = " << fstkey << "\n";
    // cout << " hash: ind = " << ind << " fstkey = " << seckey << "\n";
}

void build()
{
    ind = 1;
    // cout << " k = " << k << "  ind = " << ind << " < " << n - k << " ";
    while (ind <= n - k + 1)
    {
        // cout << "\ngabba\n";
        hash_key();
        if (mapa.find(fstkey) == mapa.end() && mapa.find(seckey) == mapa.end())
        {
            mapa[fstkey] = 1;
            mapa[seckey] = 1;
            // cout << " found " << fstkey;
            // cout << " found " << seckey;
            ++curr_ans;
        }
        ind += k;
        if (ind >= n)
        {

            // cout << " FORCED END k = " << k << "  ind = " << ind << " < " << n - k << " \n";
            break;
        }
    }
    // cout << "\nEND k = " << k << "  ind = " << ind << " < " << n - k << " \n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> ciag[i];
    }

    get_base();

    // cout << curr_ans << " >= " << ans << "\n";
    while (curr_ans >= ans)
    {
        ++k;
        if (k > n)
        {
            // cout << "\nforced_end\n";
            break;
        }
        curr_ans = 0;
        build();
        if (curr_ans == ans)
        {
            ++acu;
            // cout << " case 1 ";
        }
        else if (curr_ans > ans)
        {
            ans = curr_ans;
            acu = 1;
            // cout << " case 2 " << curr_ans;
        }
        // cout << " k = " << k;
        // cout << "\n________________________________________________________________\n";
        // if (k > 4)
        //     break;
    }
    // cout << " ENDED curr = " << curr_ans << " k = " << k;
    // cout << "\n";

    cout << ans << " " << acu << "\n";

    for (int i = 0; i < acu; ++i)
    {
        cout << k - i - 1 << " ";
    }

    return 0;
}
