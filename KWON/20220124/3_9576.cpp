#include <iostream>
#include <vector>
using namespace std;

int T, N, M, cnt = 0;
pair<int, int> num[1001];
bool visited[1001];
int match[1001] = {
    0,
};

bool dfs(int n)
{
    int a = num[n].first;
    int b = num[n].second;

    for (int i = a; i <= b; i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        if (match[i] == 0 || dfs(match[i]))
        {
            match[i] = n;
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;

        pair<int, int> tmp = {0, 0};
        fill(num, num + 1001, tmp);
        fill(match, match + 1001, 0);
        cnt = 0;

        int a, b;
        for (int i = 1; i <= M; i++)
        {
            cin >> a >> b;
            num[i].first = a;
            num[i].second = b;
        }

        for (int i = 1; i <= M; i++)
        {
            fill(visited, visited + 1001, false);
            if (dfs(i))
                cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}