#include "TSP.h"
#include "Ant.cpp"
#include "Parser.cpp"
#include "Plotter.cpp"

//Number of trails at the start of the simulation
constexpr auto C = (double) 1.0;;

//how many ants we’ll use per city
constexpr auto ANTFACTOR = (double) 0.8;;

//Control the pheromone importance
constexpr auto ALPHA = (double) 1.0;;

//Control the distance priority
constexpr auto BETA = (double) 5.0; // OBS: beta >> alpha for best result;;

//percent how much the pheromone is evaporating in every iteration
constexpr auto EVAPORATION = (double) 0.2;;

//a little bit of randomness
constexpr auto RANDOMFACTOR = (double) 0.8;;

//Number of iterations before stop the algorithm
constexpr auto MAXITERATIONS = (int) 200;;

//Is AC algorithm?
constexpr auto AC = 0;;

//Is ACS algorithm?
constexpr auto ACS = 1;;

//Is MMAS algorithm?
constexpr auto MMAS = 0;;

class AntColony {
private:
	int nNodes;
	int nAnts;
	bool euc;
	vector<Ant> ants;					//  Ants vector
	vector<pair<double, double>> nodes;	//  Point vector
	vector<vector<double>> trails;		//	pheromone in every arc.
	vector<double> probabilities;		//	probabilities vector going from one node to another
	int currentIndex;

	double minPheromone;
	double maxPheromone = DBL_MAX;
	vector<int> bestTour;
	double bestTourLength = DBL_MAX;

	Plotter chart = Plotter();

public:
	AntColony(string file) {
		Parser p(file);
		p.parse();
		nodes = p.getNodes();
        nNodes = p.getDimension();
        euc = p.isEuc();
        cout << "TSP Problem: " << p.getName() << "\n";
		chart.plotPoints(nodes, nNodes);
		getchar();
		srand(time(NULL));
		nAnts = (int) (nNodes * ANTFACTOR);
		setMinPheromone();
		for (int i = 0; i < nAnts; i++) {
			ants.push_back(Ant(nNodes, euc));
		}
		resetProbabilities();
	}
	void solve() {
        srand(time(NULL));
		clearTrails();
		cout << "Algorithm used: ";
		if (AC) cout << "AC\n";
		else if(ACS) cout << "ACS\n";
		else cout << "MMAS\n";
		for (int iter = 0; iter < MAXITERATIONS; iter++) {
			cout << "Iteration number " << iter << "\n";
			//cout << "SETUP ANTS\n";
			setupAnts();
			//cout << "MOVE ANTS\n";
			moveAnts();
			//cout << "UPDATE BEST TOUR\n";
			updateBestTour();
			//cout << "GLOBAL UPDATING PHEROMONE\n";
            globalUpdating();
		}
		cout << "Best cost: " << bestTourLength << "\n";
	}
private:
	void setupAnts() {
		for (auto ant = ants.begin(); ant != ants.end(); ant++) {
			(*ant).clear();
			(*ant).visitNode((rand() % nNodes));
		}
		currentIndex = 0;
	}
	void resetProbabilities() {
        probabilities.clear();
        for (int i = 0; i < nNodes; i++) {
            probabilities.push_back(0.0);
            //cout << "Prob: " << probabilities[i] << "\n";
        }
	}
	void clearTrails() {
		trails.clear();
		for (int i = 0; i < nNodes; i++) {
			trails.push_back(vector<double>(nNodes));
		}
		for (int i = 0; i < nNodes; i++) {
			for (int j = 0; j < nNodes; j++) {
				trails[i][j] = minPheromone;
			}
		}
	}

	/*
		* Set minimum quantity of Pheromone allowed in every Arc, according to MMAS rules
	*/
	void setMinPheromone() {
	    if(!MMAS) {
	        minPheromone = 0.1;
	        return;
	    }
		double average = 0.0;
		for (int i = 0; i < nNodes; i++) {
		    for(int j = 0; j < nNodes; j++) {
		        if(i == j) continue;
                average += distance(nodes[i], nodes[j]);
		    }
		}
		average /= nNodes * (nNodes - 1);
		minPheromone = C / (nNodes * nNodes * average);
		if(minPheromone <= 0) minPheromone = 0.01;
	}

