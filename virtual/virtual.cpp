/*
 * =====================================================================================
 *
 *       Filename:  virtual.cpp
 *
 *    Description:  i
 *
 *        Version:  1.0
 *        Created:  30/05/19 10:28:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Person
{
protected:
    string name;
    short age;
public:
    virtual void getdata()
    {
    }

    virtual void putdata()
    {
    }
};

class Professor : public Person
{
private:
    short get_id()
    {
        static short cur_id = 1;

        return cur_id++;
    }
protected:
    short publications;
    short id;
public:
    Professor()
    {
        id = get_id();
    }
    void getdata()
    {
        cin >> name;
        cin >> age;
        cin >> publications;
    }


    void putdata()
    {
        cout << name << " " << age << " " << publications << " " << id << endl;
    }
};

class Student : public Person
{
private:
    short get_id()
    {
        static short cur_id = 1;

        return cur_id++;
    }
protected:
    short marks[6];
    short id;
public:
    Student()
    {
        id = get_id();
    }
    void getdata()
    {
        cin >> name;
        cin >> age;

        for (short i ; i < 6 ; i++)
        {
            cin >> marks[i];
        }
    }

    void putdata()
    {
        short sum = 0;
        for(short i = 0; i < 6; sum+=marks[i++]);

        cout << name << " " << age << " " << sum  << " " << id << endl;
    }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
