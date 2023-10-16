class WhiteBox:
    def __init__(self, top_left, height, width):
        self.top_left = top_left
        self.height = height
        self.width = width

def find_white_box(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    def is_white(x, y):
        return matrix[x][y] == 'w'

    def valid(x, y):
        return 0 <= x < rows and 0 <= y < cols

    max_area = 0
    white_box = None

    for i in range(rows):
        for j in range(cols):
            if is_white(i, j):
                current_height = 0
                current_width = 0

                # Check the height of the white box
                while valid(i + current_height, j) and is_white(i + current_height, j):
                    current_height += 1

                # Check the width of the white box
                while valid(i, j + current_width) and is_white(i, j + current_width):
                    current_width += 1

                # Calculate the area
                area = current_height * current_width

                if area > max_area:
                    max_area = area
                    white_box = WhiteBox((i, j), current_height, current_width)

    return white_box

# Example matrix
matrix = [
    ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'],
    ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'],
    ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'],
    ['b', 'b', 'b', 'b', 'w', 'w', 'w', 'w', 'w', 'b', 'b', 'b'],
    ['b', 'b', 'b', 'b', 'w', 'w', 'w', 'w', 'w', 'b', 'b', 'b'],
    ['b', 'b', 'b', 'b', 'w', 'w', 'w', 'w', 'w', 'b', 'b', 'b'],
    ['b', 'b', 'b', 'b', 'w', 'w', 'w', 'w', 'w', 'b', 'b', 'b'],
    ['b', 'b', 'b', 'b', 'w', 'w', 'w', 'w', 'w', 'b', 'b', 'b'],
    ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'],
    ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'],
    ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'],
    ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b']
]

white_box = find_white_box(matrix)

if white_box:
    print(f"Top-Left: {white_box.top_left}")
    print(f"Height: {white_box.height}")
    print(f"Width: {white_box.width}")
else:
    print("No white box found in the matrix.")
