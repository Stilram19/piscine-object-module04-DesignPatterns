#ifndef BREAK_BELL_HPP
# define BREAK_BELL_HPP

class BreakBellObserver;

# include "List.hpp"
# include "Bell.hpp"

// this class was created in order to make the code adhere to the Open/Closed principle

class BreakBell : public List<BreakBellObserver>, public Bell {
    private:
        bool isPauseOver;

    public:
        BreakBell() : List<BreakBellObserver>(false), isPauseOver(true) {}
        ~BreakBell() {}

    private:
        // Break event
        static void pauseOverNotification(BreakBellObserver *observer);
        static void pauseStartsNotification(BreakBellObserver *observer);

    public:
        virtual void ring();
        virtual void addObserver(BellObserver *observer);
        virtual void removeObserver(BellObserver *observer);
};

#endif