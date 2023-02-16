#include "StringCell.h"
#include <iomanip>

using namespace std;

StringCell::StringCell() : SpreadsheetCell() {
}

StringCell::StringCell(string value) : SpreadsheetCell(value) {
}

void StringCell::printCell(std::ostream &outs) const {
    if (value) {
        outs << "|" << left << setw(numChars) << *value;
    } else {
        outs << "|" << left << setw(numChars) << "";
    }
}

StringCell operator+(const StringCell &lhs, const StringCell &rhs) {
    StringCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value + *rhs.value);
    } else {
        // One or both of the parameters are nullopt.
        returnVal.setToNull();
    }
    return returnVal;
}

StringCell &StringCell::operator+=(const StringCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value) {
        setValue(*value + *rhs.value);
    }
    return *this;
}

StringCell operator*(const StringCell &lhs, const unsigned int &rhs) {
    StringCell returnVal;
    if (lhs.value && rhs >= 0) {
        returnVal.setValue("");
        for (int i = 0; i < rhs; i++) {
            returnVal.setValue(*returnVal.getValue() + *lhs.getValue());
        }
    } else {
        returnVal.setToNull();
    }
    return returnVal;
}

StringCell &StringCell::operator*=(const unsigned int &rhs) {
    // if either value is nullopt, no change to `this`
    if (value && rhs >= 0) {
        string repeat = *value;
        setValue("");
        for (int i = 0; i < rhs; i++) {
            setValue(*getValue() + repeat);
        }
    }
    return *this;
}

bool operator==(const StringCell &lhs, const StringCell &rhs) {
    if (lhs.value && rhs.value) {
        return (*lhs.value == *rhs.value);
    } else if (!lhs.value && !rhs.value) {
        // both are nullopt, so they are equal
        return true;
    }
    return false;
}

bool operator!=(const StringCell &lhs, const StringCell &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StringCell &lhs, const StringCell &rhs) {
    if (lhs.value && rhs.value) {
        return (*lhs.value < *rhs.value);
    }
    return false;
}

bool operator<=(const StringCell &lhs, const StringCell &rhs) {
    return (lhs < rhs || lhs == rhs);
}

bool operator>(const StringCell &lhs, const StringCell &rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const StringCell &lhs, const StringCell &rhs) {
    return !(lhs < rhs);
}
