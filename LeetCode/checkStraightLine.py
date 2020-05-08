class Solution(object):
    def checkStraightLine(self, coordinates):
        """
        :type coordinates: List[List[int]]
        :rtype: bool
        """
        l = len(coordinates)
        if l <= 2:
            return True
        else:
            dx = (coordinates[0][1] - coordinates[1][1])
            dy = (coordinates[0][0] - coordinates[1][0])
            for i in range(2, l):
                if dx * (coordinates[i][0] - coordinates[0][0]) != (coordinates[i][1] - coordinates[0][1]) * dy:
                    return False
            return True