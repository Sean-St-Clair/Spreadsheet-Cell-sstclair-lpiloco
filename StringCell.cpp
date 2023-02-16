#include "StringCell.h"
#include <iomanip>

using namespace std;

StringCell::StringCell() : SpreadsheetCell() {

}

StringCell::StringCell(int value) : SpreadsheetCell(value) {

}

void StringCell::printCell(std::ostream &outs) const {
    if (value) {
        outs << "|" << right << setw(numChars) << *value;
    } else {
        outs << "|" << right << setw(numChars) << "";
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

StringCell operator-(const StringCell &lhs, const StringCell &rhs) {
    StringCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value - *rhs.value);
    } else {
        // One or both of the parameters are nullopt.
        returnVal.setToNull();
    }
    return returnVal;
}

StringCell &StringCell::operator-=(const StringCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value) {
        setValue(*value - *rhs.value);
    }
    return *this;
}

StringCell operator*(const StringCell &lhs, const StringCell &rhs) {
    StringCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value * *rhs.value);
    } else {
        returnVal.setToNull();
    }
    return returnVal;
}

StringCell &StringCell::operator*=(const StringCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value) {
        setValue(*value * *rhs.value);
    }
    return *this;
}

StringCell &StringCell::operator/=(const StringCell &rhs) {
    // if either value is nullopt, no change to `this`
    if (rhs.value && value && *rhs.value != 0) {
        setValue(*value / *rhs.value);
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
