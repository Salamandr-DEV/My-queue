#pragma once

#include <mutex>

using namespace std;

template <class T>
class Queue
{
private:
	struct Node
	{
		T data;
		Node *next; // указывает на элемент идущий ЗА (с головы в хвост)
	};
	Node *head;
	Node *tail;
	mutex m;
public:
	Queue() : head(nullptr), tail(nullptr) {}
	void Push(const T &val)
	{
		Node *p = new Node;
		p->data = val;
		p->next = nullptr;
		lock_guard<mutex> lck(m);
		if (head == nullptr) // Очередь пуста
		{
			tail = p;
			head = p;
		}
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	void Pop()
	{	
		if (head == nullptr)
		{
			return;
		}
		Node *p = head;
		if (head == tail)
		{
			lock_guard<mutex> lck(m);
			tail = nullptr;
			head = nullptr;
		}
		else
		{
			lock_guard<mutex> lck(m);
			head = head->next;
		}
		delete p;
	}
	T Front()
	{
		lock_guard<mutex> lck(m);
		if (head != nullptr)
		{
			return head->data;
		}
		cout << "warning: queue is empty!" << endl;
		return T();
	}
	bool Empty()
	{
		lock_guard<mutex> lck(m);
		return tail == nullptr;
	}
	~Queue()
	{
		lock_guard<mutex> lck(m);
		while (head != nullptr)
		{
			Node *p = head->next;
			delete head;
			head = p;
		}
	}
};