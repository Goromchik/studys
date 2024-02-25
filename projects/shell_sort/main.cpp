#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <algorithm>
using namespace std;


vector<int> generateRandom(int n) {
	vector <int> a(n);
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
	return a;
}

vector<int> generateSmoothNumbers(int n) {
	vector<int> arr;
	int num = 1;

	while (arr.size() < n) {
		int t = num;
		while (t % 2 == 0) {
			t /= 2;
		}
		while (t % 3 == 0) {
			t /= 3;
		}
		if (t == 1) {
			arr.push_back(num);
		}
		num++;
	}
	return arr;
}

vector<int> shellSort(vector<int> a) {
	int k = 1;
	int n = a.size();
	vector<int> R = generateSmoothNumbers(n);
	for (int x = 0; x < R.size(); ++x) {
		if (R[x] != 0) {
			k = R[x];
			for (int i = k; i < n; ++i) {
				int temp = a[i];
				int j = i;
				for (; j >= k && a[j - k] > temp; j -= k)
					a[j] = a[j - k];
				a[j] = temp;
			}
		}
	}
	return a;

}

void printArray(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> array = generateRandom(n);
	vector<int> intervals = generateSmoothNumbers(array.size());

	cout << "Время до сортировки:" << endl;
	printArray(array);
	auto start1 = std::chrono::steady_clock::now();
	vector<int> sortedByShell = shellSort(array);
	auto end1 = std::chrono::steady_clock::now();
	std::chrono::duration<double> time1 = end1 - start1;
	cout << "Время сортировки Шелла - " << time1.count() << '\n';
	cout << "Время после сортировки Шелла:" << endl;
	printArray(sortedByShell);

	cout << "Время до обычной сортировки:" << endl;
	printArray(array);
	auto start2 = std::chrono::steady_clock::now();
	sort(array.begin(), array.end());
	auto end2 = std::chrono::steady_clock::now();
	std::chrono::duration<double> time2 = end2 - start2;
	cout << "Время обычной сортировки - " << time2.count() << '\n';
	cout << "Время после обычной сортировки:" << endl;
	printArray(array);
}