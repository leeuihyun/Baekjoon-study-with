#include <iostream>
#include <stdlib.h>
#include <queue>
#include <tuple>
using namespace std;

int N, M, H;
int tomato = 0, cnt = 0;
short box[1000][1000][100] = {
    0,
};
queue<pair<tuple<short, short, short>, int>> Q;
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

bool check(short x, short y, short z)
{
    if (x >= 0 && y >= 0 && x < M && y < N && z >= 0 && z < H)
        return true;
    return false;
}

int bfs()
{
    int x, y, z, day;

    while (!Q.empty())
    {
        x = get<0>(Q.front().first);
        y = get<1>(Q.front().first);
        z = get<2>(Q.front().first);

        day = Q.front().second;
        Q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (check(nx, ny, nz) && box[nx][ny][nz] == 0)
            {
                cnt++;
                box[nx][ny][nz] = 1;
                Q.push({{nx, ny, nz}, day + 1});
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
    cin >> H;
    tomato = N * M * H;

    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int data;
                cin >> data;
                box[i][j][k] = data;
                if (data == 1)
                {
                    cnt++;
                    Q.push({{i, j, k}, 0});
                }
                if (data == -1)
                    tomato--;
            }
        }
    }
    cout << bfs();

    return 0;
}