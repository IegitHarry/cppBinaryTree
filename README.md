# 🌳 Binary Search Tree in C++

A small, dependency-free C++ program that reads integers from a text file, builds a **Binary Search Tree (BST)**, prints the values in sorted order, and then frees every node while counting the deletions.

![C++](https://img.shields.io/badge/C%2B%2B-11%2B-blue?logo=cplusplus)
![License](https://img.shields.io/badge/license-MIT-green)
![Status](https://img.shields.io/badge/status-educational-orange)

## ✨ Features

- **Reads input from a file**: loads integers from `values.txt`
- **BST insertion**: recursive insert using pointer-to-pointer references
- **In-order traversal**: prints all values in ascending order
- **Safe cleanup**: post-order deletion frees all allocated memory
- **Deletion counter**: reports how many nodes were freed

## 📁 Project Structure

```
.
├── main.cpp        # Source code
├── values.txt      # Input file with integers
└── README.md
```

## 🚀 Getting Started

### Prerequisites

- A C++ compiler such as `g++`, `clang++`, or MSVC

### Build

```bash
g++ -std=c++11 -Wall -o bst main.cpp
```

### Run

Make sure `values.txt` is in the same directory as the executable, then:

```bash
./bst
```

## 📄 Input Format

`values.txt` should contain whitespace-separated integers. The **first number becomes the root** of the tree.

```
50 30 70 20 40 60 80
```

## 🖥️ Example Output

```
20 30 40 50 60 70 80
Deleted: 7
```

The first line is the sorted (in-order) traversal, and the second line is the number of nodes freed.

## 🧠 How It Works

| Function | Description |
|----------|-------------|
| `insertTree(tree *&t, int number)` | Recursively inserts a value. Larger values go right; smaller or equal values go left. |
| `displayTree(tree *t)` | In-order traversal (left → node → right), which prints values in sorted order. |
| `deleteTree(tree *t)` | Post-order traversal (left → right → node) that deletes each node and increments `deleteOpr`. |

### Tree Node

```cpp
struct tree {
    int number;
    struct tree *lPointer, *rPointer;
};
```

### Complexity

| Operation | Average | Worst case (degenerate tree) |
|-----------|---------|------------------------------|
| Insert    | O(log n) | O(n) |
| Traversal | O(n)     | O(n) |
| Delete all | O(n)    | O(n) |

> The worst case occurs when the input is already sorted, which makes the tree behave like a linked list.

## ⚠️ Notes & Limitations

- Duplicate values are inserted into the **left** subtree.
- If `values.txt` is missing or empty, the root's value is left uninitialized. Add a file check before reading for more robust behavior.
- Very deep (unbalanced) trees may cause deep recursion. Consider a self-balancing tree (AVL, Red-Black) for large sorted inputs.

## 🔮 Possible Improvements

- [ ] Error handling for a missing or empty input file
- [ ] Accept the filename as a command-line argument
- [ ] Add search and single-node delete operations
- [ ] Replace raw pointers with `std::unique_ptr`
- [ ] Add pre-order and post-order display options

## 🤝 Contributing

Contributions, issues, and feature requests are welcome. Feel free to open an issue or submit a pull request.

## 📜 License

This project is licensed under the [MIT License](LICENSE).
