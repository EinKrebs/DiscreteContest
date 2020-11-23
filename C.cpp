#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int VISITED = 100000;

vector<unordered_set<int>> sort(vector<vector<int>> &graph, vector<int> &power)
{
    vector<unordered_set<int>> sorted;
    for (int i = 0; i < graph.size(); i++)
        sorted.emplace_back();
    for (int i = 0; i < graph.size(); i++)
        sorted[power[i]].insert(i);
    return sorted;
}

int get_next_min_power(int min_power, vector<unordered_set<int>> &sorted)
{
    while (sorted[min_power].empty())
        min_power++;
    return min_power;
}

vector<int> get_sorted_order(vector<vector<int>> &graph, vector<int> &power)
{
    vector<unordered_set<int>> sorted = sort(graph, power);
    vector<int> order;
    int min_power = *min_element(power.begin(), power.end());
    for (int i = 0; i < graph.size(); i++) {
        min_power = get_next_min_power(min_power, sorted);
        int v = *(sorted[min_power].begin());
        order.push_back(v);
        sorted[power[v]].erase(v);
        power[v] = VISITED;
        for (int i = 0; i < graph[v].size(); i++) {
            int w = graph[v][i];
            if (power[w] != VISITED &&
                sorted[power[w]].find(w) != sorted[power[w]].end()) {
                sorted[power[w]].erase(w);
                power[w]--;
                if (power[w] < min_power)
                    min_power = power[w];
                sorted[power[w]].insert(w);
            }
        }
    }
    return order;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<int> power(n);
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        power[i] = k;
        for (int j = 0; j < k; ++j)
        {
            int incident;
            cin >> incident;
            incident--;
            graph[i].push_back(incident);
        }
    }
    vector<int> order = get_sorted_order(graph, power);
    vector<int> colors(n);
    for (auto vertex: order)
    {
        set<int> incident_colors;
        for (auto incident: graph[vertex])
        {
            incident_colors.insert(colors[incident]);
        }
        int color = 1;
        while(incident_colors.count(color) == 1)
            color++;
        colors[vertex] = color;
    }

    for (auto color: colors)
        cout << color << "\n";
    return 0;
}
