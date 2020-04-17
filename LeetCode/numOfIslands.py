class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    def mark(ti, tj):
                        if ti == -1 or tj == -1 or ti == len(grid) or tj == len(grid[ti]):
                            return
                        if grid[ti][tj] == "1":
                            grid[ti][tj] = 0
                            mark(ti + 1, tj)
                            mark(ti, tj + 1)
                            mark(ti - 1, tj)
                            mark(ti, tj - 1)
                    mark(i, j)
                    res += 1
        return res

#The following is from LeetCode
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def expand(row, col):
            grid[row][col] = "0"
            if row > 0 and grid[row-1][col] == "1":
                expand(row-1, col)
            if row < rolCount-1 and grid[row+1][col] == "1":
                expand(row+1, col)
            if col > 0 and grid[row][col-1] == "1":
                expand(row, col-1)
            if col < colCount-1 and grid[row][col+1] == "1":
                expand(row, col+1)
            
        
        count = 0
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0
        rolCount = len(grid)
        colCount = len(grid[0])
        
        for row in range(0, len(grid)):
            for col in range(0,len(grid[0])):
                if grid[row][col] == "1":
                    count+=1
                    expand(row, col)
        return count