#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point
{
    int x;
    int y;

    bool operator == (point other) const
    {
        return this->x == other.x && this->y == other.y;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<point>> cuts(n);
    int dif = 0;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        cuts[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> cuts[i][j].x >> cuts[i][j].y;
        }
        if (!(cuts[i][0] == cuts[i][k - 1]))
            dif += 1;
    }
    cout << max(0, dif - 1);
    return 0;
}
