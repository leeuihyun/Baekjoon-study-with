#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
vector <int> v;
int answer;

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int number;
        cin >>number;
        v.push_back(number);
    }
    sort(v.begin(),v.end(),greater<>());
    for(int i=0;i<n;i++){
        if(v[i] > k) continue;
        answer+=k/v[i];
        k%=v[i];
        if(k==0)break;
    }
    cout << answer;
    return 0;
}