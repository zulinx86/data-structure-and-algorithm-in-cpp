/*
 * Heap Sort
 * N: the number of items in the given array
 * Time complexity: O(N log N)
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

void heap_sort(vector<int> &arr, const int n) {
	// heapify
	for (int i = 1; i < n; ++i) {
		int j = i;
		while (j > 0) {
			int k = (j - 1) / 2;
			if (arr[k] < arr[j])
				swap(arr[k], arr[j]);
			j = k;
		}
	}

	// pop from heap
	for (int m = n - 1; m >= 0; --m) {
		swap(arr[0], arr[m]);

		int curr = 0, next = 2 * curr + 1;
		while (next < m) {
			if (next + 1 < m && arr[next] < arr[next + 1])
				++next;

			if (arr[curr] < arr[next])
				swap(arr[curr], arr[next]);

			curr = next;
			next = 2 * curr + 1;
		}
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
	heap_sort(arr, n);
	auto end = chrono::system_clock::now();

	cout << "after: ";
	show(arr);

	cout << "time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " [us]" << endl;
	return 0;
}