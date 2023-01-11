#pragma once
#include<iostream>
#include "point.h"
using namespace std;


template<typename T>
class Linklist
{

	class Node
	{
	private:
		Node* next;
		T poi;
		int data;

	public:

		friend class Queue;
		friend class Linklist<T>;
		Node()
		{
			poi.set(0, 0);
			next = nullptr;
			data = 0;
		}
		Node(T p)
		{
			poi.set(p.getX(), p.getY());
			next = nullptr;

		}

	};

private:
	Node* head;
	Node* tail;
public:
	friend class Stack;
	Linklist()
	{
		head = new Node;
		tail = head;
	}
	~Linklist()
	{
		Node* temp;
		while (head != tail)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
		delete head;
		delete tail;
	}

	class Stack
	{

	private:

		Linklist<T>* list;
		int count;
		int size;


	public:
	
		friend class Queuee;
		Stack()
		{
			list = new Linklist<T>;
			size = 0;
			count = 0;

		}
		Stack(int s,int r,int c)
		{
			list = new Linklist<T>;
			size = s;
			count = 0;
		}
		bool IsFull()
		{
			if (count == size)
				return true;

			else
				return false;
		}
		bool IsEmpty()
		{
			if (list->head == list->tail)
				return true;
			else
				return false;
		}
		void Push(point p)
		{
			if (!this->IsFull())
			{
				Node* n = new Node(p);
				if (this->IsEmpty())
				{
					list->head->next = n;
					list->tail = n;
				}
				else
				{
					Node* temp = list->head->next;
					list->head->next = n;
					n->next = temp;
				}
				count += 1;;
			}
			return;

		}
		T Top()
		{
			if (!this->IsEmpty())
				return list->head->next->poi;
		}
		T Pop()
		{
			if (this->IsEmpty() == false)
			{

				Node* temp = list->head->next;
				T  p(temp->poi.getX(), temp->poi.getY());
				list->head->next = temp->next;
				if (temp == list->tail)
				{
					list->tail = list->head;
				}
				count -= 1;
				delete temp;
				return p;
			}
			
		}
		void Print()
		{
			if (!this->IsEmpty())
			{

				Node* current = list->head->next;
				do
				{
					cout << current->poi.getX()<< current->poi.getY() << " ";
					current = current->next;
				} while (current != nullptr);
			}



		}

	};

	class Queuee
	{

	private:
		Linklist<T> ::Stack s1;
		Linklist<T> ::Stack s2;

	public:

		Queuee(int s)
		{
			s1.size = s;
			s2.size = s;
		}
		bool IsFull()
		{
			if (s1.IsFull())
				return true;
			else return false;
		}
		bool IsEmpty()
		{
			if (s1.IsEmpty())
				return true;
			else false;
		}
		void Enqueue(T v)
		{
			if (!s1.IsFull())
			{
				while (!s1.IsEmpty()) {
					s2.Push(s1.Top());
					s1.Pop();
				}

				// Push item into s1
				s1.Push(v);

				// Push everything back to s1
				while (!s2.IsEmpty()) {
					s1.Push(s2.Top());
					s2.Pop();
				}
			}
		}
		T Dequeue()
		{
			if (!s1.IsEmpty()) {


				T x = s1.Top();
				s1.Pop();
				return x;
			}

		}
		
		void Print()
		{

			while (!s1.IsEmpty())
			{
				cout << s1.Top() << " ";
				s2.Push(s1.Top());
				s1.Pop();
			}

			while (!s2.IsEmpty())
			{
				s1.Push(s2.Top());
				s2.Pop();
			}
		}


	};

};
