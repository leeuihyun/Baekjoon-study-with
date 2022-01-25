#include <iostream>
#include <queue>

using namespace std;

int cases;

priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int> max_pq;

int current_number;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    cin >> cases;
    while (cases--)
    {
        int number;
        cin >> number;
        if (max_pq.size() == min_pq.size())
        {
            max_pq.push(number);
        }
        else
        {
            min_pq.push(number);
        }
        if (!max_pq.empty() && !min_pq.empty() && max_pq.top() > min_pq.top())
        {
            int max_val, min_val;
            max_val = max_pq.top();
            min_val = min_pq.top();
            max_pq.pop();
            min_pq.pop();
            max_pq.push(min_val);
            min_pq.push(max_val);
        }
        cout << max_pq.top() << "\n";
    }
    return 0;
}