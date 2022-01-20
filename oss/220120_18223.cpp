#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V, P, E, dist[5001];
vector<pair<int, int>>v[5001];
int di(int s, int e)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    for (int i = 1; i <= V; i++)dist[i] = 1e9;
    q.push({ 0,s }); dist[s] = 0;
    while (!q.empty()) {
        int curD = q.top().first, cur = q.top().second; q.pop();
        for (pair<int, int>p : v[cur]) {
            int next = p.first, nextD = p.second;
            if (curD + nextD < dist[next]) {
                dist[next] = curD + nextD;
                q.push({ dist[next],next });
            }
        }
    }
    return dist[e];
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> V >> E >> P;
    for (int i = 0, a, b, c; i < E; i++) {
        cin >> a >> b >> c; v[a].push_back({ b,c }); v[b].push_back({ a,c });
    }
    int a = di(1, P), b = di(P, V), c = di(1, V);
    if (a + b > c)cout << "GOOD BYE"; else cout << "SAVE HIM";
}


/*
#include <iostream>
#include <vector>
using namespace std;
int N, M, K, t;
vector<int>Map[401][401], smell[401][401];
vector<pair<int, pair<int, int>>>live;
int pHead[401], priority[5][5][401]; //priority 어디봤을 때, 우선 순위 순서, 누군지
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1, a; j <= N; j++) {
            cin >> a; if (a != 0)live.push_back({ a,{j,i} });
            Map[i][j].push_back(a); smell[i][j].push_back(a);
        }
    for (int i = 1; i <= M; i++)cin >> pHead[i];
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                cin >> priority[j][k][i];
            }
        }
    }
    while (1) {

        for (pair<int, pair<int, int>>p : live) {
            int num = p.first, x = p.second.first, y = p.second.second, d = pHead[num];
        }
        int cnt = 0;
        for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)if (Map[i][j].size() == 1)cnt++;
        if (cnt == 1) { cout << t; return; }t++;
        if (t == 1000) { cout << "-1"; return; }
    }
}

*/