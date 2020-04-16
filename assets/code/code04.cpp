class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        bool found = false;
        //空数组
        if (matrix.size() == 0) {
            return false;
        }

        //从右上角开始搜素
        int rows = matrix.size();
        int columns = matrix[0].size();
        int row = 0;
        int column = columns - 1;

        if (rows > 0 && columns > 0) {
            while (row < rows && column >= 0) {
                if (matrix[row][column] == target) {
                    found = true;
                    break;
                } else if (matrix[row][column] > target) {
                    column--;
                } else {
                    row++;
                }
            }
        } 
        return found;
    }
};