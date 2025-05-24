from collections import defaultdict

def complete(board):
    for row in board:
        if 0 in row:
            return False
    
    return True

def check(board):
    for i in range(0, 9):
        umap = defaultdict(int)
        for j in range(0, 9):
            if (board[i][j] != 0):
                umap[board[i][j]] += 1
                if (umap[board[i][j]] > 1):
                    return False

    for i in range(0, 9):
        umap = defaultdict(int)
        for j in range(0, 9):
            if (board[j][i] != 0):
                umap[board[j][i]] += 1
                if (umap[board[j][i]] > 1):
                    return False

    rows = [1, 4, 7]

    for r in rows:
        for c in rows:
            umap = defaultdict(int)
            for dr in range(-1, 2):
                for dc in range(-1, 2):
                    R = r + dr
                    C = c + dc
                    if (board[R][C] != 0):
                        umap[board[R][C]] += 1
                        if (umap[board[R][C]] > 1):
                            return False

    return True


def solve(board):
    if complete(board):
        return True
    
    for i in range(0, 9):
        for j in range(0, 9):
            if board[i][j] == 0:
                flag = False
                for k in range(1, 10):
                    board[i][j] = k
                    if (check(board) and solve(board)):
                        flag = True
                        return True
                board[i][j] = 0
                if (not flag):
                    return False
    return False
    

def main():
    file = open("sudoku.txt", "r")
    lines = file.readlines()
    boards = []
    for i in range(0, len(lines), 10):
        grid = int(lines[i].strip().split(" ")[1])
        board = []

        for line in range(1, 10):
            row = list(map(int, list(lines[i + line].strip())))
            board.append(row)
        # for row in board:
        #     print(row)
        # print()
        boards.append(board)

    sum = 0
    for index, board in enumerate(boards):
        print(f"Solving board: {index + 1}")
        flag = solve(board)
        if flag:
            for row in board:
                print(row)
            print()
            sum = sum + (board[0][0] * 100 + board[0][1] * 10 + board[0][2])
        else:
            print(f"Could not solve board: {index + 1}")
    
    print(sum)
        

if __name__ == "__main__":
    main()