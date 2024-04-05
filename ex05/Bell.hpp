#ifndef BELL_HPP
# define BELL_HPP

class BellObserver;

class Bell {
    public:
        virtual ~Bell() {}

    public:
        virtual void ring() = 0;
        virtual void addObserver(BellObserver *observer) = 0;
        virtual void removeObserver(BellObserver *observer) = 0;
};

#endif