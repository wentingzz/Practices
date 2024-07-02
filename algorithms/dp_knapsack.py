def read_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    # First line: [knapsack_size] [number_of_items]
    knapsack_size, number_of_items = map(int, lines[0].split())

    items = []
    for line in lines[1:]:
        value, weight = map(int, line.split())
        items.append((value, weight))

    return knapsack_size, number_of_items, items


def knapsack(knapsack_size, number_of_items, items):
    # Initialize the DP table
    dp = [[0] * (knapsack_size + 1) for _ in range(number_of_items + 1)]

    # Fill the DP table
    for i in range(1, number_of_items + 1):
        value, weight = items[i - 1]
        for w in range(knapsack_size + 1):
            if weight > w:
                dp[i][w] = dp[i - 1][w]
            else:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight] + value)

    # The maximum value is found at dp[number_of_items][knapsack_size]
    return dp[number_of_items][knapsack_size]


# Example usage
file_path = 'knap.txt'  # replace with the path to your input file
knapsack_size, number_of_items, items = read_file(file_path)
print(knapsack(knapsack_size, number_of_items, items))
