import ROOT as root
import atlasplots as aplt
from ROOT import TFile
from ROOT import TH1

def data_MC(data_hist, sig_hist, var, label, outPath):
    # Set the ATLAS Style
    aplt.set_atlas_style()

    # Create a figure and axes
    fig, (ax1, ax2) = aplt.ratio_plot(name="fig1", figsize=(800, 800), hspace=0.05)

    # Define "background", "signal" and "data" distributions
    # bkg_func = root.TF1("bkg_func", "[0]*exp([1]*x)", 0, 10)
    # bkg_func.SetParameters(20, -0.5)

    # sig_func = root.TF1("sig_func", "x*gaus(0)", 0, 10)
    # sig_func.SetParameters(10, 4, 1)

    # Randomly fill histograms according to the above distributions
    # bkg_hist = root.TH1F("bkg_hist", "Background", 50, 0, 10)
    # bkg_hist.FillRandom("bkg_func", 10000)
    # bkg_hist.SetFillColor(root.kRed+1)
    # bkg_hist.SetLineWidth(0)
    # bkg_hist.Sumw2()

    # sig_hist = root.TH1F("sig_hist", "Signal", 50, 0, 10)
    # sig_hist.FillRandom("sig_func", 10000)
    # sig_hist.SetFillColor(root.kAzure+1)
    # sig_hist.SetLineWidth(0)
    # sig_hist.Sumw2()

    # data_hist = root.TH1F("data_hist", "Data", 50, 0, 10)
    # data_hist.FillRandom("bkg_func", 10000)
    # data_hist.FillRandom("sig_func", 10000)
    # data_hist.Sumw2()
    # data_hist.SetBinErrorOption(root.TH1.EBinErrorOpt.kPoisson)  # Use 68% Poisson errors

    # Stack the background and signal histograms
    bkg_and_sig = root.THStack("bkg_and_sig", "")
    # bkg_and_sig.Add(bkg_hist)
    bkg_and_sig.Add(sig_hist)

    # Draw the stacked histogram on these axes
    ax1.plot(bkg_and_sig)

    # Plot the MC stat error as a hatched band
    err_band = aplt.root_helpers.hist_to_graph(
        bkg_and_sig.GetStack().Last(),
        show_bin_width=True
    )
    ax1.plot(err_band, "2", fillcolor=1, fillstyle=3254, linewidth=0)

    # ax1.set_yscale("log")  # uncomment to use log scale for y axis

    # Plot the data as a graph
    data_graph = aplt.root_helpers.hist_to_graph(data_hist)
    # line1 = root.TLine(91, ax1.get_ylim()[0], 91, ax1.get_ylim()[1]) #   OS,SS ori: 91, fit: 90.61
    # line2 = root.TLine(81, ax1.get_ylim()[0], 81, ax1.get_ylim()[1]/2) # OS,SS ori: 81
    # line3 = root.TLine(101, ax1.get_ylim()[0], 101, ax1.get_ylim()[1]/2) # OS,SS ori: 101, 
    # gauss fit values
    # line4 = root.TLine(90.61, ax1.get_ylim()[0], 90.61, ax1.get_ylim()[1]) #   OS fit: 90.61
    # line5 = root.TLine(77.262, ax1.get_ylim()[0], 77.262, ax1.get_ylim()[1]/2) # OS 4sigma: 77.262
    # line6 = root.TLine(103.96, ax1.get_ylim()[0], 103.96, ax1.get_ylim()[1]/2) # OS 4sigma: 103.958
    # line7 = root.TLine(80.6, ax1.get_ylim()[0], 80.6, ax1.get_ylim()[1]/2) # OS 3sigma: 80.6
    # line8 = root.TLine(100.62, ax1.get_ylim()[0], 100.62, ax1.get_ylim()[1]/2) # OS 3sigma: 100.62
    # line9 = root.TLine(78.93, ax1.get_ylim()[0], 78.93, ax1.get_ylim()[1]/2) # OS 3.5sigma: 78.93
    # line10 = root.TLine(102.29, ax1.get_ylim()[0], 102.29, ax1.get_ylim()[1]/2) # OS 3.5sigma: 102.29

    #BW fit values
    # line4 = root.TLine(90.64, ax1.get_ylim()[0], 90.64, ax1.get_ylim()[1]) #   OS fit: 90.64
    # line5 = root.TLine(71.96, ax1.get_ylim()[0], 71.96, ax1.get_ylim()[1]/2) # OS 4sigma: 77.262
    # line6 = root.TLine(109.32, ax1.get_ylim()[0], 109.32, ax1.get_ylim()[1]/2) # OS 4sigma: 103.958
    # line7 = root.TLine(76.63, ax1.get_ylim()[0], 76.63, ax1.get_ylim()[1]/2) # OS 3sigma: 80.6
    # line8 = root.TLine(104.65, ax1.get_ylim()[0], 104.65, ax1.get_ylim()[1]/2) # OS 3sigma: 100.62
    # line9 = root.TLine(81.3, ax1.get_ylim()[0], 81.3, ax1.get_ylim()[1]/2) # OS  2sigma             gausss3.5sigma: 78.93
    # line10 = root.TLine(99.98, ax1.get_ylim()[0], 99.98, ax1.get_ylim()[1]/2) # OS 2sigma         gauss 3.5sigma: 102.29


    # line4 = root.TLine(89.56, ax1.get_ylim()[0], 89.56, ax1.get_ylim()[1]) #   SS fit: 89.48
    # line5 = root.TLine(67.04, ax1.get_ylim()[0], 67.04, ax1.get_ylim()[1]/2) # SS 4sigma: 74.108
    # line6 = root.TLine(112.08, ax1.get_ylim()[0], 112.08, ax1.get_ylim()[1]/2) # SS 4sigma: 104.852
    # line7 = root.TLine(72.67, ax1.get_ylim()[0], 72.67, ax1.get_ylim()[1]/2) # SS 3sigma: 77.95
    # line8 = root.TLine(106.45, ax1.get_ylim()[0], 106.45, ax1.get_ylim()[1]/2) # SS 3sigma: 101.01
    # line9 = root.TLine(78.3, ax1.get_ylim()[0], 78.3, ax1.get_ylim()[1]/2) # SS 2 sigma           gaussSS 3.5sigma: 76.03
    # line10 = root.TLine(100.82, ax1.get_ylim()[0], 100.82, ax1.get_ylim()[1]/2) # SS2 sigma    gauss 3.5sigma: 102.93


    ax1.plot(data_graph, "P")
    # ax1.plot(line1, linewidth=2)
    # ax1.plot(line2, linewidth=2)
    # ax1.plot(line3, linewidth=2)
    # ax1.plot(line4, linecolor=root.kBlue+1, linewidth=2)
    # ax1.plot(line5, linecolor=root.kRed+1, linewidth=2,  label="4 #sigma")
    # ax1.plot(line6, linecolor=root.kRed+1, linewidth=2)
    # ax1.plot(line7, linecolor=root.kBlue+1, linewidth=2,  label="3 #sigma")
    # ax1.plot(line8, linecolor=root.kBlue+1, linewidth=2)
    # ax1.plot(line9, linecolor=root.kGreen+1, linewidth=2,  label="2 #sigma")
    # ax1.plot(line10, linecolor=root.kGreen+1, linewidth=2)
    # Use same x-range in lower axes as upper axes
    ax2.set_xlim(ax1.get_xlim())

    # Draw line at y=1 in ratio panel
    line = root.TLine(ax1.get_xlim()[0], 1, ax1.get_xlim()[1], 1)
    ax2.plot(line)

    # Plot the relative error on the ratio axes
    err_band_ratio = aplt.root_helpers.hist_to_graph(
        bkg_and_sig.GetStack().Last(),
        show_bin_width=True,
        norm=True
    )
    ax2.plot(err_band_ratio, "2", fillcolor=1, fillstyle=3254)

    # Calculate and draw the ratio
    ratio_hist = data_hist.Clone("ratio_hist")
    ratio_hist.Divide(bkg_and_sig.GetStack().Last())
    ratio_graph = aplt.root_helpers.hist_to_graph(ratio_hist)
    ax2.plot(ratio_graph, "P0")

    # Add extra space at top of plot to make room for labels
    ax1.add_margins(top=0.16)

    # Set axis titles
    ax2.set_xlabel(label)
    ax1.set_ylabel("Events")
    ax2.set_ylabel("Data / Pred.", loc="centre")

    ax2.set_ylim(0.5, 1.25)
    ax2.draw_arrows_outside_range(ratio_graph)

    # Go back to top axes to add labels
    ax1.cd()

    # Add the ATLAS Label
    aplt.atlas_label(text="Internal", loc="upper left")
    # ax1.text(0.2, 0.84, "33.3 fb^{-1}", size=22, align=13)
    # ax1.text(0.2, 0.84, "#sqrt{s} = 13 TeV, 139 fb^{-1}", size=22, align=13)

    # Add legend
    legend = ax1.legend(
        loc=(0.68, 0.65, 1 - root.gPad.GetRightMargin() - 0.03, 1 - root.gPad.GetTopMargin() - 0.03),
        textsize=22
    )
    legend.AddEntry(data_graph, "Data", "EP")
    legend.AddEntry(sig_hist, "Signal", "F")
    # legend.AddEntry(bkg_hist, "Background", "F")
    legend.AddEntry(err_band, "MC Stat. Unc.", "F")
    # legend.AddEntry(line1, "[81,101]")
    # legend.AddEntry(line5, "4 #sigma")
    # legend.AddEntry(line9, "3.5 #sigma")
    # legend.AddEntry(line7, "3 #sigma")
    # Save the plot as a PDF
    fig.savefig(outPath+var+"_data_MC_all.pdf")
    fig.savefig(outPath+var+"_data_MC_all.png")


