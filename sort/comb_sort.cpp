/*
 * Comb Sort
 * N: the number of items in the given array
 * p: a number of increment
 * Time complexity: O(N^2 / 2^p)
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

void comb_sort(vector<int> &arr, const int n) {
	int d = (n * 10) / 13;

	while (true) {
		bool ok = true;
		for (int i = 0; i < n - d; ++i) {
			if (arr[i] > arr[i + d]) {
				swap(arr[i], arr[i + d]);
				ok = false;
			}
		}
		if (d == 1) {
			if (!ok)
				break;
		} else {
			d = (d * 10) / 13;
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
	comb_sort(arr, n);
	auto end = chrono::system_clock::now();

	cout << "after: ";
	show(arr);

	cout << "time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " [us]" << endl;
	return 0;
}