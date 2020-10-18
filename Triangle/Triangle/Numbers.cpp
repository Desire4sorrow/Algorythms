/*
3.4. K-ичные числа (4)
Найти количество натуральных N-значных (1 ≤ N ≤ 20) чисел в системе счисления с
основанием K (2 ≤ K ≤ 8), таких, что их запись не содержит двух подряд идущих нулей.
Ввод из файла INPUT.TXT. В единственной строке содержатся числа N и K в десятичной
записи, разделенные пробелом.
Вывод в файл OUTPUT.TXT. Программа должна выдать искомое число в десятичной записи.
Санархин Руслан ПС-32
Microsoft Visual C++ 2019
*/
#include <iostream>
#include <fstream>

using namespace std; 

int main() 
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	uint64_t n, k, func;
	uint64_t count = 2;
	func = 1;
	fin >> n >> k;

	uint64_t amount[20];
	amount[1] = k - 1;

	for (count = 2; count <= n;) //целое больше 1 и не превышающее N
	{
		amount[func] = amount[count - 1] + amount[count - 2];
		amount[count] = amount[func] * (k - 1);
		++count;
	}

	fout << amount[n];
	fin.close();
	fout.close();
	return 0;
}