if __name__ == '__main__':
    root.gROOT.SetBatch()
    # DataFile = TFile("/eos/home-s/ssindhu/4tops/post_prodQmisID/data/data16.root")
    # inFile = TFile("/eos/home-s/ssindhu/4tops/data_MC.root")
    # signalFile = TFile("/eos/home-s/ssindhu/4tops/finaltest_noCS.root")
    # signalFile = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/new_bins/60_90_130/mc16a.root")
    # signalFile1 = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/no_cuts/mc16a.root")
    dataFile1 = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/no_cuts/data_15_16.root")
    signalFile1 = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/new_bins/60_90_130/mc16a.root")
    dataFile1 = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/new_bins/60_90_130/data_15_16_nocut.root")
    signalFile2 = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/new_bins/60_90_130/mc16d.root")
    dataFile2 = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/new_bins/60_90_130/data_17_nocut.root")
    signalFile3 = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/new_bins/60_90_130/mc16e.root")
    dataFile3 = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/new_bins/60_90_130/data_18_nocut.root")
    # signalFile = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/new_bins/60_90_130/mc_all.root")
    # dataFile = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/new_bins/60_90_130/data_all.root")
    
    outPath = "/eos/home-s/ssindhu/4tops/plots/final_showdown/"
    # for event in DataFile.nominal_Loose:
    # variables= ["ss_n_Muons", "ss_n_Electrons", "ss_n_Jets", "ss_lep_0_pt", "ss_lep_1_pt", "ss_HT_all", "ss_Mll", "ss_Mll_small", "ss_met", "ss_n_btags_77"]
    variables= ["os_n_Muons", "os_n_Electrons", "os_n_Jets", "os_lep_0_pt", "os_lep_1_pt", "os_HT_all", "os_Mll", "os_Mll_small", "os_met", "os_n_btags_77"]
    label = ["n Muons", "n Electrons", "n Jets", "leading lepton p_{T} [GeV]", "Subleading lepton p_{T} [GeV]", "H_{T} all [GeV]","M(l,l) [GeV]" ,"M(l,l) [GeV]", "met [GeV]", "n Btags @ 77"]
    # variables = ["ss_Mll", "ss_Mll_small"]
    # label = ["M(l,l) [GeV]", "M(l,l) [GeV]"]

    # nominalTree = DataFile.Get("nominal_Loose")
    for var in variables: 
        # dataHist = dataFile.Get("Data16/"+var)
        # dataHist2 = dataFile2.Get("Data15/"+var)
        # signalHist = signalFile.Get("Signal/"+var)
        dataHist3 = dataFile3.Get(var)
        signalHist3 = signalFile3.Get(var)
        dataHist1 = dataFile1.Get(var)
        signalHist1 = signalFile1.Get(var)
        dataHist2 = dataFile2.Get(var)
        signalHist2 = signalFile2.Get(var)
        dataHist = dataHist1+dataHist2+signalHist3
        signalHist = signalHist1+signalHist2+signalHist3
        # dataHist = dataFile.Get(var)
        # signalHist = signalFile.Get(var)
        # SignalHist.Scale(138965.16)
        # SignalHist.Scale(10000)
        # dataHist.Add(dataHist2)
        data_MC(dataHist, signalHist, var, label[variables.index(var)], outPath)
