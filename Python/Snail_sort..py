def snail(array):
    snail = []
    n = len(array)
    n2 = n*n
    row_len = n
    col_len = n
    row_start = 0
    col_start = 0
    count = 0
    n_count = 0
    if not array[0]:
        return []
    while True:
        ## Move right
        for c in range(col_start, col_start + row_len):
            snail.append(array[row_start][c])
            count += 1
            n_count += 1
            if n_count >= n2: return snail
        col_start += (count - 1)
        row_start += 1
        col_len -= 1
        count = 0
        ## Move down
        for r in range(row_start, row_start + col_len):
            snail.append(array[r][col_start])
            count += 1
            n_count += 1
            if n_count >= n2: return snail
        row_start += (count - 1)
        col_start -= 1
        count = 0
        row_len -= 1
        ## Move left
        for c in range(col_start, col_start - row_len, -1):
            snail.append(array[row_start][c])
            count += 1
            n_count += 1
            if n_count >= n2: return snail
        col_start -= (count - 1)
        row_start -= 1
        col_len -= 1
        count = 0
        ## Move up
        for r in range(row_start, row_start - col_len, -1):
            snail.append(array[r][col_start])
            count += 1
            n_count += 1
            if n_count >= n2: return snail
        row_start -= (count - 1)
        col_start += 1
        count = 0
        row_len -= 1