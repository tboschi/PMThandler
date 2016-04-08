#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "PMTH.h"
#include "TH1F.h"

int main(int argc, char** argv)
{

	std::string def = "passTE";
	if (argc > 1) def = argv[1];
	std::ifstream fin(def.c_str());
	std::stringstream ssL;
	std::string Line, Path, Ntree, hName, hTime, rOut;

	while (getline(fin, Line))
	{
		if (Line[0] == '#') continue;
		else
		{
			ssL.str("");
			ssL.clear();
			ssL << Line;
			ssL >> Path;
			ssL >> Ntree;
			ssL >> hName;
			ssL >> hTime;
			ssL >> rOut;
		}
	}
	fin.close();

	TFile* f = new TFile(Path.c_str());
	TTree* tree;
	f->GetObject(Ntree.c_str(), tree);

	PMTH* PMT = new PMTH(tree);

	std::vector<TH1F*> tplot;
	TH1F* hist, *htim;
	
	TFile tFout (rOut.c_str(), "RECREATE");
	if (tFout.IsZombie()) return 1;
	tFout.cd();

	int n = PMT->fChain->GetEntriesFast();
	std::cout << "GetEntriesFast " << n << std::endl;
	for (int i = 0; i < n; i++)
	{
		int ret = PMT->GetEntry(i);
		for (int j = 0; j < 4; j++)
		{
			ssL.str("");
			ssL.clear();
			ssL << hName << '_' << PMT->CardID;
			ssL << '_' << j;
			hist = new TH1F(ssL.str().c_str(), ssL.str().c_str(), 100, 300, 400);
			ssL.str("");
			ssL.clear();
			ssL << hTime << '_' << PMT->CardID;
			ssL << '_' << j;
			htim = new TH1F(ssL.str().c_str(), ssL.str().c_str(), 1000, 0, 40000);

			for (int k = 0; k < 40000; k++)
			{
				hist->Fill(PMT->Data[40000*j + k]);
				htim->Fill(k, PMT->Data[40000*j + k]);
			}
			hist->Write();
			htim->SetOption("C");
			htim->Write();
			tplot.push_back(hist);
			tplot.push_back(htim);
		}
	}

	tFout.Close();
	std::cout << tplot.size() << std::endl;

	return 0;
}
