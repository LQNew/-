class Solution {
public:
    string reverseWords(string s) {
        int length = s.size();
        if(length == 0) return s;
        int i,j;
        i = 0; j = 0;
        while(i<length){
            if(s[i] == ' '){ // �����ײ����ֶ���Ŀո�ֱ�ӻ���
                i++;
                j++;
            }
            else if(s[j] == ' ' || s[j] == '\0'){ // β�����ֿո�򵽽�β����ת ͷ��β��һ���ֵĵ���
                int tmp1 = j;
                tmp1--;
                while(i<tmp1){ // �۰뽻����ʱ�俪����СһЩ��
                    char tmp = s[i];
                    s[i] = s[tmp1];
                    s[tmp1] = tmp;
                    i ++;
                    tmp1--;
                }
                i = ++j;
            }
            else j++;
        }
        return s;
    }
};
