#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

// Queue implementation with linked list
class Queue
{
public:
  Queue();
  ~Queue();
  void push(int value);
  void pop();
  int front();
  int back();
  bool empty();
  int size();
  void print();
private:
  struct Node
  {
    int m_value;
    Node* m_next;
  };

  Node* m_head;
  Node* m_tail;
  int m_size;
};


Queue::Queue()
{
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

Queue::~Queue()
{
  Node* p;
  for(; m_head != nullptr; m_head = p)
  {
    p = m_head->m_next;
    delete m_head;
  }
}

void Queue::push(int value)
{
  Node* newNode = new Node;
  newNode->m_value = value;

  if(m_tail == nullptr)
  {
    newNode->m_next = nullptr;
    m_tail = newNode;
    m_head = newNode;
    m_size++;
    return;
  }

  newNode->m_next = nullptr;
  m_tail->m_next = newNode;
  m_tail = newNode;
  m_size++;
}

void Queue::pop()
{
  if(m_head == nullptr)
      exit(1);

  if(m_head == m_tail)
  {
    m_size--;
    delete m_head;
    m_head = nullptr;
    m_tail = nullptr;
    return;
  }

  Node* p = m_head;
  m_head = p->m_next;
  delete p;
  m_size--;
}

int Queue::front()
{
  if(m_head == nullptr)
      exit(1);

  return (m_head->m_value);
}

int Queue::back()
{
  if(m_tail == nullptr)
      exit(1);

  return (m_tail->m_value);
}

bool Queue::empty()
{
  return (m_size == 0);
}

int Queue::size()
{
  return m_size;
}

void Queue::print()
{
  Node* p;
  for(p = m_head; p != nullptr; p = p->m_next)
      cout << p->m_value;
}
