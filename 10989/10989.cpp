#include <iostream>
#include <vector>

using namespace std;

int n;
int idx = 0;
vector <int> v(10001,0);

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int number;
        cin >> number;
        v[number]+=1;
    }
    while(idx!=v.size()){
        if(v[idx]==0){
            idx+=1;
            continue;
        }
        cout << idx << "\n";
        v[idx]-=1;
    }
    return 0;
}

