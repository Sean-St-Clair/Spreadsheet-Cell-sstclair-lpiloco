#include "SpreadsheetCell.h"
#include "IntCell.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

void testIntCell();

int main() {
    testIntCell();

    vector<vector<unique_ptr<SpreadsheetCell<int>>>> cells;
    vector<unique_ptr<SpreadsheetCell<int>>> row;
    row.push_back(make_unique<IntCell>());
    row.push_back(make_unique<IntCell>(300000));
    cells.push_back(move(row));
    row.clear();
    row.push_back(make_unique<IntCell>(-5));
    row.push_back(make_unique<IntCell>(90));
    cells.push_back(move(row));
    // TODO: Create a function to print the 2-D vector
    // It should work for all subclasses of SpreadsheetCell.
    //printCells(cells);

    return 0;
}

void testIntCell() {

    IntCell i1;
    IntCell i2(7.9);

    IntCell i3 = i1 + i2;
    if (i3.getValue()) {
        cout << "FAILED nullopt + test case" << endl;
    }
    i3 = i1 - i2;
    if (i3.getValue()) {
        cout << "FAILED nullopt - test case" << endl;
    }
    i3 = i2 * i1;
    if (i3.getValue()) {
        cout << "FAILED nullopt * test case" << endl;
    }
    i3.setValue(4);
    i3 += i2;
    if (i3.getValue() != 11) {
        cout << "FAILED += test case" << endl;
    }
    i3 -= i1;
    if (i3.getValue() != 11) {
        cout << "FAILED -= nullopt test case" << endl;
    }
    i3 *= i2;
    if (i3.getValue() != 77) {
        cout << "FAILED *= test case" << endl;
    }
    i3 /= IntCell(11);
    if (i3.getValue() != 7) {
        cout << "FAILED /= test case" << endl;
    }

    i1.setValue(4);
    cout << "Testing IntCell print and setNumChars methods" << endl;
    i1.printCell(cout);
    i2.printCell(cout);
    cout << endl;
    i1.setNumChars(5);
    i1.printCell(cout);
    cout << endl << "End testing IntCell print and setNumChars methods" << endl;

    cout << endl << boolalpha;
    if (i1 == i2) {
        cout << "FAILED == test case" << endl;
    }
    if (!(i1 != i2)) {
        cout << "FAILED != test case" << endl;
    }
    if (!(i1 < i2)) {
        cout << "FAILED < test case" << endl;
    }
    if (!(i1 <= i2)) {
        cout << "FAILED <= test case" << endl;
    }
    if (i1 > i2) {
        cout << "FAILED > test case" << endl;
    }
    if (i1 >= i2) {
        cout << "FAILED >= test case" << endl;
    }
    i1.setValue(7);
    if (!(i1 == i2)) {
        cout << "FAILED == test case 2" << endl;
    }
    if (!(i1 <= i2)) {
        cout << "FAILED <= test case 2" << endl;
    }
    if (!(i1 >= i2)) {
        cout << "FAILED >= test case 2" << endl;
    }
}