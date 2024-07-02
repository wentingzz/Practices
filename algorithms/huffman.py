
import heapq

def read_weights_from_file(filename):
    weights = []
    with open(filename, 'r') as file:
        lines = file.readlines()
        number_of_symbols = int(lines[0].strip())
        for i in range(1, number_of_symbols + 1):
            weight = int(lines[i].strip())
            weights.append((weight, 0))
    return weights

def huffman(weights):

    heapq.heapify(weights)

    while(len(weights) > 1):
        min1, h1 = heapq.heappop(weights)
        min2, h2 = heapq.heappop(weights)

        node = (min1 + min2, max(h1, h2) + 1)
        heapq.heappush(weights, node)

    print(weights[0])
    return weights[0][1]


data = read_weights_from_file('./huffman.txt')

huffman(data)