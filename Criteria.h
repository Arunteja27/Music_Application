#ifndef CRITERIA_H
#define CRITERIA_H
#include "Song.h"
#include "defs.h"
#include <iostream>
#include <string>

class Criteria{

    friend ostream& operator<<(ostream&, const Criteria& c);

    public:
       
        virtual bool matches(const Song&) = 0;
        virtual void print(ostream&) const  = 0;

};

class A_Criteria : virtual public Criteria{

    public:
        A_Criteria(const string& a);
    
        virtual bool matches(const Song& s);

        virtual void print(ostream& os) const;

    private:
        string artist;
};

class C_Criteria: virtual public Criteria{

    public:
        C_Criteria(const string& c);
        
        virtual bool matches(const Song& s);

        virtual void print(ostream& os)const;


    private:
        string category;

};

class AorC_Criteria: public A_Criteria, public C_Criteria{
    public:
        AorC_Criteria(const string& artist, const string& category);
        
        virtual bool matches(const Song& s);

        virtual void print(ostream& os) const;


};



#endif