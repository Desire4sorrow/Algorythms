/*20.4. Циклический сдвиг (5)
Последовательность круглых скобок называют правильной, если можно добавить в нее числа и
знаки арифметических операций так, что полученное алгебраическое выражение станет
корректным. Например, скобочная последовательность (())() является правильной, а (())) и ())(()
такими не являются.
Задана скобочная последовательность из N символов (1 ≤ N ≤ 6×10 5 ). Найти минимальный
номер позиции, начиная с которой последовательность, образованная циклическим сдвигом,
окажется правильной скобочной последовательностью.
Ввод из файла INPUT.TXT. В первой строке задано значение N. Во второй строке находится
скобочная последовательность длины N.
Вывод в файл OUTPUT.TXT. Вывести номер позиции. Если правильную скобочную
последовательность получить невозможно, вывести No.
Санархин Руслан, ПС-32
Visual Studio 2019*/

#include <iostream>
#include <fstream>

using namespace std;


unsigned int FindCorrectSequence(ifstream& in, int number) {
	unsigned int index_position = 1;
	int indicator = 0;
	bool flag_right_bracket = false;
	char ch;
	for (int i = 0; i < number; i++) {
		in >> ch;
		if (ch == '(') {
			indicator++;
			if ((flag_right_bracket == true) and (indicator <= 0)) {
				index_position = i + 1;
				flag_right_bracket = false;
			}
		}
		else {
			indicator--;
			if (index_position == 1) {
				flag_right_bracket = true;
			}
		}
	}
	if (indicator != 0) {
		index_position = 0;
	}
	return index_position;
}

int main()
{
	ifstream in("input.txt");
	unsigned int number;
	in >> number;

	unsigned int result = FindCorrectSequence(in, number);

	ofstream out("output.txt");
	if (result != 0) {
		out << result;
	}
	else {
		out << "No";
	}

}