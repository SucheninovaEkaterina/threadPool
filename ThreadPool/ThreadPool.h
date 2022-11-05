#pragma once
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <vector>
#include <fstream>

typedef void (*task_t)();

class ThreadPool
{
private:
	// флаг для отметки, что задача выполнена
	std::atomic_bool stop{ false };
	// защита объекта
	std::mutex mtx;
	// потоки для выполнения
	std::vector<std::thread> setThreads;
	// очередь задач
	std::queue<task_t> Tasks;

	void runThread();
public:
	ThreadPool(int countThreads);
	~ThreadPool();
	void AddTask(task_t newTask);
	void DelTask(int id);

};