#include <iostream>

void merge_sorted_arrays(int data[], int left, int mid, int right) {
    int len_f = mid - left + 1;
    int len_s = right - mid;

    int first[len_f];
    for (int i = 0; i < len_f; i++) {
        first[i] = data[left + i];
    }
    
    int second[len_s];
    for (int i = 0; i < len_s; i++) {
        second[i] = data[mid + i + 1];
    }
    
    int i = 0;
    int j = 0;
    int index = left;
    
    while (i < len_f && j < len_s) {
        if (first[i] < second[j]) {
            data[index++] = first[i++];
        } else {
            data[index++] = second[j++];
        }
    }
    
    while (i < len_f) {
        data[index++] = first[i++];    
    }
    
    while (j < len_s) {
        data[index++] = second[j++];
    }
}

void merge_sort(int data[], int left, int right) {
    if (left == right) {
        return;
    }

    int mid = (left + right) / 2;

    merge_sort(data, left, mid);
    merge_sort(data, mid + 1, right);

    merge_sorted_arrays(data, left, mid, right);
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
	
	merge_sort(data, 0, n - 1);
	
	std::cout << "Sorted data: ";
	print_data(data, n);
}
