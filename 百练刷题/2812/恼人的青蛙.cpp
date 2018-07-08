//poj 2812 ���˵����ܣ���Ŀ����̫�࣬�ڴ˴��Ͳ�������Ŀ�ˣ�����ֱ�ӵ���ҳȥ����Ŀ
//������������ʵ�����Ǳ������ȵ�ˮ�����ҵ����·��
//����ֱ�۵�ö��˼·������ö���������ÿ��Ž����нڵ��ź��򣬽��������ڹ̶�����ʼ�����ڵ����ö��ֲ�ѯ��ѯ�������Ľڵ��Ƿ���ڣ�ע��˴� �����Լ����ֲ�ѯ����ڽṹ�����д��
//������п����ߵ�·�������õ����·���������ַ�����ʱ�������������֦��ǰɸȡһЩ�б�������TL���ǳ���
//������Ҫ��֦����ؼ����б���ʼ���������ǲ�����㣬�Լ����õ�ǰmax�����б�ӵ�ǰ�õ�����������᲻�����
//�ӵ㣺1����Ҫ��֦����ʼ�������б�Ҫ�������
//2���ڶ��ֲ�ѯ�б�ڵ��Ƿ����ʱ�������ǰ�ڵ���һ��Ԥ��ڵ����û�г��絫�ǲ����ڣ�˵�����ܲ�����ͨ�����·����������ô���·���������ڣ�����stepӦ�����㣡
//�����������algorithm���qsort()�������ڽṹ��������п��ţ����ŵĺ���ʹ��һ��Ҫ��Ϥ���Լ�bsearch()�������ж��ֲ�ѯ��bsearch���÷�һ��Ҫ��Ϥ����
#include<iostream>
#include<algorithm>
using namespace std;
struct Plant //�ṹ��Ĺ����Լ�ʹ��Ҫ�˽⣡
{
    int x,y;//�ṹ�壬�洢ׯ�ڵĺ����ꡢ������
};
int R,C;
int N;
Plant plant[5001];

int compare(const void*a,const void*b) //����qsort ʹ�õ�compare�������йش�compare��������дӦ���⣡��ʽ����һ�µģ��Լ�Ҫ��Ϥд��~
//�˴��Ժ�������������
{
    Plant*p1;
    Plant*p2;
    p1=(Plant*)a;
    p2=(Plant*)b;
    if((*p1).x==(*p2).x)
        return((*p1).y-(*p2).y);
    else
        return((*p1).x-(*p2).x);
}

int search_1(int j,int dx,int dy)
{
    int step=2;
    Plant p;
    p.x=plant[j].x+dx;
    p.y=plant[j].y+dy;
    while(p.x<=R&&p.y<=C&&p.x>=1&&p.y>=1)
    {
        if(bsearch(&p,plant,N,sizeof(Plant),compare)) //���ֲ��� ����ģ��
        //bsearch(const void *key, const void *base, size_t num, size_t size, int (*cmp)(const void *, const void *));
        //key ָ��Ҫ���ҵ�Ԫ�أ�base ָ����в��ҵ����飬num ������Ԫ�صĸ�����size ������ÿ��Ԫ�صĴ�С��һ����sizeof()��ʾ��cmp �Ƚ�����Ԫ�صĺ���������ȽϹ���
        {
            p.x+=dx;
            p.y+=dy;
            step++;
        }
        else //û�е����ﾡͷ����ˣ�˵������·��������ѹ��û�߹�������Ҫ�������б𣡣�
        {
            step=0;
            break;
        }

    }
    if(step<3)
        return 0;
    return step;
}

int main()
{
    cin>>R>>C;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>plant[i].x>>plant[i].y;
    }
    qsort(plant,N,sizeof(Plant),compare); //qsort ���ڽṹ��Ŀ�������!!
    int max=0;
    int steps;
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            int dx=plant[j].x-plant[i].x;
            int dy=plant[j].y-plant[i].y;
            if(plant[i].x-dx>=1&&plant[i].x-dx<=R&&plant[i].y-dy>=1&&plant[i].y-dy<=C) //�����ʼ��
                continue;
            if(plant[i].x+max*dx>R) //���x���磬˵�����ڸ�x��������������ڵ㶼������ϣ�����������ǰ��jѭ��
                break;
            if(plant[i].y+max*dy<1||plant[i].y+max*dy>C) //������磬��ô�˴β�����step���㣬continue��ֱ������forѭ����
                continue;
            steps=search_1(j,dx,dy);
            if(max<steps)
                max=steps;
        }
    }
    cout<<max<<endl;
    return 0;
}
