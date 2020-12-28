#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void forward_dfs(int vertex, vector<vector<int>>& graph,
                 vector<bool>& visited, vector<int>& order)
{
    visited[vertex] = true;
    for (auto incident: graph[vertex])
        if (!visited[incident])
            forward_dfs(incident, graph, visited, order);
    order.push_back(vertex);
}

void reverse_dfs(int vertex, vector<vector<int>>& graph,
                 vector<bool>& visited, vector<unordered_set<int>>& components)
{
    visited[vertex] = true;
    components[components.size() - 1].insert(vertex);
    for (auto incident: graph[vertex])
        if (!visited[incident])
            reverse_dfs(incident, graph, visited, components);
}

vector<unordered_set<int>> get_components(vector<vector<int>>& graph, vector<vector<int>>& re_graph)
{
    vector<unordered_set<int>> components;
    int m = graph.size() / 2;
    vector<bool> visited(2 * m);
    vector<int> order;
    for (int i = 0; i < 2 * m; ++i)
        if (!visited[i])
            forward_dfs(i, graph, visited, order);
    visited.assign(2 * m, false);
    for (int i = order.size() - 1; i >= 0; i--)
        if (!visited[order[i]])
        {
            components.emplace_back();
            reverse_dfs(order[i], re_graph, visited, components);
        }
    return components;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> m;
    vector<vector<int>> graph(2 * m), re_graph(2 * m);
    int count;
    cin >> count;
    for (int i = 0; i < count; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        re_graph[b].push_back(a);
        graph[b + m].push_back(a + m);
        re_graph[a + m].push_back(b + m);
    }
    cin >> count;
    for (int i = 0; i < count; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b + m);
        re_graph[b + m].push_back(a);
        graph[b].push_back(a + m);
        re_graph[a + m].push_back(b);
    }
    cin >> count;
    for (int i = 0; i < count; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a + m].push_back(b);
        re_graph[b].push_back(a + m);
        graph[b + m].push_back(a);
        re_graph[a].push_back(b + m);
    }
    vector<unordered_set<int>> components = get_components(graph, re_graph);
    vector<int> values;
    values.assign(m, -1);
    for (int i = 0; i < components.size(); i++) {
        unordered_set<int> &component = components[components.size() - 1 - i];
        for (auto vertex: component) {
            if (component.count((vertex + m) % (2 * m))) {
                cout << -1;
                return 0;
            }
            if (values[vertex % m] != -1)
                continue;
            if (vertex < m)
                values[vertex % m] = 1;
            else
                values[vertex % m] = 0;
        }
    }
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        if (values[i])
            ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for (auto vertex: ans)
        cout << vertex << " ";
    return 0;
}
