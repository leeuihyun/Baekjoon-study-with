#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, sum = 0;
priority_queue<int, vector<int>, greater<int>> card;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int data;

    for (int i = 0; i < N; i++)
    {
        cin >> data;
        card.push(data);
    }

    int a, b;
    a = card.top();
    card.pop();
    while (!card.empty())
    {
        b = card.top();
        card.pop();

        sum += a + b;
        card.push(a + b);

        a = card.top();
        card.pop();
    }

    cout << sum;

    return 0;
}