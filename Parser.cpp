#include "TSP.h"
#include <fstream>

class Parser {
private:
	string filePath;

public:
	Parser(string path) {
		filePath = path;
	}
	vector<pair<double, double>> parse() {
		vector<pair<double, double>> nodes;
		string line;
		ifstream file(filePath);
		bool takeData = false;
		if (file.is_open()) {
			while (getline(file, line)) {
				if (line.compare("EOF") == 0) break;
				if (takeData) {
					//cout << "COORDINATES:\n";
					size_t current, previous = 0;
					current = line.find(' ');
					previous = current + 1;
					current = line.find(' ', previous);
					double x = stod(line.substr(previous, current - previous));
					previous = current + 1;
					current = line.find(' ', previous);
					double y = stod(line.substr(previous, current - previous));
					//cout << " X: " << x << " Y: " << y << "\n";
					nodes.push_back(pair<double, double>(x, y));
				}
				if (line.compare("NODE_COORD_SECTION") == 0) takeData = true;
			}
		}
		else {
			cout << "Unable to open file";
			exit(1);
		}
		return nodes;
	}
};