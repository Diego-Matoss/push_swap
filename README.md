# Push Swap

*This project has been created as part of the 42 curriculum by dimatos-, rimatos-.*

## Description

**Push Swap** is a 42 project whose goal is to sort a stack of integers using a limited set of operations on two stacks, with the lowest possible number of moves.

The program receives a list of integers as input, validates it, and reorganizes the values into ascending order using a predefined set of stack operations. The implementation is structured around parsing, validation, stack manipulation, and algorithm selection, making it a strong exercise in data structures, algorithm design, and performance optimization.

The project is divided into several parts:
* Parsing and input validation.
* Stack management and index assignment.
* Implementation of multiple sorting strategies.
* Benchmarking and evaluation of the chosen approach.

## Algorithm Choices and Justification

The sorting logic was designed to adapt to the input size and its level of disorder. This choice was made to balance clarity, robustness, and performance.

* **Simple strategy**: Selected when the input is already close to sorted order or when the user explicitly chooses this path. It is a lighter approach that performs well on nearly ordered data and keeps the implementation predictable. It is based on a selection sort using the minimum extraction algorithm approach. It searches for the minimum number and moves it to stack B to have them sorted max-to-min, and then pushes everything to stack A already ordered.
* **Medium strategy**: Used for moderately disordered lists. It introduces a more structured approach to reduce the number of operations while remaining manageable in complexity. It uses a chunk strategy that classifies the numbers into thirds and subsequently into sixths. Once that is done, the algorithm rotates the numbers to make sure they land on stack A already sorted.
* **Complex strategy**: Applied to highly disordered inputs where a more advanced strategy is required to achieve better performance and lower move counts. Using the radix strategy, it traverses the whole stack classifying the numbers in two boxes based on their relevant bit (0 or 1) and then joining the stacks, performing these two actions sequentially for each bit.
* **Small inputs (≤ 5)**: A dedicated small-input strategy is used. This is efficient because the search space is tiny, and a direct, optimized solution avoids unnecessary complexity.
* **Adaptive mode**: The decision for the adaptive mode is based on a disorder metric computed from the initial stack. This allows the program to choose the most suitable algorithm rather than relying on a single fixed method for every case.

## Team Roles

* **Algorithms and operations:** rimatos-
* **Parsing and input handling:** dimatos-
* **Main flow and structural decisions:** both contributors

## Instructions

### Compilation

From the project root, run:

```bash
make
```

This builds the static library used by the project.

### Execution

Run the program with a list of integers:

```bash
./push_swap 4 67 3 87 23
```

### Flags

The program supports different sorting strategies:

```bash
--simple
--medium
--complex
```

The selected strategy must be specified **before the list of integers**.
For example:

```bash
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
```

The `--bench` flag enables benchmark mode:

```bash
./push_swap --bench 4 67 3 87 23
```

`--bench` can also be combined with a sorting strategy:

```bash
./push_swap --bench --medium 4 67 3 87 23
```

The order of the flags does not matter:

```bash
./push_swap --bench --complex 4 67 3 87 23
./push_swap --complex --bench 4 67 3 87 23
```

However, **all flags must appear before the integers**.

Only **one strategy flag** should be used at a time. Therefore, combinations such as:

```bash
./push_swap --simple --medium 4 67 3 87 23
```

will not necessarily produce an error, but the program may not behave as expected.

Each flag can only appear once, so duplicated flags such as:

```bash
./push_swap --bench --bench 4 67 3 87 23
./push_swap --simple --simple 4 67 3 87 23
```

will make the program not behave as expected.

You can also clean the generated files with:

```bash
make clean
make fclean
```

## Resources

The following references were very useful while studying and refining the approach for this project:

- [Chunk strategy](https://medium.com/@kilfenbaridon/how-to-over-optimize-an-algorithm-push-swap-42-school-project-d01a50e5fd78) ~ Kilfen Baridon
- [Radix strategy](https://leofu890806.medium.com/push-swap-tutorial-fa746e6aba1e) ~ Leo Fu
- AI was used to have a starting point of this README and to make tests. It was also used for a deeper understanding of the algorithms.