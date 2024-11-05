def solution(memory, queries):
    ALLOC = 0
    ERASE = 1

    m = {}
    result = []
    id_counter = 0

    for query in queries:
        op = query[0]

        if op == ALLOC:
            can_allocate = False
            start = 0
            for i in range(0, len(memory), 8):
                j = i
                has_enough = True
                while has_enough:
                    if memory[j] == 1:
                        has_enough = False
                        break

                    j += 1

                if has_enough and not can_allocate:
                    can_allocate = True
                    start = i

            if can_allocate:
                m[id_counter] = start
                result.append(start)
                id_counter += 1
                for j in range(start, start + query[1]):
                    memory[j] = 1
            else:
                result.append(-1)

        elif op == ERASE:
            if query[1] not in m:
                result.append(-1)
            else:
                result.append(2000)

    return result


print(solution([0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1], [[0, 2],
                                                                  [0, 1],
                                                                  [0, 1],
                                                                  [1, 1],
                                                                  [0, 3],
                                                                  [1, 4],
                                                                  [0, 4]]))
print(solution([1, 1, 1, 1, 1, 1, 1, 1], [[0, 1],
                                          [1, 1]]))

print(solution([0, 0, 0, 0, 1, 1, 1, 1], [[0, 4],
                                          [0, 1],
                                          [1, 1],
                                          [0, 2],
                                          [0, 2]]))
