//���͵ı������⣬��Ŀ������ú��Ƿ��ӣ����˲��׶�����Ŀ�����������ѶȲ��Ǻܴ�
//��ͳ��˵����ʵ�����Ͼ��Ǹ�һ������Ȼ�����һЩ�̶��������ø���ֻ��ͨ����Щ�̶��������мӼ�������ã�������Ĵ���Ҫ����
//��ϸ�ط�������������ȫ����������ۺϣ�����Сֵ
//������ȫ��������������ȫ��������������ϸ��������֪��Ŀ�ľ��ǣ�ÿ���ܹ����õ�֮ǰ�������õ���С�����ֵ
//ͬʱ����0-1������Ҫ�˽���ǣ�0-1������������Ϊÿ������ֻ���õ�һ�Σ�����ߵ�ϸ������һ��Ҫ�˽⣡
#include<iostream>
#include<iomanip>
using namespace std;
const int INF=0x7fffffff;
int maxn=5000;
int cases;
int a[6];
int dp[5001];
int main(){
    cin>>cases;
    for(int i=0;i<cases;i++){
        for(int i=0;i<6;i++) cin>>a[i];
        for(int i=0;i<=maxn;i++) dp[i]=INF; //��ʼ����ע����memset��ʼ��ʱֻ���Գ�ʼ��Ϊ0��-1��������������
        dp[0]=0;
        for(int i=0;i<6;i++){
            for(int j=a[i];j<=maxn;j++) dp[j]=min(dp[j],dp[j-a[i]]+1); //��ȫ������������ӵ�ʱ��
        }
        for(int i=0;i<6;i++){
            for(int j=maxn-a[i];j>=0;j--) dp[j]=min(dp[j],dp[j+a[i]]+1); //��ȫ���������������ʱ��
        }
        int max1=-1;
        int s=0;
        for(int i=1;i<=100;i++){
            if(dp[i]>max1) max1=dp[i];
            s+=dp[i];
        }
        cout<<fixed<<setprecision(2)<<double(s)/100.0<<' '<<max1<<endl;
    }
    return 0;
}
