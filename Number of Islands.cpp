class Solution {
    
    void mark_current_island(vector<vector<char>> &matrix,int x,int y,int r,int c)
                            //Here int x and int y is ->> Current cordinate
                            //Here int r and int c is ->> grid (m * n) size
    {
        if(x<0 || x>=r || y<0 || y>=c || matrix [x][y] != '1') //Boundary case
           
            return;
            
            //Make current call as visited
            matrix [x][y] = '2';
        
            //Make recursive call in all adjacent directions
           
           mark_current_island(matrix,x-1,y,r,c); //Top
               
           mark_current_island(matrix,x+1,y,r,c); //Down
               
           mark_current_island(matrix,x,y-1,r,c); //Left
               
           mark_current_island(matrix,x,y+1,r,c); //right
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
                
        int rows = grid.size();
        
        if(rows == 0)  //Empty Grid Boundary Case
        {
            return 0;
        }
        
        int cols = grid[0].size();
        
        //Now iterate all cols of the array
        
        int No_of_Island = 0;
        
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j] =='1')
                {
                    mark_current_island (grid,i,j,rows,cols);
                   
                    No_of_Island += 1;
                }
            }
        }
        
        return  No_of_Island;
    }
};