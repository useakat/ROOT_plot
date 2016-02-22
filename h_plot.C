void h_plot()
{
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   gROOT->LoadMacro("DividegPad.C");
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetFrameLineWidth(2);

   TLegend* legend;
   Double_t x1leg = 0.60;
   Double_t y1leg = 0.43;
   Double_t x2leg = 0.88;
   Double_t y2leg = 0.58;
   TLatex* text = new TLatex();
   text->SetTextAlign(12);
   text->SetTextSize(0.040);
   TString f_pdf = "plot.pdf";
   TString f_eps = "plot.eps";
   TFile* f1 = new TFile("../LHEAnalysis_pp_ttx_Wmjjbbx.root");
   //   TFile* f2 = new TFile("../LHEAnalysis_pp_Wmjjbbx.root");
   //TFile* f3 = new TFile("../LHEAnalysis_pp_Wmjjjj.root");

   TH1D* h1 = (TH1D*)f1->Get("h_chi2");
   h1->SetLineWidth(2);
   h1->SetLineStyle(1);
   h1->SetLineColor(kRed+1);
   /*
   TH1D* h2 = (TH1D*)f2->Get("h_chi2")
   h2->SetLineWidth(2);
   h2->SetLineStyle(2);
   h2->SetLineColor(kBlue+1);

   TH1D* h3 = (TH1D*)f3->Get("h_chi2")
   h3->SetLineWidth(2);
   h3->SetLineStyle(3);
   h3->SetLineColor(kGreen+1);
   */
   TCanvas* c1 = new TCanvas("c1","Plot");
   h1->GetXaxis()
      ->SetTitle("Plot");
   //   gPad->SetLogy(1);
   //   gPad->SetLogx(1);

   h1->Draw();
   //   h2->Draw("same");
   //h3->Draw("same");

   legend = new TLegend(x1leg,y1leg,x2leg,y2leg);
   legend->AddEntry(h1,"h1","l");
   //legend->AddEntry(h2,"h2","l");
   //legend->AddEntry(h3,"h3","l");
   legend->SetTextSize(0.035);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   c1->Update();
   c1->Print(f_eps);

}
