#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

int N, M;
int tomato = 0, cnt = 0;
int box[1000][1000] = {
    0,
};
queue<pair<pair<int, int>, int>> Q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool check(int x, int y)
{
    if (x >= 0 && y >= 0 && x < M && y < N)
        return true;
    return false;
}

int bfs()
{
    int x, y, day;

    while (!Q.empty())
    {
        x = Q.front().first.first;
        y = Q.front().first.second;
        day = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check(nx, ny) && box[nx][ny] == 0)
            {
                cnt++;
                box[nx][ny] = 1;
                Q.push({{nx, ny}, day + 1});
            }
        }
    }

    if (cnt == tomato)
    {
        return day;
    }
    else
        return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    cin >> M;
    tomato = N * M;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int data;
            cin >> data;
            box[i][j] = data;
            if (data == 1)
            {
                cnt++;
                Q.push({{i, j}, 0});
            }
            if (data == -1)
                tomato--;
        }
    }
    cout << bfs();

    return 0;
}