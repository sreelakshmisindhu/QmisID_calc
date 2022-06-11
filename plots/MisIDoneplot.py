import ROOT as root
import atlasplots as aplt
import numpy as np
from ROOT import TFile
from ROOT import TH1


def uncs(outPath):
    aplt.set_atlas_style()
    fig, (ax1, ax2) = aplt.ratio_plot(name="fig1", figsize=(800, 800), hspace=0.05)

    pTBins=[8,60,90,130,1000]
    etaBins=np.array([0,0.6,1.1,1.52,1.7,2.3,2.5], dtype='float64')
    sigma3_bw = [4.02612E-05, 0.000120388, 0.000347194, 0.00132347, 7.3542E-05, 0.000282824, 0.000778923, 0.00281347, 0.000154639, 0.000625872, 0.00192782, 0.00603786, 0.000311132, 0.00100242, 0.00309482, 0.0102888, 0.000543691, 0.00155772, 0.00497516, 0.0158106, 0.0010541, 0.00569056, 0.015626, 0.0413519] #3 sigma BW

    s3_err_bw = [4.72247E-06, 1.25356E-05, 2.82976E-05, 8.83283E-05, 5.90073E-06, 1.74598E-05, 7.08379E-05, 0.000163445, 1.05191E-05, 4.70753E-05, 0.000127092, 0.000468457, 1.99548E-05, 7.09369E-05, 0.000241699, 0.000608859, 4.15377E-06, 5.65753E-05, 0.000140252, 0.000588034, 4.1028E-05, 0.000188804, 0.000805984, 0.00267722] #3 sigma bw error


    sigma2_bw =[3.3447E-05, 0.000102218, 0.000302609, 0.00128252, 6.94749E-05, 0.000275807, 0.000738401, 0.00271407, 0.000146621, 0.000607518, 0.00194558, 0.00612981, 0.000295325, 0.000951644, 0.00305973, 0.010952, 0.000546632, 0.00147883, 0.00501401, 0.0161612, 0.00104932, 0.00586099, 0.0165123, 0.0391828]

    s2_err_bw = [2.11207E-07, 8.14423E-07, 2.46321E-06, 6.46642E-06, 3.69794E-07, 1.77276E-06, 5.03471E-06, 1.08291E-05, 1.4E-06, 3.67117E-06, 1.02005E-05, 2.70881E-05, 1.60507E-06, 4.03686E-061, .76246E-05, 3.71283E-05, 1.69689E-06, 1.03172E-05, 8.46863E-06, 0.00010648, 1.9889E-06, 0.000260639, 5.51562E-05, 0.000164472]

    sigma4_bw = [4.40728E-05, 0.000119373, 0.000360996, 0.0013677, 8.6988E-05, 0.000283872, 0.0007929, 0.00282845, 0.000172512, 0.000646759, 0.00194257, 0.00612243, 0.000348031, 0.00102347, 0.00323065, 0.0104057, 0.000557384, 0.0016087, 0.00498309, 0.0160015, 0.00110113, 0.00558765, 0.0153383, 0.0411622]

    s4_err_bw = [3.80526E-06, 1.19148E-05, 4.04042E-05, 9.20568E-05, 4.60477E-06, 1.80728E-05, 5.53099E-05, 0.000197717, 9.5801E-06, 5.08874E-05, 0.000128907, 0.000307564, 2.54054E-05, 8.26319E-05, 0.000454215, 0.00076925, 2.98529E-05, 4.77966E-05, 0.000219887, 0.000459219, 4.27844E-05, 0.000385815, 0.000955765, 0.00274624]

    sigma3 = [3.36064E-05, 0.000105937, 0.000299397, 0.00126576, 7.10368E-05, 0.00027268, 0.000737339, 0.00272032, 0.00014522, 0.000602727, 0.00193299, 0.00606077, 0.000286898, 0.000947173, 0.003027, 0.010872, 0.000545306, 0.00148787, 0.00495277, 0.0157645, 0.00103669, 0.00582632, 0.0162814, 0.0402141]# 3sigma

    s3_err = [2.94609E-06, 1.20319E-05, 4.30008E-05, 0.000135398, 4.76697E-06, 2.11696E-05, 7.36807E-05, 0.000219806, 1.03773E-05, 4.90007E-05, 0.000189031, 0.000529546, 2.08968E-05, 8.67882E-05, 0.000332658, 0.00107426, 1.55579E-05, 7.37667E-05, 0.000255507, 0.000788004, 5.17013E-05, 0.000341017, 0.00107094, 0.00322004]# 3 sigma error

    sigma4 = [3.69267E-05, 0.000121321, 0.000340163, 0.00134184, 7.68468E-05, 0.0002751, 0.000753798, 0.00273213, 0.000151832, 0.000618405, 0.00191832, 0.00609876, 0.000299502, 0.00096763, 0.00303735, 0.0103543, 0.000548696, 0.00153442, 0.00496281, 0.0157161, 0.00104143, 0.00566937, 0.0155961, 0.0406812] # 4sigma

    s4_err = [1.40555E-06, 1.1774E-06, 3.77827E-06, 7.40038E-06, 3.79664E-06, 3.77212E-06, 6.95042E-06, 1.239E-05, 1.2338E-06, 7.32139E-06, 9.90759E-06, 0.000256216, 1.80211E-06, 7.39931E-06, 2.16127E-05, 0.000107846, 1.8011E-06, 6.74745E-06, 1.6833E-05, 3.80293E-05, 3.444E-06, 3.963E-05, 6.07069E-05, 0.000167697] #4sigma error

    initial = [2.77956E-05, 9.18632E-05, 0.000293832, 0.00122626, 6.23563E-05, 0.000266847, 0.000719646, 0.00257103, 0.000145766, 0.000593666, 0.00190437, 0.00597857, 0.000279288, 0.000928315, 0.00305011, 0.0106833, 0.000512649, 0.00144844, 0.00487751, 0.0156174, 0.0010072, 0.00568093, 0.0161041, 0.0400924] #intial 91+10

    initial_err = [3.73267E-06, 1.02802E-05, 3.80722E-05, 0.000152155, 3.13463E-06, 2.37791E-05, 0.000182927, 0.000169867, 8.35917E-06, 4.10496E-05, 7.8764E-05, 0.00044802, 2.64194E-05, 8.87423E-05, 0.000314245, 0.000650364, 1.67966E-05, 5.88483E-05, 0.000229615, 0.000606669, 3.33957E-05, 0.000363123, 0.000758974, 0.00342056]

    h1 = root.TH1D("h1","",24,-0.5,23.5)
    h2 = root.TH1D("h2","",24,-0.5,23.5)
    h3 = root.TH1D("h2","",24,-0.5,23.5)
    ratio_hist1 = root.TH1D("h2","",24,-0.5,23.5)
    print(sigma3)
    ax1.set_yscale("log")

    for i in range(1,25):
        print(i,sigma3_bw[i-1],sigma3[i-1])
        # h1.SetBinContent(i,initial[i-1])
        h1.SetBinContent(i,sigma3_bw[i-1])
        h3.SetBinContent(i,sigma4_bw[i-1])
        h2.SetBinContent(i,sigma2_bw[i-1])
        h1.SetBinError(i,s3_err_bw[i-1])
        ratio_hist1.SetBinContent(i, abs(h2.GetBinContent(i) - h3.GetBinContent(i)))
        
        # h3.SetBinError(i,s3_err_bw[i-1])
        # h2.SetBinError(i,s3_err[i-1])

    # h1_dummy.SetLineColor(root.kGreen)
    # h1_dummy.GetXaxis().SetRange(5, 8)
    # ax1.plot(h1_dummy, "E1 Same", markerstyle =1)
    # h1_dummy.SetLineColor(root.kRed)
    # h1_dummy.GetXaxis().SetRange(9, 12)
    # ax1.plot(h1_dummy, "E1 Same", markerstyle =1)

    # ax1.plot(h1, "E1", markerstyle =1, label="No fit 91[81, 101]", labelfmt="L")
    ax1.plot(h1, "HIST", markerstyle =1 , linecolor=root.kBlack, label="3#sigma BW", labelfmt="L")
    ax1.plot(h3, "HIST", markerstyle =1 , linecolor=root.kBlue+1, label="4#sigma BW", labelfmt="L")
    ax1.plot(h2, "HIST", markerstyle =1 ,linecolor=root.kRed+1, label="2#sigma BW", labelfmt="L")
    line = root.TLine(ax1.get_xlim()[0], 0, ax1.get_xlim()[1], 0)
    
    line1 = root.TLine(3.5, 0.00001,3.5, ax1.get_ylim()[1])
    line2 = root.TLine(7.5,  0.00001,7.5, ax1.get_ylim()[1])
    line3 = root.TLine(11.5,  0.00001,11.5, ax1.get_ylim()[1])
    line4 = root.TLine(15.5, 0.0003 ,15.5,0.1)
    line5 = root.TLine(19.5, 0.0003 ,19.5, 0.1)
    ax2.plot(line)
    ax1.plot(line1)
    ax1.plot(line2)
    ax1.plot(line3)
    ax1.plot(line4)
    ax1.plot(line5)
    ax1.set_ylim(0.00001)

    # ax1.plot(line4)
    # ax1.plot(line5)

    # Calculate and draw the ratio                                                                                                                                                                                                            
    # ratio_hist1 = h2 - h3
    ratio_hist1.Divide(h1)
    ax2.plot(ratio_hist1,"HIST")

    # Add extra space at top of plot to make room for labels                                                                                                                                                                                  
    ax1.add_margins(top=0.3)

    # Set axis titles                                                                                                                                                                                                                         
    ax2.set_xlim(ax1.get_xlim())
    # ax2.set_ylim(0.5, 1.5)
    ax2.set_xlabel("|#eta|")
    ax1.set_ylabel("Charge mis ID rate")
    ax2.set_ylabel("relative unc.", loc="centre")

    # Add extra space at top and bottom of ratio panel
    ax2.add_margins(top=0.1, bottom=0.1)
    # Go back to top axes to add labels                                                                                                                                                                                                      
    ax1.cd()

    aplt.atlas_label(text="Internal", loc="upper left")
    ax1.text(0.2, 0.58,  "#eta[0, 0.6]", size=22, align=13) 
    ax1.text(0.31, 0.58,  "[0.6, 1.1]", size=22, align=13) 
    ax1.text(0.43, 0.62,  "[1.1, 1.52]", size=22, align=13) 
    ax1.text(0.57, 0.65,  "[1.52, 1.7]", size=22, align=13) 
    ax1.text(0.7, 0.68,  "[1.7, 2.3]", size=22, align=13) 
    ax1.text(0.83, 0.74,  "[2.3, 2.5]", size=22, align=13) 
    ax1.text(0.65, 0.24,  "Bin1: pT [15,60] GeV", size=22, align=13) 
    ax1.text(0.65, 0.20,  "Bin2: pT [60,90] GeV", size=22, align=13) 
    ax1.text(0.65, 0.16,  "Bin3: pT [90,130] GeV", size=22, align=13) 
    ax1.text(0.65, 0.12,  "Bin4: pT [130,1000] GeV", size=22, align=13) 
    
    # Add legend
    ax1.legend(loc=(0.2, 0.68, 0.4, 0.84))
    fig.savefig(outPath+"bw_2_3_4_sigma.png")


