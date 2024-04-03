#ifndef OBSERVER_HPP
# define OBSERVER_HPP

class BellObserver {
    public:
        virtual void pauseOver() = 0;
        virtual void pauseStarts() = 0;
        virtual ~BellObserver() {}
};

#endif