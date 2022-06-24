#ifndef QmisID_count_h
#define QmisID_count_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH1.h>
#include <TH2.h>
#include <TMath.h>
#include "TLorentzVector.h"

#include <vector>
#include <fstream>
#include <iostream>

// Header file for the classes stored in the TTree if any.
using namespace std;

class QmisID_count : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   // This is the list of variables available to you.
   Float_t         boostedRecoHiggsPt;
   Float_t         lep_2_pt;
   Float_t         lep_1_e;
   Float_t         lep_0_eta;
   Float_t         lep_2_charge;
   Float_t         GenFiltHT;
   Float_t         lep_0_e;
   Float_t         mJSum;
   Float_t         lep_2_phi;
   Float_t         lep_0_phi;
   Float_t         HT_all;
   Float_t         lep_1_pt;
   Float_t         lep_0_pt;
   Float_t         HT_jets;
   Float_t         lep_1_phi;
   Float_t         lep_2_e;
   Float_t         lep_0_charge;
   Float_t         lep_1_eta;
   Float_t         lep_1_charge;
   Float_t         lep_2_eta;
   Int_t           TopHeavyFlavorFilterFlag;
   Int_t           nJets;
   Int_t           nRCJetsM100;
   Int_t           nPrimaryVtx;
   Int_t           mmm;
   Int_t           nMuons;
   Int_t           nBTags_DL1r_70;
   Int_t           SSem;
   Int_t           nElectrons;
   Int_t           nBTags_DL1_85;
   Int_t           nBTags_DL1_77;
   Int_t           nBTags_DL1_70;
   Int_t           nBTags_DL1_60;
   Int_t           eee;
   Int_t           eee_Zveto;
   Int_t           mmm_Zveto;
   Int_t           emm;
   Int_t           lep_1_pdgid;
   Int_t           emm_Zveto;
   Int_t           loose_SSee;
   Int_t           eem;
   Int_t           OSee;
   Int_t           eem_Zveto;
   Int_t           lep_0_pdgid;
   Int_t           nBTags_DL1r_85;
   Int_t           nRCJets;
   Int_t           nBTags_DL1r_60;
   Int_t           nBTags_DL1r_77;
   Int_t           randomRunNumber;
   Char_t          passedOfflineBoostedSelection;
   Char_t          lep_1_isTight;
   Char_t          lep_0_isTight;
   ULong64_t       eventNumber;
   UInt_t          mcChannelNumber;
   UInt_t          runNumber;
   vector<float>   *el_pt;
   vector<float>   *el_eta;
   vector<float>   *el_phi;
   vector<float>   *el_e;
   vector<float>   *el_charge;
   vector<float>   *mu_pt;
   vector<float>   *mu_eta;
   vector<float>   *mu_phi;
   vector<float>   *mu_e;
   vector<float>   *mu_charge;
   Float_t         met_met;
   Float_t         met_phi;
   vector<int>     *el_truthPdgId;
   vector<int>     *el_true_firstEgMotherPdgId;
   vector<int>     *el_true_pdg;
   vector<int>     *el_true_type;
   vector<int>     *el_true_origin;
   vector<int>     *el_isPrompt;
   vector<int>     *el_true_firstEgMotherTruthType;
   vector<int>     *el_true_firstEgMotherTruthOrigin;
   vector<float>   *el_ECIDSResult_float;
   vector<float>   *el_sumTrackPt;
   vector<float>   *el_separationMinDCT;
   vector<float>   *el_leadTrackPt;
   vector<float>   *el_leadSubleadDr;
   vector<float>   *el_leadSubleadDphi;
   vector<float>   *el_leadSubleadDeta;
   vector<float>   *el_deltaPhi2;
   vector<float>   *el_bestmatchSiTrackEta;
   vector<float>   *el_closestSiTrackEta;
   vector<float>   *el_RadiusCO;
   vector<float>   *el_delta_z0_sintheta;
   vector<float>   *el_closestSiTracknIL;
   vector<float>   *el_closestSiTrackPhi;
   vector<float>   *el_d0sig;
   vector<float>   *el_PromptLeptonVeto;
   vector<float>   *el_topoetcone20;
   vector<float>   *el_closestSiTrackeIL;
   vector<float>   *el_MeeCO;
   vector<float>   *el_bestmatchSiTrackPt;
   vector<float>   *el_bestmatchSiTrackPhi;
   vector<float>   *el_bestmatchSiTrackZ0;
   vector<float>   *el_subleadTrackPt;
   vector<float>   *el_closestSiTrackQ;
   vector<float>   *el_closestSiTrackD0;
   vector<float>   *el_closestSiTracknNIL;
   vector<float>   *el_bestmatchSiTrackQ;
   vector<float>   *el_closestSiTrackPt;
   vector<float>   *el_bestmatchSiTrackD0;
   vector<float>   *el_closestSiTrackZ0;
   vector<char>    *el_isoLooseTrackOnly;
   vector<char>    *el_isoLoose;
   vector<char>    *el_isoGradientLoose;
   vector<char>    *el_isoGradient;
   vector<char>    *el_LHMedium;
   vector<char>    *el_isoFixedCutTightTrackOnly;
   vector<char>    *el_ECIDS;
   vector<char>    *el_LHTight;
   vector<char>    *el_isTight;
   vector<char>    *el_isoFixedCutLoose;
   vector<char>    *el_isoFixedCutTight;
   vector<int>     *mu_true_origin;
   vector<int>     *mu_true_type;
   vector<int>     *mu_isPrompt;
   vector<int>     *mu_true_pdg;
   vector<float>   *mu_d0sig;
   vector<float>   *mu_delta_z0_sintheta;
   vector<float>   *mu_topoetcone20;
   vector<float>   *mu_PromptLeptonVeto;
   vector<char>    *mu_isoLooseTrackOnly;
   vector<char>    *mu_isoLoose;
   vector<char>    *mu_isoGradientLoose;
   vector<char>    *mu_Tight;
   vector<char>    *mu_isTight;
   vector<char>    *mu_Medium;
   vector<char>    *mu_isoFixedCutLoose;
   vector<char>    *mu_isoFixedCutTightTrackOnly;
   vector<char>    *mu_isoGradient;
   Float_t         weight_pileup;
   Float_t         weight_leptonSF;
   Float_t         weight_mc;
   Float_t         weight_jvt;
   Float_t         weight_bTagSF_DL1r_77;
   Float_t         weight_bTagSF_DL1r_70;
   Float_t         weight_ttbar_FracRw;
   Float_t         weight_bTagSF_DL1r_60;
   Float_t         weight_bTagSF_DL1r_85;
   Float_t         weight_bTagSF_DL1r_Continuous;
   Float_t         weight_indiv_SF_MU_TTVA;
   Float_t         weight_indiv_SF_MU_ID;
   Float_t         weight_indiv_SF_EL_Isol;
   Float_t         weight_indiv_SF_MU_Isol;
   Float_t         weight_indiv_SF_EL_Reco;
   Float_t         weight_indiv_SF_EL_ID;
   vector<float>   *mc_generator_weights;
   Float_t         weight_normalise;
   vector<string>  *weight_mcweight_name;
   vector<float>   *weight_mcweight_normalise;
   Int_t           lepton_1_ID;
   Int_t           Tlepton_0_DFCommonAddAmbiguity;
   Int_t           nTight;
   Int_t           loose_eee;
   Int_t           Tlepton_0_charge;
   Int_t           SSem_passEtaCut;
   Int_t           SSee_passECIDS;
   Int_t           SSem_passECIDS;
   Int_t           OSem_passECIDS;
   Int_t           OSem_passEtaCut;
   Int_t           OSee_passECIDS;
   Int_t           lepton_0_truthClassificationSM4t_bkgFlag;
   Int_t           lepton_1_DFCommonAddAmbiguity;
   Int_t           lepton_1_truthClassificationSM4t_bkgFlag;
   Int_t           lepton_2_truthClassificationSM4t_bkgFlag;
   Int_t           Evt_Channel;
   Int_t           lepton_2_ID;
   Int_t           lepton_0_ID;
   Int_t           lepton_0_ambiguityType;
   Int_t           ttW_CRFlag;
   Int_t           loose_SSem;
   Int_t           Tlepton_2_ambiguityType;
   Int_t           lepton_0_DFCommonAddAmbiguity;
   Int_t           lepton_2_DFCommonAddAmbiguity;
   Int_t           lepton_1_ambiguityType;
   Int_t           lepton_2_ambiguityType;
   Int_t           OSee_passEtaCut;
   Int_t           Tlepton_1_ID;
   Int_t           Tlepton_2_ID;
   Int_t           Tlepton_1_DFCommonAddAmbiguity;
   Int_t           Tlepton_2_DFCommonAddAmbiguity;
     
   //List of branches
   TBranch        *b_boostedRecoHiggsPt;
   TBranch        *b_lep_2_pt;
   TBranch        *b_lep_1_e;
   TBranch        *b_lep_0_eta;
   TBranch        *b_lep_2_charge;
   TBranch        *b_GenFiltHT;
   TBranch        *b_lep_0_e;
   TBranch        *b_mJSum;
   TBranch        *b_lep_2_phi;
   TBranch        *b_lep_0_phi;
   TBranch        *b_HT_all;
   TBranch        *b_lep_1_pt;
   TBranch        *b_lep_0_pt;
   TBranch        *b_HT_jets;
   TBranch        *b_lep_1_phi;
   TBranch        *b_lep_2_e;
   TBranch        *b_lep_0_charge;
   TBranch        *b_lep_1_eta;
   TBranch        *b_lep_1_charge;
   TBranch        *b_lep_2_eta;
   TBranch        *b_TopHeavyFlavorFilterFlag;
   TBranch        *b_nJets;
   TBranch        *b_nRCJetsM100;
   TBranch        *b_nPrimaryVtx;
   TBranch        *b_mmm;
   TBranch        *b_nMuons;
   TBranch        *b_nBTags_DL1r_70;
   TBranch        *b_SSem;
   TBranch        *b_nElectrons;
   TBranch        *b_nBTags_DL1_85;
   TBranch        *b_nBTags_DL1_77;
   TBranch        *b_nBTags_DL1_70;
   TBranch        *b_nBTags_DL1_60;
   TBranch        *b_eee;
   TBranch        *b_eee_Zveto;
   TBranch        *b_mmm_Zveto;
   TBranch        *b_emm;
   TBranch        *b_lep_1_pdgid;
   TBranch        *b_emm_Zveto;
   TBranch        *b_loose_SSee;
   TBranch        *b_eem;
   TBranch        *b_OSee;
   TBranch        *b_eem_Zveto;
   TBranch        *b_lep_0_pdgid;
   TBranch        *b_nBTags_DL1r_85;
   TBranch        *b_nRCJets;
   TBranch        *b_nBTags_DL1r_60;
   TBranch        *b_nBTags_DL1r_77;
   TBranch        *b_randomRunNumber;
   TBranch        *b_passedOfflineBoostedSelection;
   TBranch        *b_lep_1_isTight;
   TBranch        *b_lep_0_isTight;
   TBranch        *b_eventNumber;
   TBranch        *b_mcChannelNumber;
   TBranch        *b_runNumber;
   TBranch        *b_mu_pt;
   TBranch        *b_mu_eta;
   TBranch        *b_mu_phi;
   TBranch        *b_mu_e;
   TBranch        *b_mu_charge;
   TBranch        *b_met_met;
   TBranch        *b_met_phi;
   TBranch        *b_el_truthPdgId;
   TBranch        *b_el_true_firstEgMotherPdgId;
   TBranch        *b_el_true_pdg;
   TBranch        *b_el_true_type;
   TBranch        *b_el_true_origin;
   TBranch        *b_el_isPrompt;
   TBranch        *b_el_true_firstEgMotherTruthType;
   TBranch        *b_el_true_firstEgMotherTruthOrigin;
   TBranch        *b_el_ECIDSResult_float;
   TBranch        *b_el_sumTrackPt;
   TBranch        *b_el_separationMinDCT;
   TBranch        *b_el_leadTrackPt;
   TBranch        *b_el_leadSubleadDr;
   TBranch        *b_el_leadSubleadDphi;
   TBranch        *b_el_leadSubleadDeta;
   TBranch        *b_el_deltaPhi2;
   TBranch        *b_el_bestmatchSiTrackEta;
   TBranch        *b_el_closestSiTrackEta;
   TBranch        *b_el_RadiusCO;
   TBranch        *b_el_delta_z0_sintheta;
   TBranch        *b_el_closestSiTracknIL;
   TBranch        *b_el_closestSiTrackPhi;
   TBranch        *b_el_d0sig;
   TBranch        *b_el_PromptLeptonVeto;
   TBranch        *b_el_topoetcone20;
   TBranch        *b_el_closestSiTrackeIL;
   TBranch        *b_el_MeeCO;
   TBranch        *b_el_bestmatchSiTrackPt;
   TBranch        *b_el_bestmatchSiTrackPhi;
   TBranch        *b_el_bestmatchSiTrackZ0;
   TBranch        *b_el_subleadTrackPt;
   TBranch        *b_el_closestSiTrackQ;
   TBranch        *b_el_closestSiTrackD0;
   TBranch        *b_el_closestSiTracknNIL;
   TBranch        *b_el_bestmatchSiTrackQ;
   TBranch        *b_el_closestSiTrackPt;
   TBranch        *b_el_bestmatchSiTrackD0;
   TBranch        *b_el_closestSiTrackZ0;
   TBranch        *b_el_isoLooseTrackOnly;
   TBranch        *b_el_isoLoose;
   TBranch        *b_el_isoGradientLoose;
   TBranch        *b_el_isoGradient;
   TBranch        *b_el_LHMedium;
   TBranch        *b_el_isoFixedCutTightTrackOnly;
   TBranch        *b_el_ECIDS;
   TBranch        *b_el_LHTight;
   TBranch        *b_el_isTight;
   TBranch        *b_el_isoFixedCutLoose;
   TBranch        *b_el_isoFixedCutTight;
   TBranch        *b_mu_true_origin;
   TBranch        *b_mu_true_type;
   TBranch        *b_mu_isPrompt;
   TBranch        *b_mu_true_pdg;
   TBranch        *b_mu_d0sig;
   TBranch        *b_mu_delta_z0_sintheta;
   TBranch        *b_mu_topoetcone20;
   TBranch        *b_mu_PromptLeptonVeto;
   TBranch        *b_mu_isoLooseTrackOnly;
   TBranch        *b_mu_isoLoose;
   TBranch        *b_mu_isoGradientLoose;
   TBranch        *b_mu_Tight;
   TBranch        *b_mu_isTight;
   TBranch        *b_mu_Medium;
   TBranch        *b_mu_isoFixedCutLoose;
   TBranch        *b_mu_isoFixedCutTightTrackOnly;
   TBranch        *b_mu_isoGradient;
   TBranch        *b_weight_pileup;
   TBranch        *b_weight_leptonSF;
   TBranch        *b_weight_mc;
   TBranch        *b_weight_jvt;
   TBranch        *b_weight_bTagSF_DL1r_77;
   TBranch        *b_weight_bTagSF_DL1r_70;
   TBranch        *b_weight_ttbar_FracRw;
   TBranch        *b_weight_bTagSF_DL1r_60;
   TBranch        *b_weight_bTagSF_DL1r_85;
   TBranch        *b_weight_bTagSF_DL1r_Continuous;
   TBranch        *b_weight_indiv_SF_MU_TTVA;
   TBranch        *b_weight_indiv_SF_MU_ID;
   TBranch        *b_weight_indiv_SF_EL_Isol;
   TBranch        *b_weight_indiv_SF_MU_Isol;
   TBranch        *b_weight_indiv_SF_EL_Reco;
   TBranch        *b_weight_indiv_SF_EL_ID;
   TBranch        *b_mc_generator_weights;
   TBranch        *b_weight_normalise;
   TBranch        *b_weight_mcweight_name;
   TBranch        *b_weight_mcweight_normalise;
   TBranch        *b_lepton_1_ID;   
   TBranch        *b_Tlepton_0_DFCommonAddAmbiguity;   
   TBranch        *b_nTight;   
   TBranch        *b_loose_eee;   
   TBranch        *b_Tlepton_0_charge;   
   TBranch        *b_SSem_passEtaCut;   
   TBranch        *b_SSee_passECIDS;   
   TBranch        *b_SSem_passECIDS;   
   TBranch        *b_OSem_passECIDS;   
   TBranch        *b_OSem_passEtaCut;   
   TBranch        *b_OSee_passECIDS;   
   TBranch        *b_lepton_0_truthClassificationSM4t_bkgFlag;   
   TBranch        *b_lepton_1_DFCommonAddAmbiguity;   
   TBranch        *b_lepton_1_truthClassificationSM4t_bkgFlag;   
   TBranch        *b_lepton_2_truthClassificationSM4t_bkgFlag;   
   TBranch        *b_Evt_Channel;   
   TBranch        *b_lepton_2_ID;   
   TBranch        *b_lepton_0_ID;   
   TBranch        *b_lepton_0_ambiguityType;   
   TBranch        *b_ttW_CRFlag;   
   TBranch        *b_loose_SSem;   
   TBranch        *b_Tlepton_2_ambiguityType;   
   TBranch        *b_lepton_0_DFCommonAddAmbiguity;   
   TBranch        *b_lepton_2_DFCommonAddAmbiguity;   
   TBranch        *b_lepton_1_ambiguityType;   
   TBranch        *b_lepton_2_ambiguityType;   
   TBranch        *b_OSee_passEtaCut;   
   TBranch        *b_Tlepton_1_ID;   
   TBranch        *b_Tlepton_2_ID;   
   TBranch        *b_Tlepton_1_DFCommonAddAmbiguity;   
   TBranch        *b_Tlepton_2_DFCommonAddAmbiguity;   


   QmisID_count(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~QmisID_count() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   //User added functions
   //You add functions here
   int ReadLimited(int level, Long64_t entry); //This is an important function.
   void SetHstFileName(const char *HstFileName){ _HstFileName = HstFileName;}
   void SetSumFileName1(const char *SumFileName1){ _SumFileName1 = SumFileName1;}
   void SetSumFileName2(const char *SumFileName2){ _SumFileName2 = SumFileName2;}
   void SetSample(int sample){_sample=sample;}
   void SetVerbose(int verbose){ _verbosity = verbose; }
   void SetData(int data){_data=data;}
   void SetSumWeights(float SumWeights){_sumWeights = SumWeights;} 
   void BookHistograms();
   Int_t min_delR(vector<double> deltaR);
   bool pass_muon_cuts(int level, int i, TLorentzVector v);
   bool pass_electron_cuts(int level, int i, TLorentzVector v);
   //bool pass_tau_cuts(int level, int i, TLorentzVector v); 
   //bool pass_jet_cuts(int level, int i, TLorentzVector v);
   //bool pass_photon_cuts(int level, int i, TLorentzVector v);
   float delta_phi(float phi1, float phi2);
   float delta_r(float deltaeta, float deltaphi);
   Double_t delR(TLorentzVector v1,  TLorentzVector v2);
   double weight(int data);
   double weight_closure(TLorentzVector l1, TLorentzVector l2);

 public:
   struct Hists {
     //Declare the histograms you want in here.
     TH1F *ss_Muons, *ss_Electrons, *ss_Jets,*ss_n_Btags, *ss_OSee, *ss_loose_SSee;

     TH1D *ss_HT, *ss_HT_Jets, *ss_met, *ss_M_ll[2]; 
     TH1D *ss_lep_pt[3], *ss_lep_eta[3], *ss_lep_pt_Q[3], *ss_lep_e[3];
     TH2D *ss_pt_eta[2];

     TH1F *os_Muons, *os_Electrons, *os_Jets,*os_n_Btags, *os_OSee, *os_loose_SSee;

     TH1D *os_HT, *os_HT_Jets, *os_met, *os_M_ll[2]; 
     TH1D *os_lep_pt[3], *os_lep_eta[3], *os_lep_pt_Q[3], *os_lep_e[3];
     TH2D *os_pt_eta[2];

   };
   struct Lepton {
     TLorentzVector v;
     int id;
     int ind;
     float wt;
     int flavor;
   };   
 protected:
   Hists h;

 private:
   //Global variables go here. Make them global only if necessary.
   TFile *_HstFile;
   const char *_HstFileName;
   const char *_SumFileName1;
   const char *_SumFileName2;
   int _verbosity;
   int _sample;
   float GEV, MEV2GEV;
   int nEvtTotal;
   int _data;
   float _sumWeights;
   float Sum;
   float MW_high;
   float MW_low;

   float h_OS[5][6][5][6]= {.0};
   float h_SS[5][6][5][6] ={.0};
   int pt_bins =5;
   int eta_bins = 6;
   float etaBins[7] = {0,0.6,1.1,1.52,1.7,2.3,2.5};
   float pTBins[6] = {15,45,60,90,130,1000};
   float sigma = 3;


   /* vector<Lepton> goodMu;//,goodEle, goodPho,goodTau,goodJet, goodLep; */
   /* vector<Lepton> goodEle;//(sl) */
   /* vector<Lepton> goodPart; */
   /* vector<Lepton> goodRecoEle; */
   /* vector<Lepton> goodRecoMu; */


   void Sort(int opt, vector<Lepton> good);
   ClassDef(QmisID_count,0);
};

