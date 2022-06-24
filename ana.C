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
void ana(int sample=1)
{
  const char *hstfilename, *sumfilename1, *sumfilename2;
  string name = "data_15_16";

  TChain *chain = new TChain("nominal_Loose");
  QmisID_count m_selec;//declared an instance of our class.

  std::cout<<"Declared chains"<<std::endl;
  
    
  // if(sample==1){
     // chain->Add("/eos/home-s/ssindhu/4tops/post_prodQmisID/ECIDS/data15.root");
     // chain->Add("/eos/home-s/ssindhu/4tops/post_prodQmisID/ECIDS/data16.root");
     // chain->Add("/eos/home-s/ssindhu/4tops/post_prodQmisID/ECIDS/data17.root");
     // chain->Add("/eos/home-s/ssindhu/4tops/post_prodQmisID/ECIDS/data18.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data15.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data16.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data17.root");
     chain->Add("/eos/home-s/ssindhu/4tops/new_QmisID/SSML/data/test/data18.root");
     // chain->Add("/eos/atlas/atlascerngroupdisk/phys-top/topplusx/4tops2021/common-fw_tag212120/HBSM4t-212120_HBSM4tops_syst_off_v7.1/SSML/QmisID/data18.root");
     
     // chain->Add("/eos/home-s/ssindhu/4tops/post_prodQmisID/ECIDS/QmisID_mc16a.root");
    //  chain->Add("/eos/home-s/ssindhu/4tops/post_prodQmisID/data16.root");
    // chain->Add("/eos/home-s/ssindhu/4tops/post_prodQmisID/data15.root");
    // chain->Add("/home/sreelakshmi/Work/DYJetsToLL_M50/resultsMC_2.root");
    //    chain->Add("/afs/cern.ch/work/s/ssindhu/private/QmisID_new/data16.slim.root");
    //chain->Add("DY50_test.root");
    //can have more chain->Add() lines here.
     
     hstfilename="new_bins/45_60_90_130/data_all_closure.root";//output histogram file

     sumfilename1="new_bins/45_60_90_130/ss.data_all_closure.txt"; //output text file
     sumfilename2="new_bins/45_60_90_130/os.data_all_closure.txt"; //output text file
  // }

  std::cout<<"Output files are "<<hstfilename<<" and "<<sumfilename1<<" and "<<sumfilename2<<std::endl;
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName1(sumfilename1);
  m_selec.SetSumFileName2(sumfilename2);
  m_selec.SetVerbose(200);//set verbosity level for output.
  m_selec.SetData(3);//******IMPORTANT***** 0 is MC, 1 data, 2 data with BG subtraction, 3 QmisID reweighting, 4 gammastar region, 5 co region, 6 ttw region

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
  int sample_id = atoi(argv[1]);

  ana(sample_id);
  return 0;
}

