#include <iostream>
#include <string>
#include "Criteria.h"

ostream& operator<<(ostream& output, const Criteria& c)
{
  c.print(output);
  return output;
}


A_Criteria::A_Criteria(const string& a): artist(a){}

bool A_Criteria::matches(const Song& s){
    return s.matches(artist, s.getTitle());
}

void A_Criteria::print(ostream& os)const{
    os<<"Artist name: "<<artist<<endl;
}



C_Criteria::C_Criteria(const string& c): category(c){}

bool C_Criteria::matches(const Song& s){
    return s.getCategory() == category;
}

void C_Criteria::print(ostream& os) const{
    os<<"Category name: "<<category<<endl;
}



AorC_Criteria::AorC_Criteria(const string& artist, const string& category): A_Criteria::A_Criteria(artist), C_Criteria::C_Criteria(category){}

bool AorC_Criteria::matches(const Song& s){
    return A_Criteria::matches(s) && C_Criteria::matches(s);
}

void AorC_Criteria::print(ostream& os) const{
    A_Criteria::print(os);
    C_Criteria::print(os);
}


