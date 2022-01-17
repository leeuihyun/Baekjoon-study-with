#include <iostream>
#include <cmath>

using namespace std;

int cases;
int arr[10001];
int dp[10001];
int answer = 0;
int main(){
    cin >>cases;
    for(int i=1;i<=cases;i++){
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = dp[1]+arr[2];
    for(int i=3;i<=cases;i++){
        dp[i] = max(dp[i-3]+arr[i-1],dp[i-2])+arr[i];
        dp[i] = max(dp[i],dp[i-1]);
    }
    cout << dp[cases];
    return 0;
}