*This project has been created as part of the 42 curriculum by rhrandri.*

# Push_swap

## Description

Push_swap is a sorting algorithm project where a stack of integers must be sorted using a limited set of operations and two stacks. The goal is to sort the data using the minimum number of operations possible.

The program implements four distinct sorting strategies:
- **Simple O(n²)**: Selection sort adaptation
- **Medium O(n√n)**: Chunk-based sorting
- **Complex O(n log n)**: Radix sort using binary representation
- **Adaptive**: Automatically selects the best strategy based on the disorder metric of the input

## Instructions

### Compilation
```bash
make        # builds push_swap
make bonus  # builds checker
make clean  # removes object files
make fclean # removes object files and binaries
make re     # recompiles everything
```

### Usage
```bash
# basic usage
./push_swap 5 4 3 2 1

# with quoted string
./push_swap "5 4 3 2 1"

# force a specific strategy
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1

# benchmark mode
./push_swap --bench 5 4 3 2 1
./push_swap --bench --complex 5 4 3 2 1

# verify with checker
./push_swap 5 4 3 2 1 | ./checker 5 4 3 2 1
```

### Error handling
The program prints `Error` to stderr for:
- Non-integer arguments
- Integers outside int range
- Duplicate values

## Algorithms

### Simple O(n²) — Selection Sort
Repeatedly finds the minimum element in stack a, rotates it to the top using the shortest path, and pushes it to stack b. After leaving 3 elements in a, uses a hardcoded sort for the remaining elements, then pulls everything back.

**Complexity**: O(n²) operations — suitable for nearly sorted inputs (disorder < 0.2)

### Medium O(n√n) — Chunk Sort
Assigns ranks 0 to n-1 to each element. Divides ranks into √n chunks and pushes elements chunk by chunk to b, using rb to maintain order within b. Pulls back by always selecting the maximum rank from b.

**Complexity**: O(n√n) operations — suitable for partially sorted inputs (0.2 ≤ disorder < 0.5)

### Complex O(n log n) — Radix Sort
Assigns ranks and sorts using binary representation. For each bit from LSB to MSB: elements with bit=0 are pushed to b, elements with bit=1 stay in a via ra. After each bit round, all elements are pulled back from b. Repeats for log2(n) rounds.

**Complexity**: O(n log n) operations — suitable for highly disordered inputs (disorder ≥ 0.5)

### Adaptive
Computes the disorder metric (ratio of inversions to total pairs) and selects:
- disorder < 0.2 → Simple
- disorder < 0.5 → Medium  
- disorder ≥ 0.5 → Complex

### Disorder Metric
Measures how far the stack is from being sorted:
```
disorder = number of inverted pairs / total pairs
```
A value of 0 means perfectly sorted, 1 means worst possible order.

## Performance

| Input size | Operations | Rating |
|-----------|------------|--------|
| 100 numbers | ~820 avg | Good |
| 500 numbers | ~6500 avg | Good |

## Contributions

- **rhrandri**: Algorithm design and implementation, parsing, data structures, benchmark mode
- **tandrian**: Code review, testing, optimization

## Resources

### References
- [Wikipedia - Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Wikipedia - Insertion Sort](https://en.wikipedia.org/wiki/Insertion_sort)
- [Big-O Notation Guide](https://www.bigocheatsheet.com/)
- [Sorting Algorithms Visualized](https://visualgo.net/en/sorting)

### AI Usage
Claude (Anthropic) was used throughout this project for:
- Explaining algorithmic concepts (radix sort, chunk sort, complexity analysis)
- Debugging segfaults and memory leaks
- Code review and identifying edge cases
- Guidance on project structure and function decomposition

All code was written and understood by the learners. AI was used as a learning tool and mentor, not to generate copy-paste solutions.
