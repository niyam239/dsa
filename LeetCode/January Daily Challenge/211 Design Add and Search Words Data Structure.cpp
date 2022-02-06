/** 
	Problem : Design Add and Search Words Data Structure 
	topics : trie or prefix tree
	time complexitiy: O(len) - insert the word
					  O(len + 26^len) - serach the word	 
					  here, len = size of largest word
					  		26^len for recursive calls of wild card ('.')
	space complexity: In trie data structure we can not define the space complexity
					  
	problem link: https://leetcode.com/problems/design-add-and-search-words-data-structure/
**/

struct Node {
    Node* links[26];
    bool endsWith = false;
    
    bool containsKey(char c) {
        return (links[c - 'a'] != NULL);
    }
    Node* get(char c) {
        return links[c - 'a'];
    }
    void put(char c, Node* node) {
        links[c - 'a'] = node;
    }
    void setEndsWith() {
        endsWith = true;
    }
    bool isEndsWith() {
        return endsWith;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEndsWith();
    }
    
    //we have added second parameter with default value for recursive calls 
    //for find word having wild card : '.'
    bool search(string word, Node* startRoot = NULL) {
        Node* node = (startRoot == NULL ? root : startRoot);
        for(int i=0; i<word.size(); i++) {
            if(word[i] == '.') { 
                for(int j=0; j<26; j++) {
                    if(node->containsKey(char('a' + j)) 
                       && search(word.substr(i+1), node->get(char('a' + j)))) {
                        return true;
                    }
                }
                return false;
            }
            else if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node && node->isEndsWith();
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
