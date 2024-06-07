# Data Structures and Algorithms in C++

This repo contains my implementations of various data structures and algorithms in C++.  

## Features

-   Segment Trees
    -   Range Minimum Query
    -   Range Sum Query
-   Square Root Decomposition
-   Trie

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

*   g++ compiler

    ```bash
    # Check if you have g++ installed
    g++ --version

    # If not, install it (Ubuntu/Debian)
    sudo apt update
    sudo apt install build-essential
    ```
*   make (optional, but recommended)

    ```bash
    # Check if you have make installed
    make --version

    # If not, install it (Ubuntu/Debian)
    sudo apt update
    sudo apt install make
    ```

### Installation

1.  Clone the repo
    ```bash
    git clone https://github.com/your_username_/Project-Name.git
    ```
2.  Compile the code (replace `<program>` with the desired program, e.g., `trie`, `rmq`, `rsq`  or `srd`)
    ```bash
    # Using make (recommended)
    make <program>

    # Manual compilation
    g++ -std=c++11 <program_directory>/*.cpp -o <program>

    # Example for compiling the Trie:
    g++ -std=c++11 trie/trie.cpp trie/main.cpp -o trie
    ```

<!-- USAGE EXAMPLES -->

## Usage

This section explains how to run the different programs and the relationships between the files in each program.

### Segment Trees

The `segment_trees` directory contains implementations of segment trees for efficient range queries. 

**Range Minimum Query (RMQ)**

*   `segment_trees/templated/segment_tree.cpp`: This file contains a templated implementation of a segment tree. The template parameter allows you to define the function used to combine values during queries.
*   `segment_trees/templated/main.cpp`: This file demonstrates how to use the `SegmentTree` class for range minimum queries using the `Min` class to find the minimum value in a range. You can compile and run this file to see the RMQ functionality.

**Range Sum Query (RSQ)**

*   `segment_trees/rsq/rsq_segment_tree.cpp`: This file implements a segment tree specifically for range sum queries. It builds the tree and provides a `querySumRange` method. 
*   `segment_trees/rsq/main.cpp`: This file shows how to use the `RSQSegmentTree` class. You can compile and run it to perform range sum queries.

#### Running the Segment Tree Examples:

1. Compile the code following the instructions in the Installation section.
2.  Run the compiled executable:

    ```bash
    ./rmq
    ./rsq
    ```

### Square Root Decomposition

*   `square_root_decomp/square_root_decomp.cpp`: Contains the implementation for square root decomposition, allowing for range sum queries and updates.
*   `square_root_decomp/main.cpp`: Demonstrates the usage of the `SquareRootDecomp` class by creating an instance, performing a range sum query, updating a value, and performing another query.

#### Running the Square Root Decomposition Example:

1. Compile the code following the instructions in the Installation section.
2.  Run the compiled executable:

    ```bash
    ./srd
    ```

### Trie

*   `trie/trie.cpp`: Contains the implementation of the `Trie` class, enabling efficient insertion, search for complete words, and prefix searches.
*   `trie/main.cpp`: Demonstrates the `Trie` class's capabilities by inserting words, checking for their existence, and testing prefix searches.

#### Running the Trie Example:

1. Compile the code following the instructions in the Installation section.
2.  Run the compiled executable:

    ```bash
    ./trie
    ```

## License

MIT
