#include "TCanvas.h"
#include "TFrame.h"
#include "TBenchmark.h"
#include "TString.h"
#include "TF1.h"
#include "TH1.h"
#include "TFile.h"
#include "TROOT.h"
#include "TError.h"
#include "TInterpreter.h"
#include "TSystem.h"
#include "TPaveText.h"

double DoubleSidedCrystalballFunction(double *x, double *par)
 { 
   double alpha_l = par[0]; 
   double alpha_h = par[1]; 
   double n_l     = par[2]; 
   double n_h     = par[3]; 
     double mean= par[4]; 
     double sigma= par[5];
     double N= par[6];
   float t = (x[0]-mean)/sigma;
   double result;
   double fact1TLessMinosAlphaL = alpha_l/n_l;
double fact2TLessMinosAlphaL = (n_l/alpha_l) - alpha_l -t;
   double fact1THihgerAlphaH = alpha_h/n_h;
   double fact2THigherAlphaH = (n_h/alpha_h) - alpha_h +t;
   
   if (-alpha_l <= t && alpha_h >= t)
     {
       result = exp(-0.5*t*t);
     }
   else if (t < -alpha_l)
     {
       
       result = exp(-0.5*alpha_l*alpha_l)*pow(fact1TLessMinosAlphaL*fact2TLessMinosAlphaL, -n_l);
       
     }
   else if (t > alpha_h)
     {
       result = exp(-0.5*alpha_h*alpha_h)*pow(fact1THihgerAlphaH*fact2THigherAlphaH, -n_h);       
     }
   return N*result;
 }
 
void fit_cb()
{
  TCanvas *c1 = new TCanvas("c1","c1",700,500);
  TPad* thePad = (TPad*)c1->cd();
  TFile *f = new TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/no_bg_no_cuts/data_all.root");
  TH1F *hpx = (TH1F*)f->Get("ss_Mll_small");
  TF1 *fitDSCB = new TF1("fitDSCB",DoubleSidedCrystalballFunction, 60,120, 7);
  // hpx->GetYaxis()->SetRangeUser(0, 30);
  gStyle->SetOptFit(1);
  fitDSCB->SetParameters(1, 2, 2, 1, hpx->GetMean(), hpx->GetRMS(),hpx->Integral(60, 120));
  fitDSCB->SetParNames ("alpha_{low}","alpha_{high}","n_{low}", "n_{high}", "mean", "sigma", "Norm");
  hpx->Fit(fitDSCB, "", "", 60, 120);
  Double_t chi2 = fitDSCB->GetChisquare();
  cout << "chi2 = " << chi2 << endl; 
  hpx->Draw("func");
  hpx->Draw("ep");
  hpx->GetXaxis()->SetRangeUser(60, 120);
  thePad->Print("DSCBFit.pdf");
  
}
