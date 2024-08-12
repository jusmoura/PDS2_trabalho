#include "../include/cell.hpp"

Cell::Cell() {
    _value = 0;
    _wasSelected = false;
}

int Cell::getValue() {
    return _value;
}

void Cell::setValue(int value) {
    this->_value = value;
}

bool Cell::getSelected() {
    return _wasSelected;
}

void Cell::setSelected(bool wasSelected) {
    this->_wasSelected = wasSelected;
}