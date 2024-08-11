#ifndef CELL_H
#define CELL_H

class Cell {
private:
    int _value;
    bool _wasSelected;
public:
    Cell();
    int getValue();
    void setValue(int value);
    bool getSelected();
    void setSelected(bool wasSelected);
};

#endif //CELL_H