	/*
		*
	*/
	void moveAnts() {
		for (int i = 1; i < nNodes; i++) {
			for (auto ant = ants.begin(); ant != ants.end(); ant++) {
			    int node = selectNextNode(*ant);
				(*ant).visitNode(node);
				if(ACS) localUpdating(*ant);
			}
			currentIndex++;
		}
	}

	/*
		* Ant Colony System (ACS) method selecting next node to visit
		* Pseudo Random Proportional Rule
	*/
	int selectNextNode(Ant ant) {
	    // If ACS or MMAS algorithm are selected we use probabilities to choose,
	    // otherwise we use Exploration selection.
	    double numrand = (ACS | MMAS) ? ((double) rand() / (RAND_MAX)) : 1.0;
		if (numrand < RANDOMFACTOR) {
			//cout << "EXPLOITATION SELECTION\n";
			int i = ant.getTrailNode(currentIndex);
			int node = -1;
			double argmax = 0.0;
			for (int f = 0; f < nNodes; f++) {
				if (!ant.isVisited(f)) {
					double arg = pow(trails[i][f], ALPHA) * pow(distance(nodes[i],nodes[f]), BETA);
					if (arg > argmax) {
						argmax = arg;
						node = f;
					}
				}
			}
			return node;
		}
		else {
			//cout << "BAISED EXPLORATION SELECTION\n";
			calculateProbabilities(ant);
			double r = ((double) rand() / (RAND_MAX));
			double total = 0.0;
			int last = -1;
            //cout << "Rand: " << r << "\n";
			for (int i = 0; i < nNodes; i++) {
			    if(probabilities[i] != 0) last = i;
				total += probabilities[i];
                //cout << "Total: " << total << "\n";
				if (total > r) {
                    //cout << "NextNode: " << i << "\n\n";
                    return i;
				}
			}
			if(last == -1) cout << "return -1\n";
			return last;
		}
	}

	/*
		* Ant Colony (AC) method to calculate probabilities moving from one node to another -> Pk(r,s)
		* Update probabilities vector
	*/
	void calculateProbabilities(Ant ant) {
	    resetProbabilities();
		int i = ant.getTrailNode(currentIndex);
		double denominator = 0.0;
		for (int f = 0; f < nNodes; f++) {
			if (!ant.isVisited(f)) {
				denominator += trails[i][f] * pow((1 / distance(nodes[i], nodes[f])), BETA);
			}
		}
		//cout << "Denominator: " << denominator << "\n";
		for (int f = 0; f < nNodes; f++) {
			if (ant.isVisited(f)) {
				probabilities[f] = 0.0;
			}
			else {
				double numerator = trails[i][f] * pow((1 / distance(nodes[i], nodes[f])), BETA);
                probabilities[f] = (denominator == 0.0) ? 0.0 : numerator / denominator;
			}
            //cout << "Prob: " << probabilities[f] << "\n";
		}
	}

	/*
		* Local Pheromone Updating with ACS rule. Every movement about ants pheromone array is updated.
		* delta is equal to: 1/(nNodes * Lnn) where Lnn is the tour length produced by the nearest neighbor heuristic.
		* We don't implement NNH, then we aproximate Lnn <- nNodes * nNodes * distance(i,j)
		* Then we deposit more pheromone shortest is the distance(i,j).
	*/
	void localUpdating(Ant ant) {
		int node1 = ant.getTrailNode(currentIndex);
		int node2 = ant.getTrailNode(currentIndex + 1);
		double delta = 1 / (nNodes * nNodes * distance(nodes[node1], nodes[node2]));
		trails[node1][node2] = (1 - EVAPORATION) * trails[node1][node2] + EVAPORATION * delta;
	}

