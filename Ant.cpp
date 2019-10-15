#ifndef ANT_CLASS
#define ANT_CLASS

#include "TSP.h"

class Ant {
private:
	int trailSize;
	vector<int> trail;
	vector<bool> visited;
public:
	Ant(int tourSize) : trailSize(tourSize) {
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
	int distance(pair<double, double> node1, pair<double, double> node2) {
		double xd = node1.first - node2.first;
		double yd = node1.second - node2.second;
		return (int)(0.5 + sqrt(pow(xd, 2) + pow(yd, 2)));
	}

};

#endif // !ANT_CLASS