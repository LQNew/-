// ��������Ҫ���ȼ�����滻Ϊ�ո����ַ���Ӧ��Ϊ�ĳ��ȣ�Ȼ��ʼ�Ӻ���ǰ�滻�������������Ӱ�쵽֮ǰ��ֵ���о�˼·ʮ�־��ɣ���
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(length <= 0 || str == NULL) return;
        int num_of_space = 0;
        int origin_length = 0;
        int i=0;
        while(str[i] != '\0'){
            origin_length++;
            if(str[i]==' ') num_of_space++;
            i++;
        }
        int final_length = origin_length + num_of_space * 2;
        if(final_length > length) return; //�������滻Ϊ�ո��ĳ��ȴ���str�ַ�������󳤶ȣ���ô�޷��滻��return
        while(origin_length>=0 && final_length > origin_length){
            if(str[origin_length]==' '){
                str[final_length--] = '0';
                str[final_length--] = '2';
                str[final_length--] = '%';
                origin_length --;
            }
            else{
                str[final_length--] = str[origin_length];
                origin_length --;
            }
        }
	}
};
