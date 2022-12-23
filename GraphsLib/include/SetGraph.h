#ifndef INC_1_SETGRAPH_H_
#define INC_1_SETGRAPH_H_

#include <cstddef>
#include <vector>
#include <unordered_set>

#include "IGraph.h"

class SetGraph: public IGraph {
public:
    SetGraph(size_t size);

    SetGraph(const IGraph &graph);

    ~SetGraph() override = default;

    void AddEdge(size_t from, size_t to) override;

    size_t VerticesCount() const override;

    std::vector<size_t> GetNextVertices(size_t vertex) const override;

    std::vector<size_t> GetPrevVertices(size_t vertex) const override;

private:
    std::vector<std::unordered_set<size_t>> adjacencySets;
};

#endif //INC_1_SETGRAPH_H_

