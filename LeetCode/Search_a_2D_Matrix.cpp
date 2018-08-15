class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        // �ж϶�ά�����ǲ��ǿյ�
        if(matrix.size()==0) return found;
        int rows = matrix.size();
        if(matrix[0].size()==0) return found;
        int cols = matrix[0].size();
        // ���ڶ�ά����Ĳ����Ǵӵ�һ�����Ҳ࿪ʼ���ң������������ά���鹹�������ȥ����
        int row = 0;
        int col = cols - 1;
        while(row<rows && col>=0){
            if(matrix[row][col] == target){
                found = true;
                break;
            }
            else if(matrix[row][col] < target) row++;
            else col--;
        }
        return found;
    }
};
