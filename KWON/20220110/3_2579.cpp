#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int m[301] = { 0, };
int score[301] = { 0, };
int result = 0;

void stairsGame() {
	m[1] = score[1];
	m[2] = score[1] + score[2];
	m[3] = max(score[1] + score[3], score[2] + score[3]);

	for (int i = 4; i <= N; i++) {
		m[i] = max(m[i - 2] + score[i], m[i - 3] + score[i - 1] + score[i]);
	}

	cout << m[N];
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> score[i];

	stairsGame();

	return 0;
}