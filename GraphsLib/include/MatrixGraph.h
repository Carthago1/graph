#ifndef INC_1_MATRIXGRAPH_H_
#define INC_1_MATRIXGRAPH_H_

#include <cstddef>
#include <vector>

#include "IGraph.h"

class MatrixGraph: public IGraph {
public:
    MatrixGraph(size_t size);

    MatrixGraph(const IGraph &graph);

    ~MatrixGraph() override = default;

    void AddEdge(size_t from, size_t to) override;

    size_t VerticesCount() const override;

    std::vector<size_t> GetNextVertices(size_t vertex) const override;

    std::vector<size_t> GetPrevVertices(size_t vertex) const override;

private:
    std::vector<std::vector<size_t>> matrix;
};

#endif //INC_1_MATRIXGRAPH_H_

