#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

class GraphTest : public testing::Test {
 protected:
    GraphTest() {
      file_to_graph("src/small.txt",testGraph);

      distances = dijkstra_shortest_path(testGraph, 0, previous);
      path = extract_shortest_path(distances,previous,2);
      int size = path.size();
      for (int i = 0; i < size; i++){
        path_weight+=distances[i];
      }
      print_path(path, path_weight);
    }
    Graph testGraph;
    vector<int> previous;
    vector<int> distances;
    vector<int> path;
    int path_weight = 0;
};

TEST_F(GraphTest, runTest) {
  EXPECT_TRUE(true);
}
