/*****************************************************************
 *   AUTHORS         : Joshua McDermott & Jack Hawley
 *   Lab 2           : Bag Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45-11:10am, TR: 9:45-11:50am
 *   Due Date        : 2/20/2020
 ******************************************************************/

#include "keyed_bag.h"
#include <algorithm>
#include <iostream>

/**************************************************************
 *keyed_bag::keyed_bag():used(0){}
 * ____________________________________________________________
 * This constructor creates a keyed_bag
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * Now have a keyed_bag, with 0 used items.
 *************************************************************/
keyed_bag::keyed_bag():used(0){}

/**************************************************************
 *void keyed_bag::insert(const value_type& entry, int key)
 * ____________________________________________________________
 * This mutator inserts a particular key:value combination.
 * It fails if the key is already in the key list.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag
 *
 * Post-Condition
 * if assertion didn't fail, keybag now has entry and key stored
 *************************************************************/
void keyed_bag::insert(const value_type& entry, // IN - the inValue
                       int key                  // IN - the inKey
                       )
{
    //PROC - ensure size permits and key is unique
    assert(size() < CAPACITY);
    assert(!keys.contains(key));
    keys.insert(key);
    data[used] = entry;
    ++used;
}

/**************************************************************
 *bool keyed_bag::erase_one(int key)
 * ____________________________________________________________
 * This mutator erases a value with the inputted key.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag
 *
 * Post-Condition
 * value:key combo is erased if found and true is returned.
 * returns false if not found.
 *************************************************************/
bool keyed_bag::erase_one(int key)  //IN - the inputted key
{
    if (!keys.contains(key))
        return false;
    size_type indexToRemove = keys.getIndex(key);
    used--;
    data[indexToRemove] = data[used];
    keys.erase_one(key);
    return true;
}

/**************************************************************
 *void keyed_bag::display()
 * ____________________________________________________________
 * This accessor simply displays all of the value:key combinations.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag
 *
 * Post-Condition
 * keyed_bag is displayed
 *************************************************************/
void keyed_bag::display()
{
    for (size_type i = 0;i<used;i++)
    {
        //OUTPUT - key and value
        std::cout << "key: " << keys.get(i) << " value: " <<
                     data[i] << std::endl;

    }
    std::cout << std::endl;
}

/**************************************************************
 *void keyed_bag::operator+=(const keyed_bag& addend)
 * ____________________________________________________________
 * This mutator attempts to add all of the key:value combinations
 * into *this, if it can't add them all in, because of either
 * size or duplicate keys, an assertion fails.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag, addend
 *
 * Post-Condition
 * keyed_bag contains all of the value:key combinations from addend
 *************************************************************/
void keyed_bag::operator+=(const keyed_bag& addend) // IN - the bag to add
{
    bool fullyDistinctSets = true;
    //PROC - determining if key sets are unique
    for (size_type i = 0;i<addend.used;i++)
    {
        if ((keys.contains(addend.keys.get(i))))
            fullyDistinctSets = false;
    }

    //PROC - only continue if size and uniqueness permit
    assert((used + addend.used <= CAPACITY)&& fullyDistinctSets);
    for (size_type i = 0;i<addend.used;i++)
    {
        data[used] = addend.data[i];
        keys.insert(addend.keys.get(i));
        used++;
    }
}

/**************************************************************
 *keyed_bag keyed_bag::operator+(const keyed_bag& b)
 * ____________________________________________________________
 * This function attempts to compute the union of *this and b
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag, b
 *
 * Post-Condition
 * returned keyed_bag contains all of the value:key combinations
 * from both bags if possible, else, an assertion fails
 *************************************************************/
keyed_bag keyed_bag::operator+(const keyed_bag& b)  // IN - the bag to add
{
    keyed_bag answer;
    answer+=*this;
    answer+=b;
    return answer;
}

/**************************************************************
 *keyed_bag keyed_bag::operator-(const keyed_bag& b)
 * ____________________________________________________________
 * This function returns a bag that has all of the elements
 * of *this, with all of the elements that share a key with an
 * element in b removed.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag, b
 *
 * Post-Condition
 * returned keyed_bag contains all of the value:key combinations
 * that were unique to *this
 *************************************************************/
