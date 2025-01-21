def maxCost(grid, n):
    dp = [[-1 for i in range(n)] for i in range(n)]

    def solve(r, c):
        if dp[r][c] != -1:
            return dp[r][c]
        if r == n-1:
            return grid[r][c]
        down = grid[r][c] + solve(r+1, c)
        diagonal = grid[r][c] + solve(r+1, c+1)

        dp[r][c] = max(down, diagonal)
        return dp[r][c]
    return solve(0, 0)


def main():
    file = open('maxpath.txt','r')
    lines = file.readlines()

    grid = []
    for line in lines:
        temp = [int(i) for i in line.strip().split(" ")]
        grid.append(temp)

    n = len(grid)

    print(maxCost(grid, n))

main()