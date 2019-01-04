#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct Edge {
    int label;
    int weight;
    Edge(int _label, int _weight) : label(_label), weight(_weight) {};
};

class EdgeCompare {
public:
    bool operator() (Edge e1, Edge e2) {
	    return e1.weight > e2.weight;
	}
};

class Dijkstra {
public:
    void addEdge(int v1, int v2, int weight);
    void printPath(vector<int> path);
    vector<int> shortestPath(int src, int dst);
    
private:
    unordered_map<int, vector<Edge>> graph;
    unordered_map<int, int> distance;
    unordered_map<int, int> previous;
    void buildPath(vector<int>& path, int node);
};

#endif