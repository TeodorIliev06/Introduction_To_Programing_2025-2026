# Видове сортиране - https://visualgo.net/en/sorting?slide=1-1

- Bubble sort
- Selection sort

# Търсене на елемент в сортиран масив

- Binary search

### Bubble sort

```c++
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

### Selection sort

```c++
void selectionSort(int arr[], int n)
{
    int minIndex = 0;
 
    for (int i = 0; i < n - 1; i++) {
 
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
 
        if (minIndex != i)
            swap(arr[minIndex], arr[i]);
    }
}
```

### Binary search

```c++
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}
```

## Примери

```c++
#include <iostream>

void printSize(const int* arr) {
	std::cout << sizeof(arr) << std::endl;
	std::cout << sizeof(arr) / sizeof(int) << std::endl;
}


int main()
{
	int arr[10];
	std::cout << sizeof(arr) << std::endl;
	std::cout << sizeof(arr) / sizeof(int) << std::endl;
	printSize(arr);
}
```

```c++
#include <iostream>

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	std::cout << *(arr + 1) << std::endl;
	std::cout << arr[1] << std::endl;
	std::cout << &arr[3] - arr << std::endl;
}
```

## Pointers vs References
```c++
#include <iostream>

int main()
{
	int a = 5, b = 4;

	// References MUST be initialized
	int& r1 = a; // fine
	int& r2; // ERROR


	// Pointers have a default invalid value (nullptr)
	int* ptr = nullptr; // fine
	int& r2 = nullptr; // ERROR

	// References CAN'T be reassigned
	int& r3 = a;
	r3 = b; // this will change the value of a instead of r3 starting to point to b
	std::cout << r3 << std::endl;
	std::cout << a;
}
```

## Pointers visualized
![Pointers visualized](https://i.redd.it/my-new-favorite-way-to-explain-pointers-to-newbies-v0-m9p5757l45i91.jpg?width=1709&format=pjpg&auto=webp&s=3a2806c2092e2e17bd2ae6704ee62b240ce78a9e)

## Dereferencing
![Dereferencing](https://i.redd.it/my-new-favorite-way-to-explain-pointers-to-newbies-v0-5ta9tgzi45i91.png?width=498&format=png&auto=webp&s=06ce9b86ceb6d6ffc06a6c005cd7922e50873806)

﻿
## Задачи

#### Напишете програма, която чете цяло число **N** в интервала [1, 1000], после **N** цели числа и вика следните функции върху масив от тези числа.

**1.**  Да се напише функция, която приема масив от цели числа и размера му и връща средната стойност от елементите му и числото, което е най-близо до тази средна стойност.

**Пример:**

Вход:
```c++
[5 7 4 9]
```

Изход:
```c++
6.25
7
```
**2.** Да се напише функция, която приема масив от цели числа и връща минимума и максимума на числата.

**Пример:**

Вход:
```c++
[3 1 2 8 13 5 1 6 25]
```

Изход:
```c++
Min: 1
Max: 25
```
**3.** Напишете функция, която масив от цели числа и индекс и премахва числото, което се намира на този индекс.

**Пример:**

Вход:
```c++
[33 1 23 8 54 5 1 6] 4
```

Изход:
```c++
[33 1 23 54 5 1 6]
```

**4.** Напишете функция, която приема 2 масива от цели числа **arr** и  **result** (който е празен), 2 числа **a** и **b**  и пълни масива **result** с всички числа от  **arr**, които са  в  интервала **[a, b]** .

**Пример:**

Вход:
```c++
[5 7 1 4 3 9 10]
2 8
```

Изход:
```c++
[5 7 4 3]
```

**5.** Да се напише функция, която приема масив от цели числа и връща дали е симетричен.

**Пример:**

Вход:
```c++
[1 2 3 2 1]
```

Изход:
```c++
yes
```
Вход:
```c++
[1 2 3 4 1]
```

Изход:
```c++
no
```
**6.** Да се напише функция, която приема масив от цели числа и връща дължината на най-дългата намаляваща подредица.

**Пример:**

Вход:
```c++
[1 2 7 3 2 8 4]
```

Изход:
```c++
3
```
**7.** Да се напише функция, която приема масив от цели числа и връща дължината на най-дългата редица от еднакви числа.

**Пример:**

Вход:
```c++
[3 3 2 2 2 5 2 2 3 3 3]
```

Изход:
```c++
3
```

**8.** Да се напише функция, която приема масив от цели числа с дължина най-много **9** и занулява всички числа, които не съдържат като цифра индекса на масива.

**Пример:**

Вход:
```c++
[45 62 23 47 47 65 100]
```

Изход:
```c++
[0 0 23 0 47 65 0]
```

**9.** Да се напише функция, която приема масив от цели числа и връща кое е първото най-често срещано число в него.

**Пример:**

Вход:
```c++
[6 3 5 7 6 5 3 6 5]
```

Изход:
```c++
6
```

#### Напишете програма, която чете цели числа **N** и **M** в интервала [1, 1000], после **N + M** цели числа, и вика следните функции върху масиви от тези числа с размери съответно N и M.


**10.** Да се напишат функции, които приемат 3 масива от цели числа - **arr1**, **arr2** и **result** (който е празен) и пълнят третия съответно с обединението и сечението на **arr1** и **arr2**.

**Пример:**

Вход:
```c++
[2 4 1 7 8]
[1 2 3 5]
```

Изход:
```c++
Intersection: [2 1]
Union: [2 4 1 7 8 3 5]
```

**11.** Да се напише функция, която приема 3 масива от цели числа - **arr1**, **arr2** и **result** (който е празен), като **arr1** и **arr2** са сортирани във възходящ ред. В края на функцията **result** представлява обединение на 2-та масива и е сортиран във възходящ ред.

**Пример:**

Вход:
```c++
[1 5 7 8]
[2 3 9]
```

Изход:
```c++
[1 2 3 5 7 8 9]
```

**12.** Да се напише функция, която приема 2 масива от цели числа и връща резултат дали са линейно зависими.

**Пример:**

Вход:
```c++
[1 2 3 4 5]
[2 4 6 8 10]
```
Изход:
```c++
yes
```
Вход:
```c++
[1 2 3 4 5]
[2 4 6 8 11]
```
Изход:
```c++
no
```



**13.** Напишете функция, която приема два масива от цели числа и размерите им, и проверява дали вторият масив е подмасив на първия.

Вход:
```c++
[1, 4, 4, 0, 4, 2]
[4, 0, 4]
```

Изход:
```c++
true
```

Вход:
```c++
[1, 4, 9, 8, 4, 2]
[4, 9, 2]
```

Изход:
```c++
false
```