keyed_bag keyed_bag::operator-(const keyed_bag& b)  //IN - the bag to subtract
{
    keyed_bag answer;
    answer += *this;

    for (size_type i = 0;i<b.used;i++)
    {
        answer.erase_one(b.keys.get(i));
    }

    return answer;
}

/**************************************************************
 *void keyed_bag::operator-=(const keyed_bag& b)
 * ____________________________________________________________
 * This function returns *this, with all of the elements that shared
 * a key with an element in b removed.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag, b
 *
 * Post-Condition
 * *this contains all of the value:key combinations
 * that were unique to *this
 *************************************************************/
void keyed_bag::operator-=(const keyed_bag& b) // IN - the bag to subtract
{
    for (size_type i = 0;i<b.used;i++)
    {
        erase_one(b.keys.get(i));
    }
}

/**************************************************************
 *bool keyed_bag::operator==(const keyed_bag &keyed_bagToCompare) const
 * ____________________________________________________________
 * This function returns true iff the two bags have the same size,
 * identical keys, and identical values associated with those keys.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag, keyed_bagToCompare
 *
 * Post-Condition
 * returns true if bags are equal
 *************************************************************/
bool keyed_bag::operator==(const keyed_bag &keyed_bagToCompare) const
//IN - The bag to compare
{

    if (used==keyed_bagToCompare.used)
    {
        for (size_type i = 0;i<keyed_bagToCompare.used;i++)
        {
            //PROC - The bags share a key
            if (keys.contains(keyed_bagToCompare.keys.get(i)))
            {
                //PROC - the value of the shared key in keyed_bagToCompare
                value_type desiredValue = keyed_bagToCompare.data[i];
                size_type desiredIndex =
                        keys.getIndex(keyed_bagToCompare.keys.get(i));
                //PROC - value is expected value
                if (data[desiredIndex] == desiredValue)
                    continue;
                return false;
            }
            else
                return false;
        }
        return true;

    }
    return false;
}

/**************************************************************
 *bool keyed_bag::operator!=(const keyed_bag &keyed_bagToCompare) const
 * ____________________________________________________________
 * This function returns false iff *this == keyed_bagToCompare
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag, keyed_bagToCompare
 *
 * Post-Condition
 * returns true if bags are unequal
 *************************************************************/
bool keyed_bag::operator!=(const keyed_bag &keyed_bagToCompare) const
//IN - the bag to compare
{
    return !(*this==keyed_bagToCompare);
}

/**************************************************************
 *bool keyed_bag::operator < (const keyed_bag &rhs) const
 * ____________________________________________________________
 * This function returns true iff size() < rhs.size()
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag, keyed_bagToCompare
 *
 * Post-Condition
 * returns true if size() < rhs.size()
 *************************************************************/
bool keyed_bag::operator < (const keyed_bag &rhs) const
//IN - the bag to compare
{
    return used < rhs.used;
}

/**************************************************************
 *bool keyed_bag::operator > (const keyed_bag &rhs) const
 * ____________________________________________________________
 * This function returns true iff size() > rhs.size()
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag, keyed_bagToCompare
 *
 * Post-Condition
 * returns true if size() > rhs.size()
 *************************************************************/
bool keyed_bag::operator > (const keyed_bag &rhs) const
//IN - the bag to compare
{
    return used > rhs.used;
}

/**************************************************************
 *bool keyed_bag::operator <= (const keyed_bag &rhs) const
 * ____________________________________________________________
 * This function returns true iff size() <= rhs.size()
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag, keyed_bagToCompare
 *
 * Post-Condition
 * returns true if size() <= rhs.size()
 *************************************************************/
bool keyed_bag::operator <= (const keyed_bag &rhs) const
//IN - the bag to compare
{
    return used <= rhs.used;
}

/**************************************************************
 *bool keyed_bag::operator >= (const keyed_bag &rhs) const
 * ____________________________________________________________
 * This function returns true iff size() >= rhs.size()
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid keyed_bag, keyed_bagToCompare
 *
 * Post-Condition
 * returns true if size() >= rhs.size()
 *************************************************************/
bool keyed_bag::operator >= (const keyed_bag &rhs) const
//IN - the bag to compare
{
    return used >= rhs.used;
}
