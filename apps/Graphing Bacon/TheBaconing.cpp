//Finding bacon
//Zachary Bolden
//Help from Jo Gentry

#include "../../include/Graphs/Graphs.h"

bool findPathToKevinBacon(Graph<int>& graph, int start, int end, std::vector<int>& path, std::vector<bool>& visited) {
    
    if (start == end) {
        path.push_back(start);
        return true;
    }

   
    visited[start] = true;

   
    std::vector<int> neighbors = graph.neighbors(start);
    for (int neighbor : neighbors) {
        if (!visited[neighbor]) {
            
            if (findPathToKevinBacon(graph, neighbor, end, path, visited)) {
                path.push_back(start); 
                return true;
            }
        }
    }

    return false;
}

bool isConnectedToKevinBacon(Graph<int>& graph, int end, std::vector<int>& path) {
    int start = 0; 

   
    std::vector<bool> visited(21, false);

    
    bool isConnected = findPathToKevinBacon(graph, start, end, path, visited);

 
    reverse(path.begin(), path.end());

    return isConnected;
}

int main() {
    AdjacencyListGraph<int> socialGraph(21); 

    socialGraph.addEdge(0, 1); 
    socialGraph.addEdge(0, 2); 
    socialGraph.addEdge(0, 3);
    socialGraph.addEdge(2, 3);
    socialGraph.addEdge(1, 2);
    socialGraph.addEdge(3, 7); 
    socialGraph.addEdge(7, 20);

    std::vector<int> pathToKevinBacon;
    int kevinBaconNode = 20;
    for (int i = 0; i < socialGraph.size(); ++i) {
        std::cout << "Node " << i << " neighbors: ";
        std::vector<int> neighbors = socialGraph.neighbors(i);
        for (int neighbor : neighbors) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }

    bool isConnected = isConnectedToKevinBacon(socialGraph, kevinBaconNode, pathToKevinBacon);

    if (isConnected) {
        std::cout << "Congratulations! You are connected to Kevin Bacon!" << std::endl;
        std::cout << "The path to Kevin Bacon is:" << std::endl;
        for (int node : pathToKevinBacon) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Sorry, you are not connected to Kevin Bacon." << std::endl;
    }
    return 0;
}