/*
    ����
        ��һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש����վ������һ���ɫ�Ĵ�ש�ϣ�ֻ�������ڵĺ�ɫ��ש�ƶ���
        ��дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��
    ����
        ����������ݼ��ϡ�ÿ�����ݼ��ϵĵ�һ������������W��H���ֱ��ʾx�����y�����ש��������W��H��������20���ڽ�������H���У�ÿ�а���W���ַ���
        ÿ���ַ���ʾһ���ש����ɫ���������£�
        1����.������ɫ�Ĵ�ש��
        2����#������ɫ�Ĵ�ש��
        3����@������ɫ�Ĵ�ש��������վ������ש�ϡ����ַ���ÿ�����ݼ�����Ψһ����һ�Ρ�
        ����һ���ж������������ʱ����ʾ���������
    ���
        ��ÿ�����ݼ��ϣ��ֱ����һ�У���ʾ��ӳ�ʼλ�ó����ܵ���Ĵ�ש��(����ʱ������ʼλ�õĴ�ש)��
*/
//������������ǵ��͵Ĺ�������������⣬˼·��Ϊ�򵥣����Ǵ�ÿһ�������ȥ��Ѱ�õ�����ܣ���Ҫע����ǣ���ĳ���㱻������Ӧ���ϱ�ʶ��
#include<iostream>
using namespace std;
char map1[20][20];
int W,H;
struct location
{
  int row;
  int col;
};

location find_location() //���ؽṹ��
{
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(map1[i][j]=='@')
            {
                location locat;
                locat.row=i;
                locat.col=j;
                return locat;
            }
        }
    }
}

int search_1(int i,int j)
{
    if(i<0||j<0||i>=H||j>=W)
        return 0;
    else
    {
        if(map1[i][j]=='.'||map1[i][j]=='@')
        {
            map1[i][j]='!'; //���ϱ�ʶ
            return search_1(i-1,j)+1+search_1(i+1,j)+search_1(i,j-1)+search_1(i,j+1);
        }
        else
            return 0;
    }
}
int main()
{
    cin>>W>>H;
    while(!(W==0||H==0))
    {
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                cin>>map1[i][j];
            }
        }
        location locat=find_location(); //�ҵ�@��λ��
        int cnt=search_1(locat.row,locat.col); //�Ըõ�Ϊ��ʼ�㿪ʼ����
        cout<<cnt<<endl;
        cin>>W>>H;
    }
    return 0;
}
