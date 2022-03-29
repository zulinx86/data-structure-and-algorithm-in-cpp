/*
 * Introspective Sort (IntroSort)
 * N: the number of items in the given array
 * Time complexity: O(N log N)
 * Space complexity: O(log N)
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>

using namespace std;

void show(const vector<int> &arr) {
	for (int val : arr)
		cout << val << " ";
	cout << endl;
}

void insertion_sort(vector<int> &arr, int left, int right) {
	for (int i = left + 1; i < right; ++i) {
		int val = arr[i];

		int j;
		for (j = i; j > left; --j) {
			if (arr[j - 1] > val)
				arr[j] = arr[j - 1];
			else
				break;
		}
		arr[j] = val;
	}
}

void heap_sort(vector<int> &arr, int left, int right) {
	const int n = right - left;

	for (int i = 1; i < n; ++i) {
		int j = i;
		while (j > 0) {
			int k = (j - 1) / 2;
			if (arr[left + k] < arr[left + j])
				swap(arr[left + k], arr[left + j]);
			j = k;
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		swap(arr[left], arr[left + i]);

		int curr = 0, next = 2 * curr + 1;
		while (next < i) {
			if (next + 1 < i && arr[left + next] < arr[left + next + 1])
				++next;

			if (arr[left + curr] < arr[left + next])
				swap(arr[left + curr], arr[left + next]);
			else
				break;

			curr = next;
			next = 2 * curr + 1;
		}
	}
}

int median_of_three(const vector<int> &arr, int p1, int p2, int p3) {
	if (arr[p1] <= arr[p2] && arr[p2] <= arr[p3])
		return p2;
	else if (arr[p1] <= arr[p3] && arr[p3] <= arr[p2])
		return p3;
	else if (arr[p2] <= arr[p1] && arr[p1] <= arr[p3])
		return p1;
	else if (arr[p2] <= arr[p3] && arr[p3] <= arr[p1])
		return p3;
	else if (arr[p3] <= arr[p1] && arr[p1] <= arr[p2])
		return p1;
	else // arr[p3] <= arr[p2] && arr[p2] <= arr[p1]
		return p2;
}

void __introspective_sort(vector<int> &arr, int left, int right, int depth_limit) {
	if (right - left <= 1)
		return;

	// insertion sort
	const int size = right - left;
	if (size < 16) {
		insertion_sort(arr, left, right);
		return;
	}

	// heap sort
	if (depth_limit == 0) {
		heap_sort(arr, left, right);
		return;
	}

	// quick sort
	int idx = median_of_three(arr, left, (left + right) / 2, right - 1);
	swap(arr[idx], arr[right - 1]);

	int p = left;
	for (int i = left; i < right - 1; ++i) {
		if (arr[i] < arr[right - 1])
			swap(arr[p++], arr[i]);
	}
	swap(arr[p], arr[right - 1]);

	__introspective_sort(arr, left, p, depth_limit - 1);
	__introspective_sort(arr, p + 1, right, depth_limit - 1);
}

void introspective_sort(vector<int> &arr, const int n) {
	int depth_limit = 2 * log(n);
	__introspective_sort(arr, 0, n, depth_limit);
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
	introspective_sort(arr, n);
	auto end = chrono::system_clock::now();

	cout << "after: ";
	show(arr);

	cout << "time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " [us]" << endl;
	return 0;
}