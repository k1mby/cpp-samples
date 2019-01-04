#include "dijkstra.h"

int main() {

    Dijkstra ds;

    ds.addEdge(1, 2, 1);
    ds.addEdge(2, 5, 2);
    ds.addEdge(5, 4, 1);
    ds.addEdge(1, 8, 4);
    ds.addEdge(8, 4, 7);

    vector<int> path;
    
    path = ds.shortestPath(1, 4);
    ds.printPath(path);

    path = ds.shortestPath(1,12);
    ds.printPath(path);

    return 0;
}