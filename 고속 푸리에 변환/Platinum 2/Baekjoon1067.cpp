#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>

using namespace std;
const double PI = acos(-1);
typedef complex<double> cpx; // complex ��� ������ include�Ͽ� ���Ҽ��� ����Ѵ�.
// imag() : ���Ҽ��� ��� ���� ��Ҹ� �����ϴ� �Լ�
// real() : ���Ҽ��� �Ǽ� ���� ��Ҹ� �����ϴ� �Լ�
typedef vector<cpx> vec;

int N;
vec A, B, C;
long long answer = 0;

// ��� Ǫ���� ��ȯ(Fast Fourier Transform) : �ְ������� N-1�� �� ���׽��� O(nlogn)�� �ð����⵵�� ������ ���� ����.
// N���� X���� ������ �ش��ϴ� �Լ��� ������ ��ȯ�� ������ �����ٸ� ��ü������ ���׽��� ���� ������ ����� �� �ִ�.
// ���׽��� ���� ���ϴ� �� �ɸ��� �� �ð��� DFT(O(nlogn)) + �ռ��������� ��(O(n)) + IDFT(O(nlogn)) = O(nlogn)�� �ȴ�.
void FFT(vec &F, cpx W) { // M-1�� ���׽� F�� M���� ���Ҽ��� DFT(Discrete Fourier Transform, �̻� Ǫ���� ��ȯ)�Ѵ�. �� �� X=W�̴�.
	int M = F.size();
	if (M == 1) { // Base Case
		return;
	}
	// ���׽��� �и��Ѵ�. ������ ���� M/2���� ������ �ִ�.
	vec Even(M >> 1);
	vec Odd(M >> 1);
	for (int i = 0; i < M; i++) {
		if (i & 1) {
			Odd[i >> 1] = F[i];
		}
		else {
			Even[i >> 1] = F[i];
		}
	}

	// ������ ���׽��� ��������� DFT�Ѵ�.(Divide)
	FFT(Even, W * W);
	FFT(Odd, W * W);

	// ��������� �ľ��� DFT ����� �̹� �Լ��� ����� ����Ѵ�.(Conquer)
	cpx WP(1, 0);
	for (int i = 0; i < (M / 2); i++) {
		F[i] = Even[i] + WP * Odd[i];
		F[i + (M / 2)] = Even[i] - WP * Odd[i];
		WP *= W;
	}
}

vec Multiply(vec S, vec E) { // IDFT(Inverse Discrete Fourier Transform) : �� ���׽� S, E�� ���� T�� ����� �����ִ� �Լ��̴�. ���⼭ i��° ���Ҵ� x^i�� ����̴�.
	int M = 1; // ���׽��� ���̺��� ū �ּ��� 2�� �ŵ��������� ã�� M���� �д�.
	while ((M <= S.size()) || (M <= E.size())) {
		M <<= 1;
	};
	M <<= 1;
	S.resize(M);
	E.resize(M);
	vec T(M);
	cpx W(cos(2 * PI / M), sin(2 * PI / M));

	// FFT�� ���Ͽ� �� ���׽��� DFT�� �ش�.
	FFT(S, W);
	FFT(E, W);

	// DFT�� ���鳢�� ���ϸ� ��� ���׽��� DFT���� �ȴ�.
	for (int i = 0; i < M; i++) {
		T[i] = S[i] * E[i];
	}

	// T�� DFT�����κ��� T�� ���׽� ���¸� �����Ѵ�.(����ȯ)
	FFT(T, cpx(1, 0) / W);
	for (int i = 0; i < M; i++) {
		T[i] /= cpx(M, 0);
		T[i] = cpx(round(T[i].real()), round(T[i].imag()));
	}
	return T;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N; // X�� Y�� ����ִ� ���� ����
	vector<int> X(N * 2); // X�� 2�� �̾�ٿ��� ���� ���Ͽ� N+N ũ��� resize
	vector<int> Y(N); // Y�� ����� ����.
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		cin >> Y[i];
	}
	for (int i = 0; i < N; i++) {
		X[i + N] = X[i];
	}

	// ���� Nĭ�� 0���� ä���.
	for (auto i : X) {
		A.push_back(cpx(i, 0));
	}
	for (auto i : Y) {
		B.push_back(cpx(i, 0));
	}
	C = Multiply(A, B);

	for (int i = 0; i < C.size(); i++) { // N-1 ~ 2N-2��° ���� �� �ִ��� ���̴�.
		answer = max<long long>(answer, round(C[i].real()));
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}