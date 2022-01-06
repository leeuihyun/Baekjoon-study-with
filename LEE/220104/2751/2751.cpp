#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

#define SWAP(x,y,t) (t=x,x=y,y=t)
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#define MAX 5
#define S 4

int A[1000001];
int B[1000001];
int n;
void merge_sort(int left, int right);
void merge(int left, int mid, int right);
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	merge_sort(0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d\n", A[i]);
	}
	return 0;
}

void merge_sort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

void merge(int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if (A[i] <= A[j]) B[k++] = A[i++];
		else B[k++] = A[j++];
	}
	if (i >= mid) {
		for (l = j; l <= right; l++) {
			B[k++] = A[l];
		}
	}
	if(j>=right){
		for (l = i; l <= mid; l++) {
			B[k++] = A[l];
		}
	}
	for (l = left; l <= right; l++) {
		A[l] = B[l];
	}
}