#endif

#ifdef QmisID_count_cxx
void QmisID_count::Init(TTree *tree)
{

  mu_pt = 0;
  mu_eta = 0;
  mu_phi = 0;
  mu_e = 0;
  mu_charge = 0;
  el_truthPdgId = 0;
  el_true_firstEgMotherPdgId = 0;
  el_true_pdg = 0;
  el_true_type = 0;
  el_true_origin = 0;
  el_isPrompt = 0;
  el_true_firstEgMotherTruthType = 0;
  el_true_firstEgMotherTruthOrigin = 0;
  el_ECIDSResult_float = 0;
  el_sumTrackPt = 0;
  el_separationMinDCT = 0;
  el_leadTrackPt = 0;
  el_leadSubleadDr = 0;
  el_leadSubleadDphi = 0;
  el_leadSubleadDeta = 0;
  el_deltaPhi2 = 0;
  el_bestmatchSiTrackEta = 0;
  el_closestSiTrackEta = 0;
  el_RadiusCO = 0;
  el_delta_z0_sintheta = 0;
  el_closestSiTracknIL = 0;
  el_closestSiTrackPhi = 0;
  el_d0sig = 0;
  el_PromptLeptonVeto = 0;
  el_topoetcone20 = 0;
  el_closestSiTrackeIL = 0;
  el_MeeCO = 0;
  el_bestmatchSiTrackPt = 0;
  el_bestmatchSiTrackPhi = 0;
  el_bestmatchSiTrackZ0 = 0;
  el_subleadTrackPt = 0;
  el_closestSiTrackQ = 0;
  el_closestSiTrackD0 = 0;
  el_closestSiTracknNIL = 0;
  el_bestmatchSiTrackQ = 0;
  el_closestSiTrackPt = 0;
  el_bestmatchSiTrackD0 = 0;
  el_closestSiTrackZ0 = 0;
  el_isoLooseTrackOnly = 0;
  el_isoLoose = 0;
  el_isoGradientLoose = 0;
  el_isoGradient = 0;
  el_LHMedium = 0;
  el_isoFixedCutTightTrackOnly = 0;
  el_ECIDS = 0;
  el_LHTight = 0;
  el_isTight = 0;
  el_isoFixedCutLoose = 0;
  el_isoFixedCutTight = 0;
  mu_true_origin = 0;
  mu_true_type = 0;
  mu_isPrompt = 0;
  mu_true_pdg = 0;
  mu_d0sig = 0;
  mu_delta_z0_sintheta = 0;
  mu_topoetcone20 = 0;
  mu_PromptLeptonVeto = 0;
  mu_isoLooseTrackOnly = 0;
  mu_isoLoose = 0;
  mu_isoGradientLoose = 0;
  mu_Tight = 0;
  mu_Medium = 0;
  mu_isoFixedCutLoose = 0;
  mu_isoFixedCutTightTrackOnly = 0;
  mu_isoGradient = 0;
  mc_generator_weights = 0;
  weight_mcweight_name = 0;
  weight_mcweight_normalise = 0;

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);
   fChain->SetBranchAddress("boostedRecoHiggsPt", &boostedRecoHiggsPt, &b_boostedRecoHiggsPt);
   fChain->SetBranchAddress("lep_2_pt", &lep_2_pt, &b_lep_2_pt);
   fChain->SetBranchAddress("lep_1_e", &lep_1_e, &b_lep_1_e);
   fChain->SetBranchAddress("lep_0_eta", &lep_0_eta, &b_lep_0_eta);
   fChain->SetBranchAddress("lep_2_charge", &lep_2_charge, &b_lep_2_charge);
   fChain->SetBranchAddress("GenFiltHT", &GenFiltHT, &b_GenFiltHT);
   fChain->SetBranchAddress("lep_0_e", &lep_0_e, &b_lep_0_e);
   fChain->SetBranchAddress("mJSum", &mJSum, &b_mJSum);
   fChain->SetBranchAddress("lep_2_phi", &lep_2_phi, &b_lep_2_phi);
   fChain->SetBranchAddress("lep_0_phi", &lep_0_phi, &b_lep_0_phi);
   fChain->SetBranchAddress("HT_all", &HT_all, &b_HT_all);
   fChain->SetBranchAddress("lep_1_pt", &lep_1_pt, &b_lep_1_pt);
   fChain->SetBranchAddress("lep_0_pt", &lep_0_pt, &b_lep_0_pt);
   fChain->SetBranchAddress("HT_jets", &HT_jets, &b_HT_jets);
   fChain->SetBranchAddress("lep_1_phi", &lep_1_phi, &b_lep_1_phi);
   fChain->SetBranchAddress("lep_2_e", &lep_2_e, &b_lep_2_e);
   fChain->SetBranchAddress("lep_0_charge", &lep_0_charge, &b_lep_0_charge);
   fChain->SetBranchAddress("lep_1_eta", &lep_1_eta, &b_lep_1_eta);
   fChain->SetBranchAddress("lep_1_charge", &lep_1_charge, &b_lep_1_charge);
   fChain->SetBranchAddress("lep_2_eta", &lep_2_eta, &b_lep_2_eta);
   fChain->SetBranchAddress("TopHeavyFlavorFilterFlag", &TopHeavyFlavorFilterFlag, &b_TopHeavyFlavorFilterFlag);
   fChain->SetBranchAddress("nJets", &nJets, &b_nJets);
   fChain->SetBranchAddress("nRCJetsM100", &nRCJetsM100, &b_nRCJetsM100);
   fChain->SetBranchAddress("nPrimaryVtx", &nPrimaryVtx, &b_nPrimaryVtx);
   fChain->SetBranchAddress("mmm", &mmm, &b_mmm);
   fChain->SetBranchAddress("nMuons", &nMuons, &b_nMuons);
   fChain->SetBranchAddress("nBTags_DL1r_70", &nBTags_DL1r_70, &b_nBTags_DL1r_70);
   fChain->SetBranchAddress("SSem", &SSem, &b_SSem);
   fChain->SetBranchAddress("nElectrons", &nElectrons, &b_nElectrons);
   fChain->SetBranchAddress("eee", &eee, &b_eee);
   fChain->SetBranchAddress("eee_Zveto", &eee_Zveto, &b_eee_Zveto);
   fChain->SetBranchAddress("mmm_Zveto", &mmm_Zveto, &b_mmm_Zveto);
   fChain->SetBranchAddress("emm", &emm, &b_emm);
   fChain->SetBranchAddress("lep_1_pdgid", &lep_1_pdgid, &b_lep_1_pdgid);
   fChain->SetBranchAddress("emm_Zveto", &emm_Zveto, &b_emm_Zveto);
   fChain->SetBranchAddress("loose_SSee", &loose_SSee, &b_loose_SSee);
   fChain->SetBranchAddress("eem", &eem, &b_eem);
   fChain->SetBranchAddress("OSee", &OSee, &b_OSee);
   fChain->SetBranchAddress("eem_Zveto", &eem_Zveto, &b_eem_Zveto);
   fChain->SetBranchAddress("lep_0_pdgid", &lep_0_pdgid, &b_lep_0_pdgid);
   fChain->SetBranchAddress("nBTags_DL1r_85", &nBTags_DL1r_85, &b_nBTags_DL1r_85);
   fChain->SetBranchAddress("nRCJets", &nRCJets, &b_nRCJets);
   fChain->SetBranchAddress("nBTags_DL1r_60", &nBTags_DL1r_60, &b_nBTags_DL1r_60);
   fChain->SetBranchAddress("nBTags_DL1r_77", &nBTags_DL1r_77, &b_nBTags_DL1r_77);
   fChain->SetBranchAddress("randomRunNumber", &randomRunNumber, &b_randomRunNumber);
   fChain->SetBranchAddress("passedOfflineBoostedSelection", &passedOfflineBoostedSelection, &b_passedOfflineBoostedSelection);
   fChain->SetBranchAddress("lep_1_isTight", &lep_1_isTight, &b_lep_1_isTight);
   fChain->SetBranchAddress("lep_0_isTight", &lep_0_isTight, &b_lep_0_isTight);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("mu_pt", &mu_pt, &b_mu_pt);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_e", &mu_e, &b_mu_e);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("met_met", &met_met, &b_met_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("el_truthPdgId", &el_truthPdgId, &b_el_truthPdgId);
   fChain->SetBranchAddress("el_true_firstEgMotherPdgId", &el_true_firstEgMotherPdgId, &b_el_true_firstEgMotherPdgId);
   fChain->SetBranchAddress("el_true_pdg", &el_true_pdg, &b_el_true_pdg);
   fChain->SetBranchAddress("el_true_type", &el_true_type, &b_el_true_type);
   fChain->SetBranchAddress("el_true_origin", &el_true_origin, &b_el_true_origin);
   fChain->SetBranchAddress("el_isPrompt", &el_isPrompt, &b_el_isPrompt);
   fChain->SetBranchAddress("el_true_firstEgMotherTruthType", &el_true_firstEgMotherTruthType, &b_el_true_firstEgMotherTruthType);
   fChain->SetBranchAddress("el_true_firstEgMotherTruthOrigin", &el_true_firstEgMotherTruthOrigin, &b_el_true_firstEgMotherTruthOrigin);
   fChain->SetBranchAddress("el_ECIDSResult_float", &el_ECIDSResult_float, &b_el_ECIDSResult_float);
   fChain->SetBranchAddress("el_sumTrackPt", &el_sumTrackPt, &b_el_sumTrackPt);
   fChain->SetBranchAddress("el_separationMinDCT", &el_separationMinDCT, &b_el_separationMinDCT);
   fChain->SetBranchAddress("el_leadTrackPt", &el_leadTrackPt, &b_el_leadTrackPt);
   fChain->SetBranchAddress("el_leadSubleadDr", &el_leadSubleadDr, &b_el_leadSubleadDr);
   fChain->SetBranchAddress("el_leadSubleadDphi", &el_leadSubleadDphi, &b_el_leadSubleadDphi);
   fChain->SetBranchAddress("el_leadSubleadDeta", &el_leadSubleadDeta, &b_el_leadSubleadDeta);
   fChain->SetBranchAddress("el_deltaPhi2", &el_deltaPhi2, &b_el_deltaPhi2);
   fChain->SetBranchAddress("el_bestmatchSiTrackEta", &el_bestmatchSiTrackEta, &b_el_bestmatchSiTrackEta);
   fChain->SetBranchAddress("el_closestSiTrackEta", &el_closestSiTrackEta, &b_el_closestSiTrackEta);
   fChain->SetBranchAddress("el_RadiusCO", &el_RadiusCO, &b_el_RadiusCO);
   fChain->SetBranchAddress("el_delta_z0_sintheta", &el_delta_z0_sintheta, &b_el_delta_z0_sintheta);
   fChain->SetBranchAddress("el_closestSiTracknIL", &el_closestSiTracknIL, &b_el_closestSiTracknIL);
   fChain->SetBranchAddress("el_closestSiTrackPhi", &el_closestSiTrackPhi, &b_el_closestSiTrackPhi);
   fChain->SetBranchAddress("el_d0sig", &el_d0sig, &b_el_d0sig);
   fChain->SetBranchAddress("el_PromptLeptonVeto", &el_PromptLeptonVeto, &b_el_PromptLeptonVeto);
   fChain->SetBranchAddress("el_topoetcone20", &el_topoetcone20, &b_el_topoetcone20);
   fChain->SetBranchAddress("el_closestSiTrackeIL", &el_closestSiTrackeIL, &b_el_closestSiTrackeIL);
   fChain->SetBranchAddress("el_MeeCO", &el_MeeCO, &b_el_MeeCO);
   fChain->SetBranchAddress("el_bestmatchSiTrackPt", &el_bestmatchSiTrackPt, &b_el_bestmatchSiTrackPt);
   fChain->SetBranchAddress("el_bestmatchSiTrackPhi", &el_bestmatchSiTrackPhi, &b_el_bestmatchSiTrackPhi);
   fChain->SetBranchAddress("el_bestmatchSiTrackZ0", &el_bestmatchSiTrackZ0, &b_el_bestmatchSiTrackZ0);
   fChain->SetBranchAddress("el_subleadTrackPt", &el_subleadTrackPt, &b_el_subleadTrackPt);
   fChain->SetBranchAddress("el_closestSiTrackQ", &el_closestSiTrackQ, &b_el_closestSiTrackQ);
   fChain->SetBranchAddress("el_closestSiTrackD0", &el_closestSiTrackD0, &b_el_closestSiTrackD0);
   fChain->SetBranchAddress("el_closestSiTracknNIL", &el_closestSiTracknNIL, &b_el_closestSiTracknNIL);
   fChain->SetBranchAddress("el_bestmatchSiTrackQ", &el_bestmatchSiTrackQ, &b_el_bestmatchSiTrackQ);
   fChain->SetBranchAddress("el_closestSiTrackPt", &el_closestSiTrackPt, &b_el_closestSiTrackPt);
   fChain->SetBranchAddress("el_bestmatchSiTrackD0", &el_bestmatchSiTrackD0, &b_el_bestmatchSiTrackD0);
   fChain->SetBranchAddress("el_closestSiTrackZ0", &el_closestSiTrackZ0, &b_el_closestSiTrackZ0);
   fChain->SetBranchAddress("el_isoLooseTrackOnly", &el_isoLooseTrackOnly, &b_el_isoLooseTrackOnly);
   fChain->SetBranchAddress("el_isoLoose", &el_isoLoose, &b_el_isoLoose);
   fChain->SetBranchAddress("el_isoGradientLoose", &el_isoGradientLoose, &b_el_isoGradientLoose);
   fChain->SetBranchAddress("el_isoGradient", &el_isoGradient, &b_el_isoGradient);
   fChain->SetBranchAddress("el_LHMedium", &el_LHMedium, &b_el_LHMedium);
   fChain->SetBranchAddress("el_isoFixedCutTightTrackOnly", &el_isoFixedCutTightTrackOnly, &b_el_isoFixedCutTightTrackOnly);
   fChain->SetBranchAddress("el_ECIDS", &el_ECIDS, &b_el_ECIDS);
   fChain->SetBranchAddress("el_LHTight", &el_LHTight, &b_el_LHTight);
   fChain->SetBranchAddress("el_isTight", &el_isTight, &b_el_isTight);
   fChain->SetBranchAddress("el_isoFixedCutLoose", &el_isoFixedCutLoose, &b_el_isoFixedCutLoose);
   fChain->SetBranchAddress("el_isoFixedCutTight", &el_isoFixedCutTight, &b_el_isoFixedCutTight);
   fChain->SetBranchAddress("mu_true_origin", &mu_true_origin, &b_mu_true_origin);
   fChain->SetBranchAddress("mu_true_type", &mu_true_type, &b_mu_true_type);
   fChain->SetBranchAddress("mu_isPrompt", &mu_isPrompt, &b_mu_isPrompt);
   fChain->SetBranchAddress("mu_true_pdg", &mu_true_pdg, &b_mu_true_pdg);
   fChain->SetBranchAddress("mu_d0sig", &mu_d0sig, &b_mu_d0sig);
   fChain->SetBranchAddress("mu_delta_z0_sintheta", &mu_delta_z0_sintheta, &b_mu_delta_z0_sintheta);
   fChain->SetBranchAddress("mu_topoetcone20", &mu_topoetcone20, &b_mu_topoetcone20);
   fChain->SetBranchAddress("mu_PromptLeptonVeto", &mu_PromptLeptonVeto, &b_mu_PromptLeptonVeto);
   fChain->SetBranchAddress("mu_isoLooseTrackOnly", &mu_isoLooseTrackOnly, &b_mu_isoLooseTrackOnly);
   fChain->SetBranchAddress("mu_isoLoose", &mu_isoLoose, &b_mu_isoLoose);
   fChain->SetBranchAddress("mu_isoGradientLoose", &mu_isoGradientLoose, &b_mu_isoGradientLoose);
   fChain->SetBranchAddress("mu_Tight", &mu_Tight, &b_mu_Tight);
   fChain->SetBranchAddress("mu_isTight", &mu_isTight, &b_mu_isTight);
   fChain->SetBranchAddress("mu_Medium", &mu_Medium, &b_mu_Medium);
   fChain->SetBranchAddress("mu_isoFixedCutLoose", &mu_isoFixedCutLoose, &b_mu_isoFixedCutLoose);
   fChain->SetBranchAddress("mu_isoFixedCutTightTrackOnly", &mu_isoFixedCutTightTrackOnly, &b_mu_isoFixedCutTightTrackOnly);
   fChain->SetBranchAddress("mu_isoGradient", &mu_isoGradient, &b_mu_isoGradient);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("weight_leptonSF", &weight_leptonSF, &b_weight_leptonSF);
   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("weight_jvt", &weight_jvt, &b_weight_jvt);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_77", &weight_bTagSF_DL1r_77, &b_weight_bTagSF_DL1r_77);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_70", &weight_bTagSF_DL1r_70, &b_weight_bTagSF_DL1r_70);
   fChain->SetBranchAddress("weight_ttbar_FracRw", &weight_ttbar_FracRw, &b_weight_ttbar_FracRw);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_60", &weight_bTagSF_DL1r_60, &b_weight_bTagSF_DL1r_60);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_85", &weight_bTagSF_DL1r_85, &b_weight_bTagSF_DL1r_85);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous", &weight_bTagSF_DL1r_Continuous, &b_weight_bTagSF_DL1r_Continuous);
   fChain->SetBranchAddress("weight_indiv_SF_MU_TTVA", &weight_indiv_SF_MU_TTVA, &b_weight_indiv_SF_MU_TTVA);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID", &weight_indiv_SF_MU_ID, &b_weight_indiv_SF_MU_ID);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Isol", &weight_indiv_SF_EL_Isol, &b_weight_indiv_SF_EL_Isol);
   fChain->SetBranchAddress("weight_indiv_SF_MU_Isol", &weight_indiv_SF_MU_Isol, &b_weight_indiv_SF_MU_Isol);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Reco", &weight_indiv_SF_EL_Reco, &b_weight_indiv_SF_EL_Reco);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ID", &weight_indiv_SF_EL_ID, &b_weight_indiv_SF_EL_ID);
   fChain->SetBranchAddress("mc_generator_weights", &mc_generator_weights, &b_mc_generator_weights);
   fChain->SetBranchAddress("weight_normalise", &weight_normalise, &b_weight_normalise);
   fChain->SetBranchAddress("weight_mcweight_name", &weight_mcweight_name, &b_weight_mcweight_name);
   fChain->SetBranchAddress("weight_mcweight_normalise", &weight_mcweight_normalise, &b_weight_mcweight_normalise);
   fChain->SetBranchAddress("lepton_1_ID", &lepton_1_ID, &b_lepton_1_ID);
   fChain->SetBranchAddress("Tlepton_0_DFCommonAddAmbiguity", &Tlepton_0_DFCommonAddAmbiguity, &b_Tlepton_0_DFCommonAddAmbiguity);
   fChain->SetBranchAddress("nTight", &nTight, &b_nTight);
   fChain->SetBranchAddress("loose_eee", &loose_eee, &b_loose_eee);
   fChain->SetBranchAddress("Tlepton_0_charge", &Tlepton_0_charge, &b_Tlepton_0_charge);
   fChain->SetBranchAddress("SSem_passEtaCut", &SSem_passEtaCut, &b_SSem_passEtaCut);
   fChain->SetBranchAddress("SSee_passECIDS", &SSee_passECIDS, &b_SSee_passECIDS);
   fChain->SetBranchAddress("SSem_passECIDS", &SSem_passECIDS, &b_SSem_passECIDS);
   fChain->SetBranchAddress("OSem_passECIDS", &OSem_passECIDS, &b_OSem_passECIDS);
   fChain->SetBranchAddress("OSem_passEtaCut", &OSem_passEtaCut, &b_OSem_passEtaCut);
   fChain->SetBranchAddress("OSee_passECIDS", &OSee_passECIDS, &b_OSee_passECIDS);
   fChain->SetBranchAddress("lepton_0_truthClassificationSM4t_bkgFlag", &lepton_0_truthClassificationSM4t_bkgFlag, &b_lepton_0_truthClassificationSM4t_bkgFlag);
   fChain->SetBranchAddress("lepton_1_DFCommonAddAmbiguity", &lepton_1_DFCommonAddAmbiguity, &b_lepton_1_DFCommonAddAmbiguity);
   fChain->SetBranchAddress("lepton_1_truthClassificationSM4t_bkgFlag", &lepton_1_truthClassificationSM4t_bkgFlag, &b_lepton_1_truthClassificationSM4t_bkgFlag);
   fChain->SetBranchAddress("lepton_2_truthClassificationSM4t_bkgFlag", &lepton_2_truthClassificationSM4t_bkgFlag, &b_lepton_2_truthClassificationSM4t_bkgFlag);
   fChain->SetBranchAddress("Evt_Channel", &Evt_Channel, &b_Evt_Channel);
   fChain->SetBranchAddress("lepton_2_ID", &lepton_2_ID, &b_lepton_2_ID);
   fChain->SetBranchAddress("lepton_0_ID", &lepton_0_ID, &b_lepton_0_ID);
   fChain->SetBranchAddress("lepton_0_ambiguityType", &lepton_0_ambiguityType, &b_lepton_0_ambiguityType);
   fChain->SetBranchAddress("ttW_CRFlag", &ttW_CRFlag, &b_ttW_CRFlag);
   fChain->SetBranchAddress("loose_SSem", &loose_SSem, &b_loose_SSem);
   fChain->SetBranchAddress("Tlepton_2_ambiguityType", &Tlepton_2_ambiguityType, &b_Tlepton_2_ambiguityType);
   fChain->SetBranchAddress("lepton_0_DFCommonAddAmbiguity", &lepton_0_DFCommonAddAmbiguity, &b_lepton_0_DFCommonAddAmbiguity);
   fChain->SetBranchAddress("lepton_2_DFCommonAddAmbiguity", &lepton_2_DFCommonAddAmbiguity, &b_lepton_2_DFCommonAddAmbiguity);
   fChain->SetBranchAddress("lepton_1_ambiguityType", &lepton_1_ambiguityType, &b_lepton_1_ambiguityType);
   fChain->SetBranchAddress("lepton_2_ambiguityType", &lepton_2_ambiguityType, &b_lepton_2_ambiguityType);
   fChain->SetBranchAddress("OSee_passEtaCut", &OSee_passEtaCut, &b_OSee_passEtaCut);
   fChain->SetBranchAddress("Tlepton_1_ID", &Tlepton_1_ID, &b_Tlepton_1_ID);
   fChain->SetBranchAddress("Tlepton_2_ID", &Tlepton_2_ID, &b_Tlepton_2_ID);
   fChain->SetBranchAddress("Tlepton_1_DFCommonAddAmbiguity", &Tlepton_1_DFCommonAddAmbiguity, &b_Tlepton_1_DFCommonAddAmbiguity);
   fChain->SetBranchAddress("Tlepton_2_DFCommonAddAmbiguity", &Tlepton_2_DFCommonAddAmbiguity, &b_Tlepton_2_DFCommonAddAmbiguity);

   Notify();
 }

