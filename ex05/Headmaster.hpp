#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

# include "Staff.hpp"
# include "Events.hpp"
# include "List.hpp"
# include <map>

class Professor;
class Student;
class Secretary;
class Classroom;
class Bell;

// this class represents the invoker or the sender (of the Command "Form")
// as you see it is independent from the receiver ("Course" in case of CourseFinishedForm
// and SubscriptionToCourseForm as an example)

// this class represents the Mediator for Professor and Student. (the mediator cannot
// depend on concrete Forms because it is also the invoker of the Command "Form").

class Headmaster : public Staff, public List<Form> {
    // list of subjects (Observer design pattern)
    private:
        std::map<Event, Bell *>    bells;
        Secretary   *secretary;

    private:
        Headmaster(const Headmaster &);
        Headmaster &operator=(const Headmaster &);

    public:
        Headmaster(std::string &p_name, Secretary *secretary);
        ~Headmaster();

    public:
        void receiveForm(Form *p_form);
        void executeForm(Form *p_form);
        virtual void sign(Form *p_form);

    public:
        void askProfToAttendClass(Professor *prof);
        void commandStudentToAttendClass(Student *student, Classroom *classroom);
        Form *getNewForm(FormType formtype);// returns a new form to be filled

    public:
        void bellRing(Event event);
        void subscribeObserverToEvent(BellObserver *observer, Event event);
        void subscribeToAllEvents(BellObserver *observer);
        void removeBellOvserver(BellObserver *observer, Event event);
};

#endif
