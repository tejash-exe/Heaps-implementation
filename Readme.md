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

## Implementation 🔧
```cpp
class Heap{
  protected:
    vector<int> arr;

    //Nodes
    int find_parent(int child){
        return (child - 1) >> 1;
    }

    int find_leftChild(int parent){
        return (parent << 1) + 1;
    }

    int find_rightChild(int parent){
        return find_leftChild(parent) + 1;
    }

    //Heapify
    virtual void heapify(int index) = 0;
  
  public:
    Heap() = default;

    virtual void insert(int value) = 0;

    void pop(){
        //Time complexity = O(logn)
        //Space complexity = O(1)

        if(arr.empty()){
            cout << "Heap is empty!" << endl;
            return;
        }

        //1. Replace root with last node
        arr[0] = arr.back();
        arr.pop_back();

        //2. Place root value to its correct position
        if(arr.empty()){
            return;
        }

        int index = 0;
        heapify(index); // Time complexity = O(logn)
    }

    int size(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        return arr.size();
    }

    int top(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        if(arr.empty()){
            cout << "Heap is empty!" << endl;
            return INT_MIN;
        }

        return arr[0];
    }

    void print(){
        //Time complexity = O(n)
        //Space complexity = O(1)

        for(auto element : arr){
            cout << element << " ";
        }
        cout << endl;
    }

    bool empty(){
        //Time complexity = O(1)
        //Space complexity = O(1)

        if(arr.size() == 0){
            return true;
        }

        return false;
    }

    virtual ~Heap() = default;
};

class MaxHeap : public Heap{
  private:
    void heapify(int index){
        //Time complexity = O(logn)
        //Space complexity = O(1)

        while(1){
            int left = find_leftChild(index);
            int right = find_rightChild(index);
            int largest = index;

            if(left < arr.size() && arr[left] > arr[largest]){
                largest = left;
            }
            
            if(right < arr.size() && arr[right] > arr[largest]){
                largest = right;
            }

            if(largest == index){
                break;
            }

            swap(arr[largest], arr[index]);
            index = largest;
        }
    }

  public:
    void insert(int value) override{
        //Time complexity = O(logn)
        //Space complexity = O(1)

        // 1. Insert at End
        arr.push_back(value);
        int index = arr.size() - 1;

        //2. Put value to correct position
        while(index > 0){
            int parent = find_parent(index);
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                break;
            }
        }
    }
};

class MinHeap : public Heap{
  private:
    void heapify(int index){
        //Time complexity = O(logn)
        //Space complexity = O(1)

        while(1){
            int left = find_leftChild(index);
            int right = find_rightChild(index);
            int smallest = index;

            if(left < arr.size() && arr[left] < arr[smallest]){
                smallest = left;
            }

            if(right < arr.size() && arr[right] < arr[smallest]){
                smallest = right;
            }

            if(smallest == index){
                break;
            }

            swap(arr[smallest], arr[index]);
            index = smallest;
        }
    }
  
  public:
    void insert(int value) override{ 
        //Time complexity = O(logn)
        //Space complexity = O(1)

        //1. Insert value at last
        arr.push_back(value);

        //2. Place it at correct place
        int index = arr.size() - 1;

        while(index > 0){
            int parent = find_parent(index);
            if(arr[parent] > arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                break;
            }
        }
    }
};
```