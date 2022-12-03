#ifndef Card_H //header file for card class
#define Card_H
class card {
    public:
        void initialise(int, char, char);
        void display();
        bool is_ace();
        int get_value();
        char get_number();
    //private:
        int value;
        char number;
        char suit;
    //For the Playround function, I runned the code in a compiler, and it seems that it is not working well
    //because of the "private:".
    //I did not learn "class" so I don't know why it is happening. However, after deleting the "private:",
    //All things are working well. So let's discuss this in our meeting later on, whether to delete it or modify the playround function.
};
#endif
