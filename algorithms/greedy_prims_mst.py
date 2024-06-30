import heapq

def read_graph(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    # Read number of nodes and edges
    num_nodes, num_edges = map(int, lines[0].strip().split())

    # Read the edges
    edges = []
    for line in lines[1:]:
        u, v, cost = map(int, line.strip().split())
        edges.append((cost, u, v))

    return num_nodes, edges


def prim_mst(num_nodes, edges):
    # Create an adjacency list
    adj_list = {i: [] for i in range(1, num_nodes + 1)}
    for cost, u, v in edges:
        adj_list[u].append((cost, v))
        adj_list[v].append((cost, u))

    # Start with an arbitrary node, here node 1
    start_node = 1

    # Min-heap to store the edges with the smallest weight
    min_heap = []
    for cost, v in adj_list[start_node]:
        heapq.heappush(min_heap, (cost, start_node, v))

    # Set of nodes included in the MST
    in_mst = set([start_node])

    mst_cost = 0

    while len(in_mst) < num_nodes:
        # Get the edge with the minimum cost
        cost, u, v = heapq.heappop(min_heap)

        if v not in in_mst:
            # Add the edge to the MST
            in_mst.add(v)
            mst_cost += cost

            # Add all edges from the new vertex to the heap
            for next_cost, next_v in adj_list[v]:
                if next_v not in in_mst:
                    heapq.heappush(min_heap, (next_cost, v, next_v))

    return mst_cost


# Path to the input file
file_path = 'graph.txt'

# Read graph from the file
num_nodes, edges = read_graph(file_path)

# Calculate the total cost of the minimum spanning tree
mst_cost = prim_mst(num_nodes, edges)

# Output the result
print(mst_cost)
