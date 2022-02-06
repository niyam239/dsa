/** 
	Problem : Implement Trie (Prefix Tree) 
	topics : trie or prefix tree
	time complexitiy: O(len) - insert the word
					  O(len) - serach the word	 
					  here, len = size of largest word
	space complexity: In trie data structure we can not define the space complexity
					  
	problem link: https://leetcode.com/problems/implement-trie-prefix-tree/
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
    void setEnd() {
        endsWith = true;
    }
    bool isEnd() {
        return endsWith;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++) {
            if(!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
