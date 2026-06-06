# push_swap

## Description

**push_swap** is a sorting algorithm project. The goal is to sort a list of integers using a limited set of stack operations, while minimizing the number of moves.

The project uses two stacks:
- **Stack A**: initially contains the unsorted integers
- **Stack B**: used as auxiliary storage

Only a restricted set of operations is allowed (`sa`, `pb`, `ra`, etc.), making this a problem focused on **algorithm optimization and strategy design**.

---

## Stack Operations Reference

All sorting operations work with two stacks (A and B):

| Operation    | Code  | Description                                      |
| ------------ | ----- | ------------------------------------------------ |
| Swap A       | `sa`  | Swap the first 2 elements of stack A             |
| Swap B       | `sb`  | Swap the first 2 elements of stack B             |
| Swap Both    | `ss`  | Execute `sa` and `sb` simultaneously             |
| Push A       | `pa`  | Move top element from B to top of A              |
| Push B       | `pb`  | Move top element from A to top of B              |
| Rotate A     | `ra`  | Shift all elements of A up, top goes to bottom   |
| Rotate B     | `rb`  | Shift all elements of B up, top goes to bottom   |
| Rotate Both  | `rr`  | Execute `ra` and `rb` simultaneously             |
| Rev Rotate A | `rra` | Shift all elements of A down, bottom goes to top |
| Rev Rotate B | `rrb` | Shift all elements of B down, bottom goes to top |
| Rev Both     | `rrr` | Execute `rra` and `rrb` simultaneously           |

---

## Features

✅ Four different sorting strategies for optimal performance
✅ Adaptive algorithm selection based on input disorder
✅ Input validation (range checking, duplicate detection)
✅ Comprehensive benchmarking statistics
✅ Support for negative integers and large ranges
✅ Memory-safe implementation

---

## Instructions
### Compilation

Build the main program:

```bash
make
```

Clean build artifacts:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

### Usage

```bash
./push_swap [OPTIONS] numbers...
```

### Examples

```bash
./push_swap 3 2 1
./push_swap 5 1 4 2 3
./push_swap --medium 8 3 5 2 9 1
```

### Available Options

| Option        | Description                          |
|--------------|--------------------------------------|
| `--simple`   | Use simple sorting algorithm         |
| `--medium`   | Use medium sorting algorithm         |
| `--complex`  | Use complex sorting algorithm        |
| `--adaptive` | Automatically choose best strategy   |
| `--bench`    | Display performance statistics       |

---

## Algorithms & Strategy

This project implements a **multi-strategy sorting system**, with automatic selection based on input characteristics.

---

### 🔹 1. Simple Sort — O(n²)

Used for very small datasets (≤ 5 elements).

**Approach:**
- Push the smallest elements from Stack A to Stack B
- Sort the remaining 3 elements directly
- Push everything back to Stack A

**Why?**
- Very efficient for small inputs
- Minimal overhead

---

### 🔹 2. Medium Sort — O(n√n)

Used for moderately sized inputs.

**Approach:**
- Divide elements into **chunks** using a range of √n
- Push elements from A to B progressively
- Rotate B to keep elements roughly ordered
- Reinsert elements into A by always selecting the maximum

**Why?**
- Reduces unnecessary rotations
- Good balance between simplicity and efficiency

---

### 🔹 3. Complex Sort — ~O(n log n)

Optimized for large datasets.

**Approach:**
- Use adaptive chunk size:
  - `n / 7` for ≤ 100 elements
  - `n / 14` for larger inputs
- Push elements to B while maintaining partial ordering
- Optimize reinsertion by:
  - Pre-pushing near-max elements
  - Minimizing rotations
- Ensure correct order with swaps when needed

**Why?**
- Significantly reduces total operations
- Handles large inputs efficiently

---

### 🔹 4. Adaptive Strategy

The program computes a **disorder metric**:

- Based on the number of inversions in the list
- Represents how "unsorted" the input is

**Selection logic:**
- Disorder < 0.2 → Simple Sort
- 0.2 ≤ Disorder < 0.5 → Medium Sort
- Disorder ≥ 0.5 → Complex Sort

**Why?**
- Avoids unnecessary complexity
- Dynamically adapts to input characteristics

---

## Benchmark Mode

Enable with:

```bash
./push_swap --bench [numbers...]
```

Displays:
- Disorder percentage
- Selected strategy
- Total operations
- Detailed breakdown (`sa`, `pb`, `ra`, etc.)

---

## Technical Choices & Justifications

### Why Four Strategies?

Different input patterns require different approaches. Rather than using a single algorithm for all cases, we implemented adaptive selection to:

1. Handle nearly-sorted data efficiently
2. Process moderately unsorted data optimally
3. Tackle highly scrambled data with advanced algorithms
4. Automatically select the best strategy transparently

### Why Chunk-Based Approach for Complex Cases?

Chunk-based sorting reduces unnecessary rotations by:

- Grouping related elements together
- Minimizing search distance traversals
- Allowing parallel operations on both stacks
- Scaling better with larger datasets
