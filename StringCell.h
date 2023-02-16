#ifndef StringCell_H
#define StringCell_H

#include "SpreadsheetCell.h"

class StringCell : public SpreadsheetCell<int> {
public:
    /* Constructors */
    StringCell();

    explicit StringCell(int value);

    /* Override pure virtual method from parent */
    void printCell(std::ostream &outs) const override;

    /* Overloaded operators */
    friend StringCell operator+(const StringCell &lhs, const StringCell &rhs);

    StringCell &operator+=(const StringCell &rhs);

    friend StringCell operator-(const StringCell &lhs, const StringCell &rhs);

    StringCell &operator-=(const StringCell &rhs);

    friend StringCell operator*(const StringCell &lhs, const StringCell &rhs);

    StringCell &operator*=(const StringCell &rhs);

    // TODO: After implementing StringCell, uncomment and implement the following function
    // friend StringCell operator / (const StringCell &lhs, const StringCell &rhs);
    StringCell &operator/=(const StringCell &rhs);

    friend bool operator==(const StringCell &lhs, const StringCell &rhs);

    friend bool operator!=(const StringCell &lhs, const StringCell &rhs);

    friend bool operator<(const StringCell &lhs, const StringCell &rhs);

    friend bool operator<=(const StringCell &lhs, const StringCell &rhs);

    friend bool operator>(const StringCell &lhs, const StringCell &rhs);

    friend bool operator>=(const StringCell &lhs, const StringCell &rhs);
};

#endif
