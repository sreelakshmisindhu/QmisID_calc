import ROOT as root
import numpy as np
from ROOT import TFile, TCanvas, TPad, TColor
from ROOT import kBlack, kBlue, kRed, kGreen
from ROOT import TH1
from ROOT import TH2


def _drawATLASLabel(x, y, text, doNDC = True, fontsize = 0.07):
    _drawText(x, y, "ATLAS", fontsize = fontsize, font = 72, doNDC = doNDC, alignment = 11)
    _drawText(x + 0.1, y, text, fontsize = fontsize, font = 42, doNDC = doNDC, alignment = 11)

def _drawText(x, y, text, color = kBlack, fontsize = 0.05, font = 42, doNDC = True, alignment = 12):
    tex = root.TLatex()
    if doNDC:
        tex.SetNDC()
    root.SetOwnership(tex, False)
    tex.SetTextAlign(alignment)
    tex.SetTextSize(fontsize)
    tex.SetTextFont(font)
    tex.SetTextColor(color)
    tex.DrawLatex(x, y, text)

def createCanvasPads():

    canv = TCanvas("canv_ratio_plot", "canv", 10, 10, 2400, 1450)
    root.SetOwnership(canv, False)


    canv.SetRightMargin(0.15)
    canv.SetTopMargin(0.15)
    canv.SetBottomMargin(0.15)
    canv.SetLeftMargin(0.15)


    pad1 = TPad("pad1", "pad1", 0, 0, 1, 1.0)
    pad1.SetRightMargin(0.15)
    pad1.SetTopMargin(0.1)
    pad1.SetLeftMargin(0.15)
    pad1.SetBottomMargin(0.1)

    pad1.SetFillColor(root.kWhite)
    pad1.SetFrameFillStyle(0)
    canv.cd()
    pad1.Draw()


    return canv, pad1