if __name__ == '__main__':
    root.gROOT.SetBatch()
    outPath = "/eos/home-s/ssindhu/4tops/plots/final_uncs/"
    uncs(outPath)





#   # TFile* output= new TFile("diff_3.root","recreate");

#   TH1F* h1_dummy = new TH1F("h1_dummy","",6,etaBins);
# #  TH1F* h1_dummy = new TH1F("h1_dummy","",8,etaBins);
#   h1_dummy->GetXaxis()->SetTitle("electron |#eta|");
#   h1_dummy->GetYaxis()->SetTitle("charge mis ID rate");
#   h1_dummy->GetYaxis()->SetRangeUser(1e-5,0.5);
#   h1_dummy->SetLineColor(1);
#   TH1F* h1_pT1 = (TH1F*)h1_dummy->Clone("h1_pT1");
#   TH1F* h1_pT2 = (TH1F*)h1_dummy->Clone("h1_pT2");
#   TH1F* h1_pT3 = (TH1F*)h1_dummy->Clone("h1_pT3");
#   TH1F* h1_pT4 = (TH1F*)h1_dummy->Clone("h1_pT4");

#   TH1F* h1_pT21 = (TH1F*)h1_dummy->Clone("h1_pT21");
#   TH1F* h1_pT22 = (TH1F*)h1_dummy->Clone("h1_pT22");
#   TH1F* h1_pT23 = (TH1F*)h1_dummy->Clone("h1_pT23");
#   TH1F* h1_pT24 = (TH1F*)h1_dummy->Clone("h1_pT24");