Bool_t QmisID_count::Notify()
{
   return kTRUE;
}
int QmisID_count::ReadLimited(int level, Long64_t entry)
{
  // This function is meant to speed up your run-time.
  // It does this by not reading in all branches for an event,
  // but only those that we tell it to.
  // With level=0, the whole event is read-in. This is default behavior.
  // With level=1, you turn on only needed variables.

  if(level==0){ GetEntry(entry); return 1; }
  if(level==1){
    //Turn on only those branches that we need
    //Muon Variables
    b_lep_0_pt->GetEntry(entry);
    b_lep_1_pt->GetEntry(entry);
    /* /\* b_lep_2_pt->GetEntry(entry); *\/ */
    b_lep_0_e->GetEntry(entry);
    b_lep_1_e->GetEntry(entry);
    /* /\* b_lep_2_e->GetEntry(entry); *\/ */
    b_lep_0_eta->GetEntry(entry);
    b_lep_1_eta->GetEntry(entry);
    /* /\* b_lep_2_eta->GetEntry(entry); *\/ */
    b_lep_0_phi->GetEntry(entry);
    b_lep_1_phi->GetEntry(entry);
    /* /\* b_lep_2_phi->GetEntry(entry); *\/ */
    b_HT_all->GetEntry(entry);
    b_HT_jets->GetEntry(entry);
    /* /\* b_lep_0_charge->GetEntry(entry); *\/ */
    /* /\* b_lep_1_charge->GetEntry(entry); *\/ */
    /* /\* b_lep_2_charge->GetEntry(entry); *\/ */
    b_nMuons->GetEntry(entry);
    b_nElectrons->GetEntry(entry);
    b_nJets->GetEntry(entry);
    b_runNumber->GetEntry(entry);
    b_OSee->GetEntry(entry);
    b_loose_SSee->GetEntry(entry);
    /* /\* b_el_isTight->GetEntry(entry); *\/ */
    b_lep_0_isTight->GetEntry(entry);
    b_lep_1_isTight->GetEntry(entry);
    b_nBTags_DL1r_70->GetEntry(entry);
    b_nBTags_DL1r_77->GetEntry(entry);
    b_nBTags_DL1r_60->GetEntry(entry);
    b_nBTags_DL1r_85->GetEntry(entry);
    b_met_met->GetEntry(entry);
    b_el_ECIDSResult_float->GetEntry(entry);
    b_SSee_passECIDS->GetEntry(entry);
    b_SSem_passECIDS->GetEntry(entry);
    b_Tlepton_1_DFCommonAddAmbiguity->GetEntry(entry);
    b_Tlepton_0_DFCommonAddAmbiguity->GetEntry(entry);
    if(_data==0){
    b_mcChannelNumber->GetEntry(entry);
    b_weight_mc->GetEntry(entry);
    b_weight_normalise->GetEntry(entry);
    b_weight_indiv_SF_EL_ID->GetEntry(entry);
    b_weight_pileup->GetEntry(entry);
    b_weight_leptonSF->GetEntry(entry);
    b_weight_jvt->GetEntry(entry);
    b_weight_bTagSF_DL1r_Continuous->GetEntry(entry);
    }
    return 1;
  }
  
  return 0;
}
#endif // #ifdef QmisID_count_cxx

