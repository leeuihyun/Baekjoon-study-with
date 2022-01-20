#include <iostream>
using namespace std;

int N, K;
int A[10] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int data;
    int index = 0, sum = 0, count = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> data;
        A[i] = data;
        if (A[i] <= K)
            index = i;
    }

    while (index >= 0)
    {
        sum += A[index];
        count++;

        if (sum > K)
        {
            sum -= A[index];
            count--;
            index--;
        }
        else if (sum == K)
            break;
    }

    cout << count;

    return 0;
}