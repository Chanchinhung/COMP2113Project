#ifndef Card_H //header file for data structure storing cards
#define Card_H
class card {
    public:
        void initialise(int, char, char);
        void display();
    private:
        int value;
        char number;
        char suit;
};
#endif
