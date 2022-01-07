#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAX 1000000

int N;
int cnt = 0, i;
vector<int> T;
int primeArr[MAX] = { 0, };

void primeChk() {
	for (int i = 2; i * i < MAX; i++)
		if (!primeArr[i])
			for (int j = i * i; j < MAX; j += i)
				primeArr[j] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int sum = 0;
	int left, right;

	primeChk();
	while (1) {
		int data;
		cin >> data;
		if (data == 0)
			break;
		T.push_back(data);
	}

	for (i = 0; i < T.size(); i++) {
		int data = T[i];

		left = 3;
		right = data - 3;

		while (left <= right)
		{
			if (!primeArr[left] && !primeArr[right])
				if ((left + right) == data)
					break;
			if(left + right < data)
			left += 2;
			right -= 2;
		}
		if (left > right)
			cout << "Goldbach's conjecture is wrong.";
		else
			cout << data << " = " << left << " + " << right << "\n";
	}

	return 0;
}