#include "SetGraph.h"

SetGraph::SetGraph(size_t size): adjacencySets(size) {}

SetGraph::SetGraph(const IGraph &graph): adjacencySets(graph.VerticesCount()) {
    std::vector<size_t> nextVertices;
    for (size_t i = 0; i < graph.VerticesCount(); i++) {
        nextVertices = graph.GetNextVertices(i);
        adjacencySets[i] = std::unordered_set<size_t>(nextVertices.begin(), nextVertices.end());
    }
}

void SetGraph::AddEdge(size_t from, size_t to) {
    adjacencySets[from].insert(to);
}

size_t SetGraph::VerticesCount() const {
    return adjacencySets.size();
}

std::vector<size_t> SetGraph::GetNextVertices(size_t vertex) const {
    return std::vector<size_t>(adjacencySets[vertex].begin(), adjacencySets[vertex].end());
}

std::vector<size_t> SetGraph::GetPrevVertices(size_t vertex) const {
    std::vector<size_t> prevVertices;

    for (size_t from = 0; from < adjacencySets.size(); from++) {
        for (size_t to: adjacencySets[from]) {
            if (to == vertex) {
            prevVertices.push_back(from);
            }
        }
    }

    return prevVertices;
}

