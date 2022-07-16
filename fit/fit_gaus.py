import ROOT as root
import atlasplots as aplt
from ROOT import TFile
from ROOT import TH1
from ROOT import TMath

def DoubleSidedCrystalballFunction(x, par):

   alpha_l = par[0]
   alpha_h = par[1]
   n_l     = par[2]
   n_h     = par[3]
   mean= par[4]
   sigma= par[5]
   N= par[6]
   # float = (x[0]-mean)/sigma
   fact1TLessMinosAlphaL = alpha_l/n_l
   fact2TLessMinosAlphaL = (n_l/alpha_l) - alpha_l -t
   fact1THihgerAlphaH = alpha_h/n_h
   fact2THigherAlphaH = (n_h/alpha_h) - alpha_h +t

   if (-alpha_l <= t and alpha_h >= t):
      result = exp(-0.5*t*t)
   elif (t < -alpha_l):
      result = exp(-0.5*alpha_l*alpha_l)*pow(fact1TLessMinosAlphaL*fact2TLessMinosAlphaL, -n_l)
   elif (t > alpha_h):
      result = exp(-0.5*alpha_h*alpha_h)*pow(fact1THihgerAlphaH*fact2THigherAlphaH, -n_h)
   return N*result


def BreitWigner(x, mean, gamma):

   bw = gamma/((x-mean)*(x-mean) + gamma*gamma/4)
   return bw/(2*3.14)
 


def fit(hist, outPath, name, label):
    # Set the ATLAS Style
    aplt.set_atlas_style()

    # Create a figure and axes
    fig, (ax1, ax2) = aplt.ratio_plot(name="fig1", figsize=(800, 800), hspace=0.05)

    # Define a distribution
    # height = 1000000 #hist.GetMaximum()
    # mean = 90.6 #hist.GetMean()
    # sigma = 3.337 #hist.GetRMS()
    # sqroot = root.TF1("sqroot",  "[1]/2*3.14*((x-[0])*(x-[0]) + [1]*[1]/4*2*3.14)", 60, 120)
    # sqroot = root.TF1( "sqroot", "breitwigner", 60, 120)
    sqroot = root.TF1( "sqroot", "DoubleSidedCrystalballFunction", 60, 120)
    sqroot.SetParameters(1, 2, 2, 1, hist.GetMean(), hist.GetRMS(),hist.Integral(60, 120))
    sqroot.SetParNames ("alpha_{low}","alpha_{high}","n_{low}", "n_{high}", "mean", "sigma", "Norm")
 
    sqroot.SetParameters(hist.GetMaximum(),hist.GetMean(),hist.GetRMS())
    # sqroot.SetParameters(1, hist.GetMean())
    # sqroot.SetParameters(2 ,hist.GetRMS()()
    # Randomly fill the histogram according to the above distribution
    print(hist.GetMean(),hist.GetRMS())
    # Fit the histogram with the original distribution; store graphics func but do not draw
    hist.Fit("sqroot", "0")

    # Draw the histogram on these axes
    ax1.plot(hist, "E1", linewidth=2, label=name, labelfmt="E0")

    # Draw the fit function
    sqroot.SetNpx(1000)
    ax1.plot(sqroot, linecolor=root.kRed+1, label="Fit", labelfmt="L")

    # Draw line at y=0 in residuals panel
    line = root.TLine(ax1.get_xlim()[0], 0, ax1.get_xlim()[1], 0)
    ax2.plot(line)

    # Calculate and draw the fit residuals
    resids = hist.Clone("resids")
    for i in range(1, resids.GetNbinsX()):
        resids.SetBinContent(i, hist.GetBinContent(i) - sqroot.Eval(hist.GetBinCenter(i)))
        resids.SetBinError(i, hist.GetBinError(i))

    ax2.plot(resids, "E1", linewidth=1)

    # Add extra space at top of plot to make room for labels
    ax1.add_margins(top=0.16)

    # Add extra space at top and bottom of residuals panel
    ax2.add_margins(top=0.1, bottom=0.1)

    # Set axis titles
    ax2.set_xlabel(label)
    ax1.set_ylabel("Events")
    ax2.set_ylabel("Data - Fit", loc="center")

    # Go back to top axes to add labels
    ax1.cd()

    # Add the ATLAS Label
    aplt.atlas_label(text="Internal", loc="upper left")
    # ax1.text(0.2, 0.84, "#sqrt{s} = 13 TeV, 139 fb^{-1}", size=22, align=13)
    # ax1.text(0.2 ,0.79 , " Mean =  "+ str(round(sqroot.GetParameter(1),2))+ " GeV", size=22, align=13 )
    # ax1.text(0.2 ,0.74 , " Width =  " + str(round(sqroot.GetParameter(2),2))+ " GeV", size=22, align=13)
    # ax1.text(0.2 ,0.69 , " chi2 / ndof = " +str(round(sqroot.GetChisquare(),2))+"/"+str(round(sqroot.GetNDF(),2)), size=22, align=13 )
    # ax1.text(0.3 ,0.64, " = "+str(round(sqroot.GetChisquare()/sqroot.GetNDF(),2)), size=22, align=13 )
    # Add legend
    ax1.legend(loc=(0.65, 0.78, 0.92, 0.90))

    # Save the plot as a PDF
    # fig.savefig(outPath+name+"_gauss_fit.pdf")
    fig.savefig(outPath+name+"_gauss_morebins_fit.png")


if __name__ == '__main__':
    root.gROOT.SetBatch()
    inFile = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/no_bg_no_cuts/data_all.root")
    # inFile = TFile("/afs/cern.ch/work/s/ssindhu/private/qmisid_calc/no_cuts/more_bins/data_all.root")
    Hist = inFile.Get('ss_Mll_small')
    outPath = "/eos/home-s/ssindhu/4tops/plots/fit/"
    name = "SS"
    label = "M(l,l) [GeV]"
    fit(Hist, outPath, name, label)
