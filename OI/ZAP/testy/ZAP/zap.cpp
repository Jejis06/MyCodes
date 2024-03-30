#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 10;

vector<int> glowne, zap, absolute;
unordered_map<int, int> zap_dla;

struct wyklad {
    int start, end, id;
} wyklady[N];


// rosnaco wedlug koncow...
bool wyklad_rosnacy(const wyklad& a, const wyklad& b) {
    return a.end < b.end;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s, e;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> s >> e;
        wyklady[i] = {s, e, i+1};
    }

    sort(wyklady, wyklady+n, wyklad_rosnacy);

    int main_end = -1, prev_main_end = -1, zap_end = -1, absolute_end = -1;
    
    for (int i=0; i<n; i++) {
        if (wyklady[i].start >= absolute_end) {
            absolute.push_back(i);
            absolute_end = wyklady[i].end;
        }
        
        if (glowne.size() == zap.size()) {
            // glowny
            if (wyklady[i].start >= main_end && wyklady[i].start >= zap_end) {
                prev_main_end = main_end;
                main_end = wyklady[i].end;
                glowne.push_back(i);
            }

            // zapasowy do kolejnego
            else if (wyklady[i].start >= main_end)
                zap.push_back(i);
        }
        
        else if (glowne.size() > zap.size()) {
            // zapasowy do kolejnego 
            int last_main = glowne.size() - 1;
            if (wyklady[i].start >= prev_main_end && zap_dla.find(glowne[last_main]) == zap_dla.end()) {
                zap_end = wyklady[i].end;
                zap.push_back(i);
                zap_dla[glowne[last_main]] = i;
            }

            // glowny
            else if (wyklady[i].start >= zap_end && wyklady[i].start >= main_end) {
                prev_main_end = main_end;
                main_end = wyklady[i].end;
                glowne.push_back(i);
            }
        }

        else if (glowne.size() < zap.size()) {
            // glowny z juz przydzielonym wczesniej zap
            if (wyklady[i].start >= main_end && wyklady[i].start >= zap_end) {
                prev_main_end = main_end;
                main_end = wyklady[i].end;
                glowne.push_back(i);

                zap_dla[i] = zap[zap.size() - 1];
            } 
        }
    }

    if (glowne.size() <= absolute.size() -1 || glowne.size() > zap.size()) {
        cout << absolute.size() -1 << '\n';
        for (int i=0; i<absolute.size() -1; i++)
            cout << wyklady[absolute[i]].id << ' ' << wyklady[absolute[absolute.size() -1]].id << '\n';
    }
    else {
        cout << glowne.size() << '\n';
        for (int i=0; i<glowne.size(); i++) {
            int id = glowne[i];
            cout << wyklady[id].id << ' ' << wyklady[zap_dla[id]].id << '\n';
        }
    }
}


