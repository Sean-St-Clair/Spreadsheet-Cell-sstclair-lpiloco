#ifndef DoubleCell_H
#define DoubleCell_H

#include "SpreadsheetCell.h"

class DoubleCell : public SpreadsheetCell<int> {
public:
    /* Constructors */
    DoubleCell();

    explicit DoubleCell(int value);

    /* Override pure virtual method from parent */
    void printCell(std::ostream &outs) const override;

    /* Overloaded operators */
    friend DoubleCell operator+(const DoubleCell &lhs, const DoubleCell &rhs);

    DoubleCell &operator+=(const DoubleCell &rhs);

    friend DoubleCell operator-(const DoubleCell &lhs, const DoubleCell &rhs);

    DoubleCell &operator-=(const DoubleCell &rhs);

    friend DoubleCell operator*(const DoubleCell &lhs, const DoubleCell &rhs);

    DoubleCell &operator*=(const DoubleCell &rhs);

    // TODO: After implementing DoubleCell, uncomment and implement the following function
    // friend DoubleCell operator / (const DoubleCell &lhs, const DoubleCell &rhs);
    DoubleCell &operator/=(const DoubleCell &rhs);

    friend bool operator==(const DoubleCell &lhs, const DoubleCell &rhs);

    friend bool operator!=(const DoubleCell &lhs, const DoubleCell &rhs);

    friend bool operator<(const DoubleCell &lhs, const DoubleCell &rhs);

    friend bool operator<=(const DoubleCell &lhs, const DoubleCell &rhs);

    friend bool operator>(const DoubleCell &lhs, const DoubleCell &rhs);

    friend bool operator>=(const DoubleCell &lhs, const DoubleCell &rhs);
};

#endif
