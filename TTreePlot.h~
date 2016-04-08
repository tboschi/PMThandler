#ifndef TTreePlot_H
#define TTreePlot_H

#include <string>
#include <iostream>
#include <cstring>
#include <sstream>

#include "Tool.h"

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"

class TTreePlot: public Tool {


 public:

  TTreePlot();
  bool Initialise(std::string configfile,DataModel &data);
  bool Execute();
  bool Finalise();


 private:

  TFile *tF1;
  TTree *ttree;

  std::string sFname;
  std::string sBranch;
  
  std::stringstream ssRoot;

  int row, col;

  bool xtime;


};


#endif
