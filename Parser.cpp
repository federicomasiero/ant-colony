#include "TSP.h"
#include <fstream>
#include <boost/tokenizer.hpp>

class Parser {
private:
	string filePath;
	string name;
	int dimension;
	bool euc = false;
	bool geo = false;
    vector<pair<double, double>> nodes;
public:
	Parser(string path) : filePath(path) {}
	void parse() {
	    using namespace boost;
		string line;
		ifstream file(filePath);
		bool takeData = false;
		if (file.is_open()) {
			while (getline(file, line)) {
                char_separator<char> delim{" "};
                tokenizer<char_separator<char>> tok(line, delim);
                auto beg=tok.begin();
				if (line.compare("EOF") == 0) break;
				if (takeData) {
					//cout << "COORDINATES:\n";
                    beg++;
					double x = stod(*beg);
                    beg++;
					double y = stod(*beg);
					tok.end();
					//cout << " X: " << x << " Y: " << y << "\n";
					nodes.push_back(pair<double, double>(x, y));
				}
				else {
                    string word(*beg);
                    if(word.compare("NAME:") == 0) {
                        beg++;
                        string str(*beg);
                        name = str;
                    }
                    else if(word.compare("TYPE:") == 0) {
                        beg++;
                        string type(*beg);
                        if(type.compare("TSP") != 0) exit(5);
                    }
                    else if(word.compare("DIMENSION:") == 0) {
                        beg++;
                        dimension = stoi(*beg);
                    }
                    else if(word.compare("EDGE_WEIGHT_TYPE:") == 0) {
                        *beg++;
                        string weight(*beg);
                        if(weight.compare("EUC_2D")==0) euc = true;
                        else if(weight.compare("GEO")==0) geo = true;
                        else exit(6);
                    }
                    else if (line.compare("NODE_COORD_SECTION") == 0) takeData = true;
                    tok.end();
                }
			}
		}
		else {
			cout << "Unable to open file";
			exit(1);
		}
	}

	string getName() const {
        return name;
    }

    int getDimension() const {
        return dimension;
    }

    bool isEuc() const {
        return euc;
    }

    vector<pair<double, double>> getNodes() const{
        return nodes;
    }
};