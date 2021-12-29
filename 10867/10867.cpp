#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int number;
vector <int> v;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> number;
    for(int i=0;i<number;i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    return 0;
}