#define FTAna_cxx

#include "FTAna.h"
#include <TH2.h>
#include <TStyle.h>


void FTAna::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
   TString option = GetOption();
}
void FTAna::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).
   TString option = GetOption();
   //Initialize global variables here.
   GEV = 1000.;    MEV2GEV = .001;
   nEvtTotal = 0;
   //Create the histogram file
   _HstFile = new TFile(_HstFileName,"recreate");
   //Call the function to book the histograms we declared in Hists.
   BookHistograms();
}
void FTAna::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
  //Write histograms and close histogram file
  _HstFile->Write();
  _HstFile->Close();

  //Output to screen.
  cout<<"Total events = "<<nEvtTotal<<endl;
  //Open the text output file
  ofstream fout(_SumFileName1);
  //Put text output in the summary file.

  for(int a=0;a<4;a++){
    for(int b=0;b<6;b++){
      for(int c=0;c<4;c++){
        for(int d=0;d<6;d++){
          fout<<h_SS[a][b][c][d]<<endl;
        }
      }
    }
  }
  ofstream fout2(_SumFileName2);

  for(int a=0;a<4;a++){
    for(int b=0;b<6;b++){
      for(int c=0;c<4;c++){
        for(int d=0;d<6;d++){
          fout2<<h_OS[a][b][c][d]<<endl;
        }
      }
    }
  }

}
void FTAna::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
}
Bool_t FTAna::Process(Long64_t entry)
{
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The return value is currently not used.

  // Decide to read in whole event or just some branches.
  int readevent = ReadLimited(1,entry);
  if(readevent==0){ cout<<"Did not read in any branches.. quitting."<<endl; return kTRUE;}
  //Increment counter of number of events read in.
  nEvtTotal++;
  //Output processing information to screen based on verbosity level.
  if(_verbosity>1000 && nEvtTotal%100==0)cout<<"Processed "<<nEvtTotal<<" event..."<<endl;      
  else if(_verbosity>0 && nEvtTotal%50000==0)cout<<"Processed "<<nEvtTotal<<" event..."<<endl;
  
  //Your CODE starts here
  // if (nEvtTotal < 100000) Terminate();
  // std::cout<<"before loop"<<nEvtTotal<<std::endl;
  double weights = 0;
  // float eventweight = 0;
  // eventweight = 1/_sumWeights;
  // double cs = 0;
  double Mll = 0;
  double lumi = 0;
  double Zmass =0;                                                                                                                                                        
  double massWindow=0;                                                                                                                                                   

  Float_t etaBins[7] = {0,0.6,1.1,1.52,1.7,2.3,2.5};
  Float_t pTBins[5] = {15,60,90,130,1000};
  // cs = 55.5413852*(mcChannelNumber==700320)+286.392209*(mcChannelNumber==700321)+1879.375291*(mcChannelNumber==700322);

  Lepton lep0; lep0.v.SetPtEtaPhiE(lep_0_pt/1000, lep_0_eta, lep_0_phi, lep_0_e/1000);
  Lepton lep1; lep1.v.SetPtEtaPhiE(lep_1_pt/1000, lep_1_eta, lep_1_phi, lep_1_e/1000);
  Lepton lep2; lep2.v.SetPtEtaPhiE(lep_2_pt/1000, lep_2_eta, lep_2_phi, lep_2_e/1000);
  Mll = (lep0.v+lep1.v).M();
 
  // std::cout<<lep_0_pt<<"  "<<lep_1_pt<<" Mll "<<Mll<<" OSee "<< OSee<<" SSee "<<loose_SSee<<" nJets "<<nJets<<" tight "<<(lep_0_isTight==1)<<(lep_1_isTight==1)<<" n "<<nEvtTotal<<std::endl;
  // if(lep_0_isTight!=1 or lep_1_isTight!=1){std::cout<<nEvtTotal<<" "<<lep_1_isTight<<"  "<<lep_0_isTight<<std::endl;}          
  
   if(OSee==1 or loose_SSee ==1){               
     if (OSee == 1){Zmass = 90.64; massWindow = 4.67*3;}      // mass window from gauss fit {Zmass = 90.61; massWindow = 3.337*3.5;}
     else if (loose_SSee == 1){Zmass = 89.56; massWindow = 5.63*3; MW_low = 89.56 - 5.63*3; MW_high = 89.56 + 5.63*3;}// mass windoe from gauss fit {Zmass = 89.48; massWindow = 3.843*3.5; MW_low = 89.48 - 3.843*3.5; MW_high = 89.48 + 3.843*3.5;}
    if(lep_0_isTight==1 and lep_1_isTight==1){ // remove loose lepton         
      // std::cout<<"pass cuts"<<nEvtTotal<<" "<<lep_1_isTight<<"  "<<lep_0_isTight<<std::endl;
      if(Mll>(Zmass-2*massWindow) and Mll<(Zmass+2*massWindow) ){
    	if( nJets>0 ){

    	  if(el_ECIDSResult_float->at(0)>-0.337671 and el_ECIDSResult_float->at(1)>-0.337671){
	  // std::cout<<" IN "<<lep_0_pt<<"  "<<lep_1_pt<<" Mll "<<Mll<<" OSee "<< OSee<<" SSee "<<loose_SSee<<" nJets "<<nJets<<" tight "<<(lep_0_isTight==1)<<(lep_1_isTight==1)<<" n "<<nEvtTotal<<std::endl;
	    if (_data == 0){ 
	      if ( Mll>(Zmass - massWindow) and Mll < (Zmass+massWindow)) {
		  lumi =36207.7*(runNumber==284500)+44307.4*(runNumber==300000)+(runNumber==310000)*58450.1;
		  weights = weight_mc*weight_pileup*weight_jvt*weight_leptonSF*weight_bTagSF_DL1r_Continuous*weight_normalise*lumi;}}
	    else if (_data == 1){
	      // if ( Mll>(Zmass - massWindow) and Mll < (Zmass+massWindow)) {
		weights = 1;}
	    else if (_data == 2){
	      if(Mll>(Zmass-massWindow) and Mll<(Zmass+massWindow) ){
		weights = 1;}
	      else{weights = -0.5;}}
	    // else if (_data == 3){
	    //   if(OSee==1){
	    //   // if ( Mll>(Zmass - massWindow) and Mll < (Zmass+massWindow)) {
	    // 	weights = weight_closure(lep0.v, lep1.v);}
	    //   // else{weights = -0.5*weight_closure(lep0.v, lep1.v);}}
	    //   else if (loose_SSee == 1){
	    // 	// if ( Mll>(Zmass - massWindow) and Mll < (Zmass+massWindow)) {
	    // 	  weights =1;}
	    // // else {weights = -0.5;}}}
	    else if (_data == 3){
	      if(OSee == 1){
	    	weights = weight_closure(lep0.v, lep1.v);
	      }
	      else if (loose_SSee == 1){
		if(Mll>(Zmass-massWindow) and Mll<(Zmass+massWindow) ){
		  weights = 1;}
		else{weights = -0.5;}

	      }}

	    
	    if(_verbosity>0 && nEvtTotal%50000==0)cout<<"lumi"<<lumi<<" weights "<<weights<<" mll "<<Mll<<" OSee " << OSee<<" SSee" <<loose_SSee<<std::endl;
	  

   int i=0,j=0,k=0,l=0, m=0;

 if(lep_0_pt<60000) i=0;
 else if(lep_0_pt<90000) i=1;
 else if(lep_0_pt<130000) i=2;
 else i=3;

 if(lep_1_pt<60000) k=0;
 else if(lep_1_pt<90000) k=1;
 else if(lep_1_pt<130000) k=2;
 else k=3;

 if(fabs(lep_0_eta)<0.6) j=0;
 else if(fabs(lep_0_eta)<1.1) j=1;
 else if(fabs(lep_0_eta)<1.52) j=2;
 else if(fabs(lep_0_eta)<1.7) j=3;
 else if(fabs(lep_0_eta)<2.3) j=4;
 else j=5;

 if(fabs(lep_1_eta)<0.6) l=0;
 else if(fabs(lep_1_eta)<1.1) l=1;
 else if(fabs(lep_1_eta)<1.52) l=2;
 else if(fabs(lep_1_eta)<1.7) l=3;
 else if(fabs(lep_1_eta)<2.3) l=4;
 else l=5;

  Sum = Sum+weights;
  if(OSee==1){

    h_OS[i][j][k][l] += weights;

  h.os_Jets->Fill(nJets,weights);
  h.os_Muons->Fill(nMuons,weights);
  h.os_Electrons->Fill(nElectrons,weights);
  h.os_HT->Fill(HT_all/1000,weights);
  h.os_HT_Jets->Fill(HT_jets/1000,weights);
  h.os_met->Fill(met_met/1000,weights);
  h.os_lep_pt[0]->Fill(lep0.v.Pt(),weights); 
  h.os_lep_pt[1]->Fill(lep1.v.Pt(),weights); 
  h.os_lep_pt[2]->Fill(lep2.v.Pt(),weights); 
  h.os_lep_pt_Q[0]->Fill(lep0.v.Pt(),weights); 
  h.os_lep_pt_Q[1]->Fill(lep1.v.Pt(),weights); 
  h.os_lep_pt_Q[2]->Fill(lep2.v.Pt(),weights); 
  h.os_lep_eta[0]->Fill(lep0.v.Eta(),weights); 
  h.os_lep_eta[1]->Fill(lep1.v.Eta(),weights); 
  h.os_lep_eta[2]->Fill(lep2.v.Eta(),weights); 
  h.os_pt_eta[0]->Fill(lep0.v.Eta(),lep0.v.Pt(),weights); 
  h.os_pt_eta[1]->Fill(lep1.v.Eta(),lep1.v.Pt(),weights); 
  h.os_n_Btags->Fill(nBTags_DL1r_77,weights);
  h.os_OSee->Fill(OSee,weights);
  h.os_loose_SSee->Fill(loose_SSee,weights);
  if(Mll>MW_low and Mll<MW_high ){

  h.os_M_ll[0]->Fill(Mll,weights);
  h.os_M_ll[1]->Fill(Mll,weights);
  }

    // std::cout<<" OSee "<<lep_0_charge<<" pdgid "<<lep_0_pdgid<<" 1" << lep_1_charge<<" pdgid "<<lep_1_pdgid<<std::endl;
}
  else if (loose_SSee==1){
    h_SS[i][j][k][l] += weights;

  h.ss_Jets->Fill(nJets,weights);
  h.ss_Muons->Fill(nMuons,weights);
  h.ss_Electrons->Fill(nElectrons,weights);
  h.ss_HT->Fill(HT_all/1000,weights);
  h.ss_HT_Jets->Fill(HT_jets/1000,weights);
  h.ss_met->Fill(met_met/1000,weights);
  h.ss_lep_pt[0]->Fill(lep0.v.Pt(),weights); 
  h.ss_lep_pt[1]->Fill(lep1.v.Pt(),weights); 
  h.ss_lep_pt[2]->Fill(lep2.v.Pt(),weights); 
  h.ss_lep_pt_Q[0]->Fill(lep0.v.Pt(),weights); 
  h.ss_lep_pt_Q[1]->Fill(lep1.v.Pt(),weights); 
  h.ss_lep_pt_Q[2]->Fill(lep2.v.Pt(),weights); 
  h.ss_lep_eta[0]->Fill(lep0.v.Eta(),weights); 
  h.ss_lep_eta[1]->Fill(lep1.v.Eta(),weights); 
  h.ss_lep_eta[2]->Fill(lep2.v.Eta(),weights); 
  h.ss_pt_eta[0]->Fill(lep0.v.Eta(),lep0.v.Pt(),weights); 
  h.ss_pt_eta[1]->Fill(lep1.v.Eta(),lep1.v.Pt(),weights); 
  h.ss_n_Btags->Fill(nBTags_DL1r_77,weights);
  h.ss_OSee->Fill(OSee,weights);
  h.ss_loose_SSee->Fill(loose_SSee,weights);
  if(Mll>MW_low and Mll<MW_high ){
  
  h.ss_M_ll[0]->Fill(Mll,weights);
  h.ss_M_ll[1]->Fill(Mll,weights);
  }}
  

      //std::cout<<" SSee "<<lep_0_charge<<" pdgid "<<lep_0_pdgid<<" 1" << lep_1_charge<<" pdgid "<<lep_1_pdgid<<std::endl;
	  }}}}}

  return 0;


}

