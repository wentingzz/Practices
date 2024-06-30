# Function to read jobs from file and return a list of tuples (weight, length)
def read_jobs(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    num_jobs = int(lines[0].strip())
    jobs = []

    for line in lines[1:num_jobs + 1]:
        weight, length = map(int, line.split())
        jobs.append((weight, length))

    return jobs

# Function to calculate the weighted sum of completion times using the greedy algorithm
def calculate_weighted_sum(jobs):
    # Sort jobs based on (weight - length), and then by weight if tied
    jobs_sorted = sorted(jobs, key=lambda x: (x[0] - x[1], x[0]), reverse=True)
    # Sort jobs based on (weight/length)
    # jobs_sorted = sorted(jobs, key=lambda x: (x[0]/x[1]), reverse=True)

    weighted_sum = 0
    completion_time = 0

    for weight, length in jobs_sorted:
        completion_time += length
        weighted_sum += weight * completion_time

    return weighted_sum


# Path to the input file
file_path = 'jobs.txt'

# Read jobs from the file
jobs = read_jobs(file_path)

# Calculate the weighted sum of completion times
result = calculate_weighted_sum(jobs)

# Output the result
print(result)
