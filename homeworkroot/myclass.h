#pragma once
#include "TObject.h"
#include <cmath>

class EmmaClass : public TObject {
    public:
        EmmaClass(); // default
        EmmaClass(Int_t RandomInt); //constructor with paramaters using root type
        virtual ~EmmaClass(); //destructor

        double px;
        double py;
        double pz;
        double magnitude;
    
        void findMagnitude(){
            magnitude = std::sqrt(px*pz + py*py + pz*pz);
        }//added px py pz and magnitude as per instruction on pdf!
        //asked chat gpt what the calculation would be

    private:
        Int_t PrivateInt; //private member variable

    ClassDef(EmmaClass, 1); //my_class, where 1 = the version (pg 17 lecture 8 slides)
};