#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector <int> v;

int main(){
    cin >> n >>m;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    do{
        for(int i=0;i<m;i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        reverse(v.begin()+m, v.end());
    }while(next_permutation(v.begin(),v.end()));
    return 0;
}