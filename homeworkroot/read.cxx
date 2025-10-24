#include "myclass.h" //emma class
#include "TFile.h" //file
#include "TTree.h" //tree
#include "TH2.h" //needed for histogram
#include "TCanvas.h" //drawing

void read(){
    //initialize object
    EmmaClass* EmmaObj = nullptr;
    
    //open fle
    TFile* file = TFile::Open("tree_file.root");
    
    //get tree
    TTree* tree = (TTree*)file->Get("tree");

    //set branch address
    tree->SetBranchAddress("emmaThing", &EmmaObj);

    //#8 write my hsitogram stuff before filling it (order of operations etc)
    TH2F* Momentum = new TH2F("Momentum", "px vs py; px; py", 100, -0.1, 01, 100, -0.1, 0.1);

    //write for loop
    Int_t N = tree->GetEntries(); //needed to define N before using it 
    for (Int_t i= 0; i < N; i++){
        //loop over whole tree
        tree->GetEntry(i);
        //something (in this case fill the plot)
        Momentum->Fill(EmmaObj->px, EmmaObj->py);
    }
    
    //actually DRAW the histogram
    Momentum->Draw();

    //#9: scatterplot of px*py vs pz and criterion of magntitude using ttree::draw
    tree->Draw("px*py:pz", "magnitude > 0.0123456789");
}