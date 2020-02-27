/*****************************************************************
 *   AUTHORS         : Joshua McDermott & Jack Hawley
 *   Lab 2           : Bag Class
 *   CLASS           : CS008
 *   SECTION         : MW: 9:45-11:10am, TR: 9:45-11:50am
 *   Due Date        : 2/20/2020
 ******************************************************************/
#include <iostream>
#include <cstdlib>
#include "bag.h"
#include "set.h"
#include "keyed_bag.h"

using namespace std;

int main()
{

    //KEYED BAG TESTING//
    cout << "***********************************" << endl;
    cout << "KEYED_BAG TESTING: \n";
    cout << "***********************************" << endl;
    cout << "kb 1: \n";
    keyed_bag k1;

    k1.insert(4,1);
    k1.insert(5,2);
    k1.insert(5,3);
    k1.insert(8,4);

//    //Assertion would fail
//    k1.insert(6,2);

    k1.display();
    cout << "Testing erase_one(key = 2): \n";
    k1.erase_one(2);
    cout << "kb 1: \n";
    k1.display();

    cout << "Adding more values: \n";
    k1.insert(10,2);
    k1.insert(9,5);
    cout << "kb 1: \n";
    k1.display();

    cout << "Making identical kb to test operators: \n";
    keyed_bag k2;
    k2.insert(4,1);
    k2.insert(10,2);
    k2.insert(5,3);
    k2.insert(8,4);
    k2.insert(9,5);
    cout << "kb 2: \n";
    k2.display();

    cout << "testing < operator (k1<k2, 0 = false, 1 = true): \n";
    cout << (k1<k2) << "\n";
    cout << "testing > operator (k1>k2): \n";
    cout << (k1>k2)<< "\n";
    cout << "testing <= operator (k1<=k2): \n";
    cout << (k1<=k2)<< "\n";
    cout << "testing >= operator (k1>=k2): \n";
    cout << (k1>=k2)<< "\n";
    cout << "testing == operator (k1==k2): \n";
    cout << (k1==k2)<< "\n";
    cout << "testing != operator (k1!=k2): \n";
    cout << (k1!=k2)<< "\n\n";

    cout << "testing union operator: \n";
    cout << "creating blank kb 4\n";
    cout << "creating kb 3: \n";
    keyed_bag k3;
    k3.insert(7,7);
    k3.insert(10,6);
    k3.display();
    keyed_bag k4;
    cout << "testing union operator kb 4 = kb 3 + kb 2: \n";
    k4 = k3 + k2;
    cout << "kb 4: \n";
    k4.display();

    cout << "testing += operator kb 1 += kb 3: \n";
    cout << "kb 1 original: \n";
    k1.display();
    cout << "kb 1 += kb 3: \n";
    cout << "kb 1 current: \n";
    k1+=k3;
    k1.display();

    cout << "testing subtraction operator: \n";
    cout << "adding to kb 2 first: \n";
    k2.insert(8,7);
    cout << "testing subtraction operator kb 5 = kb 3 - kb 2: \n";
    cout << "kb 3 current: \n";
    k3.display();
    cout << "kb 2 current: \n";
    k2.display();
    cout << "kb 5: \n";
    keyed_bag k5;
    k5 = k3-k2;
    k5.display();

    cout << "testing -= operator kb 3 -= kb 2: \n";
    cout << "kb 3 original: \n";
    k3.display();
    cout << "kb 2 original: \n";
    k2.display();
    cout << "kb 3 -= kb 2: \n";
    cout << "kb 3 current: \n";
    k3-=k2;
    k3.display();
    cout << endl;


    // BAG TESTING//
    cout << "***********************************" << endl;
    cout << "BAG TESTING: \n";
    cout << "***********************************" << endl;
    // INSERT and DISPLAY TEST
    cout << "Testing Bag: insert and display" << endl;
    bag b1;
    b1.insert(1);
    b1.insert(2);
    b1.insert(3);
    b1.insert(4);
    b1.insert(4);
    b1.insert(6);
    cout << "bag b1: \n";
    b1.display();

    // ERASE_ONE TEST
    cout << endl;
    cout << "Testing Bag: erase_one() with 1,4,4,6" << endl;
    b1.erase_one(1);
    cout << "b1: ";
    b1.display();

    b1.erase_one(4);
    cout << "b1: ";
    b1.display();

    b1.erase_one(4);
    cout << "b1: ";
    b1.display();

    b1.erase_one(6);
    cout << "b1: ";
    b1.display();


    //Creating new bags
    bag x;
    bag y;
    x.insert(1);
    x.insert(2);
    x.insert(3);
    x.insert(4);
    x.insert(5);
    x.insert(3);

    y.insert(10);
    y.insert(20);
    y.insert(3);
    y.insert(30);
    y.insert(30);
    y.insert(30);

    cout << "Creating two new bags. Bag x: ";
    x.display();

    cout << "Bag y: ";
    y.display();

    cout << endl;

    // COUNT TEST

    cout << "Testing count" << endl;
    cout << "counting 30's in y" << endl;
    bag::size_type instances = 0;
    instances = y.count(30);
    cout << "There are " << instances << " instances of \"30\" in y." << endl;
    cout << endl;

    // SUBTRACTION TEST
    cout << "Testing subtraction" << endl;
    bag z;
    cout << "x: ";
    x.display();
    cout << "y: ";
    y.display();
    cout << "z = x - y"<<endl;
    z = x-y;
    cout << "z = ";
    z.display();
    cout << endl;

    // -= TEST
    cout << "Testing -=" << endl;
    cout << "Performed x-=y"<<endl;
    x-=y;
    cout << "x: ";
    x.display();
    cout << "y: ";
    y.display();

    // ERASE TEST
    cout << "Testing erase:" << endl;
    cout << "bag y: ";
    y.display();
    cout << endl;
    cout << "Erasing 30 from bag y" << endl;
    y.erase(30);
    cout << "resulting y: ";
    y.display();
    cout << endl;

    // Addition TEST

    cout << "Testing +:" << endl;
    cout << "bag x: ";
    x.display();
    cout << endl;
    cout << "bag y: ";
    y.display();
    cout << endl;
    bag addSum;
    cout << "addSum = x + y" << endl;
    addSum = x + y;
    cout << "addSum = ";
    addSum.display();
    cout << endl;

    // += TEST
    cout << "Testing +=" << endl;
    cout << "x before: ";
    x.display();
    cout << "y before: ";
    y.display();
    cout << "x += y" << endl;
    x += y;
    cout << "x = ";
    x.display();
    cout << endl;


    //SET TESTING//
    cout << "***********************************" << endl;
    cout << "SET TESTING: \n";
    cout << "***********************************" << endl;
    cout << "set 1: \n";
    set s1;

    s1.insert(4);
    s1.insert(5);
    s1.display();

//    //Assertion would fail
//    s1.insert(5);

    cout << "Testing erase_one(5): \n";
    s1.erase_one(5);
    cout << "set 1: \n";
    s1.display();

    cout << "Adding more values: \n";
    s1.insert(6);
    s1.insert(7);
    cout << "set 1: \n";
    s1.display();

    cout << "Making identical set to test operators: \n";
    set s2;
    s2.insert(4);
    s2.insert(6);
    s2.insert(7);
    cout << "set 2: \n";
    s2.display();

    cout << "testing < operator (s1<s2): \n";
    cout << (s1<s2) << "\n";
    cout << "testing > operator (s1>s2): \n";
    cout << (s1>s2)<< "\n";
    cout << "testing <= operator (s1<=s2): \n";
    cout << (s1<=s2)<< "\n";
    cout << "testing >= operator (s1>=s2): \n";
    cout << (s1>=s2)<< "\n";
    cout << "testing == operator (s1==s2): \n";
    cout << (s1==s2)<< "\n";
    cout << "testing != operator (s1!=s2): \n";
    cout << (s1!=s2)<< "\n";

    cout << "testing subset (s1 is a subset of s2, s1.subset(s2)): \n";
    cout << s1.subset(s2)<< "\n";
    cout << "testing proper subset (s1 is a proper subset of s2, "
            "s1.proper_subset(s2)): \n";
    cout << s1.proper_subset(s2)<< "\n";

    cout << "testing union operator: \n";
    cout << "creating blank set 4\n";
    cout << "creating set 3: \n";
    set s3;
    s3.insert(9);
    s3.insert(8);
    s3.display();
    set s4;
    cout << "testing union operator set 4 = set 3 + set 2: \n";
    s4 = s3 + s2;
    cout << "set 4: \n";
    s4.display();

    cout << "testing += operator set 1 += set 3: \n";
    cout << "set 1 original: \n";
    s1.display();
    cout << "set 1 += set 3: \n";
    cout << "set 1 current: \n";
    s1+=s3;
    s1.display();

    cout << "testing subtraction operator: \n";
    cout << "adding to set 2 first: \n";
    s2.insert(8);
    cout << "testing subtraction operator (set 5 = set 3 - set 2): \n";
    cout << "set 3 current: \n";
    s3.display();
    cout << "set 2 current: \n";
    s2.display();
    cout << "set 5: \n";
    set s5  = s3-s2;
    s5.display();

    cout << "testing -= operator set 3 -= set 2: \n";
    cout << "set 3 original: \n";
    s3.display();
    cout << "set 2 original: \n";
    s2.display();
    cout << "set 3 -= set 2: \n";
    cout << "set 3 current: \n";
    s3-=s2;
    s3.display();

    cout << endl;
    return EXIT_SUCCESS;
}



