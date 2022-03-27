/*
 * Gnome Sort
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

void gnome_sort(vector<int> &arr, const int n) {
	int i = 0;
	while (i < n) {
		if (i == 0 || arr[i] >= arr[i - 1]) {
			i = i + 1;
		} else {
			swap(arr[i], arr[i - 1]);
			i = i - 1;
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
	gnome_sort(arr, n);
	auto end = chrono::system_clock::now();

	cout << "after: ";
	show(arr);

	cout << "time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " [us]" << endl;
	return 0;
}