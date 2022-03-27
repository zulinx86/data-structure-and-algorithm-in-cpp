/*
 * Linear Search
 * N: the number of items in the given array
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int linear_search(const vector<int> &arr, const int n, const int query) {
	for (int i = 0; i < n; ++i) {
		if (arr[i] == query)
			return i;
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

	auto start = chrono::system_clock::now();
	for (int i = 0; i < n; ++i) {
		int query = rnd() % (10 * n);
		int ans = linear_search(arr, n, query);
	}
	auto end = chrono::system_clock::now();

	cout << "time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " [ms]" << endl;
	return 0;
}