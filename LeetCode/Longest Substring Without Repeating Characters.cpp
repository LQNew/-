/*
  ��p2��p1����ָ��һǰһ���ߣ�p1��¼��ǰ�鿴���Ӵ��׸��ַ���p2��ǰ�����ɨ����p1��Ӧ���ַ���ͬ���ַ��ͼ�����ǰ�ߣ�ֱ��������p1�ַ���ͬ���ַ���
  ͣ�������㵱ǰɨ����ִ����ȣ�����curMax���ȡ�Ȼ��p1��ǰ�ߣ�֪������һ����p2��ͬ���ַ�������ǰһ���ų�������ظ����ַ���
  ����p1�ͳ�Ϊ����һ�������ظ��ַ����ӷ�����㣬����p2���Լ�����ǰ�ߣ��Դ����ƣ�ֱ��ɨ���������ַ���
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //˫ָ��
        int i=0;
        int j=0;
        int flag[128];
        int maxlen=0;
        memset(flag,-1,sizeof(flag));///��ʼ��Ϊ-1
        while(j<s.size()){
             //����ɨ��ָ���Ӧ��λ�õ�ֵ�Ƿ�-1���Ƿ�֮ǰ�����ʹ� or ��ɨ��ָ����������ʹ�������λ���Ƿ��ڵ�ǰͷָ��֮ǰ�������֮ǰ��
             //��ô�����µ��Ӵ�����û��Ӱ��
            if(flag[s[j]]==-1||flag[s[j]]<i){
                flag[s[j]]=j;
                if(j==(s.size()-1)){
                    maxlen=max(maxlen,j-i+1);
                    return maxlen;
                }
                j++;
            }
            else{
                maxlen=max(maxlen,j-i);
                i=flag[s[j]]+1;
                flag[s[j]]=j;
                j++;
            }
        }
        return maxlen;
    }
};
