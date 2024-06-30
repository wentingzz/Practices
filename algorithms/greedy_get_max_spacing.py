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


def kruskal_clustering(edges, n, k):
    edges.sort(key=lambda x: x[2])
    uf = UnionFind(n)
    mst_edges = []
    num_clusters = n

    for u, v, cost in edges:
        if uf.find(u) != uf.find(v):
            uf.union(u, v)
            mst_edges.append((u, v, cost))
            num_clusters -= 1
            if num_clusters == k:
                break

    max_spacing = None
    for u, v, cost in edges:
        if uf.find(u) != uf.find(v):
            max_spacing = cost
            break

    return max_spacing


def read_input(file_path):
    with open(file_path, 'r') as f:
        lines = f.readlines()

    n = int(lines[0].strip())
    edges = []

    for line in lines[1:]:
        u, v, cost = map(int, line.strip().split())
        edges.append((u - 1, v - 1, cost))  # Convert to 0-based index

    return n, edges


file_path = 'clustering1.txt'
n, edges = read_input(file_path)
k = 4
max_spacing = kruskal_clustering(edges, n, k)
print("Maximum spacing of a 4-clustering:", max_spacing)