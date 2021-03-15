#include <iostream>

int* create(int size, int first, int step) {
	int* arr = new int[size];
	*arr = first;
	for (int i = 1; i < size; ++i) {
		arr[i] = arr[i-1] + step;
	}
	return arr;
}

int* print(int* arr, int size) {
    std::cout << "[";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
	}
    std::cout << "]";
	return arr;
}

int* sort(int* arr, int size) {
    int i, key, j;
    for (i = 1; i < size; ++i)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
	return arr;
}

int main(){
    setlocale(LC_ALL, "rus");
    std::cout << "Введите размер массива, начальный элемент и шаг прогрессии.\n";
    int size, first, step;
    std::cin >> size >> first >> step;
    int* mas = create(size, first, step);
    sort(mas, size);
    print(mas, size);
    delete[] mas;
}