#   h1_pT1->SetLineColor(2);h1_pT1->SetMarkerColor(2);h1_pT1->SetLineWidth(2);h1_pT21->SetLineWidth(2);
#   h1_pT2->SetLineColor(4);h1_pT2->SetMarkerColor(4);h1_pT2->SetLineWidth(2);h1_pT22->SetLineWidth(2);
#   h1_pT3->SetLineColor(6);h1_pT3->SetMarkerColor(6);h1_pT3->SetLineWidth(2);h1_pT23->SetLineWidth(2);
#   h1_pT4->SetLineColor(7);h1_pT4->SetMarkerColor(7);h1_pT4->SetLineWidth(2);h1_pT24->SetLineWidth(2);

#   for(int i=1;i<7;i++){
#     h1_pT1->SetBinContent(i,sigma3[4*i-4]);h1_pT1->SetBinError(i,s3_err[4*i-4]);
#     h1_pT2->SetBinContent(i,sigma3[4*i-3]);h1_pT2->SetBinError(i,s3_err[4*i-3]);
#     h1_pT3->SetBinContent(i,sigma3[4*i-2]);h1_pT3->SetBinError(i,s3_err[4*i-2]);
#     h1_pT4->SetBinContent(i,sigma3[4*i-1]);h1_pT4->SetBinError(i,s3_err[4*i-1]);

