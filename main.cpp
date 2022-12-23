#include <iostream>
#include <vector>
#include <functional>
#include <queue>

#include "ArcGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"

void BFS(const IGraph &graph, size_t vertex, std::vector<bool> &visited, std::function<void(int)> &func) {
    std::queue<size_t> q;
    q.push(vertex);
    visited[vertex] = true;

    size_t currentVertex = 0;
    while (!q.empty()) {
        currentVertex = q.front();
        q.pop();

        func(currentVertex);

        for (size_t nextVertex: graph.GetNextVertices(currentVertex)) {
            if (!visited[nextVertex]) {
                q.push(nextVertex);
                visited[nextVertex] = true;
            }
        }
    }
}

void mainBFS(const IGraph &graph, std::function<void(int)> func) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (size_t i = 0; i < graph.VerticesCount(); i++) {
        if (!visited[i]) {
            BFS(graph, i, visited, func);
        }
    }
}

void DFS(const IGraph &graph, size_t vertex, std::vector<bool> &visited, std::function<void(size_t)> &func) {
    visited[vertex] = true;

    func(vertex);

    for (size_t nextVertex: graph.GetNextVertices(vertex)) {
        if (!visited[nextVertex]) {
            DFS(graph, nextVertex, visited, func);
        }
    }
}

void mainDFS(const IGraph &graph, std::function<void(size_t)> func) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (size_t i = 0; i < graph.VerticesCount(); i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, func);
        }
    }
}

int main() {
    ListGraph graph(7);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 5);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(1, 5);
    graph.AddEdge(1, 6);
    graph.AddEdge(3, 2);
    graph.AddEdge(3, 4);
    graph.AddEdge(3, 6);
    graph.AddEdge(5, 4);
    graph.AddEdge(5, 6);
    graph.AddEdge(6, 4);

    mainBFS(graph, [](size_t vertex) {std::cout << vertex << ' '; });
    std::cout << std::endl;

    MatrixGraph matrix(graph);

    mainBFS(matrix, [](size_t vertex) {std::cout << vertex << ' '; });
    std::cout << std::endl;

    ArcGraph arcs(matrix);

    mainBFS(arcs, [](size_t vertex) {std::cout << vertex << ' '; });
    std::cout << std::endl;

    SetGraph setGraph(matrix);

    mainBFS(setGraph, [](size_t vertex) {std::cout << vertex << ' '; });
    std::cout << std::endl;
    return 0;
}
