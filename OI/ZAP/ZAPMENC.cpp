#include <bits/stdc++.h>
using namespace std;

int n, a, b, koniec_przedzialu, prev_koniec_przedzialu, merdent, koniec_zast, zap_siz;
vector<pair<int, pair<int, int>>> wyk; // koniec przedzialu, { poczatek przedzilu, numer wykladu }
				       // vector<pair<int, pair<int, int>>> sec_wyk; // poczatek przedzilu, { koniec przedzialu, numer wykladu }
unordered_map<int, int> zap;
vector<int> glowne;
vector<int> zapasowe;
vector<int> merd;
// bool loOo;

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.second.first > b.second.first;
}

bool sec_comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.first < b.first;
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		pair<int, pair<int, int>> temp;
		temp.first = b;
		temp.second = {a, i + 1};
		wyk.push_back(temp);
	}

	sort(wyk.begin(), wyk.end(), comp);
	sort(wyk.begin(), wyk.end(), sec_comp);


	for (int i = 0; i < wyk.size(); ++i)
	{
		pair<int, pair<int, int>> temp = wyk[i];

		if (temp.second.first >= merdent)
		{
			merd.push_back(i);
			merdent = temp.first;
		}
		// wyk => koniec przedzialu, { poczatek przedzilu, numer wykladu }

		if (glowne.size() == zapasowe.size())
		{
			if (temp.second.first >= max(koniec_przedzialu, koniec_zast))
			{
				prev_koniec_przedzialu = koniec_przedzialu;
				koniec_przedzialu = temp.first;
				glowne.push_back(i);
			}
			else if (temp.second.first >= koniec_przedzialu)
			{
				zapasowe.push_back(i);
				++zap_siz;
			}
		}
		else if (glowne.size() > zapasowe.size())
		{
			if (temp.second.first >= max(koniec_przedzialu, koniec_zast))
			{
				prev_koniec_przedzialu = koniec_przedzialu;
				koniec_przedzialu = temp.first;
				glowne.push_back(i);
			}
			else if (temp.second.first >= prev_koniec_przedzialu && zap.find(glowne.back()) == zap.end())
			{
				zap[glowne[glowne.size() - 1]] = i;
				zapasowe.push_back(i);
				++zap_siz;
				koniec_zast = temp.first;
			}
		}
		else if (glowne.size() < zapasowe.size())
		{
			if (temp.second.first >= max(koniec_przedzialu, koniec_zast))
			{
				prev_koniec_przedzialu = koniec_przedzialu;
				koniec_przedzialu = temp.first;
				glowne.push_back(i);
				zap[glowne[glowne.size() - 1]] = zapasowe[zapasowe.size() - 1];
			}
		}

	}

	if (glowne.size() <= merd.size() - 1)
	{
		cout << merd.size() - 1 << '\n';
		for (int i = 0; i < merd.size() - 1; ++i)
		{
			cout << wyk[merd[i]].second.second << " " << wyk[merd.back()].second.second << '\n';
		}

		return 0;
	}

	if (glowne.size() <= zap_siz) // jest tyle samo zastepczych co glownych
	{
		cout << glowne.size() << '\n';
		for (int i = 0; i < glowne.size(); ++i)
		{
			cout << wyk[glowne[i]].second.second << ' ' << wyk[zap[glowne[i]]].second.second << '\n';
		}
	}
	else
	{
		cout << glowne.size() - 1 << '\n';
		for (int i = 0; i < glowne.size() - 1; ++i)
		{
			cout << wyk[glowne[i]].second.second << ' ' << wyk[glowne[glowne.size() - 1]].second.second << '\n';
		}
	}

	return 0;
}
/*

   5
   5 9
   7 9
   4 8
   5 7
   8 9

   5
   2 7
   4 7
   6 8
   1 5
   2 3

   10
   11 16
   13 18
   1 11
   9 15
   1 3
   16 20
   8 14
   16 19
   8 14
   2 18

*/

