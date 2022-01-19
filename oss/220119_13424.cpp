#pragma warning(disable:4996)
#include <stdio.h>
int T, N, M, K, a, b, c,r[101][101], p[100];
int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        int res = 2e9, room = 0;
        for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++) { r[i][j] = 1e9; if (i == j)r[i][j] = 0; }
        while (M--) { scanf("%d %d %d", &a, &b, &c); r[a][b] = c; r[b][a] = c; }
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (i == j)continue;
                    else if(r[i][k] + r[k][j] < r[i][j])r[i][j] = r[i][k] + r[k][j];
                }
            }
        }
        scanf("%d", &K);
        for (int i = 0; i < K; i++)scanf("%d", p + i);
        for (int i = 1; i <= N; i++) {
            int tmp = 0;
            for (int k = 0; k < K; k++) {
                tmp += r[i][p[k]];
            }
            if (tmp < res)res = tmp, room = i;
        }printf("%d\n", room);
    }
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