class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]==0) {
                    q.push({i,j});
                    mat[i][j]=0;

                }
                else {
                    mat[i][j]=-1;

                }

            }
        } 
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()) {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int k=0;k<4;k++) {
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==-1) {

                    mat[nr][nc]=mat[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return mat;
        
    }
};