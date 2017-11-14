#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

int newNumber(int size) {
	int res = 0;
	while (size) {
		res = res * 10 + rand() % 10;
		size--;
	}
	return res;
}

void input(int *a, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		a[i] = newNumber(1 + rand() % 5);
}

int FindLongestNumber(int *a, int size) {
	int sol = 0;
	for (int i = 0; i < size; i++) {
		int tempNumber = a[i], tempSize = 0;
		while (tempNumber) {
			tempSize++;
			tempNumber /= 10;
		}
		if (tempSize > sol)
			sol = tempSize;
	}
	return sol;
}

void RadixSort(int *a, int size) {
	int d = FindLongestNumber(a, size), p = 10;
	vector<int> matrix[10];
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < size; j++)
			matrix[(a[j] % p) / (p / 10)].push_back(a[j]);
		for(int j = 9, cnt = size - 1; j >= 0; j--)
			while (matrix[j].size()) {
				a[cnt--] = matrix[j].back();
				matrix[j].pop_back();
			}
		p *= 10;
	}
}


void QuickSort(int l, int r, int *a) {
	if (r <= l) return;

	int pivotIndex = l, pivotValue = a[l];
	for (int i = l + 1; i <= r; i++)
		if (a[i] < pivotValue)
			swap(a[++pivotIndex], a[i]);

	swap(a[pivotIndex], a[l]);
	QuickSort(l, pivotIndex - 1, a);
	QuickSort(pivotIndex + 1, r, a);
}

void MergeSort(int l, int r, int *a) {
	if (r <= l) return; //base case

	int s = (l + r) / 2;
	MergeSort(l, s, a);
	MergeSort(s + 1, r, a);

	int left = l, right = s + 1, index = 0;
	int *newArray = new int[r - l + 1];
	while (left <= s && right <= r)
		if (a[left] < a[right]) newArray[index++] = a[left++];
		else newArray[index++] = a[right++];

	while (left <= s) newArray[index++] = a[left++];
	while (right <= r) newArray[index++] = a[right++];

	for (int i = l; i <= r; i++)
		a[i] = newArray[i - l];

	delete[] newArray;
}

void output(int *a, int size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	int a[10];
	input(a, 10);
	output(a, 10);
	//RadixSort(a, 10);
	//QuickSort(0, 9, a);
	//MergeSort(0, 9, a);
	output(a, 10);


	return 0;
}
