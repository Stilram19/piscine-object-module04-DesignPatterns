# include <iostream>
# include "Course.hpp"
# include "Room.hpp"
# include "Student.hpp"
# include "Staff.hpp"
# include "singletons.hpp"

template<class T, class U>
void test1() {
    std::string firstName("First");
    std::string secondName("Second");

    T item1(firstName);
    T item2(secondName);
    U &ref = U::get_instance();

    std::cout << "List Size is: " << ref.size() << std::endl;

    ref.addItem(&item1);
    ref.addItem(&item2);

    std::cout << "List Size is: " << ref.size() << std::endl;

    ref.removeItem(&item1);

    std::cout << "List Size is: " << ref.size() << std::endl;
}

// specialization for Room, RoomList since Room doesn't have a constructor accepting a std::string
template<>
void test1<Room, RoomList>() {
    Room room1;
    Room room2;
    RoomList &ref = RoomList::get_instance();

    std::cout << "List Size is: " << ref.size() << std::endl;

    ref.addItem(&room1);
    ref.addItem(&room2);

    std::cout << "List Size is: " << ref.size() << std::endl;

    ref.removeItem(&room1);

    std::cout << "List Size is: " << ref.size() << std::endl;
}

int main() {
    test1<Course, CourseList>();
    std::cout << "*****************************" << std::endl;
    test1<Student, StudentList>();
    std::cout << "*****************************" << std::endl;
    test1<Staff, StaffList>();
    std::cout << "*****************************" << std::endl;
    test1<Room, RoomList>();
    return (0);
}
