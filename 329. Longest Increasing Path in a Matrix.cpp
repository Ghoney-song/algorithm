class Solution {
public:
    const int dx[4] = {0 ,0 ,-1 ,1};
    const int dy[4] = {-1, 1, 0, 0};
    
    int memo(int **arr, vector<vector<int>>& input, int x, int y)
    {
        if(arr[x][y] > 0) return arr[x][y];
        
        for(int i=0; i<4 ;i++)
        {
            int xi = x + dx[i];
            int yi = y + dy[i];
            
            if(!(xi<0 || yi<0 || xi >= input.size() || yi >= input[0].size()))
            {
                if(input[xi][yi] > input[x][y])
                {
                    arr[x][y] = max(arr[x][y], memo(arr, input, xi, yi));
                }
            }
        }
        
        arr[x][y]++;
        
        return arr[x][y];
    } 
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        
        int **mem = new int*[matrix.size()];
        for(int i = 0; i < matrix.size(); i++)
        {
            mem[i] = new int[matrix[0].size()];
            memset(mem[i], 0, sizeof(int)*matrix[0].size());
        }
        
        for(int i = 0; i<matrix.size(); i++)
        {
            for(int j = 0; j<matrix[0].size(); j++)
            {
                int m = memo(mem, matrix, i, j);
                ret = max(ret, m);
            }
        }
        
        
        for(int i =0 ; i<matrix.size(); i++)
        {
            delete [] mem[i];
        }
        delete [] mem;
        
        
        return ret;
    }
};