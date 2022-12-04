//header file for the class RoundStat that stores the result of and money won in a round
#ifndef RoundStat_H
#define RoundStat_H
class RoundStat{
    public:
        char WL; //Storing whether the round is won/lost/drew
        int moneywon; //Storing the money won that round, if lose money the value is negative
};
#endif
