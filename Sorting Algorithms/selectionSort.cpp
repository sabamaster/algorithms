#include <iostream>
#include <chrono>

// Selection sort
// Description: Divide the array in two. Search for the smallest element in the second subarray and inserted in the right place in the first subarray.
// Complexity: O(n²)
void selectionSort(int array[], int size) {
	for (int i = 0; i < size - 1; i++){
		int minIndex = i;
		// Search for the smallest element in the second subarray
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}
		// Insert the smallest elememt in the first subarray
		int temp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = temp;
	}
}

// Utility Functions
// Print an array
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		if (i != size - 1) {
			std::cout << array[i] << " ";
		}
		else if (i == size - 1) {
			std::cout << array[i] << "\n" << std::endl;
		}
	}
}

int main() {
	// Unordered array
	int array[] = { 4, 3, 5, 5, 2, 2, 1 };
	int size = sizeof(array) / sizeof(array[0]);

	// Print the name of the algorithm
	std::cout << "Selection sort" << "\n" << std::endl;

	// Print the unordered array
	std::cout << "Unordered array"<< std::endl;;
	printArray(array, size);

	// Execution start time
	auto start = std::chrono::steady_clock::now();

	// Insertion sort execution
	selectionSort(array, size);

	// Execution end time
	auto end = std::chrono::steady_clock::now();

	// Calculate the execution time
	auto diff = end - start;

	// Print the ordered array
	std::cout << "Ordered array" << std::endl;
	printArray(array, size);

	// Print the execution time
	std::cout << "Execution time: " << std::chrono::duration <double>(diff).count() << " ms" << std::endl;

	return 0;
}
