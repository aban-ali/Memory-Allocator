# Memory Allocator (Custom malloc/free in C)

## Overview

This project implements a **basic memory allocator** in C, simulating the behavior of `malloc` and `free` using a fixed-size memory pool.

The goal is to understand **low-level memory management**, including allocation strategies, fragmentation, and pointer-level operations.

---

## Features

* Custom `my_malloc(size_t size)` and `my_free(void* ptr)`
* Contiguous **memory pool** acting as a private heap
* **First-fit allocation strategy**
* **Block splitting** to reduce internal fragmentation
* **Coalescing (forward + backward)** to reduce external fragmentation
* Linked-list based block management

---

## Memory Layout

Each block in memory is structured as:

```
[ Metadata | User Data ]
```

Where metadata contains:

* `size` → size of user data
* `free` → allocation status
* `next` → pointer to next block

---

## Allocation Strategy

* Traverse block list using **first-fit**
* If a block is larger than required:

  * Split into allocated + free block
* Return pointer to user data (skip metadata)

---

## Freeing & Coalescing

* Mark block as free
* Merge with:

  * **Next block** (forward coalescing)
  * **Previous block** (backward coalescing via traversal)
* Helps reduce fragmentation and improve reuse

---

## Key Concepts Demonstrated

* Pointer arithmetic and memory layout
* Heap management fundamentals
* Internal vs external fragmentation
* Linked list manipulation in low-level systems
* Trade-offs in allocator design (simplicity vs performance)

---

## Limitations

* Fixed-size memory pool
* O(n) allocation and coalescing (singly linked list)
* No thread safety
* No alignment optimizations

---

## Example Usage

```c
init_allocator();

int* a = (int*) my_malloc(sizeof(int));
*a = 10;

my_free(a);
```

---

## Learning Outcome

This project provides a hands-on understanding of how memory allocators work internally, bridging the gap between high-level programming and systems-level thinking.

---

## Future Improvements

* Doubly linked list for O(1) coalescing
* Memory alignment handling
* Segregated free lists for faster allocation
* Thread-safe allocator

---
