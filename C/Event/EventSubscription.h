#ifndef EVENTSUBSCRIPTION_H
#define EVENTSUBSCRIPTION_H

class EventSubscription
{
    public:
        typedef void (*Callback_t)(void *context, const void *args);
        typedef void (*publish)(const void *args);

    private:
        void *context;
        Callback_t callback;
    
    public:
        EventSubscription(void *context, Callback_t callback)
        {
            this->context = context;
            this->callback = callback;
        }

        void Publish(const void *args)
        {
            this->callback(context, args);
        }

};

#endif