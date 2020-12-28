#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    queue<int> q;
    int first_condition;
    cin >> first_condition;
    vector<vector<int>> l(2 * n);
    vector<unordered_set<int>> c;
    vector<bool> exists;
    unordered_set<int> values;
    for (int i = 0; i < first_condition; ++i) {
        int a;
        cin >> a;
        a--;
        q.push(a);
        values.insert(a);
    }
    int second_condition;
    cin >> second_condition;
    for (int i = 0; i < second_condition; ++i) {
        c.emplace_back();
        exists.push_back(true);
        int count;
        cin >> count;
        for (int j = 0; j < count; ++j) {
            int a;
            cin >> a;
            a--;
            l[a + n].push_back(i);
            c[i].insert(a + n);
        }
        int a;
        cin >> a;
        a--;
        l[a].push_back(i);
        c[i].insert(a);
    }
    int third_condition;
    cin >> third_condition;
    for (int i = 0; i < third_condition; ++i) {
        c.emplace_back();
        exists.push_back(true);
        int count;
        cin >> count;
        for (int j = 0; j < count; ++j) {
            int a;
            cin >> a;
            a--;
            l[a + n].push_back(second_condition + i);
            c[second_condition + i].insert(a + n);
        }
    }
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
//        cout << current << "\n";
        for (auto i: l[current]) {
            if (!exists[i])
                continue;
            exists[i] = false;

            if (c[i].size() == 1)
            {
                for(auto a: c[i])
                {
                    if (values.count((a + n) % (2 * n)))
                    {
                        cout << -1;
                        return 0;
                    }
                    q.push(a);
                    values.insert(a);
                }
                exists[i] = false;
            }

            if (c[i].empty())
            {
                cout << -1;
                return 0;
            }
        }
        int not_current = (current + n) % (2 * n);
        for (auto i: l[not_current])
        {
            if (!exists[i])
                continue;
            c[i].erase(not_current);
            if (c[i].size() == 1)
            {
                for(auto a: c[i])
                {
                    if (values.count((a + n) % (2 * n)))
                    {
                        cout << -1;
                        return 0;
                    }
                    q.push(a);
                    values.insert(a);
                }
                exists[i] = false;
            }

            if (c[i].empty())
            {
                cout << -1;
                return 0;
            }
        }
    }
    vector<int> ans;
    for (auto value: values)
        if (value < n)
            ans.push_back(value + 1);
    cout << ans.size() << '\n';
    for (auto value: ans)
        cout << value << ' ';
    return 0;
}
