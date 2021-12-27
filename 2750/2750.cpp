#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//정렬이용
int n;
vector <int> v;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int number;
        cin >> number;
        v.push_back(number);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout << v[i] << "\n";
    }
    return 0;
}   