#     h1_pT21->SetBinContent(i,sigma4[4*i-4]);h1_pT21->SetBinError(i,s4_err[4*i-4]);
#     h1_pT22->SetBinContent(i,sigma4[4*i-3]);h1_pT22->SetBinError(i,s4_err[4*i-3]);
#     h1_pT23->SetBinContent(i,sigma4[4*i-2]);h1_pT23->SetBinError(i,s4_err[4*i-2]);
#     h1_pT24->SetBinContent(i,sigma4[4*i-1]);h1_pT24->SetBinError(i,s4_err[4*i-1]);
#   }
# /*
#     for(int i=4;i<7;i++){
#     h1_pT1->SetBinContent(i,0);h1_pT1->SetBinError(i,0);
#     h1_pT2->SetBinContent(i,0);h1_pT2->SetBinError(i,0);
#     h1_pT3->SetBinContent(i,0);h1_pT3->SetBinError(i,0);
#     h1_pT4->SetBinContent(i,0);h1_pT4->SetBinError(i,0);
#   }
# */

#   TCanvas* QmisID = new TCanvas("myCan","canvas",900,900);

#   TPad* pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
#     pad1->SetRightMargin(0.05);
#     pad1->SetTopMargin(0.05);
#     pad1->SetLeftMargin(0.15);
    
#     pad1->SetFillColor(kWhite);
#     pad1->SetFrameFillStyle(0);
#     pad1->Draw();
#     QmisID->cd();
#     TPad* pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
#     pad2->SetTopMargin(0);  # joins upper and lower plot
#     pad2->SetBottomMargin(0.2);
#     pad2->SetGridx();
#     pad2->Draw();
 

# #  TLegend* lg = new TLegend(0.35,0.5,0.55,0.8);
# #charge misID
# #  TLegend* lg = new TLegend(0.3,0.6,0.60,0.9,legend_title.c_str());
# #nominal
#   std::string legend_title="data15-18 likelihood";
#   TLegend* lg = new TLegend(0.65,0.1,0.85,0.4,legend_title.c_str());
#   lg->AddEntry(h1_pT1,"pT [15,60] GeV Gauss 3#sigma");
#   lg->AddEntry(h1_pT2,"pT [60,90] GeV Gauss 3#sigma");
#   lg->AddEntry(h1_pT3,"pT [90,130] GeV Gauss 3#sigma");
#   lg->AddEntry(h1_pT4,"pT [130,1000] GeV Gauss 3#sigma");
#   lg->AddEntry(h1_pT21,"pT [15,1000] GeV Gauss 4#sigma");
#   lg->SetBorderSize(0);
#   lg->SetFillStyle(0);
#   pad1->cd();
#   h1_dummy->Draw();
#   h1_pT1->Draw("same");
#   h1_pT2->Draw("same");
#   h1_pT3->Draw("same");
#   h1_pT4->Draw("same");
#   h1_pT21->Draw("same");
#   h1_pT22->Draw("same");
#   h1_pT23->Draw("same");
#   h1_pT24->Draw("same");
#   lg->Draw("same");

#   pad1->SetLogy();
#   pad2->cd();
#   h1_pT21->Divide(h1_pT1);
#   h1_pT21->Draw();
#   pad2->SetLogy();
  
#   # h1_pT1->Write();
#   # h1_pT2->Write();
#   # h1_pT3->Write();
#   # h1_pT4->Write();
#   QmisID->SaveAs("/eos/home-s/ssindhu/4tops/plots/uncs/diff3-4.png");
# #  output->Close();




# }
