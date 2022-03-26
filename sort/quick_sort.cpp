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

	int pivot = arr[left];
	int lower = left, upper = right;
	while (lower < upper) {
		while (lower < upper && arr[upper] > pivot)
			--upper;

		while (lower < upper && arr[lower] <= pivot)
			++lower;

		swap(arr[lower], arr[upper]);
	}

	swap(arr[left], arr[upper]);
	__quick_sort(arr, left, upper - 1);
	__quick_sort(arr, upper + 1, right);
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
		arr[i] = rnd() % 100;

	cout << "before: ";
	show(arr);

	quick_sort(arr, n);

	cout << "after: ";
	show(arr);

	return 0;
}