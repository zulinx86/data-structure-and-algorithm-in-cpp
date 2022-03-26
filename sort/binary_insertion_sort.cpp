/*
 * Binary Insertion Sort
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

void binary_insertion_sort(vector<int> &arr, const int n) {
	for (int i = 1; i < n; ++i) {
		int left = 0, right = i;

		while (left < right) {
			int mid = (left + right) / 2;
			if (arr[mid] <= arr[i]) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}

		int val = arr[i];
		for (int j = i; j > left; --j)
			arr[j] = arr[j - 1];
		arr[left] = val;
	}
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

	binary_insertion_sort(arr, n);

	cout << "after: ";
	show(arr);

	return 0;
}