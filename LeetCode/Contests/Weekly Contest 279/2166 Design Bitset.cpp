/** 
	Problem : Design Bitset
	topics : bit-manupulation, 
	time complexitiy for every fun: 
		function	|	 TC
		---------------------
		BitSet() 	|	O(N)
		fix()		|	O(1)
		unfix()		|	O(1)
		flip()		|	O(1)
		all()		|	O(1)
		one()		|	O(1)
		count()		|	O(1)
		toString()	|	O(N)
	space complexity : O(N) // N is max size of bitset		
	problem link: https://leetcode.com/problems/design-bitset/
**/

class Bitset {
private:
    vector<bool> arr;
    int flipFlag = 0;
    int cnt = 0;
public:
    Bitset(int size) {
        arr.resize(size, 0);   
        cnt = 0;
        flipFlag = 0;
    }
    
    void fix(int idx) {
        if(arr[idx] == flipFlag) {
            arr[idx] = 1 ^ flipFlag;
            cnt++;
        }
    }
    
    void unfix(int idx) {
        if(arr[idx] == (1 ^ flipFlag)) {
            arr[idx] = flipFlag;
            cnt--;
        }
    }
    
    void flip() {
        flipFlag = 1 ^ flipFlag;
        cnt = int(arr.size()) - cnt;
    }
    
    bool all() {
        return cnt == arr.size();
    }
    
    bool one() {
        return cnt > 0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string s(arr.size(), '0');
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] ^ flipFlag)  s[i] = '1';
            else    s[i] = '0';
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
