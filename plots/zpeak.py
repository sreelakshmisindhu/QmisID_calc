import ROOT as root
from ROOT import TFile
import atlasplots as aplt


def main():
    # Set the ATLAS Style
    aplt.set_atlas_style()
    dataFile = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/no_cuts/more_bins/data_all.root")
    outPath = "/eos/home-s/ssindhu/4tops/plots/final_showdown/"
    dataHist = dataFile.Get("ss_Mll_small")

    # Create a figure and axes
    fig, ax = aplt.subplots(1, 1, name="fig1", figsize=(800, 600))

    #BW fit values
    # line4 = root.TLine(90.64, ax.get_ylim()[0], 90.64, ax.get_ylim()[1]) #   OS fit: 90.64
    # line5 = root.TLine(71.96, ax.get_ylim()[0], 71.96, ax.get_ylim()[1]/2) # OS 4sigma: 77.262
    # line6 = root.TLine(109.32, ax.get_ylim()[0], 109.32, ax.get_ylim()[1]/2) # OS 4sigma: 103.958
    # line7 = root.TLine(76.63, ax.get_ylim()[0], 76.63, ax.get_ylim()[1]/2) # OS 3sigma: 80.6
    # line8 = root.TLine(104.65, ax.get_ylim()[0], 104.65, ax.get_ylim()[1]/2) # OS 3sigma: 100.62
    # line9 = root.TLine(81.3, ax.get_ylim()[0], 81.3, ax.get_ylim()[1]/2) # OS  2sigma             gausss3.5sigma: 78.93
    # line10 = root.TLine(99.98, ax.get_ylim()[0], 99.98, ax.get_ylim()[1]/2) # OS 2sigma         gauss 3.5sigma: 102.29


    line4 = root.TLine(89.56, ax.get_ylim()[0], 89.56, ax.get_ylim()[1]) #   SS fit: 89.48
    line5 = root.TLine(67.04, ax.get_ylim()[0], 67.04, ax.get_ylim()[1]/2) # SS 4sigma: 74.108
    line6 = root.TLine(112.08, ax.get_ylim()[0], 112.08, ax.get_ylim()[1]/2) # SS 4sigma: 104.852
    line7 = root.TLine(72.67, ax.get_ylim()[0], 72.67, ax.get_ylim()[1]/2) # SS 3sigma: 77.95
    line8 = root.TLine(106.45, ax.get_ylim()[0], 106.45, ax.get_ylim()[1]/2) # SS 3sigma: 101.01
    line9 = root.TLine(78.3, ax.get_ylim()[0], 78.3, ax.get_ylim()[1]/2) # SS 2 sigma           gaussSS 3.5sigma: 76.03
    line10 = root.TLine(100.82, ax.get_ylim()[0], 100.82, ax.get_ylim()[1]/2) # SS2 sigma    gauss 3.5sigma: 102.93


    # Add extra space at top of plot to make room for labels
    ax.add_margins(top=0.16)

    # Set axis titles
    ax.set_xlabel("M(l,l) [GeV]")
    ax.set_ylabel("Events")
    ax.plot(dataHist, "P")
    # ax.plot(line1, linewidth=2)
    # ax.plot(line2, linewidth=2)
    # ax.plot(line3, linewidth=2)
    ax.plot(line4, linecolor=root.kBlue+1, linewidth=2)
    ax.plot(line5, linecolor=root.kRed+1, linewidth=2,  label="4 #sigma")
    ax.plot(line6, linecolor=root.kRed+1, linewidth=2)
    ax.plot(line7, linecolor=root.kBlue+1, linewidth=2,  label="3 #sigma")
    ax.plot(line8, linecolor=root.kBlue+1, linewidth=2)
    ax.plot(line9, linecolor=root.kGreen+1, linewidth=2,  label="2 #sigma")
    ax.plot(line10, linecolor=root.kGreen+1, linewidth=2)

    # Add the ATLAS Label
    aplt.atlas_label(text="Internal", loc="upper left")
    ax.text(0.2, 0.86, "#sqrt{s} = 13 TeV, 139 fb^{-1}", size=22, align=13)

    # Add legend
    # legend = ax.legend(
    #     loc=(0.68, 0.65, 1 - root.gPad.GetRightMargin() - 0.03, 1 - root.gPad.GetTopMargin() - 0.03),
    #     textsize=22
    # )
    # legend = ax.legend(
    #     loc=(0.68, 0.65, 1 - root.gPad.GetRightMargin() - 0.03, 1 - root.gPad.GetTopMargin() - 0.03),
    #     textsize=22
    # )
  

    # legend.AddEntry(dataHist, "Data", "EP")
    # # legend.AddEntry(sig_hist, "Signal", "F")
    # # legend.AddEntry(bkg_hist, "Background", "F")
    # # legend.AddEntry(err_band, "MC Stat. Unc.", "F")
    # # legend.AddEntry(line1, "[81,101]")
    # legend.AddEntry(line5, "4 #sigma")
    # legend.AddEntry(line9, "2 #sigma")
    # legend.AddEntry(line7, "3 #sigma")
    # Save the plot as a PDF
    fig.savefig(outPath+"_data_all.pdf")
    fig.savefig(outPath+"_data_all.png")



if __name__ == '__main__':
    root.gROOT.SetBatch()
    main()
