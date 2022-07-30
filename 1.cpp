//백준 1654 랜선자르기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main() {
	fast;
	int K, N;
	cin >> K >> N;
	vector<long long> Lan;
	int Sun;
	for (int i = 0; i < K; i++) {
		cin >> Sun;
		Lan.push_back(Sun);
	}
	long long max = *max_element(Lan.begin(), Lan.end());
	long long min = 1;
	long long mid;
	long long search = 0;
	while (min <= max) {
		mid = (min + max) / 2;
		long long sum = 0;
		for (int i = 0; i < K; i++) {
			sum += Lan[i] / mid;
		}
		if (sum < N) max = mid - 1;
		else {
			if (search<mid) search = mid;
			min = mid + 1;
		}
	}
	cout << search;
}