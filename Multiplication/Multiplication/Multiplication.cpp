#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const int MAX_COUNT = 20;
const int MIN_COUNT = 2;
const int MAX_DOMINO_VALUE = 7;
const string INPUT_PATH = "input.txt";
const string OUTPUT_PATH = "output.txt";

void read(vector<vector<int>>& frequency);
void find_max_number(string& current, string& max_number, vector<vector<int>> frequency);
void write(string max_number);


void read(vector<vector<int>>& frequency)
{
	ifstream input(INPUT_PATH);
	if (!input.is_open())
	{
		cout << "Opening error!" << endl;
	}

	if (frequency.empty())
	{
		cout << "it's empty" << endl;
	}

	frequency.resize(MAX_DOMINO_VALUE);
	for (int i = 0; i < MAX_DOMINO_VALUE; ++i)
	{
		for (int j = 0; j < MAX_DOMINO_VALUE; ++j)
		{
			frequency[i].push_back(0);
		}
	}

	string line;
	getline(input, line);
	auto count = stoi(line);
	if (count < MIN_COUNT || count > MAX_COUNT)
	{
		throw runtime_error("Bone count does not match");
	}

	while (count > 0)
	{
		if (input.eof())
		{
			break;
		}
		else
		{
			int left, right;
			input >> left >> right;
			if (((left < 0) || (left > 6)) || ((right < 0) || (right > 6)))
			{
				throw runtime_error("The bone number exceeds the maximum");
			}
			++frequency[left][right];
			++frequency[right][left];
		}
		--count;
	}

	if (count > 0)
	{
		throw runtime_error("Your number of dominos is not equal to the Domino number listed");
	}
}

void find_max_number(string& current, string& max_number, vector<vector<int>> frequency)
{
	if (max_number.size() < current.size() || (max_number.size() == current.size() && max_number < current))
	{
		max_number = current;
	}

	if (current.empty())
	{
		for (int i = 0; i < MAX_DOMINO_VALUE; ++i)
		{
			for (int j = 0; j < MAX_DOMINO_VALUE; ++j)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}

				if (frequency[i][j] > 0)
				{
					current.push_back(char(i + '0'));
					current.push_back(char(j + '0'));
					--frequency[i][j];
					--frequency[j][i];
					find_max_number(current, max_number, frequency);
					current.pop_back();
					current.pop_back();
					++frequency[i][j];
					++frequency[j][i];
				}
			}
		}
	}
	else
	{
		int digit = current.back() - '0';
		for (int j = 0; j < MAX_DOMINO_VALUE; ++j)
		{
			if (frequency[digit][j] > 0)
			{
				current.push_back(char(digit + '0'));
				current.push_back(char(j + '0'));
				--frequency[digit][j];
				--frequency[j][digit];
				find_max_number(current, max_number, frequency);
				current.pop_back();
				current.pop_back();
				++frequency[digit][j];
				++frequency[j][digit];
			}
		}
	}
}

void write(const string max_number)
{
	ofstream output(OUTPUT_PATH);
	output << max_number;
	cout << max_number << endl;
}

int main()
{
	string current, max_number;
	vector<vector<int>> frequency;
	read(frequency);
	find_max_number(current, max_number, frequency);
	write(max_number);
}
