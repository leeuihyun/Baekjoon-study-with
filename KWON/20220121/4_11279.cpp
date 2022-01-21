#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int N, hSize = 0;
ll x, mh[100000] = {
          0,
};
vector<ll> result;

void insertHeap(int data)
{
    hSize++;
    mh[hSize] = data;
    int parent = hSize / 2, child = hSize;
    while (parent >= 1)
    {
        if (mh[parent] > mh[child])
            break;

        ll tmp = mh[child];
        mh[child] = mh[parent];
        mh[parent] = tmp;
        child = parent;
        parent = child / 2;
    }
}

void printHeap()
{
    if (hSize == 0)
        result.push_back(0);
    else
    {
        result.push_back(mh[1]);
        mh[1] = mh[hSize];
        mh[hSize] = 0;
        hSize--;
        int parent = 1, child = 2;
        while (child <= hSize)
        {
            if (child + 1 <= hSize && mh[child] < mh[child + 1])
                child = child + 1;
            if (mh[parent] > mh[child])
                break;

            ll tmp = mh[child];
            mh[child] = mh[parent];
            mh[parent] = tmp;
            parent = child;
            child = parent * 2;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x == 0)
            printHeap();
        else
            insertHeap(x);
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";

    return 0;
}