#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "QmisID_count.h"

//This is the driver script, which becomes our main program
//Here we set the options which we wish to use, which files
//we want to run over and so on.

//the argument decides what input sample we want to run over.
//we give separate names of output files for each set of
//input files.
void anaC(int signal=0)
{
  const char *hstfilename, *sumfilename1, *sumfilename2;
  string name = "data_15_16";

  TChain *chain = new TChain("nominal_Loose");
  QmisID_count m_selec;//declared an instance of our class.

  std::cout<<"Declared chains"<<std::endl;
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data15.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data16.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data17.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data18.root");
     hstfilename="etabins12/60_90/gammastr0/data_all_closure_4sigma.root";//output histogram file

     sumfilename1="etabins12/60_90/gammastr0/ss.data_all_closure_4sigma.txt"; //output text file
     sumfilename2="etabins12/60_90/gammastr0/os.data_all_closure_4sigma.txt"; //output text file
  // }

  std::cout<<"Output files are "<<hstfilename<<" and "<<sumfilename1<<" and "<<sumfilename2<<std::endl;
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName1(sumfilename1);
  m_selec.SetSumFileName2(sumfilename2);
  m_selec.SetVerbose(200);//set verbosity level for output.
  m_selec.SetData(7);//******IMPORTANT***** 0 is MC, 1 data, 2 data with BG subtraction, 3 QmisID reweighting, 4 gammastar region, 5 co region, 6 ttw region, 7 gammastr closure, 8 CO closure, 9 ttw closure
  m_selec.SetSigma(4);
  //this calls the Process function for each event in the chain
  //and runs the m_selec code over it.
  chain->Process(&m_selec);
  

}
void ana4(int signal=0)
{
  const char *hstfilename, *sumfilename1, *sumfilename2;
  string name = "data_15_16";

  TChain *chain = new TChain("nominal_Loose");
  QmisID_count m_selec;//declared an instance of our class.

  std::cout<<"Declared chains"<<std::endl;
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data15.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data16.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data17.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data18.root");
     hstfilename="etabins12/60_90/gammastr0/data_all_4sigma.root";//output histogram file

     sumfilename1="etabins12/60_90/gammastr0/ss.data_all_4sigma.txt"; //output text file
     sumfilename2="etabins12/60_90/gammastr0/os.data_all_4sigma.txt"; //output text file
  // }

  std::cout<<"Output files are "<<hstfilename<<" and "<<sumfilename1<<" and "<<sumfilename2<<std::endl;
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName1(sumfilename1);
  m_selec.SetSumFileName2(sumfilename2);
  m_selec.SetVerbose(200);//set verbosity level for output.
  m_selec.SetData(4);//******IMPORTANT***** 0 is MC, 1 data, 2 data with BG subtraction, 3 QmisID reweighting, 4 gammastar region, 5 co region, 6 ttw region 9 CO closure
  m_selec.SetSigma(4);
  //this calls the Process function for each event in the chain
  //and runs the m_selec code over it.
  chain->Process(&m_selec);
  

}
void ana3(int signal=0)
{
  const char *hstfilename, *sumfilename1, *sumfilename2;
  string name = "data_15_16";

  TChain *chain = new TChain("nominal_Loose");
  QmisID_count m_selec;//declared an instance of our class.

  std::cout<<"Declared chains"<<std::endl;
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data15.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data16.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data17.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data18.root");
     hstfilename="etabins12/60_90/gammastr0/data_all_3sigma.root";//output histogram file

     sumfilename1="etabins12/60_90/gammastr0/ss.data_all_3sigma.txt"; //output text file
     sumfilename2="etabins12/60_90/gammastr0/os.data_all_3sigma.txt"; //output text file
  // }

  std::cout<<"Output files are "<<hstfilename<<" and "<<sumfilename1<<" and "<<sumfilename2<<std::endl;
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName1(sumfilename1);
  m_selec.SetSumFileName2(sumfilename2);
  m_selec.SetVerbose(200);//set verbosity level for output.
  m_selec.SetData(4);//******IMPORTANT***** 0 is MC, 1 data, 2 data with BG subtraction, 3 QmisID reweighting, 4 gammastar region, 5 co region, 6 ttw region 9 CO closure
  m_selec.SetSigma(3);
  //this calls the Process function for each event in the chain
  //and runs the m_selec code over it.
  chain->Process(&m_selec);
  

}
void ana5(int signal=0)
{
  const char *hstfilename, *sumfilename1, *sumfilename2;
  string name = "data_15_16";

  TChain *chain = new TChain("nominal_Loose");
  QmisID_count m_selec;//declared an instance of our class.

  std::cout<<"Declared chains"<<std::endl;
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data15.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data16.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data17.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data18.root");
     hstfilename="etabins12/60_90/gammastr0/data_all_5sigma.root";//output histogram file

     sumfilename1="etabins12/60_90/gammastr0/ss.data_all_5sigma.txt"; //output text file
     sumfilename2="etabins12/60_90/gammastr0/os.data_all_5sigma.txt"; //output text file
  // }

  std::cout<<"Output files are "<<hstfilename<<" and "<<sumfilename1<<" and "<<sumfilename2<<std::endl;
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName1(sumfilename1);
  m_selec.SetSumFileName2(sumfilename2);
  m_selec.SetVerbose(200);//set verbosity level for output.
  m_selec.SetData(4);//******IMPORTANT***** 0 is MC, 1 data, 2 data with BG subtraction, 3 QmisID reweighting, 4 gammastar region, 5 co region, 6 ttw region 9 ttw closure
  m_selec.SetSigma(5);
  //this calls the Process function for each event in the chain
  //and runs the m_selec code over it.
  chain->Process(&m_selec);
  

}


int main(int argc, char *argv[])
{

  if(argc<2){
    std::cout<<" Please give one integer argument "<<std::endl;
    return 0;
  }
  int signal = atoi(argv[1]);

   anaC(signal);
  // ana3(signal);
  // ana4(signal);
  // ana5(signal);
    return 0;
}

