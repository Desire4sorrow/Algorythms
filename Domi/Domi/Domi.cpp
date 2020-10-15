/*
19.2. Домино (3)
Найти количество вариантов покрытия прямоугольника 2×N прямоугольниками 2×1.
Покрытия, которые преобразуются друг в друга симметриями, считать различными.
Ввод. В единственной строке входного файла INPUT.TXT задано значение N (1 ≤ N ≤ 20).
Вывод. В единственной строке выходного файла OUTPUT.TXT должно содержаться
количество вариантов покрытия прямоугольника.

Выполнил: Санархин Руслан ПС-32
Среда разработки: Visual studio 2019
*/


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int N = 0;
	int previous = 2;
	int prevM = 1;

	ifstream in("input.txt");
	ofstream out("output.txt");
	int result = 0;
	in >> N;

	if (N == 1)
	{
		result = 1;
		out << result << endl;
	}
	else if (N == 2)
	{
		result = 2;
		out << result << endl;
	}
	else
	{
		for (int i = 2; i != N; i++)
		{
			result = previous + prevM;
			prevM = previous;
			previous = result;
		}
		out << result << endl;
	}
}