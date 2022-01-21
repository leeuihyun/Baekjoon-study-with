#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, cnt, result, hours;
bool cheese[100][100];
bool visited[100][100];
queue<pair<int, int>> Q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool check(int x, int y)
{
    if (x >= 0 && y >= 0 && x < N && y < M && !visited[x][y])
        return true;
    return false;
}

bool bfs()
{
    Q.push({0, 0});
    visited[0][0] = true;
    hours++;
    cnt = 0;

    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check(nx, ny))
            {
                if (!cheese[nx][ny])
                    Q.push({nx, ny});
                else
                {
                    cheese[nx][ny] = false;
                    cnt++;
                }
                visited[nx][ny] = true;
            }
        }
    }
    if (cnt > 0)
    {
        result = cnt;
        return false;
    }
    else
    {
        hours--;
        return true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int data;
            cin >> data;
            if (data == 1)
                cnt++;
            cheese[i][j] = data;
        }
    }

    hours = 0;

    while (true)
    {
        if (bfs())
            break;
        memset(visited, false, sizeof(visited));
    }

    cout << hours << "\n"
         << result << "\n";

    return 0;
}