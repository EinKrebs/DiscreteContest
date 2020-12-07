#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool bfs(string& word, vector<vector<vector<int>>>& incidents,
         vector<int>& start, unordered_set<int>& terminals)
{
    vector<unordered_set<int>> r(1);
    for (auto starting: start)
        r[0].insert(starting);
    for (int i = 0; i < word.size(); i++)
    {
        r.emplace_back();
        for (auto state: r[i])
            for(auto incident: incidents[state][word[i] - 'a'])
                r[i + 1].insert(incident);
    }
    for (auto finish: r[r.size() - 1])
        if (terminals.count(finish))
            return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, sigma, s, t;
    cin >> n >> sigma;
    cin >> s;
    vector<int> start(s);
    for (int i = 0; i < s; ++i)
        cin >> start[i];
    cin >> t;
    unordered_set<int> terminal;
    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        terminal.insert(a);
    }
    vector<vector<vector<int>>> incidents(n);
    for (int i = 0; i < n; i++)
    {
        incidents[i].resize(26);
        for (int j = 0; j < sigma; j++)
        {
            char letter;
            int vertices;
            cin >> letter >> vertices;
            incidents[i][letter - 'a'].resize(vertices);
            for (int k = 0; k < vertices; k++)
                cin >> incidents[i][letter - 'a'][k];
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string word;
        cin >> word;
        if (bfs(word, incidents, start, terminal))
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
