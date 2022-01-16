#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K, cnt;
int rect[101][101];
bool visited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>> Q;
vector<int> result;

bool check(int x, int y)
{
    if (x >= 0 && x < M && y >= 0 && y < N && !visited[x][y])
        return true;
    return false;
}

int bfs(int r, int c)
{
    int area = 1;
    visited[r][c] = true;
    Q.push({r, c});

    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int l = 0; l < 4; l++)
        {
            int nx = x + dx[l];
            int ny = y + dy[l];

            if (check(nx, ny) && rect[nx][ny] == 0)
            {
                Q.push({nx, ny});
                area++;
                visited[nx][ny] = true;
            }
        }
    }

    return area;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cnt = 0;

    cin >> M >> N >> K;

    int x1, x2, y1, y2;

    for (int i = 0; i < K; i++)
    {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        for (int k = y1; k < y2; k++)
        {
            for (int j = x1; j < x2; j++)
            {
                rect[k][j] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (rect[i][j] == 0 && !visited[i][j])
            {
                cnt++;
                result.push_back(bfs(i, j));
            }
        }
    }

    cout << cnt << "\n";
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}