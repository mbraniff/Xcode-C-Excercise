#ifndef I_EVENT_H
#define I_EVENT_H

#include "LinkedList.h"
#include "EventSubscription.h"
#include <iostream>

class I_Event_t
{
private:
    friend class EventRegistry;
    LinkedList<EventSubscription> Subscriptions;

    void _Trigger(const void *args, EventSubscription *subscription)
    {
        subscription->Publish(args);
    }

    void Trigger(const void *args)
    {
        for(size_t i=0; i<Subscriptions.GetSize(); i++)
        {
            _Trigger(args, Subscriptions.getNodeAt((int)i)->data);
        }
    }
public:
    I_Event_t()
    {}
    
    void Subscribe(EventSubscription *subscription)
    {
        Subscriptions.PushBack(subscription);
    }

    void Unsubscribe(EventSubscription *subscription)
    {
        Subscriptions.Remove(subscription);
    }
};


#endif