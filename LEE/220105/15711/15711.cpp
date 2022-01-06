#include<iostream>
#include<algorithm>
#include<cstring>
#include <string>
#include<math.h>
#include<vector>
#include<malloc.h>
#include<deque>
#include<stack>
#include<queue>
#include <sstream>
#include <functional>
#include <map>
#include <list>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int cases;
const int MAX_NUM = 2000000;
long long a, b;
bool arr[MAX_NUM+1];
vector <int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	arr[1] = true;
	for (int i = 2; i*i < MAX_NUM; i++) {
		if (arr[i] == true) continue;
		for (int j = i * i; j < MAX_NUM; j+=i) {
			arr[j] = true;
		}
	}
	for (int i = 2; i <= MAX_NUM; i++)
		if (!arr[i])v.push_back(i);
	cin >> cases;
	while (cases--) {
		cin >> a >> b;
		
		long long number = a + b;
		if (number == 2 || number == 3) cout << "NO" << "\n";
		else if (number % 2 == 0) cout << "YES" << "\n"; //골드바흐의 추측
		else { // 수가 홀수 일 때 짝수소수는 2밖에 없으므로 -2한 값을 확인한다.
			number -= 2;
			bool check = true;
			for (int i = 0; i < v.size() && (long long)v[i]*v[i] <= number; i++) {
				if (number % v[i] == 0) {
					cout << "NO" << "\n";
					check = false;
					break;
				}
			}
			if (check == true) cout << "YES" << "\n";
		}
	}
	return 0;
}