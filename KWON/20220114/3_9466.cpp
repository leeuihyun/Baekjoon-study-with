#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstring>
using namespace std;

int T, N, cnt = 0;
int A[100001];
bool visited[100001];
bool team[100001];

void dfs(int index)
{
    visited[index] = true;

    int next = A[index];

    if (!visited[next])
        dfs(next);
    else if(visited[next] && !team[next]) {
        int i = next;
        while(i != index) {
            cnt++;
            i = A[i];
        }
        cnt++;
    }

    team[index] = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> T;

    while (T--)
    {
        memset(A, false, sizeof(A));
        memset(team, false, sizeof(team));
        memset(visited, false, sizeof(visited));

        cin >> N;

        for (int i = 1; i <= N; i++)
        {
            int data;
            cin >> data;
            A[i] = data;
        }
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }

        cout << N - cnt << "\n";

        cnt = 0;
    }
    return 0;
}