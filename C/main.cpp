#include <iostream>
#include "LinkedList.h"
#include "EventSubscription.h"
#include "I_Event.h"
#include "EventRegistry.h"
#include "data.h"
#include "util.h"

using namespace std;

void trigger0(void *context, const void *args)
{
    cout << "trigger 0!!" << endl;
    cout << "The change: " << *(int*)args << endl;
}

void trigger1(void *context, const void *args)
{
    cout << "trigger 1!!" << endl;
    cout << "The change: " << *(int*)args << endl;
}

int main()
{
    EventSubscription subscription0(0, trigger0);
    EventSubscription subscription1(0, trigger1);
    EventRegistry EventRegistry;
    Data_t d(&EventRegistry);
    I_Event_t *Event = d.GetOnChangeEvent();
    Event->Subscribe(&subscription1);
    // Event->Subscribe(&subscription1);
    d.add(5);
    d.add(19);
}