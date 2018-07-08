/*
    ����һ��ͼ�Ľṹ������������������У�Ҫ����ͬ�������£����С�Ķ�����ǰ��
*/
//�������򣬾���ÿ���ҵ���ǰ���Ϊ0�Ľڵ㽫��������Ȼ������������ָ��ı�Ҳ��ɾ����Ȼ��������һ�����Ϊ0�Ľڵ�
//��Ϊ�˴���Ҫ��ÿ�ζ��Ǳ��С�Ķ��㵯�������ǹ���һ�����ȶ��У�ÿ�ζ�ͷ��ŵĶ�����Сֵ
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int mark[101]; //���ڼ�¼ÿ���ڵ�����ֵ
int v1,v2;
vector<int>edge[101]; //��¼�ٽ�����
priority_queue<int,vector<int>,greater<int>> Q; //���ȶ��й��죬�˴�������С���ѣ�����ͷΪ��Сֵ��ע�����ȶ���Ĭ���Ǵ󶥶ѣ�
int v,a;
int main(){
    while(cin>>v>>a){
        for(int i=1;i<=v;i++){
            edge[i].clear();
            mark[i]=0;
        }
        for(int i=0;i<a;i++){
            cin>>v1>>v2;
            mark[v2]++;
            edge[v1].push_back(v2);
        }
        while(!Q.empty()) Q.pop();
        for(int i=1;i<=v;i++){ //�ҵ����Ϊ0�Ľڵ�ѹ��
            if(mark[i]==0) Q.push(i);
        }
        while(!Q.empty()){
            int tmp=Q.top();
            Q.pop();
            cout<<'v'<<tmp<<' ';
            for(int i=0;i<edge[tmp].size();i++){
                mark[edge[tmp][i]]--;
                if(mark[edge[tmp][i]]==0){ //�ҳ��Ƿ������������Ϊ0�Ľڵ�
                    Q.push(edge[tmp][i]);
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
