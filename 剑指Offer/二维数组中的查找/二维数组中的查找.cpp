//��һ������������ʽ�ı�̣����Ǻ���Ϥ�������˵��� ���Ǻܿ����߼���.
//��סҪ�Ӿ������ҽǿ�ʼ��ѯ�������ǰ����Ŀ��ֵ����ô������ƣ�
//�����ǰ����Ŀ��ֵС����ô���±��ƣ�
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int cols; //���������
        int rows; //���������
        int row;//����ǰ������
        int col;//����ǰ������
        bool flag=false;
        if(array.size()!=0){
            rows=array.size();
            cols=array[0].size();
            col=cols-1;
            row=0;
            while(col>=0&&row<rows){
                if(array[row][col]==target){
                    flag=true;
                    break;
                }
                else if(array[row][col]>target) col--;
                else row++;
            }
        }
        return flag;
    }
};
