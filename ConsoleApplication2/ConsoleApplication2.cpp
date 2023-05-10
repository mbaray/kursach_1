// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;

void print(int* digitals, int size) {
    for (int i = 0; i < size; i++) {
        cout << digitals[i] << "\t";
    }
    cout << endl;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_print(int* digitals, int size, int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    //РАСКОМЕНТИРОВАТЬ ДЛЯ ОТОБРАЖЕНИЯ СОРТИРОВКИ
         //for (int i = 0; i < size; i++) {
         //    if (a == &digitals[i] || b == &digitals[i]) {
         //        cout << "{" << digitals[i] << "}\t\t";
         //    }
         //    else { 
         //        cout << " " << digitals[i] << " \t\t";
         //    }
         //}
         //cout << endl;
}

void print_time(int start_time, int end_time) {
    int search_time = end_time - start_time;
     cout << "TIME -> " << search_time / 1000.0 << "с" << endl;
     //printf("%.10f", search_time / 1000.0);
}

void bubble_sort(int* digitals, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (digitals[j] > digitals[j + 1]) {
                swap_print(digitals, size, &digitals[j], &digitals[j + 1]);
                //swap(&digitals[j], &digitals[j + 1]);
            }
        }
    }
}

void quick_sort(int* digitals, int size) {
    int start = 0;
    int end = size - 1;

    int mid = digitals[size / 2];

    do {
        while (digitals[start] < mid) {
            start++;
        }
        while (digitals[end] > mid) {
            end--;
        }

        if (start <= end) {
            swap_print(digitals, size, &digitals[start], &digitals[end]);

            start++;
            end--;
        }
    } while (start <= end);


    if (end > 0) {
        //"Левый кусок"
        quick_sort(digitals, end + 1);
    }
    if (start < size) {
        //"Правый кусок"
        quick_sort(&digitals[start], size - start);
    }
}

void gnome_sort(int* digitals, int size) {
    int i = 1;
    int j = 2;
    while (i < size) {
        if (digitals[i - 1] < digitals[i]) {
            i = j;
            j++;
        }
        else {
            swap_print(digitals, size, &digitals[i - 1], &digitals[i]);
            i--;
            if (i == 0) {
                i = j;
                j++;
            }
        }
    }
}

void comb_sort(int* digitals, int size) {
    double factor = 1.2473309; // фактор уменьшения
    int step = size - 1; // шаг сортировки

    while (step >= 1) {
        for (int i = 0; i + step < size; i++) {
            if (digitals[i] > digitals[i + step]) {
                swap_print(digitals, size, &digitals[i], &digitals[i + step]);
            }
        }
        step /= factor;
    }
}

void shaker_sort(int* digitals, int size) {
    int left = 0, right = size - 1;
    bool flag = true;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // и пока в массиве имеются перемещения
    while ((left < right) && flag) {
        flag = false;
        for (int i = left; i < right; i++) { //двигаемся слева направо
            if (digitals[i] > digitals[i + 1]) { // если следующий элемент меньше текущего, // меняем их местами
                swap_print(digitals, size, &digitals[i], &digitals[i + 1]);

                flag = true;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент

        for (int i = right; i > left; i--) {  //двигаемся справа налево
            if (digitals[i - 1] > digitals[i]) { // если предыдущий элемент больше текущего, меняем их местами
                swap_print(digitals, size, &digitals[i], &digitals[i - 1]);

                flag = true;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    int start_time, end_time, search_time;

    int size;
    cout << "Введите кол-во элементов массива: ";
    cin >> size;

    int* digitals_bubble = new int[size];
    int* digitals_quick = new int[size];
    int* digitals_gnome = new int[size];
    int* digitals_comb = new int[size];
    int* digitals_shaker = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "digitals[" << i << "] = ";
        cin >> digitals_bubble[i];
    }

    copy(digitals_bubble, digitals_bubble + size, digitals_quick);
    copy(digitals_bubble, digitals_bubble + size, digitals_gnome);
    copy(digitals_bubble, digitals_bubble + size, digitals_comb);
    copy(digitals_bubble, digitals_bubble + size, digitals_shaker);


    cout << endl << "Исходный массив: ";
    print(digitals_bubble, size);


    cout << endl << "Пузырьковая сортировка" << endl;
    start_time = clock();
    bubble_sort(digitals_bubble, size);
    end_time = clock();
    print_time(start_time, end_time);

    cout << endl << "Быстрая сортировкаовка" << endl;
    start_time = clock();
    quick_sort(digitals_quick, size);
    end_time = clock();
    print_time(start_time, end_time);

    cout << endl << "Гномья сортировкаовка" << endl;
    start_time = clock();
    gnome_sort(digitals_gnome, size);
    end_time = clock();
    print_time(start_time, end_time);

    cout << endl << "Сортировка расчёскойовка" << endl;
    start_time = clock();
    comb_sort(digitals_comb, size);
    end_time = clock();
    print_time(start_time, end_time);

    cout << endl << "Шейкерная сортировкаовка" << endl;
    start_time = clock();
    shaker_sort(digitals_shaker, size);
    end_time = clock();
    print_time(start_time, end_time);

    cout << endl << endl << "Отсортированный массив: ";
    print(digitals_bubble, size);

    delete[] digitals_bubble;
    delete[] digitals_quick;
    delete[] digitals_gnome;
    delete[] digitals_comb;
    delete[] digitals_shaker;

    return 0;
}
