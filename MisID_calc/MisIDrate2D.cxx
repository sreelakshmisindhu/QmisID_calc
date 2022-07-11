#include <fstream>

//int N_os[6][8][6][8]={0};
//int N_ss[6][8][6][8]={0};


int pt_bins =4;
int eta_bins =6;
float N_os[4][6][4][6]={0.};
float N_ss[4][6][4][6]={0.};


void myfunc(int &npar, double *gin, double &f, double *par, int iflag){

  float likelihood = 0.;

  for(int i=0;i<pt_bins;i++){
    for(int j=0;j<eta_bins;j++){
      for(int k=0;k<pt_bins;k++){
        for(int l=0;l<eta_bins;l++){
          if((N_ss[i][j][k][l]+N_os[i][j][k][l])>0){
	    likelihood+=log(1.0*(N_ss[i][j][k][l]+N_os[i][j][k][l])*(par[i+pt_bins*j]*(1-par[k+pt_bins*l])+par[k+pt_bins*l]*(1-par[i+pt_bins*j])))*N_ss[i][j][k][l] - 1.0*(N_ss[i][j][k][l]+N_os[i][j][k][l])*(par[i+pt_bins*j]*(1-par[k+pt_bins*l])+par[k+pt_bins*l]*(1-par[i+pt_bins*j]));}
//          likelihood+=log(1.0*(N_ss[i][j][k][l]+N_os[i][j][k][l])*(par[i+4*j]+par[k+4*l]))*N_ss[i][j][k][l] - 1.0*(N_ss[i][j][k][l]+N_os[i][j][k][l])*(par[i+4*j]+par[k+4*l]);}
        }
      }
    }
  }



  f=-likelihood;

}


