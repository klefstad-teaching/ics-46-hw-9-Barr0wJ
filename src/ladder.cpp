#include "ladder.h"

void error(string word1, string word2, string msg){
	cout << word1 << " " << word2 << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
	int word1_size = str1.size();
	int word2_size = str2.size();
	int dif_len = word1_size-word2_size;
	if (abs(dif_len)>1){
		return false;
	}
	else if (word1_size>word2_size){
		for(int i = 0;i<word2_size;i++){
			if (str1[i]!=str2[i]) return false;
		}
	}
	else if (word2_size>word1_size){
		for(int i = 0;i<word1_size;i++){
			if (str1[i]!=str2[i]) return false;
		}
	}
	return true;
}
bool is_adjacent(const string& word1, const string& word2){
	int differ = 0;
	int word1_size = word1.size();
	if (word1.size()==word2.size()){
		for(int i = 0;i<word1_size;i++){
			if (word1[i]!=word2[i])differ++;
		}
	}
	else{
		return edit_distance_within(word1,word2,0);
	}
	if (differ>1) return false;
	else return true;
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