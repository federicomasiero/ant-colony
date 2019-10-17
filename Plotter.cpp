#include "TSP.h"
#include "gnuplot_i.h"

class Plotter {
private:
	gnuplot_ctrl gp;
public:
	Plotter() {
        gnuplot_ctrl *h = gnuplot_init();
        gnuplot_setstyle(h, "points");
        gnuplot_set_xlabel(h, "X Coord");
        gnuplot_set_ylabel(h, "Y Coord");
        gp = *h;
	}
	void plotPoints(vector<pair<double, double>> nodes) {
		for (int i = 0; i < nodes.size(); i++) {
			gnuplot_cmd(&gp, "plot %1.6le %1.6le\n", nodes[i].first, nodes[i].second);
		}
	}
	void plotSolution() {
		gnuplot_cmd(&gp, "plot '-' with linespoints linestyle 1\n");
		system("PAUSE");
		gnuplot_close(&gp);
	}
};