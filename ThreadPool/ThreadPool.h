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
	// ���� ��� �������, ��� ������ ���������
	std::atomic_bool stop{ false };
	// ������ �������
	std::mutex mtx;
	// ������ ��� ����������
	std::vector<std::thread> setThreads;
	// ������� �����
	std::queue<task_t> Tasks;

	void runThread();
public:
	ThreadPool(int countThreads);
	~ThreadPool();
	void AddTask(task_t newTask);
	void DelTask(int id);

};