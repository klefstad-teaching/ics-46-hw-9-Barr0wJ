#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

class GraphTest : public testing::Test {
 protected:
    GraphTest() {
      /*
      file_to_graph("src/small.txt",testGraph);

      distances = dijkstra_shortest_path(testGraph, 0, previous);
      path = extract_shortest_path(distances,previous,2);
      int size = path.size();
      for (int i = 0; i < size; i++){
        path_weight+=distances[i];
      }
      print_path(path, path_weight);
      */
      //load_words(words, "src/words.txt");
      /*
      int size = words.size();
      for (string s : words){
        cout << s << endl;
      }
      */
      cout << edit_distance_within("apple","bapple",1) << endl;
      //result = generate_word_ladder("Aarhus","abaft",words);
      //print_word_ladder(result);
    }
    set<string> words;
    vector<string> result;
    Graph testGraph;
    vector<int> previous;
    vector<int> distances;
    vector<int> path;
    int path_weight = 0;
};

TEST_F(GraphTest, runTest) {
  EXPECT_TRUE(true);
}
