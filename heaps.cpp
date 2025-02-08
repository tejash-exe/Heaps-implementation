#include <bits/stdc++.h>
using namespace std;

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