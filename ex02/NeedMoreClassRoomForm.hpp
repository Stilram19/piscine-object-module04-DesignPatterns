#ifndef NEED_MORE_CLASS_ROOM_FORM_HPP
# define NEED_MORE_CLASS_ROOM_FORM_HPP

# include "Form.hpp"
# include <iostream>

class NeedMoreClassRoomForm : public Form {
    private:

    public:
        void execute() {
            std::cout << "Need More Class Room Form is executed!" << std::endl;
        }
};

#endif