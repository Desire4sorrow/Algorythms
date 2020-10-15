#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

const string INPUT_PATH = "input.txt";
const string OUTPUT_PATH = "output.txt"; 



void EnterPosition()//начальная позиция короля 
{
	ifstream input(INPUT_PATH);
	if (!input.is_open())
	{
		throw runtime_error("Cannot open file" + INPUT_PATH);
	}
}