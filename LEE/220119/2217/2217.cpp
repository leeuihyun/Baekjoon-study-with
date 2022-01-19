#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int cases;
int answer;
int sum;

vector <int> v;
int main(){
    cin >> cases;
    for(int i=0;i<cases;i++){
        int number;
        cin >> number;
        v.push_back(number);
    }
    sort(v.begin(),v.end());
    answer = v.front()*cases;
    for(int i=1;i<v.size();i++){
        answer = max(answer, v[i]*(cases-i));
    }
    cout << answer;
    
    return 0;
}