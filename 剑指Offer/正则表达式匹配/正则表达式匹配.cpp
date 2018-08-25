class Solution {
public:
    bool test_zero(char* pattern){
        if(*pattern == '\0') return true;
        if(*(pattern + 1) == '*') return test_zero(pattern + 2);
        if(*pattern == '*') return test_zero(pattern + 1);
        return false;

    }

    bool test(char* str, char* pattern){
        if(*str == '\0' && *pattern == '\0') return true; // ���ƥ�䴮��������ʽ��������ĩ�ˣ�ƥ��
        if(*str != '\0' && *pattern == '\0') return false; // ���ƥ�䴮δ��ĩ�ˣ�����������ʽ������ĩ�ˣ���ô��ƥ��
        if(*(pattern + 1) == '*'){
            if((*pattern == *str) || (*pattern == '.' && *str != '\0')){ // ��� p[j] �� s[i] ��ȣ���p[j + 1] Ϊ '*'
                return test(str + 1, pattern + 2) || test(str + 1, pattern)\
                       || test(str, pattern + 2);
                // (i+1, j+2) ����һ״̬�� (i+1, j) �ȶ��Ƿ���һ���ַ�s[i+1] ���� p[j]�� (i, j+2)���� p[j]��'*'
            }
            else return test(str, pattern + 2); // ���� p[j] �� '*'
        }
        // p[j+1] != '*'ʱ���������
        if(*str == *pattern || (*pattern == '.' && *str != '\0')) return test(str + 1, pattern + 1);
        return false;
    }

    bool match(char* str, char* pattern){
        if(str != NULL && pattern == NULL) return false;
        if(str == NULL){
            if(pattern == NULL) return true;
            return test_zero(pattern); // ����str Ϊ��ʱ�����
        }
        return test(str, pattern);
    }
};
