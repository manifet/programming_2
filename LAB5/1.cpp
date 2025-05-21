#include <iostream>      
#include <queue>        
#include <unordered_map>   
#include <vector>          
#include <string>          
#include <algorithm>      

// Структура графа, представленного в виде списка смежности
struct Graph {
    std::unordered_map<std::string, std::vector<std::string>> adjacencyList;

    // Метод для добавления ребра между вершинами (двунаправленное)
    void addEdge(const std::string& source, const std::string& destination) {
        adjacencyList[source].push_back(destination);
        adjacencyList[destination].push_back(source);
    }
};

// Функция для поиска кратчайшего пути в графе с помощью обхода в ширину (BFS)
std::vector<std::string> breadthFirstSearch(const Graph& graph, const std::string& startNode, const std::string& targetNode) {
    std::queue<std::string> nodesToVisit;                      // Очередь для BFS
    std::unordered_map<std::string, std::string> nodeParent;  // Родитель каждой вершины (для восстановления пути)
    std::unordered_map<std::string, bool> visitedNodes;       // Маркировка посещённых узлов

    nodesToVisit.push(startNode);
    visitedNodes[startNode] = true;
    nodeParent[startNode] = "";

    while (!nodesToVisit.empty()) {
        std::string currentNode = nodesToVisit.front();
        nodesToVisit.pop();

        // Если достигли целевой вершины, строим путь
        if (currentNode == targetNode) {
            std::vector<std::string> path;
            for (std::string node = targetNode; node != ""; node = nodeParent[node]) {
                path.push_back(node);
            }
            std::reverse(path.begin(), path.end());  // Разворачиваем путь от начала до конца
            return path;
        }

        // Обходим всех соседей текущей вершины
        for (const std::string& neighbor : graph.adjacencyList.at(currentNode)) {
            if (!visitedNodes[neighbor]) {
                visitedNodes[neighbor] = true;
                nodeParent[neighbor] = currentNode;    // Запоминаем родителя
                nodesToVisit.push(neighbor);           // Добавляем соседа в очередь
            }
        }
    }

    return {}; // Путь не найден
}

int main() {
    Graph mazeGraph;

    // Построение графа-лабиринта
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

    // Поиск кратчайшего пути от вершины S до вершины I
    std::vector<std::string> shortestPath = breadthFirstSearch(mazeGraph, "S", "I");

    // Вывод результата
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
