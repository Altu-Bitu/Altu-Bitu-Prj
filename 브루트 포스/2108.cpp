#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int arr[500001];
int cnt[8001];
int N, sum = 0, flag;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> arr[i];
		sum += arr[i];
		cnt[arr[i] + 4000]++;
	}

	sort(arr, arr + N);

	int max = 0;

	for (int i = 0; i < 8001; i++){
		if (cnt[i] > max) {
			max = cnt[i];
			flag = i;
		}
	}

	for (int i = flag + 1; i < 8001; i++){
		if (cnt[i] == max){
			flag = i;
			break;
		}
	}

	cout << round(double(sum) / N) << "\n";
	cout << arr[(N - 1) / 2] << "\n";
	cout << flag - 4000 << "\n";
	cout << arr[N - 1] - arr[0] << "\n";
}