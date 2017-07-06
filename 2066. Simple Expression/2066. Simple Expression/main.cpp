#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

#ifndef ONLINE_JUDGE
	#include <Windows.h> // Нужна для установки цвета консоли
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
	// Запускается в проверяющей системе
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
	Запускается в процессе разработки
	В цикле запускает все тест кейсы и выводит в консоль результат:
		* зелёный цвет - тест удачный
		* красный цвет - тест провален
	*/
	setlocale(LC_ALL, "Russian");

	// Создание функции для устанвки цвета
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
			setConsoleColor(12); // Красный цвет
		}
		else {
			setConsoleColor(10); // Зелёный цвет
		}
		cout << i + 1 << ". Ожидаемое значение: " << testCases[i].second << ". Полученное значение: " << result << endl;
	}
	setConsoleColor(15); // Серый цвет
	system("pause");
}