#include<iostream>

#ifndef HEAP_H
#define HEAP_H

#define PARENT(x) (x / 2)
#define FIRST_CHILD(x) (x * 2)
#define SECOND_CHILD(x) (x * 2 + 1)

class Heap {

    protected:
        int* heap;
        int length;
        std::string type;

        void buildHeap();
        void heapify(int index);

    public:
        Heap(int* heap, int length, std::string type);
        int extractTop();
        int* getHeap();
        void print();
        void sort();

};

#endif

void Heap :: buildHeap() {
    for (int i = length / 2; i > 0; i--) {
        heapify(i);
    }
}

void Heap :: heapify(int index) {
    int left = FIRST_CHILD(index);
    int right = SECOND_CHILD(index);
    int selected = index;

    if (type.compare("min") == 0) {
        if (left <= length && heap[left] < heap[index]) {
            selected = left;
        }
        if (right <= length && heap[right] < heap[left] && heap[right] < heap[index]) {
            selected = right;
        }
    } else {
        if (left <= length && heap[left] > heap[index]) {
            selected = left;
        }
        if (right <= length && heap[right] > heap[left] && heap[right] > heap[index]) {
            selected = right;
        }
    }

    if (type.compare("min") == 0) {
        if (heap[selected] < heap[index]) {
            std::swap(heap[index], heap[selected]);
            heapify(selected);
        }
    } else {
        if (heap[selected] > heap[index]) {
            std::swap(heap[index], heap[selected]);
            heapify(selected);
        }
    }
}

Heap :: Heap(int* heap, int length, std::string type="min") {
    this -> heap = new int[100];
    for(int i = 0; i < length; i++) {
        this -> heap[i + 1] = heap[i];
    }
    this -> length = length;
    this -> type = type;
    buildHeap();
}

int Heap :: extractTop() {
    std::swap(heap[1], heap[length]);
    length--;
    heapify(1);
    return heap[length + 1];
}

void Heap :: print() {
    for (int i = 1; i <= length; i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

void Heap :: sort() {
    for (int i = length; i > 1; i--) {
        std::swap(heap[1], heap[i]);
        length--;
        heapify(1);
    }
}

int* Heap :: getHeap() {
    return &heap[1];
}

int print_data(int data[], int n) {
    for (int i = 0; i < n; i++)
	    std::cout << data[i] << " ";
	std::cout << std::endl;
}

int main() {
	int n;
	std::cout << "Enter number of elements" << std::endl;
	std::cin >> n;

	int data[n];
	for (int i = 0; i < n; i++) {
		std::cout << "Enter element #" << i + 1 << ": ";
		std::cin >> data[i];
	}

	std::cout << "\nInput data: ";
	print_data(data, n);

	Heap heap(data, n, "max");
	heap.sort();

	std::cout << "Sorted data: ";
	print_data(heap.getHeap(), n);
}

