class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

def read_input(file_path):
    with open(file_path, 'r') as f:
        lines = f.readlines()

    num_nodes, num_bits = map(int, lines[0].strip().split())
    labels = []
    for line in lines[1:]:
        labels.append(line.strip().replace(" ", ""))

    return num_nodes, num_bits, labels

def hamming_distance(s1, s2):
    return sum(c1 != c2 for c1, c2 in zip(s1, s2))

def find_max_k_clustering(file_path):
    num_nodes, num_bits, labels = read_input(file_path)
    uf = UnionFind(num_nodes)

    edges = []

    # Calculate all pairs with Hamming distance less than 3
    for i in range(num_nodes):
        for j in range(i + 1, num_nodes):
            distance = hamming_distance(labels[i], labels[j])
            if distance < 3:
                edges.append((i, j, distance))

    # Union-find for all edges with Hamming distance < 3
    for u, v, dist in edges:
        uf.union(u, v)

    clusters = len(set(uf.find(i) for i in range(num_nodes)))
    return clusters

file_path = 'path_to_your_input_file.txt'
max_k = find_max_k_clustering(file_path)
print("The largest value of k such that the clustering has spacing at least 3 is:", max_k)
