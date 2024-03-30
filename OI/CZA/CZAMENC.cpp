#include <bits/stdc++.h>
using namespace std;

constexpr long long l = 1e6 + 1;
constexpr long long mod = 1e16 + 61;
long long key_hs;
long long BASE[l];
unordered_map<long long, vector<int>> wystapien; // hash; a = n, b =...
unordered_map<long long, char> next_letter;      // hash; next letter
unordered_map<long long, string> czy_wyst;       // hash; suffix
long long n, k, a, b, curr_length, letters_to_add, last_i, rep_size, rep_index;
string s, rep_fraze = "", curr_suffix, start_of_rep = ".";
char next_char;
vector<int> empty_filler{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void hash_key()
{

    key_hs = 0;

    curr_suffix.erase(0, 1);

    for (int i = 0; i < k; ++i)
    {
        key_hs += ((curr_suffix[i] - 96) * BASE[i]) % mod;
    }
}

char get_next_letter()
{

    if (czy_wyst.find(key_hs) != czy_wyst.end())
    {
        start_of_rep = czy_wyst[key_hs];
    }

    if (wystapien.find(key_hs) == wystapien.end())
    {
        wystapien[key_hs] = empty_filler;
        wystapien[key_hs]['a' - 96]++;
        next_letter[key_hs] = 'a';
    }
    else
    {

        pair<int, char> cur_max;
        cur_max.first = -1;

        for (int i = 0; i < 27; ++i)
        {
            if (wystapien[key_hs][i] > cur_max.first)
            {
                cur_max.first = wystapien[key_hs][i];
                cur_max.second = i + 96;
            }
        }

        next_letter[key_hs] = cur_max.second;
    }

    czy_wyst[key_hs] = curr_suffix;

    return next_letter[key_hs];
}

void get_filler()
{

    for (int i = 0; i < curr_length - k; ++i)
    {

        long long cur_hs = 0;

        for (int j = i; j < i + k; ++j)
        {
            cur_hs += ((s[j] - 96) * BASE[j - i]) % mod;
        }

        if (wystapien.find(cur_hs) == wystapien.end())
        {
            wystapien[cur_hs] = empty_filler;
        }
        wystapien[cur_hs][s[i + k] - 96]++;
    }

    for (int i = 0; i < curr_length - k; ++i)
    {
        long long cur_hs = 0;

        for (int j = i; j < i + k; ++j)
        {
            cur_hs += ((s[j] - 96) * BASE[j - i]) % mod;
        }

        pair<int, char> cur_max;
        cur_max.first = -1;

        for (int i = 0; i < 27; ++i)
        {
            if (wystapien[cur_hs][i] > cur_max.first)
            {
                cur_max.first = wystapien[cur_hs][i];
                cur_max.second = i + 96;
            }
        }

        next_letter[cur_hs] = cur_max.second;
    }
}

void repeating()
{
    long long cur_hs, rep_hs;
    string temp_suff = start_of_rep;

    cur_hs = key_hs;
    rep_hs = cur_hs;

    do
    {
        char nl = next_letter[cur_hs];
        rep_fraze += nl;

        temp_suff += nl;
        temp_suff.erase(0, 1);
        cur_hs = 0;

        for (int j = 0; j < k; ++j)
        {
            cur_hs += ((temp_suff[j] - 96) * BASE[j]) % mod;
        }

    } while (cur_hs != rep_hs);
    rep_size = rep_fraze.size();
}

void build_BASE()
{
    curr_length = s.size();
    letters_to_add = b - a;
    BASE[0] = 1;
    BASE[1] = 31;

    for (int i = 2; i < k + 3; ++i)
    {
        BASE[i] = (BASE[i - 1] * BASE[1]) % mod;
    }

    for (int i = curr_length - k; i < curr_length; ++i)
    {
        curr_suffix += s[i];
    }

    for (int i = 0; i < k; ++i)
    {
        key_hs += ((curr_suffix[i] - 96) * BASE[i]) % mod;
    }

    get_filler();
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> a >> b >> s;

    build_BASE();
    for (long long i = a - 1; i < n; ++i)
    {
        cout << s[i];
    }
    for (long long i = n; i < b; ++i)
    {

        if (start_of_rep == ".")
        {
            next_char = get_next_letter();
        }
        if (start_of_rep != ".")
        {

            repeating();
            last_i = i;
            break;
        }
        curr_suffix += next_char;
        if (i >= a - 1)
        {
            cout << next_char;
        }
        hash_key();
    }

    if (rep_fraze != "")
    {

        if (last_i < a - 1)
        {
            long long empty_space = ((a - last_i) % rep_size) + rep_size;
            b -= a;
            a = empty_space;
            b += a;
            last_i = 0;
        }

        rep_index = last_i;

        while (last_i < b)
        {
            if (last_i >= a - 1)
            {

                if (last_i + rep_size < b && (last_i - rep_index) % rep_size == 0)
                {
                    cout << rep_fraze;
                    last_i += rep_size - 1;
                }
                else
                {
                    cout << rep_fraze[(last_i - rep_index) % rep_size];
                }
            }
            ++last_i;
        }
    }

    return 0;
}
