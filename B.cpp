#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int VISITED = 100000;

vector<unordered_set<int>> sort(vector<vector<int>> &graph, vector<int> &power) {
    vector<unordered_set<int>> sorted;
    for (int i = 0; i < graph.size(); i++)
        sorted.push_back(unordered_set<int>());
    for (int i = 0; i < graph.size(); i++)
        sorted[power[i]].insert(i);
    return sorted;
}

int get_next_min_power(int min_power, vector<unordered_set<int>> &sorted) {
    while (sorted[min_power].size() == 0)
        min_power++;
    return min_power;
}

vector<int> get_sorted_order(vector<vector<int>> &graph, vector<int> &power) {
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


    return 0;
}
