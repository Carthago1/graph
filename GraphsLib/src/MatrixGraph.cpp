#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t size): matrix(size) {
    for (auto &row: matrix) {
        row.resize(size);
    }
}

MatrixGraph::MatrixGraph(const IGraph &graph): MatrixGraph(graph.VerticesCount()) {
    std::vector<size_t> nextVertices;

    for (size_t from = 0; from < graph.VerticesCount(); from++) {
        nextVertices = graph.GetNextVertices(from);
        for (auto &to: nextVertices) {
            matrix[from][to] = 1;
        }
    }
}

void MatrixGraph::AddEdge(size_t from, size_t to) {
    matrix[from][to] = 1;
}

size_t MatrixGraph::VerticesCount() const {
    return matrix.size();
}

std::vector<size_t> MatrixGraph::GetNextVertices(size_t vertex) const {
    std::vector<size_t> nextVertices;

    for (size_t to = 0; to < matrix.size(); to++) {
        if (matrix[vertex][to] == 1) {
        nextVertices.push_back(to);
        }
    }

    return nextVertices;
}

std::vector<size_t> MatrixGraph::GetPrevVertices(size_t vertex) const {
    std::vector<size_t> prevVertices;

    for (size_t from = 0; from < matrix.size(); from++) {
        if (matrix[from][vertex] == 1) {
        prevVertices.push_back(from);
        }
    }

    return prevVertices;
}

