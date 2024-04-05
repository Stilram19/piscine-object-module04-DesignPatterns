#ifndef GRADUATION_BELL_HPP
# define GRADUATION_BELL_HPP

class GraduationBellObserver;

# include "Bell.hpp"
# include "List.hpp"

// this class represents the subject of the LunchBellRing event, in which the Professor and Student 
// are observers.
// this class was created in order to make the code adhere to the Open/Closed principle

class GraduationBell : public List<GraduationBellObserver>, public Bell {
    public:
        GraduationBell() : List<GraduationBellObserver>(false) {}
        ~GraduationBell() {}

    private:
        // Break event
        static void lunchNotification(GraduationBellObserver *observer);

    public:
        virtual void ring();
        virtual void addObserver(BellObserver *observer);
        virtual void removeObserver(BellObserver *observer);
};

#endif
