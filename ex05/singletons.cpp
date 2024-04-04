# include "singletons.hpp"

Course *CourseList::getCourse(const std::string &name) const {
    for (std::vector<Course *>::const_iterator item = this->items.begin(); item != this->items.end(); item++) {
        if ((*item)->get_name() == name) {
            return (*item);
        }
    }
    return (NULL);
}
