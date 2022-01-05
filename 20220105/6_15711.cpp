#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 2000001

int N;
int cnt = 0, i;
bool primeArr[MAX] = { false, };
vector<long> primeN;

void primeChk() {
	primeArr[1] = true;
	for (int i = 2; i < MAX; i++)
		if (!primeArr[i]) {
			primeN.push_back(i);
			for (int j = i * 2; j < MAX; j += i)
				primeArr[j] = true;
		}
}
bool isPrime(long num) {
	if (num < MAX)
		return !primeArr[num];
	else {
		for (int i = 0; i < primeN.size(); i++) {
			if (num % primeN[i] == 0)
				return false;
		}
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	primeChk();

	cin >> N;
	for(int i = 0; i < N; i++) {
		long data1, data2;
		long sum;
		cin >> data1 >> data2;
		sum = data1 + data2;
		if (sum <= 3) cout << "NO\n";
		else if ((sum % 2) == 0) cout << "YES\n";
		else {
			long n = sum - 2;
			if(isPrime(n))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}