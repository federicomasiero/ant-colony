#include "TSP.h"
#include <C:\Users\feder\source\gnuplot-cpp\gnuplot_i.hpp>

class Plotter {
private:
	Gnuplot gp;
public:
	Plotter() {
		cout << "Start\n";
		gp << "plot 5 6\n";
		cout << "Init\n";
	}
	/*void plotPoints(vector<pair<double, double>> nodes) {
		//gnuplot_cmd(gp, "set xlabel 'X Coord'\nset ylabel 'Y Coord'\n");
		for (int i = 0; i < nodes.size(); i++) {

			gnuplot_cmd(gp, "plot %1.6le %1.6le\n", nodes[i].first, nodes[i].second);
		}
		//gnuplot_setstyle(gp, "points");
		//gnuplot_set_xlabel(gp, "X Coord");
		//gnuplot_set_ylabel(gp, "Y Coord");
	}
	void plotSolution() {
		gnuplot_cmd(gp, "plot '-' with linespoints linestyle 1\n");
		system("PAUSE");
		gnuplot_close(gp);
	}*/
};