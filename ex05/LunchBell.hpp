#ifndef LUNCH_BELL_HPP
# define LUNCH_BELL_HPP

class LunchBellObserver;

# include "Bell.hpp"
# include "List.hpp"

// this class represents the subject of the LunchBellRing event, in which the Professor and Student 
// are observers.
// this class was created in order to make the code adhere to the Open/Closed principle

class LunchBell : public List<LunchBellObserver>, public Bell {
    public:
        LunchBell() : List<LunchBellObserver>(false) {}
        ~LunchBell() {}

    private:
        // Break event
        static void lunchNotification(LunchBellObserver *observer);

    public:
        virtual void ring();
        virtual void addObserver(BellObserver *observer);
        virtual void removeObserver(BellObserver *observer);
};

#endif