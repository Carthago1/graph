#ifndef INC_1_LISTGRAPH_H_
#define INC_1_LISTGRAPH_H_

#include <cstddef>
#include <vector>

#include "IGraph.h"

class ListGraph: public IGraph {
public:
    ListGraph(size_t size);

    ListGraph(const IGraph &graph);

    ~ListGraph() override = default;

    void AddEdge(size_t from, size_t to) override;

    size_t VerticesCount() const  override;

    std::vector<size_t> GetNextVertices(size_t vertex) const override;

    std::vector<size_t> GetPrevVertices(size_t vertex) const override;

private:
    std::vector<std::vector<size_t>> adjacencyLists;
};

#endif //INC_1_LISTGRAPH_H_

