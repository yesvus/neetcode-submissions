class DynamicArray {
private:
    int* arr;       // Pointer to our block of memory
    int length;     // Number of elements currently in the array
    int capacity;   // Total available slots in the current block

public:
    // Constructor: Allocate initial memory on the heap
    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->length = 0;
        this->arr = new int[capacity]; 
    }

    // Returns the element at index i
    int get(int i) {
        return arr[i];
    }

    // Sets the element at index i to n
    void set(int i, int n) {
        arr[i] = n;
    }

    // Insert n at the end of the array
    void pushback(int n) {
        if (length == capacity) {
            resize();
        }
        arr[length] = n;
        length++;
    }

    // Remove and return the last element
    int popback() {
        length--;
        return arr[length];
    }

    // Double the capacity of the array
    void resize() {
        capacity = capacity * 2;
        int* newArr = new int[capacity];
        
        // Copy elements from the old block to the new block
        for (int i = 0; i < length; i++) {
            newArr[i] = arr[i];
        }
        
        // Delete old memory to prevent memory leaks
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }

    // Destructor: Clean up memory when the object is destroyed
    ~DynamicArray() {
        delete[] arr;
    }
};