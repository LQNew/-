// �ѶȽϴ����η�ת�ַ�����Ҫ��ɾ������Ŀո����Ҫ��Ҫ���Ӧ��string �⺯���е� erase()����
// �����߼��ϵ�ϸ��˼�����⣡
class Solution {
public:
    void reverseWords(string &s) {
        int length = s.size();
        if(length==0) return;
        int a,b;
        a = 0; b = 0;
        while(s[b]==' ') b++; // ȥ���ײ��Ŀո�
        s.erase(a,b); // ɾ����a��ʼ�� b���ַ�
        length -= b;
        if(length==0) return;
        int i = 0;
        int j = length - 1;
        // ��һ�η�ת����ת�����ַ���
        while(i<j){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        a = 0; b = 0;
        while(s[b]==' ') b++; // ȥ��β���Ŀո�
        s.erase(a,b);
        length -= b;
        if(length==0) return;
        // �ڶ��η�ת����תÿ������
        i = 0; j = 0;
        while( i < length ){
            while(s[i] == ' ' && i<length){ // ɾ������ո���Ϊ�ײ���β���Ŀո����ȥ�������Դ˴�ֻ�е��ʼ�Ķ���Ŀո�
                s.erase(i,1);
                length -= 1;
            }
            if( i>=length ) break;
            if(s[j] == ' '||s[j] == '\0'){
                int tmp1 = j;
                tmp1 --;
                while(i<tmp1){
                    char tmp = s[i];
                    s[i] = s[tmp1];
                    s[tmp1] = tmp;
                    i++;
                    tmp1--;
                }
                i = ++j; // �˴����ڿո�����һ����һ���ո�Ĳ�����������ǰ��ɾ������Ŀո񴦣�����ֱ�Ӵ���

            }
            else j++;
        }
    }
};
