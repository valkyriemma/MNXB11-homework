#include "myclass.h"

EmmaClass::EmmaClass() : PrivateInt(0) {} //initialize member to zero

EmmaClass::EmmaClass(Int_t RandomInt){ //empty for now
}

EmmaClass::~EmmaClass() {} //destructor 

ClassImp(EmmaClass) //the root thing that accompanies ClassDef