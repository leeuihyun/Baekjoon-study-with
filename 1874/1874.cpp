#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <char> answer;
stack <int> st;

int n;
int idx = 0;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while(n--){
        int number;
        cin >> number;
        if(number >= idx){
            while(number > idx){
                st.push(++idx);
                answer.push_back('+');
            }
            st.pop();
            answer.push_back('-');
        }
        else{
            if(!st.empty()){
                if(number == st.top()){ //오름차순이라서
                    st.pop();
                    answer.push_back('-');
                }
                else{
                    cout << "NO";
                    exit(0);
                }
            }
            else{
                cout << "NO";
                exit(0);
            }
        }
    }
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << "\n";
    }
    return 0;
}