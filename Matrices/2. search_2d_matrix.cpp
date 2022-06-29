#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int c=matrix[0].size();
    int r=matrix.size();
    int l=0,h=r*c-1,mid;        
    while(l<=h)
    {
        mid=l+(h-l)/2;
        if(matrix[mid/c][mid%c]==target)
            return true;
        else if(matrix[mid/c][mid%c]<target)
            l=mid+1;
        else
            h=mid-1;
    }
    return false;
}
int main()
{
    vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
    cout<<searchMatrix(matrix,4);
    return 0;
}