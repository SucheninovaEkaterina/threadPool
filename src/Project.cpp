#include "ThreadPool.h"
#include <iostream>
#include <chrono>
int global = 1;
// Задача: поиск факториала числа 50 (уже задано в методе функции)
void TestTask1()
{
    double sum = 1;
    for (double i = 1; i <= global; i++) {
        sum = sum * i;
    }
    std::cout << sum<<"\n";
}

int main()
{
   // Ввод кол-ва потоков
    int n;
    std::cout << "Enter the number of threads: ";
    std::cin >> n;
    // Ввод парамета для задачи
    std::cout << "Enter the task parameter: ";
    std::cin >> global;
    int k;
    std::cout << "Enter the number of tasks: ";
    std::cin >> k;
    ThreadPool pool(n);
    // 10 раз добавляем в очередь задачу (поиск факториала)
    for (int i = 0; i < k; i++)
       {
           pool.AddTask(TestTask1);
       }
       // Удаление задачи, находящейся на 3 месте в очереди
     pool.DelTask(3);
     std::cout << "all tasks completed! \n";
     std::this_thread::sleep_for(std::chrono::milliseconds(100000));
}
