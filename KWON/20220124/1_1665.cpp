#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int leftSize = 0, rightSize = 0, middleN = 0, qSize = 0;
priority_queue<int> leftQ;
priority_queue<int, vector<int>, greater<int>> rightQ;
vector<int> printN;

void speak_middle(int n)
{
    if (qSize == 1)
    {
        middleN = n;
    }
    else if (qSize > 1)
    {
        if (n < middleN)
            leftQ.push(n);
        else if (n >= middleN)
            rightQ.push(n);

        if (leftQ.size() > rightQ.size())
        {
            rightQ.push(middleN);
            middleN = leftQ.top();
            leftQ.pop();
        }
        else if (leftQ.size() < rightQ.size())
        {
            if (qSize % 2 != 0)
            {
                leftQ.push(middleN);
                middleN = rightQ.top();
                rightQ.pop();
            }
        }
    }

    printN.push_back(middleN);
}

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
        qSize++;
        speak_middle(data);
    }

    for (int i = 0; i < N; i++)
        cout << printN[i] << "\n";

    return 0;
}