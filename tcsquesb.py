def collect_coins_and_calories(screen):
    M, N = len(screen), len(screen[0])
    coins_collected = 0
    calories_expended = 0

    for col in range(N):
        coin_row = None
        hole_height = 0
        for row in range(M - 1, -1, -1):
            if screen[row][col] == 'C':
                coins_collected += 1
                if coin_row is None:
                    coin_row = row
            elif screen[row][col] == 'H':
                if hole_height > 0:
                    calories_expended += 2 * hole_height
                hole_height = 0
            elif screen[row][col] == '0':
                if coin_row is not None:
                    calories_expended += 2 * (coin_row - row)
                hole_height += 1

    return coins_collected, calories_expended





