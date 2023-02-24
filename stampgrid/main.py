def can_create_stamp_painting(n, desired, k, stamp):
    # First, let's find all the positions in the desired painting where the stamp can be placed
    positions = []
    for i in range(n - k + 1):
        for j in range(n - k + 1):
            match = True
            for x in range(k):
                for y in range(k):
                    if stamp[x][y] == '*' and desired[i+x][j+y] != '*':
                        match = False
                        break
                if not match:
                    break
            if match:
                positions.append((i, j))
    
    # Next, let's simulate stamping at each of the possible positions and see if we can cover the entire desired painting
    canvas = [['.'] * n for _ in range(n)]
    for i, j in positions:
        for x in range(k):
            for y in range(k):
                if stamp[x][y] == '*':
                    canvas[i+x][j+y] = '*'
        if all(desired[a][b] == canvas[a][b] for a in range(n) for b in range(n) if desired[a][b] == '*'):
            return "YES"
    
    # If we can't cover the entire desired painting, return "NO"
    return "NO"

# Read input
t = int(input())
for _ in range(t):
    n = int(input())
    desired = [input().strip() for _ in range(n)]
    k = int(input())
    stamp = [input().strip() for _ in range(k)]

    # Solve problem and print output
    print(can_create_stamp_painting(n, desired, k, stamp))
