#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

#ifndef ONLINE_JUDGE
	#include <Windows.h> // ����� ��� ��������� ����� �������
	#include <functional>
#endif

using namespace std;

vector<int> readInput();
int calculate(vector<int> input);
void writeOutput(int result);

#ifndef ONLINE_JUDGE
	template<typename inputType, typename outputType>	
	void runTests();
#endif

FILE *stream;

int main() {
#ifdef ONLINE_JUDGE
	// ����������� � ����������� �������
	vector<int> input = readInput();
	int result = calculate(input);
	writeOutput(result);
#else
	runTests<vector<int>, int>();
#endif
	return 0;
}

vector<int> readInput() {
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> result{ a, b, c };
	return result;
}

int calculate(vector<int> input) {
	sort(input.begin(), input.end());
	int subtrahend = input[1] <= 1 ? input[1] + input[2] : input[1] * input[2];
	return input[0] - subtrahend;
}

void writeOutput(int result) {
	cout << result << endl;
}

template <typename inputType, typename outputType>
void runTests() {
	/* 
	����������� � �������� ����������
	� ����� ��������� ��� ���� ����� � ������� � ������� ���������:
		* ������ ���� - ���� �������
		* ������� ���� - ���� ��������
	*/
	setlocale(LC_ALL, "Russian");

	// �������� ������� ��� �������� �����
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	auto setConsoleColor = std::bind1st(ptr_fun(SetConsoleTextAttribute), hConsole);

	vector<pair<inputType, outputType>> testCases = {
		{ { 1, 2, 3 }, -5 },
		{ { 0, 0, 2 }, -2 },
		{ { 0, 1, 2 }, -3 }
	};

	for (size_t i = 0; i < testCases.size(); i++) {
		inputType &input = testCases[i].first;
		outputType result = calculate(input);
		if (result != testCases[i].second) {
			setConsoleColor(12); // ������� ����
		}
		else {
			setConsoleColor(10); // ������ ����
		}
		cout << i + 1 << ". ��������� ��������: " << testCases[i].second << ". ���������� ��������: " << result << endl;
	}
	setConsoleColor(15); // ����� ����
	system("pause");
}