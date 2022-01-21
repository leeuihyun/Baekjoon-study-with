#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N, M;
int A[1000][1000] = {
    0,
};
bool visited[1000][1000][2]; // 0이 벽을 부순 경우, 1이 벽을 부수지 않은 경우
queue<pair<pair<int, int>, pair<int, int>>> Q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool check(int x, int y)
{
    if (x >= 0 && y >= 0 && x < N && y < M)
        return true;
    return false;
}

int bfs()
{
    while (!Q.empty())
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int wall = Q.front().second.first;
        int distance = Q.front().second.second;
        Q.pop();

        if (x == N - 1 && y == M - 1)
        {
            return distance;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check(nx, ny))
            {
                if (!A[nx][ny] && !visited[nx][ny][wall])
                {
                    visited[nx][ny][wall] = 1;
                    Q.push({{nx, ny}, {wall, distance + 1}});
                }
                else if (A[nx][ny] && wall == 0)
                {
                    visited[nx][ny][wall + 1] = 1;
                    Q.push({{nx, ny}, {wall + 1, distance + 1}});
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++)
        {
            A[i][j] = input[j] - '0';
            // scanf("%1d", &A[i][j]); 로 받았더니 틀렸다.
        }
    }

    Q.push({{0, 0}, {0, 1}});
    visited[0][0][0] = true;

    int result = bfs();
    cout << result;

    return 0;
}
