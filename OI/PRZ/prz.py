def canMaintainPower(board, buttons):
    n = len(board)
    
    def dfs(row, col, visited):
        visited[row][col] = True
        for i in range(n):
            if board[row][i] == 1 and not visited[row][i]:
                dfs(row, i, visited)
            if board[i][col] == 1 and not visited[i][col]:
                dfs(i, col, visited)
    
    def isConnected():
        visited = [[False for _ in range(n)] for _ in range(n)]
        found = False
        for button in buttons:
            row, col = button
            if not visited[row][col]:
                if found:
                    return False
                dfs(row, col, visited)
                found = True
        return True
    
    return isConnected()

# Przykład użycia funkcji
n = 3  # Wielkość planszy
board = [[0 for _ in range(n)] for _ in range(n)]  # Początkowa plansza (wszystkie przyciski wyłączone)
buttons = [(0, 0), (1, 1), (2, 2)]  # Pozycje wciśniętych przycisków

result = canMaintainPower(board, buttons)
print("Czy można utrzymać równą moc planszy? ", result)

