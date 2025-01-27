#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
// 랜선 자르기 -> 시간초과 
int main() {
	int K = 0;//이미 오영식이 가지고 있는 랜선의 개수
	cin >> K;
	int* arr = new int[K];
	int N = 0; // 필요한 랜선의 개수 
	cin >> N;
	long long int sum = 0;
	int max = 0;
	for (int i = 0; i < K; i++) {
		cin >> arr[i]; // 센티미터 단위 
		sum = sum + arr[i];
		if (max < arr[i]) {
			max = arr[i];
		}

	}
	int count = 0;
	long long int cm = sum / N;
	long long int nextcm = cm;
	long long int maxCM = 0;
	while (1) {
		count = 0;
		cm = nextcm;
		nextcm = 0;
		for (int i = 0; i < K; i++) {
			count = count + arr[i]/cm; // 몫
			if (nextcm < arr[i] / (arr[i] / cm + 1)) {
				nextcm = arr[i] / (arr[i] / cm + 1);
			}
		}
		if (count >= N ) {
			maxCM = cm;
			break;
		}
	}
	cout << maxCM << '\n';


}
