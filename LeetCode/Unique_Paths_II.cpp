//�����谭��·����Ŀ��⣬dp�㷨��Ӧ�ã��ѶȲ��󣬵��ǻ�����Ҫ������~
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        int dp[m][n];
        int f=1;
        for(int i=0;i<n;i++){ //��Ϊֻ�����һ������ߣ����Ե������ߵ�·��һ����һ���谭����ô�������Ķ�û������
            if(obstacleGrid[0][i]==1) f=0;
            dp[0][i]=f;
        }
        f=1;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1) f=0; //��Ϊֻ�����һ������ߣ����Ե������ߵ�·��һ����һ���谭����ô�������Ķ�û������
            dp[i][0]=f;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0; //�����谭ʱ���õ㲻��ǰ�У�ǰ��Ļ���ȫ����Ϊ0
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

    }
};
