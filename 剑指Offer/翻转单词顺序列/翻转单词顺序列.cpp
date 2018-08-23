// ��׼�淶���Ľⷨ~
class Solution {
public:
    string ReverseSentence(string str) {
        int length = str.size();
        if(length == 0) return str;
        int i,j;
        i = 0; j = length - 1;
        while(i<j){ // �״η�ת��ȫ��ת
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
            i++;
            j--;
        }
        i = 0; j = 0;
        while(i < length){ // �ڶ��η�ת����ת����
            if(str[i] == ' '){ // ��ͷ�ǿո��û��Ҫ��ת
                i++;
                j++;
            }
            else if(str[j] == ' ' || str[j] == '\0'){
                int tmp1 = j;
                tmp1--;
                while(i<tmp1){
                    char tmp = str[i];
                    str[i] = str[tmp1];
                    str[tmp1] = tmp;
                    i++;
                    tmp1--;
                }
                i = ++j;
            }
            else j++;
        }
        return str;
    }
};