double FTAna::weight_closure(TLorentzVector l1,TLorentzVector l2)
{
  Float_t etaBins[7] = {0,0.6,1.1,1.52,1.7,2.3,2.5};
  Float_t pTBins[5] = {15,60,90,130,1000};
  // Float_t pt_eta_w[24] = {2.77956E-05, 9.18632E-05, 0.000293832, 0.00122626, 6.23563E-05, 0.000266847, 0.000719646, 0.00257103, 0.000145766, 0.000593666, 0.00190437, 0.00597857, 0.000279288, 0.000928315, 0.00305011, 0.0106833, 0.000512649, 0.00144844, 0.00487751, 0.0156174, 0.0010072, 0.00568093, 0.0161041, 0.0400924};//intial 91+10

  // Float_t pt_eta_w[24] = {3.69267E-05, 0.000121321, 0.000340163, 0.00134184, 7.68468E-05, 0.0002751, 0.000753798, 0.00273213, 0.000151832, 0.000618405, 0.00191832, 0.00609876, 0.000299502, 0.00096763, 0.00303735, 0.0103543, 0.000548696, 0.00153442, 0.00496281, 0.0157161, 0.00104143, 0.00566937, 0.0155961, 0.0406812}; // 4sigma

  //  Float_t pt_eta_w[24] = {3.36064E-05, 0.000105937, 0.000299397, 0.00126576, 7.10368E-05, 0.00027268, 0.000737339, 0.00272032, 0.00014522, 0.000602727, 0.00193299, 0.00606077, 0.000286898, 0.000947173, 0.003027, 0.010872, 0.000545306, 0.00148787, 0.00495277, 0.0157645, 0.00103669, 0.00582632, 0.0162814, 0.0402141}; // 3sigma

  // Float_t pt_eta_w[24] = {3.51309E-05, 0.000114036, 0.000332657, 0.00130865, 7.43972E-05, 0.000275719, 0.000746133, 0.00271474, 0.00014993, 0.000618752, 0.00195181, 0.00608874, 0.000293516, 0.000959826, 0.00298587, 0.0105984, 0.000542453, 0.00152041, 0.00489787, 0.0158322, 0.001054, 0.00571437, 0.0157655, 0.0403971}; //3.5 sigma

  // Float_t pt_eta_w[24] = {3.3394E-05, 0.000108867, 0.000336047, 0.00131354, 7.41609E-05, 0.00027203, 0.00073821, 0.00271954, 0.000147556, 0.000620488, 0.00192221, 0.0061127, 0.000298625, 0.000946508, 0.00299467, 0.0106709, 0.000543555, 0.00151675, 0.00491541, 0.0158704, 0.0010614, 0.0057325, 0.0158172, 0.0402676}; // 3.4 sigma

  Float_t pt_eta_w[24] = {4.02612E-05, 0.000120388, 0.000347194, 0.00132347, 7.3542E-05, 0.000282824, 0.000778923, 0.00281347, 0.000154639, 0.000625872, 0.00192782, 0.00603786, 0.000311132, 0.00100242, 0.00309482, 0.0102888, 0.000543691, 0.00155772, 0.00497516, 0.0158106, 0.0010541, 0.00569056, 0.015626, 0.0413519}; //3 sigma BW


  // Float_t pt_eta_w[24] = {1.44690e-04, 2.99957e-04,8.53123e-04, 2.11835e-03, 4.10669e-04, 1.00980e-03, 2.04606e-03, 5.03071e-03, 1.07257e-03, 2.73275e-03, 4.66572e-03, 1.10720e-02, 2.66948e-03, 7.29937e-03, 1.30736e-02, 2.50479e-02, 5.41416e-03, 1.55881e-02, 2.63075e-02, 4.58553e-02, 1.46556e-02, 4.03585e-02, 6.09825e-02, 9.03881e-02}; //initial without ECIDS
   double weight1 = 0;
   double weight2 = 0;

    for (int eta1 =0; eta1<6; eta1++){
      for (int pt1 =0; pt1<4; pt1++){
	if (pTBins[pt1] <l1.Pt() and l1.Pt() < pTBins[pt1+1] and etaBins[eta1]< abs(l1.Eta()) and abs(l1.Eta())< etaBins[eta1+1]){
	  
	  weight1 = pt_eta_w[pt1+4*eta1]; 
	  // std::cout<<"pt1 "<<pTBins[pt1]<<" pt "<<l1.Pt()<<" pt2 "<< pTBins[pt1+1]<<" eta1 "<<etaBins[eta1]<<" eta "<<abs(l1.Eta())<<" eta2 "<<etaBins[eta1+1]<<"  "<<pt_eta_w[pt1+4*eta1]<<" "<<weight1<<std::endl;                         
	  
                                               
      }}}
    for (int eta2 =0; eta2<6; eta2++){
      for (int pt2 =0; pt2<4; pt2++){
	if (pTBins[pt2] <l2.Pt() and l2.Pt() < pTBins[pt2+1] and etaBins[eta2]< abs(l2.Eta()) and abs(l2.Eta())< etaBins[eta2+1]){
	  
	  weight2 = pt_eta_w[pt2+4*eta2]; 
	  // std::cout<<"pt2 "<<pTBins[pt2]<<" pt "<<l2.Pt()<<" pt2 "<< pTBins[pt2+1]<<" eta2 "<<etaBins[eta2]<<" eta "<<abs(l2.Eta())<<" eta2 "<<etaBins[eta2+1]<<"  "<<pt_eta_w[pt2+4*eta2]<<" "<<weight2<<std::endl;                            
	  
                                               
      }}}

  // weights = (weight1 +weight2 -2*weight1*weight2)/((1-weight1-weight2)+2*weight2*weight1);                                                                                                                                              
  // std::cout<<weight2<<weight1<<std::endl;
  // return weight1*( 1-weight2 )+weight2*(1-weight2); 
  return (weight1 + weight2 -2*weight1*weight2)/(1-weight1 -weight2 +2*weight1*weight2); 
 }
  

