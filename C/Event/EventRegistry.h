#ifndef EVENTREGISTRY_H
#define EVENTREGISTRY_H

#include "../DataStructures/LinkedList.h"
#include "I_Event.h"

class EventRegistry
{
private:
    LinkedList<I_Event_t> EventList;

public:
    EventRegistry(){}

    void Register(I_Event_t *Event)
    {
        EventList.PushBack(Event);
    }

    void Trigger(I_Event_t *Event, const void *args)
    {
        if(EventList.Contains(Event))
        {
            Event->Trigger(args);
        }
    }

};

#endif