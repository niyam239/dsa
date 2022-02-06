/** 
	Problem : Largest Rectangle in Histogram
	topics : stack, two pointer
	time complexitiy: O(N)
	space complexity: O(N)
	problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/
**/

class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        int n = histo.size();
        
        stack<int> st;
        int maxA = 0;
        
        for(int i=0;i<=n;i++) {
            while(!st.empty() && (i==n || histo[st.top()] >= histo[i])){
                int height = histo[st.top()];
                st.pop();
                
                int width;
                if(st.empty()) width = i;
                else    width = i-st.top()-1;
                
                maxA = max(maxA, height*width);
            }
            st.push(i);
        }
        return maxA; 
    }
};
