#ifndef STUDENT_HPP
# define STUDENT_HPP

class Course;

# include "Classroom.hpp"
# include "Person.hpp"

class Student : public Person {
    private:
        std::vector<Course*> _subscribedCourse;


    public:
        Student(std::string &p_name) : Person(p_name) {}

    private:
        bool is_subscribed(Course *p_course) {
            for (std::vector<Course *>::const_iterator course = this->_subscribedCourse.begin(); course != this->_subscribedCourse.end(); course++) {
                if (p_course == *course) {
                    return (true);
                }
            }
            return (false);
        }

        void erase_course(Course *p_course) {
            for (std::vector<Course *>::const_iterator course = this->_subscribedCourse.begin(); course != this->_subscribedCourse.end(); course++) {
                if (p_course == *course) {
                    this->_subscribedCourse.erase(course);
                    return ;
                }
            }
        }

    public:

        void attendClass(Classroom *p_classroom) {
            if (p_classroom == NULL) {
                return ;
            }

            if (this->is_subscribed(p_classroom->current_course())) {
                this->enter(p_classroom);
            } 
        }

        void exitClass() {
            this->exit();
        }

        void graduate(Course* p_course) {
            if (p_course == NULL) {
                return ;
            }

            this->erase_course(p_course);
        }

        void subscribe(Course *p_course) {
            if (p_course == NULL) {
                return ;
            }

            if (is_subscribed(p_course)) {
                return ;
            }

            this->_subscribedCourse.push_back(p_course);
            p_course->subscribe(this);
        }
};

#endif