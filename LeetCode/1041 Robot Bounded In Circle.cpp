/** 
	Problem : Robot Bounded in circle
	approach : math
	time complexitiy: O(len) // here, len = size of string
	space complexity: O(1)
	problem link: https://leetcode.com/problems/valid-mountain-array/
**/

class Solution {
public:
    int changeDirection(int curDir, int change) {
        curDir += change;
        if(curDir == -1) {
            curDir = 3;
        }
        if(curDir == 4) {
            curDir = 0;
        }
        return curDir;
    }
    bool isRobotBounded(string instructions) {
        string dir = "ESWN";
        int curDir = 3;
        int dirVal[4][2];
        dirVal[0][0] = 1;   dirVal[0][1] = 0;
        dirVal[1][0] = 0;   dirVal[1][1] = -1;
        dirVal[2][0] = -1;   dirVal[2][1] = 0;
        dirVal[3][0] = 0;   dirVal[3][1] = 1;
        
        int x = 0, y = 0;
        int dx = 0, dy = 1;
        for(int i=0; i<4; i++) {
            for(char it : instructions) {
                if(it == 'G') {
                    x += dx;
                    y += dy;
                } else if(it == 'L') {
                    curDir = changeDirection(curDir, -1);
                    dx = dirVal[curDir][0];
                    dy = dirVal[curDir][1];
                } else if(it == 'R' ) {
                    curDir = changeDirection(curDir, 1);
                    dx = dirVal[curDir][0];
                    dy = dirVal[curDir][1];
                }
                
                
            }
			if(x == 0 || y == 0) {
				return true;
			}
        }
        return false;
    }
};
