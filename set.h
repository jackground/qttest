/*****************************************************************
 *   AUTHORS         : Joshua McDermott & Jack Hawley
 *   Lab 2           : Bag Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45-11:10am, TR: 9:45-11:50am
 *   Due Date        : 2/20/2020
 ******************************************************************/

#ifndef SET_H
#define SET_H

#include <cassert>
#include <stddef.h>

/**************************************************************************
 *
 * set Class
 *   This class represents a set. A set is identical to a regular
 *   bag except for the fact that each value in the bag must be unique.
 *
 **************************************************************************/
class set
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
     *set()
     * Constructor:Intializes class attributes
     * Parameters: None
     * Return: None
     *************************************************/
    set();



    /********************************
     **  ACCESSORS  **
     ********************************/
    /*******************************************
     *size_type size() const
     * Accessor: returns the size of the set
     * Parameters: None
     * Return: (size_type) The size of the set
     *****************************************/
    size_type size() const{ return used;}

    /*******************************************
     *bool contains(const value_type& target) const;
     * Accessor: returns true if the set contains the target
     * Parameters: (value_type) target
     * Return: True if the set contains the target
     *****************************************/
    bool contains(const value_type& target) const;
    //IN - the target to search for

    /*******************************************
     *bool operator!=(const set &setToCompare) const;
     * Accessor: returns false if the sets are equal
     * Parameters: (set) setToCompare
     * Return: False if the sets are equal
     *****************************************/
    bool operator!=(const set &setToCompare) const;
    //IN - the set to compare

    /*******************************************
     *bool operator==(const set &setToCompare) const;
     * Accessor: returns true if the sets are equal in size and values
     * Parameters: (set) setToCompare
     * Return: True if the sets are equal
     *****************************************/
    bool operator==(const set &setToCompare) const;
    //IN - the set to compare

    /*******************************************
     *bool proper_subset(const set& inSet);
     * Accessor: returns true if every element in *this
     *   is found in inSet, and the sets are unequal
     * Parameters: (set) inSet
     * Return: True if *this is a proper_subset of inSet
     *****************************************/
    bool proper_subset(const set& inSet);
    //IN - the set that must contain all elements in *this
    //  while not being equal

    /*******************************************
     *bool subset(const set& inSet);
     * Accessor: returns true if every element in *this
     *   is found in inSet
     * Parameters: (set) inSet
     * Return: True if *this is a subset of inSet
     *****************************************/
    bool subset(const set& inSet);
    //IN - the set that must contain all elements in *this

    /****************************************************************
     * bool operator < (const set &rhs) const;
     * Accessor: returns true iff *this.size() < rhs.size()
     * Parameters: (const set) rhs
     * Return: true iff *this.size() < rhs.size()
     **************************************************************/
    bool operator < (const set &rhs) const;
    //IN - the set to compare

    /****************************************************************
     * bool operator > (const set &rhs) const;
     * Accessor: returns true iff *this.size() > rhs.size()
     * Parameters: (const set) rhs
     * Return: true iff *this.size() > rhs.size()
     **************************************************************/
    bool operator > (const set &rhs) const;
    //IN - the set to compare

    /****************************************************************
     * bool operator <= (const set &rhs) const;
     * Accessor: returns true iff *this.size() <= rhs.size()
     * Parameters: (const set) rhs
     * Return: true iff *this.size() <= rhs.size()
     **************************************************************/
    bool operator <= (const set &rhs) const;
    //IN - the set to compare

    /****************************************************************
     * bool operator >= (const set &rhs) const;
     * Accessor: returns true iff *this.size() >= rhs.size()
     * Parameters: (const set) rhs
     * Return: true iff *this.size() >= rhs.size()
     **************************************************************/
    bool operator >= (const set &rhs) const;
    //IN - the set to compare

    /****************************************************************
     * value_type get(size_type index) const;
     * Accessor: returns the value at the specified index.
     * Parameters: (size_type) index
     * Return: the element at the specified index
     **************************************************************/
    value_type get(size_type index) const;
    //IN - the desired index

    /****************************************************************
     * size_type getIndex(const value_type& target) const;
     * Accessor: returns the index of the specified target
     *   an assertion fails if the target is not contained in *this
     * Parameters: (value_type) target
     * Return: the index of the specified target
     **************************************************************/
    size_type getIndex(const value_type& target) const;
    //IN - the desired target

    /****************************************************************
     * void display();
     * Accessor: displays all of the values of the set
     * Parameters: None
     * Return: None
     **************************************************************/
    void display();


    /********************************
     **  MUTATORS  **
     ********************************/
    /****************************************************************
     *void insert(const value_type& entry);
     * Mutator: Inserts the entry into the set
     * Parameters: (value_type) entry
     * Return: None
     **************************************************************/
    void insert(const value_type& entry); // IN - the desired entry

    /****************************************************************
     *bool erase_one(const value_type& target);
     * Mutator: erases the target from the set if possible
     * Parameters: (value_type) target
     * Return: True if value was erased
     **************************************************************/
    bool erase_one(const value_type& target); //IN - the value to be erased

    /****************************************************************
     *set operator+(const set& s);
     * Mutator: computes the union of the two sets
     * Parameters: (const set) s
     * Return: A set representing the union of the two sets, if possible
     **************************************************************/
    set operator+(const set& s);
    //IN - the other set to add

    /****************************************************************
     *void operator+=(const set& addend);
     * Mutator: sets *this = the union of the two sets
     * Parameters: (const set) addend
     * Return: None
     **************************************************************/
    void operator+=(const set& addend);
    //IN - the other set to add

    /****************************************************************
     *set operator-(const set& s);
     * Mutator: returns all of the items from *this, with items that are in b
     * removed.
     * Parameters: (const set) s
     * Return: A set with all of the items from *this, with items
     *  from b removed.
     **************************************************************/
    set operator-(const set& s);
    //IN - the other set

    /****************************************************************
     *set operator-=(const set& s);
     * Mutator: removes all of the items from *this that are in b.
     * Parameters: (const set) s
     * Return: None
     **************************************************************/
    void operator-=(const set& s);
    //IN - the other set



private:
    value_type data[CAPACITY]; //  IN/OUT The underlying array that data
    size_type used;            //  IN/OUT The num of used spots in the array
};
#endif // SET_H
