/*****************************************************************
 *   AUTHORS         : Joshua McDermott & Jack Hawley
 *   Lab 2           : Bag Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45-11:10am, TR: 9:45-11:50am
 *   Due Date        : 2/20/2020
 ******************************************************************/
#include "set.h"
#include <algorithm>
#include <iostream>

/**************************************************************
 *set::set():used(0){}
 * ____________________________________________________________
 * This constructor creates a set
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * Now have a set, with 0 used items.
 *************************************************************/
set::set():used(0){}

/**************************************************************
 *void set::insert(const value_type& entry)
 * ____________________________________________________________
 * This mutator inserts a particular value.
 * It fails if the value is already in the set
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set
 *
 * Post-Condition
 * if assertion didn't fail, set now has entry stored
 *************************************************************/
void set::insert(const value_type& entry) //IN - the entry to add
{
    //PROC - Ensuring size will permit the addition
    assert((size() < CAPACITY)&&!contains(entry));

    data[used] = entry;
    ++used;
}


/**************************************************************
 *bool set::erase_one(const value_type& target)
 * ____________________________________________________________
 * This mutator erases the inputted value if found.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set
 *
 * Post-Condition
 * the set no longer contains the target
 *************************************************************/
bool set::erase_one(const value_type& target) // IN - the entry to erase
{
    size_type index;
    for (index = 0;index<used;index++)
    {
        if (data[index] == target)
        {
            --used;
            //PROC - replacing last element with target
            data[index] = data[used];
            return true;
        }
    }
    return false;
}

/**************************************************************
 *bool set::subset(const set& inSet)
 * ____________________________________________________________
 * This accessor determines if *this is a subset of inSet
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set
 *
 * Post-Condition
 * returns true if the set is a valid subset
 *************************************************************/
bool set::subset(const set& inSet) // IN - the set that must contain *this
{
    //PROC - determining if the inSet has each element
    for (size_type i=0;i<used;i++)
    {
        if (!inSet.contains(data[i]))
            return false;
    }
    return true;
}

/**************************************************************
 *bool set::proper_subset(const set& inSet)
 * ____________________________________________________________
 * This accessor determines if *this is a proper subset of inSet
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set
 *
 * Post-Condition
 * returns true if the set is a valid subset && they are not ==
 *************************************************************/
bool set::proper_subset(const set& inSet)
// IN - the set that must contain *this
{
    return ((*this).subset(inSet)&&(*this!=inSet));
}

/**************************************************************
 *bool set::contains(const value_type& target) const
 * ____________________________________________________________
 * This accessor determines if the set contains the target
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set
 *
 * Post-Condition
 * returns true if the set contains the target
 *************************************************************/
bool set::contains(const value_type& target) const
//IN - the target to search for
{
    size_type index;
    for (index = 0;index<used;index++)
    {
        if (data[index] == target)
        {
            return true;
        }
    }
    return false;
}

/**************************************************************
 *void set::display()
 * ____________________________________________________________
 * This accessor simply displays all of the values.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set
 *
 * Post-Condition
 * set is displayed
 *************************************************************/
void set::display()
{
    //OUTPUT - displaying values
    for (size_type i = 0;i<used;i++)
    {
        std::cout<< data[i];
        if (i!= used-1)
            std::cout << ",";
    }
    std::cout << std::endl;
}

/**************************************************************
 *void set::operator+=(const set& addend)
 * ____________________________________________________________
 * This mutator attempts to add all of the addends values to *this
 * if it can't add them all in, because of either
 * size or duplicate values, an assertion fails.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set, addend
 *
 * Post-Condition
 * *this contains all of the values from addend
 *************************************************************/
void set::operator+=(const set& addend) //IN - the set to add
{
    bool fullyDistinctSets = true;
    //PROC - Determining if sets are unique
    for (size_type i = 0;i<addend.used;i++)
    {
        if (contains(addend.data[i]))
            fullyDistinctSets = false;
    }
    //PROC - Ensuring sets are unique
    assert((used + addend.used <= CAPACITY) && fullyDistinctSets);
    for (size_type i = 0;i<addend.used;i++)
    {
        data[used]=addend.data[i];
        used++;
    }
}

/**************************************************************
 *set set::operator+(const set& s)
 * ____________________________________________________________
 * This function attempts to compute the union of *this and s
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set, addend
 *
 * Post-Condition
 * returned set contains all of the values from *this and addend
 *************************************************************/
