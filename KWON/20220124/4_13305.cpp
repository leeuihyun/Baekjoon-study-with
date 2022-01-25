#include <iostream>
using namespace std;
typedef unsigned long long ull;

int N;
ull sum = 0;
ull dis[100000];
ull price[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    int data;
    ull distance = 0;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> data;
        dis[i] = data;
        distance += data;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        price[i] = data;
    }

    ull sum = price[0] * dis[0];
    int index = 0;

    for(int i = 1; i < N - 1; i++) {
        if(price[index] > price[i])
            index = i;

        sum += price[index] * dis[i];
    }

    cout << sum;

    return 0;
}