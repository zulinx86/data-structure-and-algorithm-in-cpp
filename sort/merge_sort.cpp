/*
 * Merge Sort
 * N: the number of items in the given array
 * Time complexity: O(N log N)
 * Space complexity: O(N)
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

void __merge_sort(vector<int> &arr, int left, int right, vector<int> &buf) {
	if (left + 1 >= right)
		return;

	int mid = (left + right) / 2;
	__merge_sort(arr, left, mid, buf);
	__merge_sort(arr, mid, right, buf);

	for (int i = left; i < mid; ++i)
		buf[i] = arr[i];

	int idx = left, i = left, j = mid;
	while (i < mid && j < right) {
		if (buf[i] <= arr[j])
			arr[idx++] = buf[i++];
		else
			arr[idx++] = arr[j++];
	}

	while (i < mid)
		arr[idx++] = buf[i++];
}

void merge_sort(vector<int> &arr, int n) {
	vector<int> buf(n);
	__merge_sort(arr, 0, n, buf);
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
	merge_sort(arr, n);
	auto end = chrono::system_clock::now();

	cout << "after: ";
	show(arr);

	cout << "time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " [us]" << endl;
	return 0;
}