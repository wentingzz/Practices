def maximum_weight_independent_set(weights, n):
    n1 = weights[0]
    bit1 = '1'
    n2 = weights[1]
    bit2 = '01'

    for i in range(2, n):
        prev = n1 + weights[i]
        if(prev > n2):
            n3 = prev
            bit3 = bit1 + '01'
        else:
            n3 = n2
            bit3 = bit2 + '0'
        n1, n2 = n2, n3
        bit1, bit2 = bit2, bit3
    return bit1 if n1 > n2 else bit2

# Read weights from the input file (assuming it's stored in a file named "mwis.txt")
def read_weights_from_file(filename):
    weights = []
    total = 0
    with open(filename, 'r') as file:
        lines = file.readlines()
        total = int(lines[0].strip())
        for i in range(1, total + 1):
            weight = int(lines[i].strip())
            weights.append(weight)
    return weights, total

data, n = read_weights_from_file('mwis.txt')


# Compute the maximum weight independent set and print the result
result = maximum_weight_independent_set(data, n)

vertices_to_check = [1, 2, 3, 4, 17, 117, 517, 997]

# Get MWIS string
mwis_string = ''.join([result[i-1] for i in vertices_to_check])
print(mwis_string)
