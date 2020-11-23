#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<set<int>> incidents(100000);
map<pair<int, int>, int> numbers;
vector<bool> visited;

int dfs(int current)
{
    int vertex_count = 0;
    visited[current] = true;
    for (auto point: incidents[current])
        if (!visited[point])
            vertex_count += dfs(point);
    return vertex_count + incidents[current].size() % 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, c = 0;
    cin >> n;
    vector<vector<pair<int, int>>> cuts(n);
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        cuts[i].resize(k);
        vector<int> numbers_vec(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> cuts[i][j].first >> cuts[i][j].second;
            if (numbers.count(cuts[i][j]) == 0)
            {
                numbers[cuts[i][j]] = c;
                c++;
            }
            numbers_vec[j] = numbers[cuts[i][j]];
        }
        for (int j = 0; j < k - 1; ++j)
        {
            incidents[numbers_vec[j]].insert(numbers_vec[j + 1]);
            incidents[numbers_vec[j + 1]].insert(numbers_vec[j]);
        }
    }
    n = c;
    visited.resize(n);
    int linked_count = 0;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            linked_count++;
            int inner_count = dfs(i);
            count += max(0, inner_count / 2 - 1);
        }
    }
    cout << count + linked_count - 1;
    return 0;
}
