#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll A, B, V;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> V;

    int cnt = 0;

    cnt = (V - B) / (A - B);

    if ((V - B) % (A - B) != 0)
        cnt++;

    cout << cnt;

    return 0;
}