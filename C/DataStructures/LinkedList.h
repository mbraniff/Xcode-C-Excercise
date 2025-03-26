#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "../util.h"

template<typename T>
class LinkedList
{
public:
    typedef struct Node
        {
            Node *next;
            T *data;
        }Node;
    
    typedef void (*ForEachCallback_t)(void *context, T *data);

private:
    Node *head;
    size_t size;
    Node *iter;

    void _Clear(Node *node)
    {
        if(node != nullptr)
        {
            _Clear(node->next);
        }
        delete node;
    }

public:
    LinkedList()
    {
        head = nullptr;
        this->size = 0;
    }

    ~LinkedList()
    {
        Clear();
    }

    size_t GetSize()
    {
        return size;
    }

    void Clear()
    {
        size = 0;
        _Clear(head);
        head = nullptr;
    }

    Node* getNodeAt(int index)
    {
        Node *current = head;
        for(int i=0; i<index; i++)
        {
            if(current == nullptr) return nullptr;
            current = current->next;
        }

        return current;
    }

    bool Contains(Node *node)
    {
        Node *current = head;
        while(current != nullptr)
        {
            if(current == node)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool Contains(T *data)
    {
        Node *current = head;
        while(current != nullptr)
        {
            if(current->data == data)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void PushBack(T *data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if(head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while(current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;           
    }

    void PushBack(Node *node)
    {
        if(head == nullptr)
        {
            head = node;
        }
        else
        {
            Node *current = head;
            while(current->next != nullptr)
            {
                current = current->next;
            }
            current->next = node;
        }
        size++;
    }

    void PushFront(T *data)
    {
        Node *newNode = new Node;
        newNode->next = head;
        newNode->data = data;

        head = newNode;
        size++;
    }

    void PushFront(Node *node)
    {
        node->next = head;

        head = node;
        size++;
    }

    void Remove(Node *node)
    {
        Node *current = head;
        Node *previous = nullptr;
        while(current != nullptr)
        {
            if(current == node)
            {
                if(previous)
                {
                    previous->next = current->next;
                }else
                {
                    head = current->next;
                }
                delete current;
                size--;
                break;
            }
            previous = current;
            current = current->next;
        }
    }

    void Remove(T *data)
    {
        Node *current = head;
        Node *previous = nullptr;
        while(current != nullptr)
        {
            if(current->data == data)
            {
                if(previous)
                {
                    previous->next = current->next;
                }else
                {
                    head = current->next;
                }
                delete current;
                size--;
                break;
            }
            previous = current;
            current = current->next;
        }
    }

    void Dump()
    {
        Node *current = head;
        for(int i=0; i < size; i++)
        {
            std::cout << "index: " << i << " data = " << current->data << std::endl;
            current = current->next;
        }
    }

    void for_each(void *context, ForEachCallback_t each, Node *start = nullptr, Node *end = nullptr)
    {
        Node *current = head;
        if(start != nullptr)
        {
            while(current != nullptr && current != start)
            {
                current = current->next;
            }
        }

        while(current != nullptr)
        {
            if(end == nullptr)
            {
                each(context, &current->data);
            }
            else
            {
                if(current != end)
                {
                    each(context, &current->data);
                }
                else
                {
                    each(context, &current->data);
                    break;
                }
                
            }
            current = current->next;
        }
    }
};

#endif