void MisIDrate2D(std::string sample, std::string path, std::string outpath) {

  gStyle->SetOptStat(0);
  gStyle->SetErrorX(0.5);
//  SetAtlasStyle();

//  TFile* f0 = new TFile("2DMap.root","read");
//  TH2F* h_OS = (TH2F*)f0->Get("h_OS");
//  TH2F* h_SS = (TH2F*)f0->Get("h_SS");
  ifstream ss;
  ifstream os;
// input file
  ss.open((path+"ss."+sample+".txt").c_str());
  os.open((path+"os."+sample+".txt").c_str());

  std::string legend_title="data15-18 likelihood";
  std::string outputName=path+"outmisID."+sample+".root";

  float Nss;
  float Nos;

  int i=0,j=0,k=0,l=0;

  while(ss>>Nss){
    N_ss[i][j][k][l]=Nss;
    l++;
    if(l==eta_bins){l=0;k++;}
    if(k==pt_bins){k=0;j++;}
    if(j==eta_bins){j=0;i++;}
  }

  i=0;j=0;k=0;l=0;

  while(os>>Nos){
    N_os[i][j][k][l]=Nos;
    l++;
    if(l==eta_bins){l=0;k++;}
    if(k==pt_bins){k=0;j++;}
    if(j==eta_bins){j=0;i++;}
  }

  std::cout<<N_os[2][3][2][3]<<" "<<N_os[0][0][0][0]<<std::endl;

  TMinuit minuit(24);

  minuit.SetFCN(myfunc);

  double vstrt[24]={0};
  double stp[24]={0};
  double bmin[24]={0};
  double bmax[24]={0};
  for(int i=0;i<24;i++){vstrt[i]=0.001;stp[i]=0.0001;bmin[i]=0.;bmax[i]=1.0;}


  double arglist[10];
  int ierflg = 0;
  minuit.mnparm(0,"ptetabin1",vstrt[0],stp[0],bmin[0],bmax[0],ierflg);
  minuit.mnparm(1,"ptetabin2",vstrt[1],stp[1],bmin[1],bmax[1],ierflg);
  minuit.mnparm(2,"ptetabin3",vstrt[2],stp[2],bmin[2],bmax[2],ierflg);
  minuit.mnparm(3,"ptetabin4",vstrt[3],stp[3],bmin[3],bmax[3],ierflg);
  minuit.mnparm(4,"ptetabin5",vstrt[4],stp[4],bmin[4],bmax[4],ierflg);
  minuit.mnparm(5,"ptetabin6",vstrt[5],stp[5],bmin[5],bmax[5],ierflg);
  minuit.mnparm(6,"ptetabin7",vstrt[6],stp[6],bmin[6],bmax[6],ierflg);
  minuit.mnparm(7,"ptetabin8",vstrt[7],stp[7],bmin[7],bmax[7],ierflg);
  minuit.mnparm(8,"ptetabin9",vstrt[8],stp[8],bmin[8],bmax[8],ierflg);
  minuit.mnparm(9,"ptetabin10",vstrt[9],stp[9],bmin[9],bmax[9],ierflg);

  minuit.mnparm(10,"ptetabin11",vstrt[10],stp[10],bmin[10],bmax[10],ierflg);
  minuit.mnparm(11,"ptetabin12",vstrt[11],stp[11],bmin[11],bmax[11],ierflg);
  minuit.mnparm(12,"ptetabin13",vstrt[12],stp[12],bmin[12],bmax[12],ierflg);
  minuit.mnparm(13,"ptetabin14",vstrt[13],stp[13],bmin[13],bmax[13],ierflg);
  minuit.mnparm(14,"ptetabin15",vstrt[14],stp[14],bmin[14],bmax[14],ierflg);
  minuit.mnparm(15,"ptetabin16",vstrt[15],stp[15],bmin[15],bmax[15],ierflg);
  minuit.mnparm(16,"ptetabin17",vstrt[16],stp[16],bmin[16],bmax[16],ierflg);
  minuit.mnparm(17,"ptetabin18",vstrt[17],stp[17],bmin[17],bmax[17],ierflg);
  minuit.mnparm(18,"ptetabin19",vstrt[18],stp[18],bmin[18],bmax[18],ierflg);
  minuit.mnparm(19,"ptetabin20",vstrt[19],stp[19],bmin[19],bmax[19],ierflg);

  minuit.mnparm(20,"ptetabin21",vstrt[20],stp[20],bmin[20],bmax[20],ierflg);
  minuit.mnparm(21,"ptetabin22",vstrt[21],stp[21],bmin[21],bmax[21],ierflg);
  minuit.mnparm(22,"ptetabin23",vstrt[22],stp[22],bmin[22],bmax[22],ierflg);
  minuit.mnparm(23,"ptetabin24",vstrt[23],stp[23],bmin[23],bmax[23],ierflg);

  // minuit.mnparm(24,"ptetabin25",vstrt[24],stp[24],bmin[24],bmax[24],ierflg);
  // minuit.mnparm(25,"ptetabin26",vstrt[25],stp[25],bmin[25],bmax[25],ierflg);
  // minuit.mnparm(26,"ptetabin27",vstrt[26],stp[26],bmin[26],bmax[26],ierflg);
  // minuit.mnparm(27,"ptetabin28",vstrt[27],stp[27],bmin[27],bmax[27],ierflg);
  // minuit.mnparm(28,"ptetabin29",vstrt[28],stp[28],bmin[28],bmax[28],ierflg);
  // minuit.mnparm(29,"ptetabin30",vstrt[29],stp[29],bmin[29],bmax[29],ierflg);

  /*minuit.mnparm(30,"ptetabin31",vstrt[30],stp[30],bmin[30],bmax[30],ierflg);
  minuit.mnparm(31,"ptetabin32",vstrt[31],stp[31],bmin[31],bmax[31],ierflg);
  minuit.mnparm(32,"ptetabin33",vstrt[32],stp[32],bmin[32],bmax[32],ierflg);
  minuit.mnparm(33,"ptetabin34",vstrt[33],stp[33],bmin[33],bmax[33],ierflg);
  minuit.mnparm(34,"ptetabin35",vstrt[34],stp[34],bmin[34],bmax[34],ierflg);
  minuit.mnparm(35,"ptetabin36",vstrt[35],stp[35],bmin[35],bmax[35],ierflg);
  minuit.mnparm(36,"ptetabin37",vstrt[36],stp[36],bmin[36],bmax[36],ierflg);
  minuit.mnparm(37,"ptetabin38",vstrt[37],stp[37],bmin[37],bmax[37],ierflg);
  minuit.mnparm(38,"ptetabin39",vstrt[38],stp[38],bmin[38],bmax[38],ierflg);
  minuit.mnparm(39,"ptetabin40",vstrt[39],stp[39],bmin[39],bmax[39],ierflg);

  minuit.mnparm(40,"ptetabin41",vstrt[40],stp[40],bmin[40],bmax[40],ierflg);
  minuit.mnparm(41,"ptetabin42",vstrt[41],stp[41],bmin[41],bmax[41],ierflg);
  minuit.mnparm(42,"ptetabin43",vstrt[42],stp[42],bmin[42],bmax[42],ierflg);
  minuit.mnparm(43,"ptetabin44",vstrt[43],stp[43],bmin[43],bmax[43],ierflg);
  minuit.mnparm(44,"ptetabin45",vstrt[44],stp[44],bmin[44],bmax[44],ierflg);
  minuit.mnparm(45,"ptetabin46",vstrt[45],stp[45],bmin[45],bmax[45],ierflg);
  minuit.mnparm(46,"ptetabin47",vstrt[46],stp[46],bmin[46],bmax[46],ierflg);
  minuit.mnparm(47,"ptetabin48",vstrt[47],stp[47],bmin[47],bmax[47],ierflg);
*/

//  minuit.SetPrintLevel(-1);

  minuit.mnexcm("SET NOW", arglist,1,ierflg);

  minuit.SetErrorDef(0.5);

  arglist[0]=2;
  minuit.mnexcm("SET STR",arglist,1,ierflg); // 2-> more function calls, more reliable minimisation 1-> less function calls, faster

//  arglist[0]=1;
//  minuit.mnexcm("FIX ", arglist,1,ierflg);

//  minuit.FixParameter(0);

  arglist[0] = 200000;
  minuit.mnexcm("HESSE",arglist,1,ierflg);
  minuit.mnexcm("MIGRAD",arglist,1,ierflg);
  minuit.mnexcm("MINOS",arglist,1,ierflg);

  double p[24]={0.};
  double e[24]={0.};

  minuit.GetParameter(0,p[0],e[0]);
  minuit.GetParameter(1,p[1],e[1]);
  minuit.GetParameter(2,p[2],e[2]);
  minuit.GetParameter(3,p[3],e[3]);
  minuit.GetParameter(4,p[4],e[4]);
  minuit.GetParameter(5,p[5],e[5]);
  minuit.GetParameter(6,p[6],e[6]);
  minuit.GetParameter(7,p[7],e[7]);
  minuit.GetParameter(8,p[8],e[8]);
  minuit.GetParameter(9,p[9],e[9]);
  minuit.GetParameter(10,p[10],e[10]);
  minuit.GetParameter(11,p[11],e[11]);
  minuit.GetParameter(12,p[12],e[12]);
  minuit.GetParameter(13,p[13],e[13]);
  minuit.GetParameter(14,p[14],e[14]);
  minuit.GetParameter(15,p[15],e[15]);
  minuit.GetParameter(16,p[16],e[16]);
  minuit.GetParameter(17,p[17],e[17]);
  minuit.GetParameter(18,p[18],e[18]);
  minuit.GetParameter(19,p[19],e[19]);
  minuit.GetParameter(20,p[20],e[20]);
  minuit.GetParameter(21,p[21],e[21]);
  minuit.GetParameter(22,p[22],e[22]);
  minuit.GetParameter(23,p[23],e[23]);
  // minuit.GetParameter(24,p[24],e[24]);
  // minuit.GetParameter(25,p[25],e[25]);
  // minuit.GetParameter(26,p[26],e[26]);
  // minuit.GetParameter(27,p[27],e[27]);
  // minuit.GetParameter(28,p[28],e[28]);
  // minuit.GetParameter(29,p[29],e[29]);

  for(int i=0;i<24;i++){
    std::cout<<p[i]<<endl;}



  Float_t pTBins[5]={15,60,90,130,1000};
  Float_t etaBins[7]={0,0.6,1.1,1.52,1.7,2.3,2.5};

  TFile* output= new TFile(outputName.c_str(),"recreate");

  TH1F* h1_dummy = new TH1F("h1_dummy","",eta_bins,etaBins);
  TH1F* h2_dummy = new TH1F("h2_dummy","",pt_bins,pTBins);

//  TH1F* h1_dummy = new TH1F("h1_dummy","QmisID vs el eta",8,etaBins);
  h1_dummy->GetXaxis()->SetTitle("electron |#eta|");
  h1_dummy->GetYaxis()->SetTitle("charge mis ID rate");
  h1_dummy->GetYaxis()->SetRangeUser(1e-5,0.5);

  h2_dummy->GetXaxis()->SetTitle("electron p_{T} [GeV]");
  h2_dummy->GetYaxis()->SetTitle("charge mis ID rate");
  h2_dummy->GetYaxis()->SetRangeUser(1e-5,0.5);

  TH1F* h1_pT1 = (TH1F*)h1_dummy->Clone("h1_pT1");
  TH1F* h1_pT2 = (TH1F*)h1_dummy->Clone("h1_pT2");
  TH1F* h1_pT3 = (TH1F*)h1_dummy->Clone("h1_pT3");
  TH1F* h1_pT4 = (TH1F*)h1_dummy->Clone("h1_pT4");
  TH1F* h1_pT5 = (TH1F*)h1_dummy->Clone("h1_pT5");

  TH1F* h2_eta1 = (TH1F*)h2_dummy->Clone("h1_eta1");
  TH1F* h2_eta2 = (TH1F*)h2_dummy->Clone("h1_eta2");
  TH1F* h2_eta3 = (TH1F*)h2_dummy->Clone("h1_eta3");
  TH1F* h2_eta4 = (TH1F*)h2_dummy->Clone("h1_eta4");
  TH1F* h2_eta5 = (TH1F*)h2_dummy->Clone("h1_eta5");
  TH1F* h2_eta6 = (TH1F*)h2_dummy->Clone("h1_eta6");



  h1_pT1->SetLineColor(8);h1_pT1->SetMarkerColor(8);h1_pT1->SetMarkerStyle(20);
  h1_pT2->SetLineColor(3);h1_pT2->SetMarkerColor(3);h1_pT2->SetMarkerStyle(20);
  h1_pT3->SetLineColor(4);h1_pT3->SetMarkerColor(4);h1_pT3->SetMarkerStyle(20);
  h1_pT4->SetLineColor(6);h1_pT4->SetMarkerColor(6);h1_pT4->SetMarkerStyle(20);
  h1_pT5->SetLineColor(7);h1_pT5->SetMarkerColor(7);h1_pT5->SetMarkerStyle(20);

  h2_eta1->SetLineColor(2);h2_eta1->SetMarkerColor(2);h2_eta1->SetMarkerStyle(20);
  h2_eta2->SetLineColor(4);h2_eta2->SetMarkerColor(4);h2_eta2->SetMarkerStyle(20);
  h2_eta3->SetLineColor(6);h2_eta3->SetMarkerColor(6);h2_eta3->SetMarkerStyle(20);
  h2_eta4->SetLineColor(7);h2_eta4->SetMarkerColor(7);h2_eta4->SetMarkerStyle(20);
  h2_eta5->SetLineColor(8);h2_eta5->SetMarkerColor(8);h2_eta5->SetMarkerStyle(20);
  h2_eta6->SetLineColor(9);h2_eta6->SetMarkerColor(9);h2_eta6->SetMarkerStyle(20);

  for(int i=1;i<eta_bins+1;i++){
    // h1_pT1->SetBinContent(i,p[pt_bins*i-5]);h1_pT1->SetBinError(i,e[pt_bins*i-5]);
    h1_pT2->SetBinContent(i,p[pt_bins*i-4]);h1_pT2->SetBinError(i,e[pt_bins*i-4]);
    h1_pT3->SetBinContent(i,p[pt_bins*i-3]);h1_pT3->SetBinError(i,e[pt_bins*i-3]);
    h1_pT4->SetBinContent(i,p[pt_bins*i-2]);h1_pT4->SetBinError(i,e[pt_bins*i-2]);
    h1_pT5->SetBinContent(i,p[pt_bins*i-1]);h1_pT5->SetBinError(i,e[pt_bins*i-1]);
  }

    for(int i=1;i<pt_bins+1;i++){
    h2_eta1->SetBinContent(i,p[i-1]);h2_eta1->SetBinError(i,e[i-1]);
    h2_eta2->SetBinContent(i,p[1*pt_bins+i-1]);h2_eta2->SetBinError(i,e[1*pt_bins+i-1]);
    h2_eta3->SetBinContent(i,p[2*pt_bins+i-1]);h2_eta3->SetBinError(i,e[2*pt_bins+i-1]);
    h2_eta4->SetBinContent(i,p[3*pt_bins+i-1]);h2_eta4->SetBinError(i,e[3*pt_bins+i-1]);
    h2_eta5->SetBinContent(i,p[4*pt_bins+i-1]);h2_eta5->SetBinError(i,e[4*pt_bins+i-1]);
    h2_eta6->SetBinContent(i,p[5*pt_bins+i-1]);h2_eta6->SetBinError(i,e[5*pt_bins+i-1]);
  }


  TCanvas* myCan = new TCanvas("myCan","canvas",900,700);


//  TLegend* lg = new TLegend(0.35,0.5,0.55,0.8);
//charge misID
//  TLegend* lg = new TLegend(0.3,0.6,0.60,0.9,legend_title.c_str());
//nominal

  TLegend* lg = new TLegend(0.65,0.1,0.85,0.4,"");
  // lg->AddEntry(h1_pT1,"pT [15,40] GeV");
  lg->AddEntry(h1_pT2,"pT [15,40] GeV");
  lg->AddEntry(h1_pT3,"pT [40,50] GeV");
  lg->AddEntry(h1_pT4,"pT [50,60] GeV");
  lg->AddEntry(h1_pT5,"pT [60,1000] GeV");

  lg->SetBorderSize(0);
  lg->SetFillStyle(0);

  h1_dummy->Draw();
  // h1_pT1->Draw("lp same");
  h1_pT2->Draw("lp same");
  h1_pT3->Draw("lp same");
  h1_pT4->Draw("lp same");
  h1_pT5->Draw("lp same");
  lg->Draw("same");

  gPad->SetLogy();

  // h1_pT1->Write();
  h1_pT2->Write();
  h1_pT3->Write();
  h1_pT4->Write();
  h1_pT5->Write();
  myCan->Write();
  myCan->SaveAs((outpath+"misID."+sample+"_etabins.pdf").c_str());
  myCan->SaveAs((outpath+"misID."+sample+"_etabins.png").c_str());

  TCanvas* etaCan = new TCanvas("etaCan","canvas",900,700);

  TLegend* lg2 = new TLegend(0.65,0.1,0.85,0.35);
  lg2->AddEntry(h2_eta1,"|#eta| [0,0.6]" );
  lg2->AddEntry(h2_eta2,"|#eta| [0.6,1.1]" );
  lg2->AddEntry(h2_eta3,"|#eta| [1.1,1.52]" );
  lg2->AddEntry(h2_eta4,"|#eta| [1.52,1.7]" );
  lg2->AddEntry(h2_eta5,"|#eta| [1.7,2.3]" );
  lg2->AddEntry(h2_eta6,"|#eta| [2.3,2.5]" );

  lg2->SetBorderSize(0);
  lg2->SetFillStyle(0);
  etaCan->cd();

  h2_dummy->Draw();
  h2_eta1->Draw("lp same");
  h2_eta2->Draw("lp same");
  h2_eta3->Draw("lp same");
  h2_eta4->Draw("lp same");
  h2_eta5->Draw("lp same");
  h2_eta6->Draw("lp same");
  lg2->Draw("same");
  gPad->SetLogy();
  gPad->SetLogx();

  h2_eta1->Write();
  h2_eta2->Write();
  h2_eta3->Write();
  h2_eta4->Write();
  h2_eta5->Write();
  h2_eta6->Write();
  etaCan->Write();
  etaCan->SaveAs((outpath+"misID."+sample+"_ptbins.pdf").c_str());
  etaCan->SaveAs((outpath+"misID."+sample+"_ptbins.png").c_str());


  output->Close();




}
