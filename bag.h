/*****************************************************************
 *   AUTHOR          : Josh McDermott, Jack Hawley
 *   Lab 2           : Bag Class
 *   CLASS           : CS003A
 *   SECTION         : MW: 9:45 - 11:10AM, TR: 9:45 - 11:50AM
 *   Due Date        : 02/20/2020
 ******************************************************************/

#ifndef BAG_H
#define BAG_H

#include <cassert>
#include <stddef.h>

/**************************************************************************
 *
 * bag Class
 *   This class implements a container class for holding a collection of
 *   items. It has a variety of associated functions, and two private
 *   member variables -- one in which data is stored, the other to hold the
 *   number of items in the bag.
 *
 **************************************************************************/

class bag
{
public:
    //value_type is an alias of int
    typedef int value_type;

    //size_t data type is an integer data type that can hold
    //only non-negative numbers.  Each C++ implementation
    //guarantees that the values of the size_t type can hold the
    //size of any variable that can be declared on your machine.
    typedef size_t size_type;

    static const size_type CAPACITY = 30;


    /********************************
     **  CONSTRUCTOR  **
     ********************************/
    /*******************************************
     *bag()
     * Constructor:Intialize class attributes
     * Parameters: None
     * Return: None
     *****************************************/
    bag();



    /********************************
     **  ACCESSORS  **
     ********************************/
    /*******************************************
     *size_type size() const
     * Accessor: returns number of values in bag.
     * Parameters: None
     * Return: size_type
     *****************************************/
    size_type size() const{ return used;}

    /*******************************************
     *size_type count(const value_type& target) const
     * Accessor: returns quantity of specified value in bag.
     * Parameters: target (value_type) IN - value to count.
     * Return: size_type
     *****************************************/
    size_type count(const value_type& target) const;
    //IN - (value_type) the value to count

    /***********************************************
     *void display()
     * Accessor: This will output the updated information
     * Parameters: None
     * Return: Outputs the items in the bag
     **********************************************/
    void display();


    /********************************
     **  MUTATORS  **
     ********************************/
    /****************************************************************
     *void insert(const value_type& entry)
     * Mutator: Gets the user inputted data and inserts it into the
     * bag.
     * Parameters: value_type entry IN - User inputted value
     * Return: none
     **************************************************************/
    void insert(const value_type& entry);
    //IN - (value_type) the value to insert

    /****************************************************************
     *bool erase_one(const value_type& target)
     * Mutator: Gets the user inputted data and removes one copy of
     * that specified target, returning true. Returns false
     * otherwise.
     * Parameters: value_type target IN - User inputted value
     * Return: bool
     **************************************************************/
    //provided the target is actually in the bag, function removes
    //one copy of target and returns true, otherwise returns false
    bool erase_one(const value_type& target);
    //IN - (value_type) the value to erase

    /****************************************************************
     *size_type erase(const value_type& target)
     * Mutator: Gets the user inputted data and removes all copies of
     * that specified target. Returns how many copies were removed.
     * Parameters: value_type target IN - User inputted value
     * Return: size_type
     **************************************************************/
    //removes all copies of the target and return value tells how
    //many copies were removed
    size_type erase(const value_type& target);
    //IN - (value_type) the value to erase

    /****************************************************************
     *bag operator+(const bag& b)
     * Mutator: Combines the values of two bags. Returns all of their
     * values together in a new larger bag.
     * Parameters: bag b IN - User specified bag
     * Return: bag
     **************************************************************/
    //Union operator - the union of two bags is a new larger bag that contains
    //all the numbers in the first bag plus all the numbers in the second bag
    bag operator+(const bag& b);
    //IN - (bag) the bag to add to the other bag

    /****************************************************************
     *void operator+=(const bag& addend)
     * Mutator: Combines the values of two bags into the values of
     * the first bag.
     * Parameters: bag addend IN - User specified bag
     * Return: none
     **************************************************************/
    //overloading the += operator to activate the += member function of the
    //first bag and use the second bag as the argument
    //ex first_bag += second_bag;
    void operator+=(const bag& addend);
    //IN - (bag) the bag to add to the other bag

    /****************************************************************
     *bag operator-(const bag& b)
     * Mutator: Subtracts the values of the second bag from the
     * corresponding values in the first bag. Returns the remaining
     * values together in a new bag.
     * Parameters: bag b IN - User specified bag
     * Return: bag
     **************************************************************/
    bag operator-(const bag& b);
    //IN - (bag) the bag to subtract from the other bag

    /****************************************************************
     *void operator-=(const bag& b)
     * Mutator: Subtracts the values of the second bag from the
     * corresponding values in the first bag.
     * Parameters: bag b IN - User specified bag
     * Return: none
     **************************************************************/
    void operator-=(const bag& b);
    //IN - (bag) the bag to subtract from the other bag

private:
    value_type data[CAPACITY]; //  IN/OUT The underlying array that data
    size_type used;            //  IN/OUT The num of used spots in the array
};

#endif
