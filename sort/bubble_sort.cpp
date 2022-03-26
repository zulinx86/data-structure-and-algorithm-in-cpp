/*
 * Bubble Sort
 * N: the number of items in the given array
 * Time complexity: O(N^2)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void bubble_sort(vector<int> &arr, const int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void show(const vector<int> &arr) {
	for (int val : arr)
		cout << val << " ";
	cout << endl;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	random_device rnd;
	for (int i = 0; i < n; ++i)
		arr[i] = rnd() % 100;

	cout << "before: ";
	show(arr);

	bubble_sort(arr, n);

	cout << "after: ";
	show(arr);

	return 0;
}