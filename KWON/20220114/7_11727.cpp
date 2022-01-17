#include <iostream>
using namespace std;

int N, result[1001] = {
           0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    result[0] = 1;
    result[1] = 3;
    for (int i = 2; i < N; i++)
    {
        result[i] = (result[i - 1] + 2 * result[i - 2]) % 10007;
    }

    cout << result[N - 1];

    return 0;
}