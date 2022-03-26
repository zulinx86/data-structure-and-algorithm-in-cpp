#include <iostream>
#include <vector>
#include <random>

using namespace std;

void bubble_sort(vector<int> &arr, const int n) {
	for (int i = 0; i < n; ++i) {
		int min_idx = i, min_val = arr[i];
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] <= min_val) {
				min_idx = j;
				min_val = arr[j];
			}
		}			
		arr[min_idx] = arr[i];
		arr[i] = min_val;
	}
}

void show(const vector<int> &arr) {
	for (int val : arr)
		cout << val << " ";
	cout << endl;
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

	bubble_sort(arr, n);

	cout << "after: ";
	show(arr);

	return 0;
}