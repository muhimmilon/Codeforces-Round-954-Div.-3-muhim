#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        vector<int> indices(m);
        vector<char> chars(m);

        for (int i = 0; i < m; ++i) {
            cin >> indices[i];
            indices[i]--;  // Convert to 0-based index
        }

        for (int i = 0; i < m; ++i) {
            cin >> chars[i];
        }

        vector<pair<int, char>> updates;
        for (int i = 0; i < m; ++i) {
            updates.push_back({indices[i], chars[i]});
        }

        // Sort by index first, then by character to ensure lexicographical order
        sort(updates.begin(), updates.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });

        for (auto& update : updates) {
            s[update.first] = update.second;
        }

        cout << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
