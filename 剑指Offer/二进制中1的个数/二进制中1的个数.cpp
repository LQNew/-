//���������1�ĸ���������ⷨ˼·�����
class Solution{
public:
    int NumberOf1(int n){
        int count=0;
        unsigned int flag = 1; //������unsigned int �Ĵ���������
        while(flag){ //��flag����32λ�������Ϊ0�����Ǹպ�����int�ͱ���Ҳ����һ��
            if(n&flag) count++; //ֻ��һ��ֻ��һλΪ1������λȫΪ0�������룬ֻ����ҪôΪ0��Ҫô��0�Ľ��
            flag=flag<<1;
        }
        return count;
    }
};
