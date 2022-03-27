/*
 * Quick Sort
 * N: the number of items in the given array
 * Average time complexity: O(N log N)
 * Worst time complexity: O(N)
 * Space complexity: O(log N)
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

static void __quick_sort(vector<int> &arr, int left, int right) {
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	int pivot = arr[mid];
	swap(arr[mid], arr[right]);

	int i = left;
	for (int j = left; j < right; ++j) {
		if (arr[j] < pivot)
			swap(arr[i++], arr[j]);
	}
	swap(arr[i], arr[right]);

	if (i - left <= right - i) {
		__quick_sort(arr, left, i - 1);
		__quick_sort(arr, i + 1, right);
	} else {
		__quick_sort(arr, i + 1, right);
		__quick_sort(arr, left, i - 1);
	}
}

void quick_sort(vector<int> &arr, const int n) {
	__quick_sort(arr, 0, n - 1);
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
	quick_sort(arr, n);
	auto end = chrono::system_clock::now();

	cout << "after: ";
	show(arr);

	cout << "time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " [us]" << endl;
	return 0;
}