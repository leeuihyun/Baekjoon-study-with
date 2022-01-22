#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N, x;
priority_queue<int> big; //원래 pq
priority_queue<int,vector<int>,greater<int>> small; //오름차순
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0) //출력부분
		{
			if (small.empty() && big.empty()) cout << "0" << "\n";
			else 
			{
				if (small.empty())
				{
					cout << big.top() << "\n";
					big.pop();
				}
				else if (big.empty())
				{
					cout << small.top() << "\n";
					small.pop();
				}
				else
				{
					if (small.top() < big.top()*-1)
					{
						cout << small.top() << '\n';
						small.pop();
					}
					else
					{
						cout << big.top() << '\n';
						big.pop();
					}
				}
			}
		}
		else if (x > 0) 
		{
			small.push(x);
		}
		else 
		{
			big.push(x);
		}
	}

}