	/*
		* Global Pheromone Updating with ACS rule. Only best ant is allowed to deposit pheromone.
		* In order to satisfy MMAS rule, pheromone is upper limited to maxPheromone
	*/
	void globalUpdating() {
	    if(AC) {
            for (int i = 0; i < nNodes; i++) {
                for (int j = 0; j < nNodes; j++) {
                    double delta = 0.0;
                    for (auto ant = ants.begin(); ant != ants.end(); ant++) {
                        if((*ant).isEdgeInTrail(i, j)){
                            delta += 1 / (*ant).trailLength(nodes);
                        }
                    }
                    trails[i][j] = (1 - EVAPORATION) * trails[i][j] + delta;
                }
            }
	    }
	    if(ACS || MMAS) {
            double delta = 1 / bestTourLength;
            for (int f = 0; f < nNodes - 1; f++) {
                int node1 = bestTour[f];
                int node2 = bestTour[f + 1];
                trails[node1][node2] = (1 - EVAPORATION) * trails[node1][node2] + EVAPORATION * delta;
                if (MMAS) {
                    if (trails[node1][node2] < minPheromone) trails[node1][node2] = minPheromone;
                    if (trails[node1][node2] > maxPheromone) trails[node1][node2] = maxPheromone;
                }
            }
            int node1 = bestTour[nNodes - 1];
            int node2 = bestTour[0];
            trails[node1][node2] = (1 - EVAPORATION) * trails[node1][node2] + EVAPORATION * delta;
            if (MMAS) {
                if (trails[node1][node2] < minPheromone) trails[node1][node2] = minPheromone;
                if (trails[node1][node2] > maxPheromone) trails[node1][node2] = maxPheromone;
            }
        }
	}

	/*
		* Update Best Tour variable after an iteration of ant search.
	*/
	void updateBestTour() {
		for (auto ant = ants.begin(); ant != ants.end(); ant++) {
			if ((*ant).trailLength(nodes) < bestTourLength) {
				bestTourLength = (*ant).trailLength(nodes);
				bestTour = (*ant).getTrail();
				if(MMAS) maxPheromone = nNodes / bestTourLength;
                printSolution();
			}
		}
	}

	void printSolution(){
        cout << "GLOBAL UPDATE SOLUTION!\nNew Best Solution Cost: " << bestTourLength << "\n";
        /*cout << "Best Solution: \n";
        for (int f = 0; f < nNodes; f++) {
            cout << bestTour[f] << " - ";
        }*/
        chart.plotSolution(nodes, bestTour, nNodes);
	}

	/*
		* Euclidean distance from one node to another. Definition provided by TSP Data uni-heidelberg
	*/
    double distance(pair<double, double> node1, pair<double, double> node2) {
	    if(euc) {
            double xd = node1.first - node2.first;
            double yd = node1.second - node2.second;
            return (int)(0.5 + sqrt(pow(xd, 2) + pow(yd, 2)));
	    }
	    else{
            double deg = (int)(node1.first);
            double min = node1.first - deg;
            double lat_p1 = PI * (deg + 5.0*min / 3.0) / 180.0;

            deg = (int)(node1.second);
            min = node1.second - deg;
            double lon_p1 = PI * (deg + 5.0*min / 3.0) / 180.0;

            deg = (int)(node2.first);
            min = node2.first - deg;
            double lat_p2 = PI * (deg + 5.0*min / 3.0) / 180.0;

            deg = (int)(node2.second);
            min = node2.second - deg;
            double lon_p2 = PI * (deg + 5.0*min / 3.0) / 180.0;

            double q1 = cos(lon_p1 - lon_p2);
            double q2 = cos(lat_p1 - lat_p2);
            double q3 = cos(lat_p1 + lat_p2);
            double d_p1_p2 = (int)(RRR*acos(0.5*((1.0 + q1)*q2 - (1.0 - q1)*q3)) + 1.0);

            return d_p1_p2;
	    }
	}
};