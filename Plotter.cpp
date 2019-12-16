#include "TSP.h"
extern "C" {
    #include "gnuplot_i.h"
}

class Plotter {
private:
    gnuplot_ctrl* gp;
public:
    Plotter() {
        gp = gnuplot_init();
        gnuplot_set_xlabel(gp, ( char * ) "X Coord" ) ;
        gnuplot_set_ylabel(gp, ( char * ) "Y Coord" ) ;
    }
	void plotPoints(vector<pair<double, double>> nodes, int nnodes) {
        cout << "Plotting Points\n";
        vector<double> x;
        vector<double> y;
        for (int i = 0; i < nnodes; i++) {
            x.push_back(nodes[i].first);
            y.push_back(nodes[i].second);
        }
        gnuplot_setstyle(gp, ( char * ) "points" ) ;
        gnuplot_plot_xy(gp, &x[0], &y[0], nnodes, "Points");
	}
	void plotSolution(vector<pair<double, double>> nodes, vector<int> sol, int nnodes) {
        gnuplot_resetplot(gp);
        gnuplot_set_xlabel(gp, ( char * ) "X Coord" ) ;
        gnuplot_set_ylabel(gp, ( char * ) "Y Coord" ) ;
        cout << "Plotting Solution!\n";
        vector<double> x;
        vector<double> y;
        for (int i = 0; i < nnodes; i++) {
            int node = sol[i];
            x.push_back(nodes[node].first);
            y.push_back(nodes[node].second);
        }
        x.push_back(nodes[sol[0]].first);
        y.push_back(nodes[sol[0]].second);
        gnuplot_setstyle(gp, ( char * ) "linespoints" ) ;
        gnuplot_plot_xy(gp, &x[0], &y[0], (nnodes + 1), "Solution");
	}
};