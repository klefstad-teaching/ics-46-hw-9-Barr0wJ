#include "ladder.h"

void error(string word1, string word2, string msg){
	cout << word1 << " " << word2 << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
	int str1_size = str1.size();
	int str2_size = str2.size();
	vector<int> vector0(str2_size+1);
	vector<int> vector1(str2_size+1);
	for (int i = 0; i<str2_size;i++){
		vector0[i] = i;
	}
	for (int i = 0; i<str1_size-1;i++){
		vector1[0] = i+1;

		for (int j = 0; i<str2_size-1;i++){
			int substitutionCost = -3;
			int delectionCost = vector0[j+1]+1;
			int insertionCost = vector1[j] +1;
			if (str1[i] == str2[j]){
				substitutionCost = vector0[j];
				vector1[j+1] = min(min(delectionCost,insertionCost),substitutionCost);
			}
			else{
				substitutionCost = vector0[j] + 1;
				vector1[j+1] = min(min(delectionCost,insertionCost),substitutionCost);
			}
			if (substitutionCost == -3){
				vector1[j+1] = min(delectionCost,insertionCost);
			}
		}
		swap(vector0,vector1);
	}
	return (vector0[str2_size-1] <= d);
}
bool is_adjacent(const string& word1, const string& word2){
	return edit_distance_within(word1,word2,1);
}


vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
	vector<string> ladder;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()){
        ladder = ladder_queue.front();
		ladder_queue.pop();
        string last_word = ladder.back();
        for (string word : word_list){
            if (is_adjacent(last_word, word)){
                if ((visited.find(word))!=visited.end()){
                    visited.insert(word);
                    vector<string> new_ladder(ladder);
                    new_ladder.push_back(word);
                    if (word == last_word) return new_ladder;
                    ladder_queue.push(new_ladder);
				}
			}
		}
	}
	error(begin_word,end_word, " No ladder found");
    return ladder;
}
void load_words(set<string> & word_list, const string& file_name){
    ifstream in(file_name);
    if (!in) {
        throw runtime_error("Can't open input file");
    }
	string s;
	for (string s;in >> s;){//int i = 0; i<5; i++){//
		in >> s;
    	word_list.insert(s);
	}
    in.close();
}
void print_word_ladder(const vector<string>& ladder){
	int size = ladder.size();
	for (int i = 0; i<size;i++){
		cout << ladder[i] << endl;
	}
}
void verify_word_ladder(){
	cout << "temp" << endl;
}