Double_t FTAna::delR(TLorentzVector v1,  TLorentzVector v2)
 { 
   double del_eta = abs(v1.Eta() - v2.Eta());
   //cout<< sqrt( pow(del_eta,2) + pow(delta_phi(v1.Phi(),v2.Phi()),2) )<< " "<<v2.Pt()<<endl;
   return sqrt( pow(del_eta,2) + pow(delta_phi(v1.Phi(),v2.Phi()),2) );
 }


float FTAna::delta_phi(float phi1, float phi2)
{
  //Calculate the correct deltaPhi=phi1-phi2
  phi1 = TVector2::Phi_0_2pi(phi1);
  phi2 = TVector2::Phi_0_2pi(phi2);
  float dphi = fabs(phi1 - phi2);
  if(dphi>TMath::Pi()) dphi = 2*TMath::Pi() - dphi;
  return dphi;
}
Int_t FTAna::min_delR(vector<double> deltaR)
 {
 
  double min = deltaR.at(0);
  int location = 0;
  for (int i=0; i <deltaR.size();i++){
  //cout<<deltaR.at(i)<<endl;
  if (deltaR.at(i) < min) {min = deltaR.at(i); location = i;}}
  //cout<<deltaR.at(i)<< " min " <<min<<" location "<<location<<endl;
  //cout <<"loc "<< location << endl;
  return location;
  } 

