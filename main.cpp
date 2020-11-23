#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<pair<int, int>, set<pair<int, int>>> incidents;
set<pair<int, int>> visited;

int dfs(pair<int, int> current)
{
    int vertex_count = 0;
    visited.insert(current);
    for (auto point: incidents[current])
        if (visited.count(point) == 0)
            vertex_count += dfs(point);
    return vertex_count + incidents[current].size() % 2;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> cuts(n);
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        cuts[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> cuts[i][j].first >> cuts[i][j].second;
        }
        for (int j = 0; j < k - 1; ++j)
        {
            incidents[cuts[i][j]].insert(cuts[i][j + 1]);
            incidents[cuts[i][j + 1]].insert(cuts[i][j]);
        }
    }
    int linked_count = 0;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        int k = cuts[i].size();
        for (int j = 0; j < k; ++j)
        {
            if (visited.count(cuts[i][j]) == 0)
            {
                linked_count++;
                int inner_count = dfs(cuts[i][j]);
                count += max(0, inner_count / 2 - 1);
            }
        }
    }
    cout << count + linked_count - 1;
    return 0;
}
