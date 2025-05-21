#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm> 

struct Graph {
    std::unordered_map<std::string, std::vector<std::string>> adjacencyList;

    void addEdge(const std::string& source, const std::string& destination) {
        adjacencyList[source].push_back(destination);
        adjacencyList[destination].push_back(source);
    }
};

std::vector<std::string> breadthFirstSearch(const Graph& graph, const std::string& startNode, const std::string& targetNode) {
    std::queue<std::string> nodesToVisit;
    std::unordered_map<std::string, std::string> nodeParent;
    std::unordered_map<std::string, bool> visitedNodes;

    nodesToVisit.push(startNode);
    visitedNodes[startNode] = true;
    nodeParent[startNode] = "";

    while (!nodesToVisit.empty()) {
        std::string currentNode = nodesToVisit.front();
        nodesToVisit.pop();

        if (currentNode == targetNode) {
            std::vector<std::string> path;
            for (std::string node = targetNode; node != ""; node = nodeParent[node]) {
                path.push_back(node);
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (const std::string& neighbor : graph.adjacencyList.at(currentNode)) {
            if (!visitedNodes[neighbor]) {
                visitedNodes[neighbor] = true;
                nodeParent[neighbor] = currentNode;
                nodesToVisit.push(neighbor);
            }
        }
    }

    return {};
}

int main() {
    Graph mazeGraph;
    mazeGraph.addEdge("S", "A");
    mazeGraph.addEdge("S", "B");
    mazeGraph.addEdge("A", "C");
    mazeGraph.addEdge("B", "D");
    mazeGraph.addEdge("C", "E");
    mazeGraph.addEdge("D", "F");
    mazeGraph.addEdge("E", "I");
    mazeGraph.addEdge("F", "G");
    mazeGraph.addEdge("G", "H");
    mazeGraph.addEdge("H", "I");

    std::vector<std::string> shortestPath = breadthFirstSearch(mazeGraph, "S", "I");

    if (!shortestPath.empty()) {
        std::cout << "Кратчайший путь от S до I: ";
        for (const std::string& room : shortestPath) {
            std::cout << room << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Путь не найден." << std::endl;
    }

    return 0;
}