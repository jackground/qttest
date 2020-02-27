/*****************************************************************
 *   AUTHORS         : Joshua McDermott & Jack Hawley
 *   Lab 2           : Bag Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45-11:10am, TR: 9:45-11:50am
 *   Due Date        : 2/20/2020
 ******************************************************************/

#ifndef KEYED_BAG_H
#define KEYED_BAG_H


#include <cassert>
#include <stddef.h>
#include "set.h"
/**************************************************************************
 *
 * keyed_bag Class
 *   This class represents a keyed bag. A keyed bag is identical to a regular
 *   bag except for the fact that each value in data has an associated key,
 *   and this key must be unique within the bag.
 *
 **************************************************************************/
class keyed_bag
{
public:

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
    /*************************************************
     *keyed_bag()
     * Constructor:Intializes class attributes
     * Parameters: None
     * Return: None
     *************************************************/
    keyed_bag();



    /********************************
     **  ACCESSORS  **
     ********************************/
    /*******************************************
     *size_type size() const
     * Accessor: returns the size of the bag
     * Parameters: None
     * Return: (size_type) The size of the bag
     *****************************************/
    size_type size() const{ return used;}

    /****************************************************************
     *bool operator==(const keyed_bag &keyed_bagToCompare) const;
     * Accessor: true if all values have the same key in both bags,
     *   size() also must match.
     * Parameters: (const keyed_bag) keyed_bagToCompare
     * Return: true iff bags are equal
     **************************************************************/
    bool operator==(const keyed_bag &keyed_bagToCompare) const;
    //IN - the bag to compare

    /****************************************************************
     * bool operator!=(const keyed_bag &keyed_bagToCompare) const;
     * Accessor: false iff *this == keyed_bagToCompare
     * Parameters: (const keyed_bag) keyed_bagToCompare
     * Return: false iff bags are equal
     **************************************************************/
    bool operator!=(const keyed_bag &keyed_bagToCompare) const;
    //IN - the bag to compare

    /****************************************************************
     * bool operator < (const keyed_bag &rhs) const;
     * Accessor: returns true iff *this.size() < rhs.size()
     * Parameters: (const keyed_bag) rhs
     * Return: true iff *this.size() < rhs.size()
     **************************************************************/
    bool operator < (const keyed_bag &rhs) const;
    //IN - the bag to compare

    /****************************************************************
     * bool operator > (const keyed_bag &rhs) const;
     * Accessor: returns true iff *this.size() > rhs.size()
     * Parameters: (const keyed_bag) rhs
     * Return: true iff *this.size() > rhs.size()
     **************************************************************/
    bool operator > (const keyed_bag &rhs) const;
    //IN - the bag to compare

    /****************************************************************
     * bool operator <= (const keyed_bag &rhs) const;
     * Accessor: returns true iff *this.size() <= rhs.size()
     * Parameters: (const keyed_bag) rhs
     * Return: true iff *this.size() <= rhs.size()
     **************************************************************/
    bool operator <= (const keyed_bag &rhs) const;
    //IN - the bag to compare

    /****************************************************************
     * bool operator >= (const keyed_bag &rhs) const;
     * Accessor: returns true iff *this.size() >= rhs.size()
     * Parameters: (const keyed_bag) rhs
     * Return: true iff *this.size() >= rhs.size()
     **************************************************************/
    bool operator >= (const keyed_bag &rhs) const;
    //IN - the bag to compare

    /****************************************************************
     * void display();
     * Accessor: displays all of the keys and values of the bag
     * Parameters: None
     * Return: None
     **************************************************************/
    void display();

    /********************************
     **  MUTATORS  **
     ********************************/
    /****************************************************************
     *void insert(const value_type& entry, int key);
     * Mutator: Inserts the key:value combination into the bag
     * Parameters: (value_type) entry
     *             (int) key
     * Return: None
     **************************************************************/
    void insert(const value_type& entry, //IN - the entry to be passed in
                int key);                //IN - the key of said entry

    /****************************************************************
     *bool erase_one(int key);
     * Mutator: erases the key:value combination with the inputted key
     * Parameters: (int) key
     * Return: True if value was erased
     **************************************************************/
    bool erase_one(int key);  //IN - the key of the element to erase

    /****************************************************************
     *keyed_bag operator+(const keyed_bag& b);
     * Mutator: computes the union of the two bags
     * Parameters: (const keyed_bag) b
     * Return: A keyed_bag representing the union of the two bags, if possible
     **************************************************************/
    keyed_bag operator+(const keyed_bag& b); //IN - the other bag to add

    /****************************************************************
     *void operator+=(const keyed_bag& addend);
     * Mutator: sets *this = the union of the two bags
     * Parameters: (const keyed_bag) addend
     * Return: None
     **************************************************************/
    void operator+=(const keyed_bag& addend); //IN - the other bag to add

    /****************************************************************
     *keyed_bag operator-(const keyed_bag& b);
     * Mutator: returns all of the items from *this, with items that share a
     *   key with an item in b removed.
     * Parameters: (const keyed_bag) b
     * Return: A keyed bag with all of the items from *this, with items
     *  that share a key with an item in b removed.
     **************************************************************/
    keyed_bag operator-(const keyed_bag& b); //IN - the other bag

    /****************************************************************
     *void operator-=(const keyed_bag& b);
     * Mutator: removes all items from *this that share a key with an
     *   item in b
     * Parameters: (const keyed_bag) b
     * Return: None
     **************************************************************/
    void operator-=(const keyed_bag& b); //IN - the other bag

private:

    value_type data[CAPACITY]; //  IN/OUT The underlying array that data
    size_type used;            //  IN/OUT The num of used spots in the array
    set keys;                  //  IN/OUT The set of keys for the values
};


#endif // KEYED_BAG_H
