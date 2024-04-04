#ifndef SCHOOL_HPP
# define SCHOOL_HPP

# include "List.hpp"
# include "Headmaster.hpp"
# include "Secretary.hpp"

class Student;
class Professor;
class Course;

// School can't inherit from 

class School : public List<Student>, public List<Professor> {
    private:
        Secretary   secretary;
        Headmaster  headmaster;

    public:
        School(std::string headmaster_name, std::string secretary_name) : secretary(secretary_name), headmaster(headmaster_name, &secretary) {}
        ~School() {}

    public:
        void    launchClasses();
        void    recreationTime(); // break time
        void    runDayRoutine();
        void    requestRingBell();
        void    recruteProfessor();
        void    recruteStudent();

    // getters
    public:
        Course *getCourse(std::string p_name) const;
        std::vector<Student*> getStudents() const;
        std::vector<Professor*> getProfessors() const;
        Secretary getSecretary() const;
        Headmaster getHeadmaster() const;

    public:
        void graduationCeremony();
};

#endif