#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int W0, I0, T;
	int D, I, A;

	cin >> W0 >> I0 >> T >> D >> I >> A;

	int W1 = W0, W2 = W0, B = I0, gap;

	//���� ���� ��緮�� ��ȭ�� ������� �ʾ��� ��
	W1 += D * (I - I0 - A);

	if (W1 <= 0) 
		cout << "Danger Diet\n";
	else
		cout << W1 << " " << I0 << "\n";

	//���� ���� ��緮�� ��ȭ�� ����� ��
	for (int i = 0; i < D; i++) {
		gap = I - B - A;
		W2 += gap;

		if (abs(gap) > T) {
			B += floor((double) gap / 2.0);
		}

		if (W2 <= 0 || B <= 0) {
			cout << "Danger Diet\n";
			return 0;
		}
	}

	cout << W2 << " " << B << " ";
	if ((I0 - B) > 0) {
		cout << "YOYO\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}