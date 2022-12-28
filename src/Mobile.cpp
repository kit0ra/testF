#include <iostream>
#include "../../Headers/Mobile/Mobile.h"

void Mobile::goTo(Direction direction) {
    // Convert a direction in a tab
    std::vector<int> tab;
    int result = static_cast<int>(direction);
    for (int i = 0; i < 2; i++) {
        tab.insert(tab.begin(), (result % 100) - 11);
        result = (result - (result % 100)) / 100;
    }

    // cout << "[ " << tab[0] << ", " << tab[1] << " ]" << '\n';
    d_position[0] += tab[0];
    d_position[1] += tab[1];

    // cout << d_position[0] << ',' << d_position[1];
}

int Mobile::getLife() const {
    return d_life;
}

void Mobile::setLife(int life) {
    d_life = life;
}

void Mobile::setSymbol(char symbol) {
    d_symbol = symbol;
}

void Mobile::touch(Mobile& mobile) {
    if (mobile.getPosition()[0] == getPosition()[0] && mobile.getPosition()[1] == getPosition()[1]) {
        cout << mobile.getName() << " s'est fait manger par " << name << ".";
        mobile.setLife(getLife() - 1);
        mobile.setSymbol('.');
    }
}

string Mobile::getName() {
    return name;
}

void Mobile::moveTo(Mobile& mobile) {
    if (getSymbol() == 'L') {
        if (mobile.getPosition()[0] < getPosition()[0]) {
            goTo(Direction::N);
        } else if (mobile.getPosition()[0] > getPosition()[0]) {
            goTo(Direction::S);
        } else if (mobile.getPosition()[1] > getPosition()[1]) {
            goTo(Direction::E);
        } else if (mobile.getPosition()[1] < getPosition()[1]) {
            goTo(Direction::O);
        }
    } else {
        if (mobile.getPosition()[0] < getPosition()[0]) {
            if (mobile.getPosition()[1] > getPosition()[1]) {
                goTo(Direction::NE);
            } else if (mobile.getPosition()[1] < getPosition()[1]) {
                goTo(Direction::NO);
            } else {
                goTo(Direction::N);
            }
        } else if (mobile.getPosition()[0] > getPosition()[0]) {
            if (mobile.getPosition()[1] > getPosition()[1]) {
                goTo(Direction::SE);
            } else if (mobile.getPosition()[1] < getPosition()[1]) {
                goTo(Direction::SO);
            } else {
                goTo(Direction::S);
            }
        } else if (mobile.getPosition()[1] > getPosition()[1]) {
            goTo(Direction::E);
        } else if (mobile.getPosition()[1] < getPosition()[1]) {
            goTo(Direction::O);
        }
    }
}