def uncs(outPath, Type):
    # Set the ATLAS Style
    # aplt.set_atlas_style()

    # Create a figure and axes
    # fig, ax = aplt.subplots(1, 1, name="fig1", figsize=(800, 600))

    # Randomly fill a 2D histogram
    # cav = TCanvas("","",10,10,2400,2200)
    # pad = TPad("","",0.1,0.1,0.9,0.9)
    # pad
    initial = [2.77956E-05, 9.18632E-05, 0.000293832, 0.00122626, 6.23563E-05, 0.000266847, 0.000719646, 0.00257103, 0.000145766, 0.000593666, 0.00190437, 0.00597857, 0.000279288, 0.000928315, 0.00305011, 0.0106833, 0.000512649, 0.00144844, 0.00487751, 0.0156174, 0.0010072, 0.00568093, 0.0161041, 0.0400924] #intial 91+10
    

    initial_err = [3.73267E-06, 1.02802E-05, 3.80722E-05, 0.000152155, 3.13463E-06, 2.37791E-05, 0.000182927, 0.000169867, 8.35917E-06, 4.10496E-05, 7.8764E-05, 0.00044802, 2.64194E-05, 8.87423E-05, 0.000314245, 0.000650364, 1.67966E-05, 5.88483E-05, 0.000229615, 0.000606669, 3.33957E-05, 0.000363123, 0.000758974, 0.00342056]

    sigma3_bw = [4.02612E-05, 0.000120388, 0.000347194, 0.00132347, 7.3542E-05, 0.000282824, 0.000778923, 0.00281347, 0.000154639, 0.000625872, 0.00192782, 0.00603786, 0.000311132, 0.00100242, 0.00309482, 0.0102888, 0.000543691, 0.00155772, 0.00497516, 0.0158106, 0.0010541, 0.00569056, 0.015626, 0.0413519] #3 sigma BW

    s3_err_bw = [4.72247E-06, 1.25356E-05, 2.82976E-05, 8.83283E-05, 5.90073E-06, 1.74598E-05, 7.08379E-05, 0.000163445, 1.05191E-05, 4.70753E-05, 0.000127092, 0.000468457, 1.99548E-05, 7.09369E-05, 0.000241699, 0.000608859, 4.15377E-06, 5.65753E-05, 0.000140252, 0.000588034, 4.1028E-05, 0.000188804, 0.000805984, 0.00267722] #3 sigma bw error

    sigma3 = [3.36064E-05, 0.000105937, 0.000299397, 0.00126576, 7.10368E-05, 0.00027268, 0.000737339, 0.00272032, 0.00014522, 0.000602727, 0.00193299, 0.00606077, 0.000286898, 0.000947173, 0.003027, 0.010872, 0.000545306, 0.00148787, 0.00495277, 0.0157645, 0.00103669, 0.00582632, 0.0162814, 0.0402141]# 3sigma

    s3_err = [2.94609E-06, 1.20319E-05, 4.30008E-05, 0.000135398, 4.76697E-06, 2.11696E-05, 7.36807E-05, 0.000219806, 1.03773E-05, 4.90007E-05, 0.000189031, 0.000529546, 2.08968E-05, 8.67882E-05, 0.000332658, 0.00107426, 1.55579E-05, 7.37667E-05, 0.000255507, 0.000788004, 5.17013E-05, 0.000341017, 0.00107094, 0.00322004]# 3 sigma error

    sigma4 = [3.69267E-05, 0.000121321, 0.000340163, 0.00134184, 7.68468E-05, 0.0002751, 0.000753798, 0.00273213, 0.000151832, 0.000618405, 0.00191832, 0.00609876, 0.000299502, 0.00096763, 0.00303735, 0.0103543, 0.000548696, 0.00153442, 0.00496281, 0.0157161, 0.00104143, 0.00566937, 0.0155961, 0.0406812] # 4sigma

    s4_err = [1.40555E-06, 1.1774E-06, 3.77827E-06, 7.40038E-06, 3.79664E-06, 3.77212E-06, 6.95042E-06, 1.239E-05, 1.2338E-06, 7.32139E-06, 9.90759E-06, 0.000256216, 1.80211E-06, 7.39931E-06, 2.16127E-05, 0.000107846, 1.8011E-06, 6.74745E-06, 1.6833E-05, 3.80293E-05, 3.444E-06, 3.963E-05, 6.07069E-05, 0.000167697] #4sigma error

    print(s3_err_bw)

    infile = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/all_cuts/3sigma_bw/data_all_closure.root")
    # infile = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/all_cuts/closure.root")                                                                                                                                                 
    c, pad= createCanvasPads()
    hist = infile.Get("ss_pt_eta_0")

    hist_os1 = infile.Get("os_pt_eta_0")
    hist_os2 = infile.Get("os_pt_eta_1")
    hist_ss1 = infile.Get("ss_pt_eta_0")
    hist_ss2 = infile.Get("ss_pt_eta_1")


    hist_os = hist_os1.Clone("os_pt_eta_0 + os_pt_eta_1")
    hist_os.Add(hist_os2)
    hist_ss = hist_ss1.Clone("ss_pt_eta_0 + ss_pt_eta_1")
    hist_ss.Add(hist_ss2)

    closure_hist = hist_os.Clone("diff")
    # Draw the histogram on these axe                                                                                                                                                                                                         
    for j in range (1,5):
        for i in range(1,7):
            closure_hist.SetBinContent(i,j, abs(hist_os.GetBinContent(i,j) - hist_ss.GetBinContent(i,j) ))
            print("os", i,j, hist_os1.GetBinContent(i,j), hist_os2.GetBinContent(i,j),  hist_os.GetBinContent(i,j) )
            print("ss", i,j, hist_ss1.GetBinContent(i,j), hist_ss2.GetBinContent(i,j),  hist_ss.GetBinContent(i,j) )
            print("df", i,j, hist.GetBinContent(i,j))

    closure_hist.Divide(hist_ss)


    for j in range (1,5):
        for i in range(1,7):
            print(i,j, hist.GetBinContent(i,j), s3_err_bw[j-1+4*(i-1)]/sigma3_bw[j-1+4*(i-1)])
            if Type == "fit": 
                hist.SetBinContent(i,j, s3_err_bw[j-1+4*(i-1)]/sigma3_bw[j-1+4*(i-1)])
            elif Type == "width":
                hist.SetBinContent(i,j, abs(sigma3[j-1+4*(i-1)] - sigma3_bw[j-1+4*(i-1)])/sigma3_bw[j-1+4*(i-1)])
            elif Type == "total":
                width_unc = abs(sigma3[j-1+4*(i-1)] - sigma3_bw[j-1+4*(i-1)])/sigma3_bw[j-1+4*(i-1)]
                fit_unc = s3_err_bw[j-1+4*(i-1)]/sigma3_bw[j-1+4*(i-1)]
                closure_unc = closure_hist.GetBinContent(i,j)
                total = np.sqrt(width_unc*width_unc+ fit_unc*fit_unc+ closure_unc*closure_unc)
                print(width_unc, closure_unc, fit_unc, total)
                hist.SetBinContent(i,j,total)
    # Draw the histogram on these axes
    if Type == "closure":
        hist = closure_hist
    hist.SetStats(0)

    c.cd()

    pad.SetLogy()
    pad.Draw()

    pad.cd()
    root.gStyle.SetPaintTextFormat("4.4f");
    # hist.Draw("text same")
    # Change pad margins to allow space for z-axis colour bar and for ATLAS label

    # Set axis titles
    hist.GetXaxis().SetTitle("|#eta|")
    hist.GetYaxis().SetTitle("p_{T} [GeV]") 
    hist.GetZaxis().SetTitle("#Delta QmisID/QmisID")
    hist.SetMarkerSize(1.8)
    print(hist.GetBinContent(0,1))
    # ax.set_ylabel("p_{T} [GeV]")
    # ax.set_zlabel("QmisID", titleoffset=1.2)
    # ax.set_yscale("log")
    # # Add the ATLAS Label
    # aplt.atlas_label(ax.pad.GetLeftMargin(), 0.97, text="Internal", align=13)
    # ax.text(1 - ax.pad.GetRightMargin(), 0.97, "#sqrt{s} = 13 TeV, 139 fb^{-1}", size=22, align=33)

    hist.Draw("colz text same")

    # Save the plot as a PDF
    c.SaveAs(outPath+"sigma3_bw_"+Type+"syst.png")

