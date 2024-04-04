#ifndef BELL_HPP
# define BELL_HPP

class BellObserver;

# include "List.hpp"

// this class represents the subject of the Bell event, in which the Professor and Student 
// are observers

class Bell : public List<BellObserver> {
    private:
        bool isPauseOver;

    public:
        Bell() : List<BellObserver>(false), isPauseOver(true) {}
        ~Bell() {}

    private:
        static void pauseOverNotification(BellObserver *observer);
        static void pauseStartsNotification(BellObserver *observer);

    public:
        void ring();
};

#endif