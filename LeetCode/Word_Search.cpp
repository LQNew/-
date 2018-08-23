// �������ѽ�����⣬˼·�Ƚϸ��ӣ�������д�������ĳ���...
// �����������⣬����Ҫ���˼����������Ŀͨ�������ҳ��ݹ��˼·���Լ��߽�����������Ҫϸ��˼����
class Solution {
public:
    bool hasPath(vector<vector<char>>& board, int rows, int cols, int row, int col, string word, int pathlength, vector<vector<bool>>& visited){
        if(word[pathlength]=='\0') return true;
        bool flag = false;
        if(row>=0 && row<rows && col>=0 && col<cols && board[row][col]==word[pathlength] && !visited[row][col]){
            pathlength++;
            visited[row][col] = true;
            flag = hasPath(board, rows, cols, row, col-1, word, pathlength, visited)
                   || hasPath(board, rows, cols, row, col+1, word, pathlength, visited)
                   || hasPath(board, rows, cols, row+1, col, word, pathlength, visited)
                   || hasPath(board, rows, cols, row-1, col, word, pathlength, visited);
            if(!flag){
                pathlength--;
                visited[row][col] = false;
            }
        }
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()<=0 || board[0].size()<=0 || word.size()<=0) return false;
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(board.size() ,vector<bool>(board[0].size(),0));  // ��ά����ĳ�ʼ��
        int pathlength = 0;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(hasPath(board, rows, cols, row, col, word, pathlength, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
