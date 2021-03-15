#include <iostream>

struct IntArray {
	int* data;
	int size;
};

void create(IntArray* arr, int size) {
	arr->data = new int[size];
	arr->size = size;
}

void create(IntArray& arr, int size) {
	arr.data = new int[size];
	arr.size = size;
}

int get(IntArray* arr, int index){
	if (arr->size > index) {
		return arr->data[index];
	}
}

int get(IntArray& arr, int index) {
	if (arr.size > index) {
		return arr.data[index];
	}
}

void set(IntArray* arr, int index, int value) {
	if (arr->size > index) {
		arr->data[index] = value;
	}
}
void set(IntArray& arr, int index, int value) {
	if (arr.size > index) {
		arr.data[index] = value;
	}
}

void print(IntArray* arr) {
	std::cout << "[";
	for (int i = 0; i < arr->size; ++i) {
		std::cout << arr->data[i];
		if (i < arr->size - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}

void print(IntArray& arr) {
	std::cout << "[";
	for (int i = 0; i < arr.size; ++i) {
		std::cout << arr.data[i];
		if (i < arr.size - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}

void resize(IntArray* arr, int newSize) {
	if (arr->size == newSize) return;
	if (arr->size > newSize) {
		int* temp = new int[newSize];
		for (int i = 0; i < newSize; ++i) {
			temp[i] = get(arr, i);
		}
		delete[] arr->data;
		arr->data = temp;
		arr->size = newSize;
	}
	else {
		int* temp = new int[newSize];
		for (int i = 0; i < arr->size; ++i) {
			temp[i] = get(arr, i);
		}
		for (int i = arr->size; i < newSize; ++i) {
			temp[i] = 0;
		}
		delete[] arr->data;
		arr->data = temp;
		arr->size = newSize;
	}
}

void resize(IntArray& arr, int newSize) {
	if (arr.size == newSize) return;
	if (arr.size > newSize) {
		int* temp = new int[newSize];
		for (int i = 0; i < newSize; ++i) {
			temp[i] = get(arr, i);
		}
		delete[] arr.data;
		arr.data = temp;
		arr.size = newSize;
	}
	else {
		int* temp = new int[newSize];
		for (int i = 0; i < arr.size; ++i) {
			temp[i] = get(arr, i);
		}
		for (int i = arr.size; i < newSize; ++i) {
			temp[i] = 0;
		}
		delete[] arr.data;
		arr.data = temp;
		arr.size = newSize;
	}
}

void destroy(IntArray* arr) {
	if (arr->data != nullptr) {
		delete[] arr->data;
		arr->size = 0;
	}
}
void destroy(IntArray& arr) {
	if (arr.data != nullptr) {
		delete[] arr.data;
		arr.size = 0;
	}
}


int main()
{
	IntArray mas;
	create(mas, 30);
	for (int i = 0; i < 30; ++i) {
		set(mas, i, i + 1);
	}
	print(mas);
	resize(mas, 50);
	print(mas);
	resize(mas, 10);
	print(mas);
	destroy(mas);
}

