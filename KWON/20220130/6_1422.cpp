#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int K, N, i, j, cnt;
vector<pair<vector<int>, int>> v;

bool compare(pair<vector<int>, int> a, pair<vector<int>, int> b)
{
    if (a.second == b.second)
    {
        for (int k = 0; k < a.second; k++)
        {
            if (a.first[k] > b.first[k])
                return true;
            else if (a.first[k] < b.first[k])
                return false;
        }
        return false;
    }
    else
    {
        int aI = 0, bI = 0;
        while (aI < a.second && bI < b.second)
        {
            if (aI == a.second - 1 && bI == b.second - 1)
                break;
            if (a.first[aI] == b.first[bI])
            {
                cout << a.first[aI] << ", " << b.first[bI] << " : equal\n";
                if (aI + 1 != a.second)
                    aI++;
                if (bI + 1 != b.second)
                    bI++;
            }
            
            if (a.first[aI] > b.first[bI])
            {
                cout << a.first[aI] << ", " << b.first[bI] << " : true\n";
                return true;
            }
            else if (a.first[aI] < b.first[bI])
            {
                cout << a.first[aI] << ", " << b.first[bI] << " : false\n";
                return false;
            }
        }
        if (a.second < b.second)
            return true;
        else
            return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;
    string s, max = "";

    for (i = 0; i < K; i++)
    {
        cin >> s;
        cnt = 0;
        if (max < s)
            max = s;
        vector<int> tmp;
        for (j = 0; j < s.length(); j++)
            tmp.push_back(s[j] - '0');
        cnt = j;
        v.push_back({tmp, cnt});
    }
    for (i; i < N; i++)
    {
        vector<int> tmp;
        cnt = 0;
        for (j = 0; j < max.length(); j++)
            tmp.push_back(max[j] - '0');
        cnt = j;
        v.push_back({tmp, cnt});
    }

    sort(v.begin(), v.end(), compare);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < v[i].second; j++)
            cout << v[i].first[j];
    }

    return 0;
}