def closure_uncs(outPath):
    infile = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/all_cuts/3sigma_bw/data_all_closure.root")
    # infile = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/all_cuts/closure.root")
    c, pad= createCanvasPads()
    hist_os1 = infile.Get("os_pt_eta_0")
    hist_os2 = infile.Get("os_pt_eta_1")
    hist_ss1 = infile.Get("ss_pt_eta_0")
    hist_ss2 = infile.Get("ss_pt_eta_1")

    
    hist_os = hist_os1.Clone("os_pt_eta_0 + os_pt_eta_1")
    hist_os.Add(hist_os2)
    hist_ss = hist_ss1.Clone("ss_pt_eta_0 + ss_pt_eta_1")
    hist_ss.Add(hist_ss2)
    
    hist = hist_os.Clone("diff") 
    # Draw the histogram on these axe
    for j in range (1,5):
        for i in range(1,7):
            hist.SetBinContent(i,j, abs(hist_os.GetBinContent(i,j) - hist_ss.GetBinContent(i,j) ))
            print("os", i,j, hist_os1.GetBinContent(i,j), hist_os2.GetBinContent(i,j),  hist_os.GetBinContent(i,j) )
            print("ss", i,j, hist_ss1.GetBinContent(i,j), hist_ss2.GetBinContent(i,j),  hist_ss.GetBinContent(i,j) )
            print("df", i,j, hist.GetBinContent(i,j))

    hist.Divide(hist_ss)
    return hist


    # c.cd()

    # pad.SetLogy()
    # pad.Draw()

    # pad.cd()
    # root.gStyle.SetPaintTextFormat("4.4f");
    # # hist.Draw("text same")
    # # Change pad margins to allow space for z-axis colour bar and for ATLAS label

    # # Set axis titles
    # hist.GetXaxis().SetTitle("|#eta|")
    # hist.GetYaxis().SetTitle("p_{T} [GeV]") 
    # hist.GetZaxis().SetTitle("#Delta QmisID/QmisID")
    # hist.SetMarkerSize(1.8)
    # print(hist.GetBinContent(0,1))
    # # ax.set_ylabel("p_{T} [GeV]")
    # # ax.set_zlabel("QmisID", titleoffset=1.2)
    # # ax.set_yscale("log")
    # # # Add the ATLAS Label
    # # aplt.atlas_label(ax.pad.GetLeftMargin(), 0.97, text="Internal", align=13)
    # # ax.text(1 - ax.pad.GetRightMargin(), 0.97, "#sqrt{s} = 13 TeV, 139 fb^{-1}", size=22, align=33)

    # hist.Draw("colz text same")

    # # Save the plot as a PDF
    # # c.SaveAs(outPath+"sigma3_gauss_closuresyst.png")
    # c.SaveAs(outPath+"initial_closuresyst.png")


if __name__ == '__main__':
    root.gROOT.SetBatch()
    outPath = "/eos/home-s/ssindhu/4tops/plots/uncs/"
    # closure_uncs(outPath)
    uncs(outPath, "total")
