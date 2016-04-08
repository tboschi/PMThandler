//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Apr  1 10:04:35 2016 by ROOT version 5.34/32
// from TTree PMTData8/PMTData8
// found on file: DataR1S0p4.root
//////////////////////////////////////////////////////////

#ifndef PMTH_h
#define PMTH_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class PMTH {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           LastSync;
   Int_t           SequenceID;
   Int_t           StartTime;
   Int_t           CardID;
   Int_t           Channels;
   Int_t           PMTID[4];   //[Channels]
   Int_t           BufferSize;
   Int_t           FullBufferSize;
   UShort_t        Data[160000];   //[FullBufferSize]

   // List of branches
   TBranch        *b_LastSync;   //!
   TBranch        *b_SequenceID;   //!
   TBranch        *b_StartTime;   //!
   TBranch        *b_CardID;   //!
   TBranch        *b_Channels;   //!
   TBranch        *b_PMTID;   //!
   TBranch        *b_BufferSize;   //!
   TBranch        *b_FullBufferSize;   //!
   TBranch        *b_Data;   //!

   PMTH(TTree *tree=0);
   virtual ~PMTH();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Int_t    GetEntryAll(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef PMTH_cxx
PMTH::PMTH(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DataR1S0p4.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("DataR1S0p4.root");
      }
      f->GetObject("PMTData8",tree);

   }
   Init(tree);
}

PMTH::~PMTH()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t PMTH::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Int_t PMTH::GetEntryAll(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry, 1);
}

Long64_t PMTH::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void PMTH::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("LastSync", &LastSync, &b_LastSync);
   fChain->SetBranchAddress("SequenceID", &SequenceID, &b_SequenceID);
   fChain->SetBranchAddress("StartTime", &StartTime, &b_StartTime);
   fChain->SetBranchAddress("CardID", &CardID, &b_CardID);
   fChain->SetBranchAddress("Channels", &Channels, &b_Channels);
   fChain->SetBranchAddress("PMTID", PMTID, &b_PMTID);
   fChain->SetBranchAddress("BufferSize", &BufferSize, &b_BufferSize);
   fChain->SetBranchAddress("FullBufferSize", &FullBufferSize, &b_FullBufferSize);
   fChain->SetBranchAddress("Data", Data, &b_Data);
   Notify();
}

Bool_t PMTH::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void PMTH::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t PMTH::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef PMTH_cxx
