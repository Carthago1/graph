#ifndef INC_1_ARCGRAPH_H_
#define INC_1_ARCGRAPH_H_

#include <cstddef>
#include <vector>
#include <unordered_set>

#include "IGraph.h"

class ArcGraph: public IGraph {
public:
    ArcGraph(size_t size);

    ArcGraph(const IGraph &graph);

    ~ArcGraph() override = default;

    void AddEdge(size_t from, size_t to) override;

    size_t VerticesCount() const override;

    virtual std::vector<size_t> GetNextVertices(size_t vertex) const override;

    virtual std::vector<size_t> GetPrevVertices(size_t vertex) const override;

private:
    std::vector<std::pair<size_t, size_t>> arcs;
};

#endif //INC_1_ARCGRAPH_H_

