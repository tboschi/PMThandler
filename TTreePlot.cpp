#include "TTreePlot.h"

TTreePlot::TTreePlot():Tool(){}


bool TTreePlot::Initialise(std::string configfile, DataModel &data){

  if(configfile!="")  m_variables.Initialise(configfile);
  //m_variables.Print();

  m_data= &data;

  m_variables.Get("fname", sFname);
  m_variables.Get("branch", sBranch);
  m_variables.Get("row", row);
  m_variables.Get("col", col);
  m_variables.Get("xtime", xtime);
  if (row*col < m_data->DMvector.size())
	  Log("There are more channels than pads. Some channels may not be drawn\n",0,0);

  return true;
}


bool TTreePlot::Execute()
{
	

  return true;
}


bool TTreePlot::Finalise(){

	tF1 = new TFile(sFname.c_str(), "READ");
	tF1->GetObject("PSEC", ttree);

	TCanvas c1 ("test","test");
	c1.Divide(col, row);
	for (int i = 0; i < col*row; i++)
	{
		ssRoot.str("");
		ssRoot.clear();
		c1.cd(i+1);
		c1.SetGrid();
		ssRoot << sBranch;
		if (xtime) ssRoot << i << ":time";
		else ssRoot << i;
//		ttree->SetTitle(ssRoot.str().c_str());
		std::cout << ssRoot.str() << std::endl;
		ttree->Draw(ssRoot.str().c_str(), "", "AL");
	}
	ttree->Print();
	c1.SaveAs("PSEC.C");
	tF1->Close();

	return true;
}
