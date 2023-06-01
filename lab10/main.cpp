#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class myString {
private:
	string m_str;
public:
	myString(string s) {
		m_str = s;
	}
};

class ReadClass {
private:
	ifstream in;
	string line;
	int count;
	vector<string> vec;
	void searchClass() {

	}
public:
	ReadClass() {
		in.open(__FILE__);
		if (in.fail()) {
			in.close();
		}
		while (getline(in, line)) {
			if (line.find("class", 0) == 0) {
				vec.push_back(line.substr(6, (int)line.find(" ", 6) - 6));
				count++;
			}
		}
	}

	void showClass() {
		cout << count << " class in main.cpp" << endl;
		for (int i = 0; i < count;i++)
			cout << "class " << vec[i] << endl;
	}
};

int main() {
	ReadClass rfile;
	rfile.showClass();
	return 0;
}
