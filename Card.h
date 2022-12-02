#ifndef Card_H //header file for card class
#define Card_H
class card {
    public:
        void initialise(int, char, char);
        void display();
        bool is_ace();
        int get_value();
    private:
        int value;
        char number;
        char suit;
};
#endif
