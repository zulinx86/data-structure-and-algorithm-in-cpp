/*
 * Selection Sort
 * N: the number of items in the given array
 * Time complexity: O(N^2)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void show(const vector<int> &arr) {
	for (int val : arr)
		cout << val << " ";
	cout << endl;
}

void selection_sort(vector<int> &arr, const int n) {
	for (int i = 0; i < n; ++i) {
		int minval = arr[i], minidx = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < minval) {
				minval = arr[j];
				minidx = j;
			}
		}
		swap(arr[i], arr[minidx]);
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	random_device rnd;
	for (int i = 0; i < n; ++i)
		arr[i] = rnd() % 1000;

	cout << "before: ";
	show(arr);

	auto start = chrono::system_clock::now();
	selection_sort(arr, n);
	auto end = chrono::system_clock::now();

	cout << "after: ";
	show(arr);

	cout << "time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " [us]" << endl;
	return 0;
}