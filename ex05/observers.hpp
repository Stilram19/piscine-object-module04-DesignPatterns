#ifndef OBSERVERS_HPP
# define OBSERVERS_HPP 

# include "Person.hpp"

class Classroom;

class BellObserver : virtual public Person {
    protected:
        Classroom *lastAttendedClassroom;

    public:
        BellObserver(std::string &p_name) : Person(p_name), lastAttendedClassroom(NULL) {}
        virtual ~BellObserver() {}
};


class LunchBellObserver : virtual public BellObserver {
    protected:
        std::string observerType;

    public:
        LunchBellObserver(std::string &p_name, const std::string &observerType) : Person(p_name), BellObserver(p_name), observerType(observerType) {}

    public:
        virtual void LunchTime();
        virtual ~LunchBellObserver() {}
};

class BreakBellObserver : virtual public BellObserver {
    protected:
        std::string observerType;

    public:
        BreakBellObserver(std::string &p_name, const std::string &observerType) : Person(p_name), BellObserver(p_name), observerType(observerType) {}
        virtual ~BreakBellObserver() {}

    public:
        virtual void startBreak();
        virtual void stopBreak();
};

class GraduationBellObserver : virtual public BellObserver {
    public:
        GraduationBellObserver(std::string &p_name) : Person(p_name), BellObserver(p_name) {}
        virtual ~GraduationBellObserver() {}

    public:
        virtual void prepareForGraduation() = 0;
};

#endif
