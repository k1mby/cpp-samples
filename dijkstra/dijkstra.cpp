#include "dijkstra.h"

void Dijkstra::addEdge(int v1, int v2, int weight) {
    graph[v1].push_back(Edge(v2, weight));
    distance[v1] = INT_MAX;
    distance[v2] = INT_MAX;
}


vector<int> Dijkstra::shortestPath(int src, int dst) {

    vector<int> path;
    distance[src] = 0;

    priority_queue<Edge, vector<Edge>, EdgeCompare> pq;
    pq.push(Edge(src, 0));

    while (!pq.empty()) {

        auto current = pq.top();
        pq.pop();

        // Arrived at dst
        if (current.label == dst) {
            path.push_back(current.label);
            buildPath(path, current.label);
            break;
        }

        // No path between src and dst
        if (distance[current.label] == INT_MAX) {
            return {};
        }

        // Update weights
        for (auto neighbour : graph[current.label]) {
            int dist = distance[current.label] + neighbour.weight;
            if (dist < distance[neighbour.label]) {
                distance[neighbour.label] = dist;
                previous[neighbour.label] = current.label;
                pq.push(Edge(neighbour.label, dist));
            }
        }
    }

    return path;
}


void Dijkstra::buildPath(vector<int>& path, int node) {
    while (previous.count(node)) {
        path.push_back(previous[node]);
        node = previous[node];
    }
}


void Dijkstra::printPath(vector<int> path) {

    if (path.empty()) {
        cout << "No path found." << endl;
        return;
    }

    for (auto rit = path.rbegin(); rit != path.rend(); rit++) {
        cout << *rit << endl;
    }

    cout << "Distance: " << distance[path[0]] << endl;
}