/** 
	Problem : Replace Words 
	topics : trie or prefix tree
	time complexitiy: O(len) - insert the word
					  O(len) - replace the word	according to problem descrption
					  here, len = size of largest word
	space complexity: In trie data structure we can not define the space complexity
					  
	problem link: https://leetcode.com/problems/replace-words/
**/

struct Node {
    Node* links[26];
    bool flag = false;
    
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
        flag = true;
    }
    bool isEnd() {
        return flag;
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
    
    string replace(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(node->isEnd()) {
                return word.substr(0,i);
            }
            else if(!node->containsKey(word[i])){
                return word;
            }
            node = node->get(word[i]);
        }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(int i=0; i<dictionary.size(); i++) {
            trie.insert(dictionary[i]);
        }
        string ans = "", temp;
        stringstream s(sentence);
        while(s >> temp) {
            temp = trie.replace(temp);
            ans += temp + " ";
        }
        return ans.substr(0, ans.size() - 1);
        
    }
};
