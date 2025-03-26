#ifndef DATA_H
#define DATA_H

#include "I_Event.h"
#include "EventRegistry.h"

class Data_t
{
private:
    I_Event_t onChange;
    EventRegistry *registry;
    int _data;

    void changed(const void *args)
    {
        registry->Trigger(&onChange, args);
    }

public:
    Data_t(EventRegistry *registry)
    {
        this->registry = registry;
        this->registry->Register(&onChange);
        _data = 0;
    }

    void add(int value)
    {
        _data += value;
        changed(&_data);
    }

    I_Event_t *GetOnChangeEvent()
    {
        return &onChange;
    }

};

#endif