void FTAna::BookHistograms()
{
  Float_t etaBins[7] = {0,0.6,1.1,1.52,1.7,2.3,2.5};
  Float_t pTBins[5] = {15,60,90,130,1000};

  h.ss_Muons = new TH1F("ss_n_Muons", "", 4, -0.5, 3.5);
  h.ss_Electrons = new TH1F("ss_n_Electrons", "", 4, -0.5, 3.5);
  h.ss_Jets = new TH1F("ss_n_Jets", "", 8, -0.5, 7.5);
  h.ss_OSee = new TH1F("ss_OSee", "", 4, -0.5, 3.5);
  h.ss_loose_SSee = new TH1F("ss_loose_SSee", "", 4, -0.5, 3.5);
  h.ss_HT = new TH1D("ss_HT_all", "", 20, 200, 800);
  h.ss_HT_Jets = new TH1D("ss_HT_jets", "", 16, 200, 800);
  h.ss_M_ll[0] = new TH1D("ss_Mll", "", 150, 60, 120);
  h.ss_M_ll[1] = new TH1D("ss_Mll_small", "", 200, 60, 120);
  h.ss_lep_pt[0] = new TH1D("ss_lep_0_pt","",10, 15, 150);
  h.ss_lep_pt[1] = new TH1D("ss_lep_1_pt","",10, 15, 150);
  h.ss_lep_pt[2] = new TH1D("ss_lep_2_pt","",10, 15, 150);
  h.ss_lep_pt_Q[0] = new TH1D("ss_lep0_pt","",4, pTBins);
  h.ss_lep_pt_Q[1] = new TH1D("ss_lep1_pt","",4, pTBins);
  h.ss_lep_pt_Q[2] = new TH1D("ss_lep2_pt","",4, pTBins);
  h.ss_lep_eta[0] = new TH1D("ss_lep_0_eta","",6, etaBins);
  h.ss_lep_eta[1] = new TH1D("ss_lep_1_eta","",6, etaBins);
  h.ss_lep_eta[2] = new TH1D("ss_lep_2_eta","",6, etaBins);
  h.ss_n_Btags = new TH1F("ss_n_btags_77","", 6, -0.5, 5.5);
  h.ss_met = new TH1D("ss_met","", 10, 0,100);
  h.ss_pt_eta[0] = new TH2D("ss_pt_eta_0","" ,6, etaBins,4, pTBins);
  h.ss_pt_eta[1] = new TH2D("ss_pt_eta_1","" ,6, etaBins,4, pTBins);


  h.os_Muons = new TH1F("os_n_Muons", "", 4, -0.5, 3.5);
  h.os_Electrons = new TH1F("os_n_Electrons", "", 4, -0.5, 3.5);
  h.os_Jets = new TH1F("os_n_Jets", "", 8, -0.5, 7.5);
  h.os_OSee = new TH1F("os_OSee", "", 4, -0.5, 3.5);
  h.os_loose_SSee = new TH1F("os_loose_SSee", "", 4, -0.5, 3.5);
  h.os_HT = new TH1D("os_HT_all", "", 20, 200, 800);
  h.os_HT_Jets = new TH1D("os_HT_jets", "", 16, 200, 800);
  h.os_M_ll[0] = new TH1D("os_Mll", "", 150, 60, 120);
  h.os_M_ll[1] = new TH1D("os_Mll_small", "", 200, 60, 120);
  h.os_lep_pt[0] = new TH1D("os_lep_0_pt","",10, 15, 150);
  h.os_lep_pt[1] = new TH1D("os_lep_1_pt","",10, 15, 150);
  h.os_lep_pt[2] = new TH1D("os_lep_2_pt","",10, 15, 150);
  h.os_lep_pt_Q[0] = new TH1D("os_lep0_pt","",4, pTBins);
  h.os_lep_pt_Q[1] = new TH1D("os_lep1_pt","",4, pTBins);
  h.os_lep_pt_Q[2] = new TH1D("os_lep2_pt","",4, pTBins);
  h.os_lep_eta[0] = new TH1D("os_lep_0_eta","",6, etaBins);
  h.os_lep_eta[1] = new TH1D("os_lep_1_eta","",6, etaBins);
  h.os_lep_eta[2] = new TH1D("os_lep_2_eta","",6, etaBins);
  h.os_n_Btags = new TH1F("os_n_btags_77","", 6, -0.5, 5.5);
  h.os_met = new TH1D("os_met","", 10, 0,100);
  h.os_pt_eta[0] = new TH2D("os_pt_eta_0","" ,6, etaBins,4, pTBins);
  h.os_pt_eta[1] = new TH2D("os_pt_eta_1","" ,6, etaBins,4, pTBins);

// h.n_Btags = new TH1F("Btags", "",6, -0.5, 5.5);

  // lep1_pt = new TH1D("lep_1_pt", "", 4, pTBins);
  // lep0_pt = new TH1D("lep_0_pt", "", 4, pTBins);
  // lep2_pt = new TH1D("lep_2_pt", "", 4, pTBins);
  // lep1_eta = new TH1D("lep_1_eta", "", 6, etaBins);
  // lep0_eta= new TH1D("lep_0_eta", "",  6, etaBins);
  // lep2_eta = new TH1D("lep_2_eta", "", 6, etaBins);
  
}
