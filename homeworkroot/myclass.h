#pragma once
#include "TObject.h"

class EmmaClass : public TObject {
    public:
        EmmaClass(); // default
        EmmaClass(Int_t RandomInt); //constructor with paramaters using root type
        virtual ~EmmaClass(); //destructor
    
    private:
        Int_t PrivateInt; //private member variable

    ClassDef(EmmaClass, 1); //my_class, where 1 = the version (pg 17 lecture 8 slides)
};