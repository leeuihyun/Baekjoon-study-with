#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int number;
int answer;
vector<int> v;
int main(){
    cin >> number;
    while(number--){
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    if(v.size()==1){
        answer = v.front()*v.front();
    }
    else{
        answer = v.front() * v.back();
    }
    cout << answer;
    return 0;
}