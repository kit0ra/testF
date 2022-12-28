#ifndef PROJET_PROGRAMMATION_S5_EMPTY_H
#define PROJET_PROGRAMMATION_S5_EMPTY_H

#include "vector"
using namespace std;

class Empty {
    public:
        Empty();
        Empty(int x,int y);
        vector<int> getPosition() const;
        virtual void setPosition(int x, int y);
        char getSymbol() const;
    protected:
        std::vector<int> d_position;
        char d_symbol;
};


#endif //PROJET_PROGRAMMATION_S5_EMPTY_H
