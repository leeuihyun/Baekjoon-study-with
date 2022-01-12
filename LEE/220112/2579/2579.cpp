#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cases;
int dp[301];
int arr[301];
int main(){
    cin >>cases;
    for(int i=1;i<=cases;i++){
        int number;
        cin >> number;
        arr[i] = number;
    }
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = dp[1]+arr[2];
    for(int i=3;i<=cases;i++){
        dp[i] = max(dp[i-2], dp[i-3]+arr[i-1])+arr[i];
    }
    cout << dp[cases];
    return 0;
}