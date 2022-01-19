#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int cases;

string first_answer;
vector <char> cv;

vector<int> big;
vector<int> small;

bool torf(vector <int> v){
    for(int i=0;i<cases;i++){
        if(cv[i]=='<' && v[i] > v[i+1])return false;
        if(cv[i]=='>' && v[i] < v[i+1])return false;
    }
    return true;
}
int main(){
    cin >> cases;
    for(int i=0;i<cases;i++){
        char tmp;
        cin >> tmp;
        cv.push_back(tmp);
    }
    for(int i=0;i<=9;i++){
        big.push_back(9-i);
        small.push_back(i);
    }

    do{
        /*for(int i=0;i<cases;i++){
            if(cv[i] == '<'){
                if(big[i] > big[i+1]){
                    break;
                }
            }
            else if(cv[i] == '>'){
                if(big[i] < big[i+1]){
                    break;
                }
            }
        }*/
        if(torf(big)) break;
    }while(prev_permutation(big.begin(),big.end()));
    
    do{
        if(torf(small))break;
    }while(next_permutation(small.begin(),small.end()));
    for(int i=0;i<cases+1;i++)
        cout << big[i];
    cout << "\n";
    for(int i=0;i<cases+1;i++)
        cout << small[i];

    return 0;
}
