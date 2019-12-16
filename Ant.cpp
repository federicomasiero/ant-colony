#ifndef ANT_CLASS
#define ANT_CLASS

#include "TSP.h"

constexpr auto PI = (double) 3.1415926535897;

constexpr auto RRR = (double) 6378.388;

class Ant {
private:
	int trailSize;
	bool euc;
	vector<int> trail;
	vector<bool> visited;
public:
	Ant(int tourSize, bool e) : trailSize(tourSize), euc(e) {
		for (int i = 0; i < tourSize; i++) {
			visited.push_back(false);
		}
	}

	/*
		* A new node i visited by this Ant
	*/
	void visitNode(int node) {
		if (node != -1) {
			trail.push_back(node);
			visited[node] = true;
		}
	}

	/*
		* Return true if the index node is visited by this Ant
	*/
	bool isVisited(int index) {
		return visited[index];
	}

	/*
		* Return the trail do by this Ant
	*/
	vector<int> getTrail() {
		return trail;
	}

	/*
		* Return the node in the index trail's position
	*/
	int getTrailNode(int index) {
		return trail[index];
	}

	/*
		* Return trail's total length
	*/
	double trailLength(vector<pair<double, double>> graph) {
		double length = distance(graph[trail[0]], graph[trail[trailSize - 1]]);
		for (int i = 0; i < trailSize - 1; i++) {
			length += distance(graph[trail[i]], graph[trail[i + 1]]);
		}
		return length;
	}

	/*
		* Clear Ant informations
	*/
	void clear() {
		trail.clear();
		for (int i = 0; i < trailSize; i++) {
			visited[i] = false;
		}
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

#endif // !ANT_CLASS