set set::operator+(const set& s)//IN - the set to add
{
    set answer;
    answer+=*this;
    answer+=s;
    return answer;
}

/**************************************************************
 *set set::operator-(const set& s)
 * ____________________________________________________________
 * This function returns a set that has all of the elements
 * of *this, with all of the elements from s removed
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set, s
 *
 * Post-Condition
 * returned set contains all of the values that were unique to *this
 *************************************************************/
set set::operator-(const set& s) //IN - the set to subtract
{
    set answer;
    answer += *this;

    for (size_type i = 0;i<s.used;i++)
    {
        answer.erase_one(s.data[i]);
    }

    return answer;
}

/**************************************************************
 *void set::operator-=(const set& s)
 * ____________________________________________________________
 * This function removes all of the elements found in s from *this
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set, s
 *
 * Post-Condition
 * *this contains all of the values that were unique to *this
 *************************************************************/
void set::operator-=(const set& s) //IN - the set to compare
{
    for (size_type i = 0;i<s.used;i++)
    {
        erase_one(s.data[i]);
    }
}

/**************************************************************
 *bool set::operator==(const set &setToCompare) const
 * ____________________________________________________________
 * This function returns true iff the two bags have the same size,
 * and identical values.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set, setToCompare
 *
 * Post-Condition
 * returns true if bags are equal
 *************************************************************/
bool set::operator==(const set &setToCompare) const
//IN - the set to compare
{

    if (used==setToCompare.used)
    {
        for (size_type i = 0;i<used;i++)
        {
            //PROC - if data is in set
            if (setToCompare.contains(data[i]))
                continue;
            else
                return false;
        }
        return true;

    }
    return false;
}

/**************************************************************
 *bool set::operator!=(const set &setToCompare) const
 * ____________________________________________________________
 * This function returns false iff the two bags have the same size,
 * and identical values.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set, setToCompare
 *
 * Post-Condition
 * returns false iff bags are equal
 *************************************************************/
bool set::operator!=(const set &setToCompare) const
//IN - the set to compare
{
    return !(*this==setToCompare);
}

/**************************************************************
 *bool set::operator < (const set &rhs) const
 * ____________________________________________________________
 * This function returns true iff size() < rhs.size()
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set rhs
 *
 * Post-Condition
 * returns true if size() < rhs.size()
 *************************************************************/
bool set::operator < (const set &rhs) const
//IN - the set to compare
{
    return used < rhs.used;
}

/**************************************************************
 *bool set::operator > (const set &rhs) const
 * ____________________________________________________________
 * This function returns true iff size() > rhs.size()
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set rhs
 *
 * Post-Condition
 * returns true iff size() > rhs.size()
 *************************************************************/
bool set::operator > (const set &rhs) const
//IN - the set to compare
{
    return used > rhs.used;
}

/**************************************************************
 *bool set::operator <= (const set &rhs) const
 * ____________________________________________________________
 * This function returns true iff size() <= rhs.size()
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set rhs
 *
 * Post-Condition
 * returns true if size() <= rhs.size()
 *************************************************************/
bool set::operator <= (const set &rhs) const
//IN - the set to compare
{
    return used <= rhs.used;
}

/**************************************************************
 *bool set::operator >= (const set &rhs) const
 * ____________________________________________________________
 * This function returns true iff size() >= rhs.size()
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set rhs
 *
 * Post-Condition
 * returns true if size() >= rhs.size()
 *************************************************************/
bool set::operator >= (const set &rhs) const
//IN - the set to compare
{
    return used >= rhs.used;
}

/**************************************************************
 *set::value_type set::get(size_type index) const
 * ____________________________________________________________
 * This function returns the element at the specified index
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set
 *
 * Post-Condition
 * returns the value at the specified index
 *************************************************************/
set::value_type set::get(size_type index) const
//IN - the index to be accessed.
{
    return data[index];
}

/**************************************************************
 *set::size_type set::getIndex(const value_type& target) const
 * ____________________________________________________________
 * This function returns the index of the specified target value.
 * ___________________________________________________________
 * Pre-Condition
 * Have a valid set that contains the target, else assertion fails
 *
 * Post-Condition
 * returns the index of the specified target
 *************************************************************/
set::size_type set::getIndex(const value_type& target) const
//IN - target to find.
{
    //PROC - ensure value is inside of data
    assert(contains(target));
    size_type i;
    for (i = 0; i < used;i++)
    {
        if (data[i] == target)
            break;
    }
    return i;
}
