/**
 *
 * @file    event_manager.cpp
 * @author  Alexandre Sollier
 * @date    Décembre 2019
 * @version 1.0
 * @brief   Gestionnaire d'événements de minGL
 *
 **/

#include "event_manager.h"

#define EVENTMANAGER nsEvent::EventManager

bool EVENTMANAGER::hasEvent()
{
    return m_eventQueue.size() > 0;
} // hasEvent()

void EVENTMANAGER::pushEvent(const Event_t &event)
{
    m_eventQueue.push(event);
} // pushEvent()

const nsEvent::Event_t EVENTMANAGER::pullEvent()
{
    // Copy the first element and then remove it from the queue
    const Event_t event = m_eventQueue.front();
    m_eventQueue.pop();
    return event;
} // pullEvent()

#undef EVENTMANAGER
