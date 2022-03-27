/*
 * Binary Search
 * N: the number of items in the given array
 * Time complexity: O(log N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int binary_search(const vector<int> &arr, const int n, const int query) {
	int left = 0, right = n;

	while (left < right) {
		int mid = (left + right) / 2;

		if (arr[mid] == query)
			return mid;
		else if (arr[mid] < query)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	random_device rnd;
	for (int i = 0; i < n; ++i)
		arr[i] = rnd() % (10 * n);
	sort(arr.begin(), arr.end());

	auto start = chrono::system_clock::now();
	for (int i = 0; i < n; ++i) {
		int query = rnd() % (10 * n);
		int ans = binary_search(arr, n, query);
	}
	auto end = chrono::system_clock::now();

	cout << "time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " [ms]" << endl;

	return 0;
}