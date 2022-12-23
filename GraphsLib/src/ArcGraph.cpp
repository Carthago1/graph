#include "ArcGraph.h"

ArcGraph::ArcGraph(size_t size): arcs(size * size) {}

ArcGraph::ArcGraph(const IGraph &graph): arcs(graph.VerticesCount() * graph.VerticesCount()) {
    std::vector<size_t> nextVertices;

    for (size_t from = 0; from < graph.VerticesCount(); from++) {
        nextVertices = graph.GetNextVertices(from);
        for (auto &to: nextVertices) {
            arcs.push_back(std::pair<size_t, size_t>(from, to));
        }
    }
}

void ArcGraph::AddEdge(size_t from, size_t to) {
    arcs.push_back(std::pair<size_t, size_t>(from, to));
}

size_t ArcGraph::VerticesCount() const {
    std::unordered_set<size_t> vertices;

    for (const auto &vertex: arcs) {
    vertices.insert(vertex.first);
    vertices.insert(vertex.second);
    }

    return vertices.size();
}

std::vector<size_t> ArcGraph::GetNextVertices(size_t vertex) const {
    std::vector<size_t> nextVertices;

    for (const auto &v: arcs) {
        if (v.first == vertex) {
        nextVertices.push_back(v.second);
        }
    }

    return nextVertices;
}

std::vector<size_t> ArcGraph::GetPrevVertices(size_t vertex) const {
    std::vector<size_t> prevVertices;

    for (const auto &v: arcs) {
        if (v.second == vertex) {
        prevVertices.push_back(v.first);
        }
    }

    return prevVertices;
}

