#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int k;
vector<char> arr;
vector<string> ans;
bool used[10];

bool check(int index, int a, int b)
{
    if (arr[index] == '>' && a < b)
        return false;
    else if (arr[index] == '<' && a > b)
        return false;
    return true;
}

void solve(string s, int index)
{
    if (index == k + 1)
    {
        ans.push_back(s);
        return;
    }
    else
    {
        int num = s[index - 1] - '0';
        for (int i = 0; i <= 9; i++)
        {
            if (used[i])
                continue;
            if (index == 0 || check(index - 1, num, i))
            {
                used[i] = true;
                solve(s + to_string(i), index + 1);
                used[i] = false;
            };
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    char input;
    string tmp = "";

    for (int i = 0; i < k; i++)
    {
        cin >> input;
        arr.push_back(input);
    }

    solve(tmp, 0);

    auto result = minmax_element(ans.begin(), ans.end());

    cout << *result.second << "\n";
    cout << *result.first;

    return 0;
}