#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;

int N, hSize = 0;
ull x;
ull mh[100000] = {
    0,
};
vector<ull> printV;

void printRoot()
{
    if (hSize == 0)
        printV.push_back(0);
    else
    {
        printV.push_back(mh[1]);

        mh[1] = mh[hSize];
        mh[hSize] = 0;
        hSize--;

        int parent = 1, child = 2;
        while (child <= hSize)
        {
            if (child + 1 <= hSize && mh[child] > mh[child + 1])
                child = child + 1;
            if (mh[parent] < mh[child])
                break;

            ull tmp = mh[child];
            mh[child] = mh[parent];
            mh[parent] = tmp;

            parent = child;
            child = parent * 2;
        }
    }
}

void insertHeap(ull data)
{
    hSize++;
    mh[hSize] = data;

    int child = hSize, parent = child / 2;

    while (parent >= 1)
    {
        if (mh[child] > mh[parent])
            break;

        ull tmp = mh[child];
        mh[child] = mh[parent];
        mh[parent] = tmp;

        child = parent;
        parent = child / 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x == 0)
            printRoot();
        else
            insertHeap(x);
    }

    for (int i = 0; i < printV.size(); i++)
        cout << printV[i] << "\n";

    return 0;
}