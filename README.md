# C CODEBASE

Relearn and rethink C Programming Language, including some of data structures and algorithms.
A reuseable codebase for C Programming Language. 

## How to build & test

### Requirements:

* Editor/IDE 
* GCC on Mac, Linux or Windows. (Recommend msys2 + MingW on Windows.)
* Make. 
* Clang-Format. (Optional)

### build & test:

* build 

```
make
```

* test:

```
make test
```

* run:

```
make run
```

## Goals / Achievements

### Data Structures

- [x] Queue [queue.h](src/queue.h) [queue.c](src/queue.c)

### Trees
- [x] Binary Search Tree [bstree.h](src/bstree.h) [bstree.c](src/bstree.c)
- [x] AVL Tree [avltree.h](src/avltree.h) [avltree.c](src/avltree.c)
- [x] Red Black Tree [rbtree.h](src/rbtree.h) [rbtree.c](src/rbtree.c)
- [x] Binary Heap [heap.h](src/heap.h) [heap.c](src/heap.c)
- [ ] Fibonacci Heap, Binomial Heap
- [x] Skip List [skip_list.h](src/skip_list.h) [skip_list.c](src/skip_list.c)
- [ ] B+ Tree

### Graphs
- [x] Adjacency Matrix [graph.h](src/graph.h) [graph.c](src/graph.c)
- [x] Adjacency List [sparse_graph.h](src/sparse_graph.h) [sparse_graph.c](src/sparse_graph.c)
- [ ] Union-Find
- [x] BFS & DFS [graph.h##bfs(), ##dfs()](src/graph.h)
- [x] Topological sorting (Kahn) [sparse_graph_topo_sort()](src/sparse_graph.h)
- [ ] Floyd
- [x] Dijkstra [dijkstra.h](src/dijkstra.h) [dijkstra.c](src/dijkstra.c)
- [ ] Minimum spanning trees: Prim, Kruskal
- [ ] A-star

### String & Text
- [x] Text (similar to string in C++). [text.h](src/text.h) [text.c](src/text.c)
- [x] BigNum integer [bignum.h](src/bignum.h) [bignum.c](src/bignum.c)
- [ ] BigNum decimal 
- [x] KMP (Knuth-Morris-Pratt) algorithm [kmp.h](src/kmp.h) [kmp.c](src/kmp.c)
- [x] BM (Boyer-Moore) algorithm [bm.h](src/bm.h) [bm.c](src/bm.c)
- [x] Sunday algorithm [sunday.h](src/sunday.h) [sunday.c](src/sunday.c)
- [x] Trie Tree [trie.h](src/trie.h) [trie.c](src/trie.c)
- [x] Aho–Corasick algorithm [ac.h](src/ac.h) [ac.c](src/ac.c)
- [ ] DAT (Double-Array Trie)
- [x] Huffman coding [huffman.h](src/huffman.h) [huffman.c](src/huffman.c)

### Sorting
- [x] Quick Sort [arraylist.c##arraylist_sort()](src/arraylist.c)
- [x] Merge Sort [list.c##list_sort()](src/list.c)
- [x] Heap Sort [heap.h](src/heap.h) [heap.c](src/heap.c)

### Math
- [ ] Matrix multiplication
- [x] Eratosthenes sieve (prime numbers) [prime.h](src/prime.h) [prime.c](src/prime.c)

### Distance Measures
- [x] Euclidean distance [distance.h##euclidiean_distance()](src/distance.h)
- [ ] Manhattan distance 
- [ ] Hamming distance

### MISC
- [ ] Bloom filter
