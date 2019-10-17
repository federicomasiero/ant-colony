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
constexpr auto EVAPORATION = (double) 0.1;;

//a little bit of randomness
constexpr auto RANDOMFACTOR = (double) 0.9;;

//Number of iterations before stop the alghoritm
constexpr auto MAXITERATIONS = (int) 10000;;

class AntColony {
private:
	int nNodes;
	int nAnts;
	vector<Ant> ants;					//  Ants vector
	vector<pair<double, double>> nodes;	//  Point vector
	vector<vector<double>> trails;		//	pheromone in every arc.
	vector<double> probabilities;		//	probabilities vector going from one node to another
	int currentIndex;

	double minPheromone;
	double maxPheromone = DBL_MAX;
	vector<int> bestTour;
	double bestTourLength = DBL_MAX;

	Plotter chart;

public:
	AntColony(string file) {
		Parser p(file);
		nodes = p.parse();
		chart = Plotter();
		getchar();
		chart.plotPoints(nodes);
		srand(time(NULL));
		nNodes = nodes.size();
		nAnts = (int) (nNodes * ANTFACTOR);
		setMinPheromone();
		for (int i = 0; i < nAnts; i++) {
			ants.push_back(Ant(nNodes));
		}
		for (int i = 0; i < nNodes; i++) {
			probabilities.push_back(0.0);
		}
	}
	void solve() {
		clearTrails();
		for (int iter = 0; iter < MAXITERATIONS; iter++) {
			cout << "Iteration number " << iter << "\n";
			//cout << "SETUP ANTS\n";
			setupAnts();
			//cout << "MOVE ANTS\n";
			moveAnts();
			//cout << "UPDATE BEST TOUR\n";
			updateBestTour();
		}
		cout << "Best Solution Cost: " << bestTourLength << "\nBest Solution: ";
		for (int f = 0; f < nNodes; f++) {
			cout << bestTour[f] << " - ";
		}
		//	Plot solution!
	}
private:
	void setupAnts() {
		for (auto ant = ants.begin(); ant != ants.end(); ant++) {
			(*ant).clear();
			(*ant).visitNode((rand() % nNodes));
		}
		currentIndex = 0;
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
		double average = 0.0;
		for (int i = 1; i < nNodes; i++) {
			average += distance(nodes[0], nodes[i]);
		}
		average /= nNodes;
		minPheromone = C / (nNodes * nNodes * average);
	}

	/*
		*
	*/
	void moveAnts() {
		for (int i = 0; i < nNodes - 1; i++) {
			for (auto ant = ants.begin(); ant != ants.end(); ant++) {
				(*ant).visitNode(selectNextNode(*ant));
				localUpdating(*ant);
			}
			currentIndex++;
		}
	}

	/*
		* Ant Colony System (ACS) method selecting next node to visit
		* Pseudo Random Proportional Rule
	*/
	int selectNextNode(Ant ant) {
		if ((rand() / RAND_MAX) < RANDOMFACTOR) {
			//cout << "SELECT EXPLOITATION SELECTION\n";
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
			//cout << "SELECT BAISED EXPLOITATION SELECTION\n";
			calculateProbabilities(ant);
			double r = rand() / RAND_MAX;
			double total = 0.0;
			for (int i = 0; i < nNodes; i++) {
				total += probabilities[i];
				if (total > r) {
					return i;
				}
			}
			return -1;
		}
	}

	/*
		* Ant Colony (AC) method to calculate probabilities moving from one node to another -> Pk(r,s)
		* Update probabilities vector
	*/
	void calculateProbabilities(Ant ant) {
		int i = ant.getTrailNode(currentIndex);
		double pheromone = 0.0;
		for (int f = 0; f < nNodes; f++) {
			if (!ant.isVisited(f)) {
				pheromone += pow(trails[i][f], ALPHA) * pow(distance(nodes[i], nodes[f]), BETA);
			}
		}
		for (int f = 0; f < nNodes; f++) {
			if (ant.isVisited(f)) {
				probabilities[f] = 0.0;
			}
			else {
				double numerator = pow(trails[i][f], ALPHA) * pow(distance(nodes[i], nodes[f]), BETA);
				probabilities[f] = numerator / pheromone;
			}
		}
	}

	/*
		* Local Pheromone Updating with ACS rule. Every movement about ants pheromone array is updated.
		* delta is equal to: 1/(nNodes * Lnn) where Lnn is the tour length produced by the nearest neighbor heuristic.
		* We don't implement NNH, then we aproximate Lnn <- nNodes * nNodes * distance(i,j)
		* Then we deposit more pheromone shortest is the distance(i,j).
		* In order to satisfy MMAS rule, pheromone is upper limited to maxPheromone and inferior limited to minPheromone
	*/
	void localUpdating(Ant ant) {
		int node1 = ant.getTrailNode(currentIndex);
		int node2 = ant.getTrailNode(currentIndex + 1);
		double delta = 1 / (nNodes * nNodes * distance(nodes[node1], nodes[node2]));
		trails[node1][node2] = (1 - EVAPORATION) * trails[node1][node2] + EVAPORATION * delta;
		//if (trails[node1][node2] < minPheromone) trails[node1][node2] = minPheromone;
		//if (trails[node1][node2] > maxPheromone) trails[node1][node2] = maxPheromone;
	}

	/*
		* Global Pheromone Updating with ACS rule. Only best ant is allowed to deposit pheromone.
		* In order to satisfy MMAS rule, pheromone is upper limited to maxPheromone
	*/
	void globalUpdating() {
		double delta = 1 / bestTourLength;
		for (int f = 0; f < nNodes - 1; f++) {
			int node1 = bestTour[f];
			int node2 = bestTour[f + 1];
			trails[node1][node2] = (1 - EVAPORATION) * trails[node1][node2] + EVAPORATION * delta;
			//if (trails[node1][node2] < minPheromone) trails[node1][node2] = minPheromone;
			//if (trails[node1][node2] > maxPheromone) trails[node1][node2] = maxPheromone;
		}
		int node1 = bestTour[nNodes - 1];
		int node2 = bestTour[0];
		trails[node1][node2] = (1 - EVAPORATION) * trails[node1][node2] + EVAPORATION * delta;
		//if (trails[node1][node2] < minPheromone) trails[node1][node2] = minPheromone;
		//if (trails[node1][node2] > maxPheromone) trails[node1][node2] = maxPheromone;
	}

	/*
		* Update Best Tour variable after an iteration of ant search.
	*/
	void updateBestTour() {
		for (auto ant = ants.begin(); ant != ants.end(); ant++) {
			if ((*ant).trailLength(nodes) < bestTourLength) {
				cout << "GLOBAL UPDATE SOLUTION!\n";
				bestTourLength = (*ant).trailLength(nodes);
				cout << "Best tour length: " << bestTourLength << "\n";
				bestTour = (*ant).getTrail();
				//maxPheromone = nNodes / bestTourLength;
				globalUpdating();
			}
		}
	}

	/*
		* Euclidean distance from one node to another. Definition provided by TSP Data uni-heidelberg
	*/
	int distance(pair<double, double> node1, pair<double, double> node2) {
		double xd = node1.first - node2.first;
		double yd = node1.second - node2.second;
		return (int)(0.5 + sqrt(pow(xd, 2) + pow(yd, 2)));
	}
};