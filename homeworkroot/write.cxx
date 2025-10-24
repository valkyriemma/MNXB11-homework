#include "myclass.h" //my custom class EmmaClass
#include "TFile.h" //needed to write root file
#include "TTree.h" //needed for ttree
#include "TRandom.h" //lets me generate numbers to fill object


void write(){
    //initialize object (as a pointer like the slides?)
    EmmaClass* EmmaObj = nullptr;
    
    //create root file
    TFile* file = TFile::Open("tree_file.root", "RECREATE");
    //named it to fulfill #7 on the assignment pdf 
    
    //create tree
    TTree* tree = new TTree("tree", "Tree with EmmaClass objects");
   
    //associated branches 
    tree->Branch("emmaThing", &EmmaObj);

    //create loop for filling tree with data
    //nEvents wasnt declared so i declare it 
    Int_t nEvents = 10;

    for (Int_t i{0}; i < nEvents; i++){
        EmmaObj = new EmmaClass();
        //fill values from pdf
        //px,py,pz from header file
        EmmaObj->px = gRandom->Gaus(0,.02);
        EmmaObj->py = gRandom->Gaus(0,.02);
        EmmaObj->pz = gRandom->Gaus(0,.02);

        //calculate magnitude
        EmmaObj->findMagnitude(); //in header file

        //fill tree
        tree->Fill();
        //delete
        delete EmmaObj;
    }
    //save tree/file
    tree->Write();
    file->Close();
}