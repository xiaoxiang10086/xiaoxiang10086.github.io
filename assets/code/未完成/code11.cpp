class Solution {
public:
    int minArray(vector<int>& numbers) {
        int length = numbers.size();
        int index1 = 0, index2 = length - 1;
        int indexMid = index1;
        while (numbers[index1] >= numbers[index2]) {
            if (index2 - index1 <= 1){
                indexMid = index2;
                break;
            }
            indexMid = (index1 + index2) / 2;
            if (numbers[index1] == numbers[index2] &&
                numbers[index2] == numbers[indexMid]) {
                return MinInorder(numbers, index1, index2);
            }
            if (numbers[indexMid] >= numbers[index1]) {
                index1 = indexMid;
            } else {
                index2 = indexMid;
            }
        }
        return numbers[indexMid];
    }
private:
    int MinInorder(vector<int>& numbers, int index1, int index2) {
        int res = numbers[index1];
        for (int i = index1 + 1; i <= index2; i++) {
            if (res > numbers[i]) {
                res = numbers[i];
            }
        }
        return res;
    }
};