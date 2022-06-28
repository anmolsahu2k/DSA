#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(int row,int col, vector<vector<int>>& image, int orig)
    {
        int n=image.size();
        int m=image[0].size();
        if(row<n&&col<m&&row>=0&&col>=0&&image[row][col]==orig)
            return true;
        return false;
    }
    void fill(int row, int col, vector<vector<int>>& image,vector<int> dx, vector<int> dy, int color,int orig )
    {
        for(int i=0;i<4;i++)
        {
            int x=row+dx[i];
            int y=col+dy[i];
            if(isValid(x,y,image, orig))
            {
                image[x][y]=color;
                fill(x,y,image,dx,dy,color,orig);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,-1,0,1};
        int original=image[sr][sc];        
        if(color!=original)
        {
            image[sr][sc]=color;
            fill(sr,sc,image,dx,dy,color,original);
        }
        return image;
    }
};