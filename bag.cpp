/*****************************************************************
 *   AUTHOR          : Josh McDermott, Jack Hawley
 *   Lab 2           : Bag Class
 *   CLASS           : CS003A
 *   SECTION         : MW: 9:45 - 11:10AM, TR: 9:45 - 11:50AM
 *   Due Date        : 02/20/2020
 ******************************************************************/

#include "bag.h"
#include <algorithm>
#include <iostream>

/**************************************************************
 * bag::bag()
 * ____________________________________________________________
 * This function initializes the container in an empty state.
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * New empty bag created.
 *************************************************************/
bag::bag():used(0){}

/*********************************************************
 * bag::size_type bag::count(const value_type& target) const
 * ______________________________________________________
 * This function returns the quantity of the specified
 * value in the bag.
 * ______________________________________________________
 * Pre-Condition
 *  bag exists
 * Post-Condition
 *  count size_type is returned.
 ********************************************************/
bag::size_type bag::count(const value_type& target) const
//IN - (value_type) the value to count
{
    size_type answer;
    size_type i;
    answer = 0;
    // PROCESSING - iterate through used, increment answer if match.
    for (i = 0; i < used; ++i)
        if(target == data[i])
            ++answer;
    return answer;
}

/*********************************************************
 * void bag::insert(const value_type& entry)
 * ______________________________________________________
 * This function inserts the user inputted data into the
 * bag.
 * ______________________________________________________
 * Pre-Condition
 *  bag exists
 *  bag size is less than capacity
 * Post-Condition
 *  entry is inserted into the bag
 ********************************************************/
void bag::insert(const value_type& entry)
//IN - (value_type) the value to insert
{

    assert(size() < CAPACITY);
    //PROCESSING - insert entry into data array at used
    data[used] = entry;
    ++used;
}


/*********************************************************
 * bool bag::erase_one(const value_type& target)
 * ______________________________________________________
 * This function removes a single copy of the target
 * input by the user and returns true. Otherwise, it
 * returns false.
 * ______________________________________________________
 * Pre-Condition
 *  bag exists
 * Post-Condition
 *  target is removed from bag and true is returned
 *  target was not in bag and false is returned
 ********************************************************/
//provided the target is actually in the bag, function removes
//one copy of target and returns true, otherwise returns false
bool bag::erase_one(const value_type& target)
//IN - (value_type) the value to erase
{

    size_type index;
    index = 0;
    //PROCESSING - increment index while current value not equal
    //             to target
    while((index < used) && (data[index] != target))
    {
        ++index;
    }

    //PROCESSING - return false if end has been reached
    if(index == used)
        return false;

    //PROCESSING - decrement used, removing first found value from
    //             array
    --used;
    data[index] = data[used];
    return true;
}

/*********************************************************
 * bag::size_type bag::erase(const value_type& target)
 * ______________________________________________________
 * This function removes every copy of the target from
 * the bag.
 * ______________________________________________________
 * Pre-Condition
 *  bag exists
 * Post-Condition
 *  instances of target are removed from bag and number
 *  of instances removed is returned
 ********************************************************/
bag::size_type bag::erase(const value_type& target)
//IN - (value_type) the value to erase
{
    size_type index = 0;
    size_type many_removed = 0;

    //PROCESSING - search array for all instances, removing
    //             and incrementing count of removed
    while(index < used)
    {
        if(data[index] == target)
        {
            --used;
            data[index] = data[used];
            ++many_removed;
        }
        else
            ++index;
    }

    return many_removed;
}

/*********************************************************
 * void bag::display()
 * ______________________________________________________
 * This function will output the items in the bag.
 * ______________________________________________________
 * Pre-Condition
 *  bag exists
 * Post-Condition
 *  values of the items in the bag are output
 ********************************************************/
void bag::display()
{
    //PROCESSING - loop and output formatted values
    for (size_type i = 0;i<used;i++)
    {
        std::cout<< data[i];
        if (i!= used-1)
            std::cout << ",";
    }
    std::cout << std::endl;
}

/*********************************************************
 * void bag::operator+=(const bag& addend)
 * ______________________________________________________
 * This function combines the items of the bag on the
 * right hand side to the bag on the left hand side.
 * ______________________________________________________
 * Pre-Condition
 *  bags exist
 * Post-Condition
 *  values of right bag are added to left bag
 ********************************************************/
void bag::operator+=(const bag& addend)
//IN - (bag) the bag to add to the other bag
{
    assert(size() + addend.size() <= CAPACITY);

    std::copy(addend.data, addend.data + addend.used, data + used);
    used += addend.used;
}

/*********************************************************
 * bag bag::operator+(const bag& b)
 * ______________________________________________________
 * This function combines the items of the bags and
 * returns a new bag with the values.
 * ______________________________________________________
 * Pre-Condition
 *  bags exist
 * Post-Condition
 *  new bag is returned with combined contents of bags
 ********************************************************/
bag bag::operator+(const bag& b)
//IN - (bag) the bag to add to the other bag
{
    bag answer;

    assert(this->size() + b.size() <= bag::CAPACITY);

    answer += *this;
    answer += b;
    return answer;
}

/*********************************************************
 * bag bag::operator-(const bag& b)
 * ______________________________________________________
 * This function removes the matching items of the bag on
 * the left hand side from the bag on the right hand side
 * and returns a new bag with the values.
 * ______________________________________________________
 * Pre-Condition
 *  bags exist
 * Post-Condition
 *  new bag is returned with combined contents of bags
 ********************************************************/
bag bag::operator-(const bag& b)
//IN - (bag) the bag to subtract from the other bag
{
    bag answer;
    answer += *this;

    for (size_type i = 0;i<b.used;i++)
    {
        answer.erase_one(b.data[i]);
    }

    return answer;
}

/*********************************************************
 * void bag::operator-=(const bag& b)
 * ______________________________________________________
 * This function removes the items of the bag on the
 * right hand side from the bag on the left hand side.
 * ______________________________________________________
 * Pre-Condition
 *  bags exist
 * Post-Condition
 *  values of right bag are removed from left bag
 ********************************************************/
void bag::operator-=(const bag& b)
//IN - (bag) the bag to subtract from the other bag
{
    for (size_type i = 0;i<b.used;i++)
    {
        erase_one(b.data[i]);
    }
}
