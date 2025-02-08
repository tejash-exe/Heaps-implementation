# Heap Implementation 🚀

## Overview 📌
This repository contains an implementation of MinHeap and MaxHeap using C++ and Object-Oriented Programming (OOP) principles. The implementation supports inserting elements, deleting the root element, checking the heap size, retrieving the top element, printing the heap, and checking if the heap is empty.

## Features ✨
- ✅ **MinHeap & MaxHeap Implementation**
- 📥 **Insertion (`insert`)**
- 🗑️ **Deletion (`pop`)**
- 🔝 **Retrieval of Top Element (`top`)**
- 📏 **Heap Size Calculation (`size`)**
- 🖨️ **Print Heap (`print`)**
- ❓ **Check If Heap is Empty (`empty`)**
- 🏗️ **Follows Object-Oriented Programming (OOP) principles**

## Class Structure 🏛️
### 1. `Heap` (Abstract Base Class)
This is a base class that defines the structure and common functions for both MinHeap and MaxHeap.

#### Member Functions:
- 🔄 `find_parent(int child)`: Returns the parent index of a given child index.
- 🔄 `find_leftChild(int parent)`: Returns the left child index of a given parent index.
- 🔄 `find_rightChild(int parent)`: Returns the right child index of a given parent index.
- 🔧 `heapify(int index)`: A pure virtual function that is implemented in derived classes.
- ➕ `insert(int value)`: A pure virtual function implemented in derived classes.
- ❌ `pop()`: Removes the root element and restores the heap property.
- 📏 `size()`: Returns the number of elements in the heap.
- 🔝 `top()`: Returns the root element of the heap.
- 🖨️ `print()`: Prints all elements in the heap.
- ❓ `empty()`: Returns `true` if the heap is empty, otherwise `false`.

### 2. `MaxHeap` (Derived Class) 🔺
This class extends `Heap` and implements the `heapify` function for maintaining a max-heap property.

#### Member Functions:
- 🔄 `heapify(int index)`: Ensures that the max-heap property is maintained after deletion.
- ➕ `insert(int value)`: Adds a new element while maintaining the max-heap property.

### 3. `MinHeap` (Derived Class) 🔻
This class extends `Heap` and implements the `heapify` function for maintaining a min-heap property.

#### Member Functions:
- 🔄 `heapify(int index)`: Ensures that the min-heap property is maintained after deletion.
- ➕ `insert(int value)`: Adds a new element while maintaining the min-heap property.

## Time and Space Complexities ⏳

| Function   | Time Complexity | Space Complexity |
|------------|----------------|------------------|
| `insert`   | O(log n)       | O(1)             |
| `pop`      | O(log n)       | O(1)             |
| `top`      | O(1)           | O(1)             |
| `size`     | O(1)           | O(1)             |
| `print`    | O(n)           | O(1)             |
| `empty`    | O(1)           | O(1)             |

## OOP Principles Used 🎯
1. **Encapsulation** 🔒
   - The `Heap` class encapsulates common heap operations, and MinHeap/MaxHeap extend it with their specific behaviors.
   
2. **Abstraction** 🎭
   - The `Heap` class provides an abstract interface that hides implementation details from the user.
   
3. **Inheritance** 🏗️
   - `MinHeap` and `MaxHeap` inherit from the base `Heap` class, reusing its common functions while implementing specific heap properties.
   
4. **Polymorphism** 🔄
   - The `heapify` and `insert` functions are overridden in the derived classes, allowing different behaviors based on the heap type.

## Usage 🛠️
```cpp
int main(){
    //INITIALISE
    MinHeap a;
    MaxHeap b;

    //INSERT
    a.insert(4);
    b.insert(4);
    a.insert(4);
    b.insert(4);

    //POP
    a.pop();
    b.pop();

    //SIZE
    cout << "Size of a MinHeap = " << a.size() << endl;
    cout << "Size of b MaxHeap = " << b.size() << endl;

    //TOP
    cout << "Top element of a MinHeap = " << a.top() << endl;
    cout << "Top element of b MaxHeap = " << b.top() << endl;

    //PRINT
    cout << "Printing a MinHeap :" << endl;
    a.print();
    cout << "Printing b MaxHeap :" << endl;
    b.print();

    //IS-EMPTY
    cout << (a.empty() ? "MinHeap a is empty!" : "a MinHeap is not empty!") << endl;
    cout << (b.empty() ? "MaxHeap b is empty!" : "b MaxHeap is not empty!") << endl;
    return 0;
}
```

## Feedback & Contributions 🙌
Feel free to fork the repository, report issues, or submit pull requests.
I welcome feedback and suggestions to improve the project!

## Connect with Me 🌟 

- **GitHub**: [My GitHub Profile](https://github.com/tejash-exe)  
- **LinkedIn**: [My LinkedIn Profile](https://www.linkedin.com/in/aditya-choudhary-31137b291/)  

Made with ❤️ by [Aditya](https://github.com/tejash-exe)