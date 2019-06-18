/*
 * =====================================================================================
 *
 *       Filename:  abstract.cpp
 *
 *    Description:  Hackerrank https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
 *
 *        Version:  1.0
 *        Created:  30/05/19 15:16:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  skux
 *   Organization:  not RL
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

  protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
public:
    LRUCache(int capacity)
    {
        cp = capacity;
    }

    void set(int key, int value)
    {
        Node *node;
        auto it = mp.find(key);
        if (it != mp.end())
        {
            node = it->second;
            node->value = value;

        }
        else
        {
            node = new Node(key, value);
            node->next = nullptr;
            node->prev = nullptr;
            mp.insert(pair<int, Node*>(key, node));
        }

        touch(node);

    }

    int get(int key)
    {

        auto it = mp.find(key);
        if (it == mp.end())
        {
            return -1;
        }
        Node *n = it->second;

        touch(n);
        return n->value;
    }

    void touch(Node *node)
    {
        if (node->next != nullptr && node->prev != nullptr)
        {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
        else if(node->next != nullptr && node->prev == nullptr)
        {
            node->next->prev = nullptr;
        }

        if (mp.size() > 1)
        {
            Node* old = tail;
            tail = node;
            tail->prev = old;
            old->next = node;
        }
        else
        {
            tail = node;
            head = node;
        }

        if (mp.size() > cp)
        {
            int key_to_remove = head->key;
            mp.erase(key_to_remove);

            Node *new_head = head->next;
            Node *to_delete = head;
            head = new_head;

            head->prev = nullptr;
            delete to_delete;
        }

    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
