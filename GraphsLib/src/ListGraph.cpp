#include "ListGraph.h"

ListGraph::ListGraph(size_t size): adjacencyLists(size) {}

ListGraph::ListGraph(const IGraph &graph): adjacencyLists(graph.VerticesCount()) {
    for (size_t i = 0; i < graph.VerticesCount(); i++) {
        adjacencyLists[i] = graph.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(size_t from, size_t to) {
    adjacencyLists[from].push_back(to);
}

size_t ListGraph::VerticesCount() const {
    return adjacencyLists.size();
}

std::vector<size_t> ListGraph::GetNextVertices(size_t vertex) const {
    return adjacencyLists[vertex];
}

std::vector<size_t> ListGraph::GetPrevVertices(size_t vertex) const {
    std::vector<size_t> prevVertices;

    for (size_t from = 0; from < adjacencyLists.size(); from++) {
        for (size_t to: adjacencyLists[from]) {
            if (to == vertex) {
            prevVertices.push_back(from);
            }
        }
    }

    return prevVertices;
}

