/*20.6. Крестики-нолики (4)
Два студента, вернувшись из академического отпуска, снова играют на лекции в крестики-
нолики на поле размера M×N. Чтобы было интереснее, они ходят по два раза: сначала первый
студент рисует два крестика, потом второй два нолика и т. д. Выигрывает тот, кто построит
вертикальный, горизонтальный или диагональный ряд из трех своих значков. К концу лекции
студенты не успели разобраться, кто выигрывает при правильной игре обоих игроков, и решили
это выяснить на следующих занятиях. Как и раньше, это может грозить серьезными
последствиями. Помогите хорошим ребятам разобраться в проблеме и избежать неприятностей.
Санархин Руслан, ПС-32
Visual studio 2019, C++*/

#include <iostream>
#include <fstream>

using namespace std;


void FindWinner(ifstream& input_file, ofstream& output_file) {
	unsigned int number;
	input_file >> number;
	unsigned int x, y;
	for (unsigned int i = 0; i < number; i++) {
		input_file >> x >> y;
		if ((x < 3) or (y < 3)) {
			output_file << 'D' << endl;
		}
		else {
			output_file << 'X' << endl;
		}
	}
}

int main()
{
	ifstream in("input.txt");
	ifstream out("output.txt");

	FindWinner(in, out);
}