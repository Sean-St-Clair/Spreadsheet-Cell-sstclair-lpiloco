#include "SpreadsheetCell.h"
#include "IntCell.h"
#include "StringCell.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void testIntCell();

void testDoubleCell();

void testStringCell();

template<typename T>
void printCells(vector<vector<unique_ptr<SpreadsheetCell<T>>>> &vec);

int main() {
    testIntCell();
    testDoubleCell();
    testStringCell();

    vector<vector<unique_ptr<SpreadsheetCell<int>>>> intCells;
    vector<unique_ptr<SpreadsheetCell<int>>> intRow;
    intRow.push_back(make_unique<IntCell>());
    intRow.push_back(make_unique<IntCell>(300000));
    intCells.push_back(move(intRow));
    intRow.clear();
    intRow.push_back(make_unique<IntCell>(-5));
    intRow.push_back(make_unique<IntCell>(90));
    intCells.push_back(move(intRow));
    // Create a function to print the 2-D vector }
    // It should work for all subclasses of SpreadsheetCell.
    cout << endl << "Integer cells:" << endl;
    printCells(intCells);

    vector<vector<unique_ptr<SpreadsheetCell<double>>>> doubleCells;
    vector<unique_ptr<SpreadsheetCell<double>>> doubRow;
    doubRow.push_back(make_unique<DoubleCell>());
    doubRow.push_back(make_unique<DoubleCell>(3.7));
    doubleCells.push_back(move(doubRow));
    doubRow.clear();
    doubRow.push_back(make_unique<DoubleCell>(-7.7));
    doubRow.push_back(make_unique<DoubleCell>(4.1));
    doubleCells.push_back(move(doubRow));
    cout << endl << "Double cells:" << endl;
    printCells(doubleCells);

    vector<vector<unique_ptr<SpreadsheetCell<string>>>> stringCells;
    vector<unique_ptr<SpreadsheetCell<string>>> strRow;
    strRow.push_back(make_unique<StringCell>());
    strRow.push_back(make_unique<StringCell>("poobiss"));
    stringCells.push_back(move(strRow));
    strRow.clear();
    strRow.push_back(make_unique<StringCell>("lintflock"));
    strRow.push_back(make_unique<StringCell>("Circulation"));
    stringCells.push_back(move(strRow));
    cout << endl << "String cells:" << endl;
    printCells(stringCells);

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

void testDoubleCell() {
    DoubleCell i1;
    DoubleCell i2(.5);

    DoubleCell i3 = i1 + i2;
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
    if (i3.getValue() != 4.5) {
        cout << "FAILED += test case" << endl;
    }
    i3 -= i1;
    if (i3.getValue() != 4.5) {
        cout << "FAILED -= nullopt test case" << endl;
    }
    i3 *= i2;
    if (i3.getValue() != 2.25) {
        cout << "FAILED *= test case" << endl;
    }
    i3 /= DoubleCell(10);
    if (i3.getValue() != 0.225) {
        cout << "FAILED /= test case" << endl;
    }

    i1.setValue(0.2);
    cout << "Testing DoubleCell print and setNumChars methods" << endl;
    i1.printCell(cout);
    i2.printCell(cout);
    cout << endl;
    i1.setNumChars(5);
    i1.printCell(cout);
    cout << endl << "End testing DoubleCell print and setNumChars methods" << endl;

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
    i1.setValue(.5);
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

void testStringCell() {
//    DoubleCell i1;
//    DoubleCell i2(.5);
//
//    DoubleCell i3 = i1 + i2;
//    if (i3.getValue()) {
//        cout << "FAILED nullopt + test case" << endl;
//    }
//    i3 = i1 - i2;
//    if (i3.getValue()) {
//        cout << "FAILED nullopt - test case" << endl;
//    }
//    i3 = i2 * i1;
//    if (i3.getValue()) {
//        cout << "FAILED nullopt * test case" << endl;
//    }
//    i3.setValue(4);
//    i3 += i2;
//    if (i3.getValue() != 4.5) {
//        cout << "FAILED += test case" << endl;
//    }
//    i3 -= i1;
//    if (i3.getValue() != 4.5) {
//        cout << "FAILED -= nullopt test case" << endl;
//    }
//    i3 *= i2;
//    if (i3.getValue() != 2.25) {
//        cout << "FAILED *= test case" << endl;
//    }
//    i3 /= DoubleCell(10);
//    if (i3.getValue() != 0.225) {
//        cout << "FAILED /= test case" << endl;
//    }
//
//    i1.setValue(0.2);
//    cout << "Testing DoubleCell print and setNumChars methods" << endl;
//    i1.printCell(cout);
//    i2.printCell(cout);
//    cout << endl;
//    i1.setNumChars(5);
//    i1.printCell(cout);
//    cout << endl << "End testing DoubleCell print and setNumChars methods" << endl;
//
//    cout << endl << boolalpha;
//    if (i1 == i2) {
//        cout << "FAILED == test case" << endl;
//    }
//    if (!(i1 != i2)) {
//        cout << "FAILED != test case" << endl;
//    }
//    if (!(i1 < i2)) {
//        cout << "FAILED < test case" << endl;
//    }
//    if (!(i1 <= i2)) {
//        cout << "FAILED <= test case" << endl;
//    }
//    if (i1 > i2) {
//        cout << "FAILED > test case" << endl;
//    }
//    if (i1 >= i2) {
//        cout << "FAILED >= test case" << endl;
//    }
//    i1.setValue(.5);
//    if (!(i1 == i2)) {
//        cout << "FAILED == test case 2" << endl;
//    }
//    if (!(i1 <= i2)) {
//        cout << "FAILED <= test case 2" << endl;
//    }
//    if (!(i1 >= i2)) {
//        cout << "FAILED >= test case 2" << endl;
//    }
}

template<typename T>
void printCells(vector<vector<unique_ptr<SpreadsheetCell<T>>>> &vec) {
    for (int i = 0; i < size(vec); ++i) {
        for (int j = 0; j < size(vec[i]); ++j) {
            vec[i][j]->printCell(cout);
        }
        cout << endl;
    }
    cout << endl;
}