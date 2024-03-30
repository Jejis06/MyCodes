#include <bits/stdc++.h>
using namespace std;

constexpr int BASE = 1507;
int n, m, H_max, V_max, sH_max, sV_max, H_i, V_j, gen_max;
char ground[BASE][BASE];
int dpH[BASE][BASE];
int dpV[BASE][BASE];
pair<int, int> cords_H_max;
pair<int, int> cords_V_max;

void max_intercetion()
{
    if (V_j < cords_H_max.first || V_j > cords_H_max.second || H_i < cords_V_max.first || H_i > cords_V_max.second)
    {
        gen_max = min(H_max, V_max);
        gen_max = max(gen_max, max(sH_max, sV_max));
        gen_max = max(gen_max, max(H_max/2, V_max/2));
        return;
    }
    gen_max = max(
        min(H_max, max(H_i - cords_V_max.first, cords_V_max.second - H_i)),
        min(V_max, max(V_j - cords_H_max.first, cords_H_max.second - V_j)));
    gen_max = max(gen_max, max(H_max, V_max) / 2);
    gen_max = max(
        gen_max,
        max(
            min(H_max, sV_max),
            min(V_max, sH_max)));
    gen_max = max(
        gen_max,
        max(sH_max, sV_max));
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> ground[i][j];
            if (ground[i][j] == '.')
            {
                dpH[i][j] += dpH[i][j - 1] + 1;
                if (dpH[i][j] > H_max)
                {
                    H_max = dpH[i][j];
                    cords_H_max.first = j - H_max + 1;
                    cords_H_max.second = j;
                    H_i = i;
                }
                else if (dpH[i][j] > sH_max)
                {
                    sH_max = dpH[i][j];
                }

                dpV[i][j] += dpV[i - 1][j] + 1;
                if (dpV[i][j] > V_max)
                {
                    V_max = dpV[i][j];
                    cords_V_max.first = i - V_max + 1;
                    cords_V_max.second = i;
                    V_j = j;
                }
                else if (dpV[i][j] > sV_max)
                {
                    sV_max = dpV[i][j];
                }
            }
        }
    }

    if (m == 1)
    {
        cout << max(H_max, V_max);

        return 0;
    }

    max_intercetion();

    cout << gen_max;

    return 0;
}
