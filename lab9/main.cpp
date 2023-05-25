#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReplaceMyString {
public:
	ifstream input;
	ofstream output;
	string line;

	ReplaceMyString() {}

	void replaceString(string str_old, string str_new) {
		input.open(__FILE__);
		output.open("rmain.cpp");

		while (getline(input, line)) {
			size_t pos = 0;
			while (line.find(str_old, pos) != line.npos) {
				pos = line.find(str_old, pos);
				line.replace(pos, str_old.length(), str_new);
				pos = pos + str_new.length();
			}
			output << line << endl;
		}

		input.close();
		output.close();
	}
};

int main() {
	ReplaceMyString my;
	my.replaceString("IU", "IU is best");
	return 0;
}
