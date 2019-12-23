#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int N = 2005;

int n, m, k, q, ans[2005][2005], a[2005][2005], h[2005][2005], l[2005], r[2005];

deque<int> dq;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m >> k >> q;
    while(k--){
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        for(int i = x1; i < x2; i++){
            for(int j = y1; j < y2; j++)
                a[i][j] = 1;
        }
    }
    //back, front
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1) h[i][j] = 0;
            else h[i][j] = h[i - 1][j] + 1;
        }
        while(!dq.empty()) dq.pop_back();
        for(int j = 0; j < m; j++){//h[l[j]] <= h[j]
            while(!dq.empty() && h[i][dq.front()] > h[i][j]) dq.pop_front();
            if(dq.empty())
                l[j] = -1;
            else
                l[j] = dq.front();
            dq.push_front(j);
        }
        while(!dq.empty()) dq.pop_back();
        for(int j = m - 1; j >= 0; j--){//h[j] > h[r[j]]
            while(!dq.empty() && h[i][j] <= h[i][dq.back()]) dq.pop_back();
            if(dq.empty())
                r[j] = m;
            else
                r[j] = dq.back();
            dq.push_back(j);
        }
        for(int j = 0; j < m; j++){//l[j] + 1 -> j : v
            ans[h[i][j]][r[j] - l[j]]--;
            ans[h[i][j]][r[j] - j]++;
            ans[h[i][j]][0]--;
            ans[h[i][j]][j - l[j]]++;
        }
    }
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= m + 1; j++)
            ans[i][j] += ans[i][j - 1];
    }
    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--)
            ans[i][j] += ans[i + 1][j] + ans[i][j + 1] - ans[i + 1][j + 1];
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << ans[x][y] << "\n";
    }
}
