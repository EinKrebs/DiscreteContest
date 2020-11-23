#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> cuts(n);
    set<pair<int, int>> even_vertices;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        cuts[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> cuts[i][j].first >> cuts[i][j].second;
        }
        if (!(cuts[i][0] == cuts[i][k - 1]))
        {
            if(even_vertices.count(cuts[i][0]) == 1)
                even_vertices.erase(cuts[i][0]);
            else
                even_vertices.insert(cuts[i][0]);
            if(even_vertices.count(cuts[i][k - 1]) == 1)
                even_vertices.erase(cuts[i][k - 1]);
            else
                even_vertices.insert(cuts[i][k - 1]);
        }
    }
    cout << max(0LL, ll(even_vertices.size()) / 2 - 1);
    return 0;
}
