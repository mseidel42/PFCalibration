#include <stdio.h>
// #include<conio.h>
void genrateplot_responsevsE_rawwrtcorrE(TString legendname, TString plot_name,  TString plot_name2, TString dir)
{
  TString hname,hname1,pdf="plots/pdf/"+plot_name+".pdf",gif="plots/gif/"+plot_name+".gif",png="plots/png/"+plot_name+".png";
  bool xaxis_pt=false;
  TString path_root1=dir+"/response/";
  //  TString path_root2="trial/response/";
  //pdf="trial/plots/pdf/"+plot_name+".pdf";gif="trial/plots/gif/"+plot_name+".gif";png="trial/plots/png/"+plot_name+".png";
    TString path_root2=dir+"/response/";

    //    pdf=dir+"/plots/pdf/Raw_"+plot_name2+".pdf";gif=dir+"/plots/gif/Raw_"+plot_name2+".gif";png=dir+"/plots/png/Raw_"+plot_name2+".png";
    pdf=dir+"/plotsv2/Rawwrttrial3/Raw_"+plot_name+".pdf";gif=dir+"/plotsv2/Rawwrttrial3/Raw_"+plot_name+".gif";png=dir+"/plotsv2/Rawwrttrial3/Raw_"+plot_name+".png";

    if(xaxis_pt==false){
    hname= path_root2+"resp_reso_"+plot_name2+".root";
    hname1= path_root1+"resp_reso_"+plot_name+".root";

  }
  else if(xaxis_pt==true){
    hname= path_root1+"resp_reso_"+plot_name+".root";
    hname1= path_root2+"resp_reso_"+plot_name2+".root";
  }
        
  cout<<"file name --> "<<plot_name<<endl;



  TCanvas *Canvas_1_n2 = new TCanvas("Canvas_1_n2", "Canvas_1_n2",700,400);
   //   Canvas_1_n2->Range(-60.25,-0.625,562.25,0.625);
  Canvas_1_n2->Divide(2,1);
   Canvas_1_n2->SetFillColor(0);
   Canvas_1_n2->SetBorderMode(0);
   Canvas_1_n2->SetBorderSize(2);
   Canvas_1_n2->SetFrameBorderMode(0);
   Canvas_1_n2->SetFrameBorderMode(0);
   TFile * inputfile1 = new TFile(hname,"READ");
   TFile * inputfile2 = new TFile(hname1,"READ");

   TGraph* graph1 = (TGraph*) inputfile1 -> Get("response;1");
   TH2F *respHisto_1 = (TH2F*) inputfile1 -> Get("respHisto");
   TGraph* graph1_ = (TGraph*) inputfile1 -> Get("resolution;1");
   TH2F *resoHisto_1 = (TH2F*) inputfile1 -> Get("resoHisto");

   TGraph* graph2 = (TGraph*) inputfile2 -> Get("response;1");
   TH2F *respHisto_2 = (TH2F*) inputfile2 -> Get("respHisto");
   TGraph* graph2_ = (TGraph*) inputfile2 -> Get("resolution;1");
   TH2F *resoHisto_2 = (TH2F*) inputfile2 -> Get("resoHisto");

   // respHisto__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");

   Canvas_1_n2->cd(1);
   gPad->SetGrid();
   //   Canvas_1_n2->SetGridy();

   respHisto_1->SetLineColor(ci);
   respHisto_1->Draw("");
   
   graph1->SetName("Graph1");
   graph1->SetTitle("Graph");
   graph1->SetFillStyle(1000);
   graph1->SetMarkerColor(kBlue);
   graph1->SetMarkerStyle(22);
   graph1->SetMarkerSize(0.8);   

   TH1F *Graph_Graph01 = new TH1F("Graph_Graph01","Graph",100,0,554.4);
   Graph_Graph01->SetMinimum(-540.4823);
   Graph_Graph01->SetMaximum(5940.616);
   Graph_Graph01->SetDirectory(0);
   Graph_Graph01->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph01->SetLineColor(ci);
   Graph_Graph01->GetXaxis()->SetLabelFont(42);
   if(xaxis_pt==false)
     Graph_Graph01->GetXaxis()->SetLabelSize(0.035);
   else if(xaxis_pt==true)
     Graph_Graph01->GetXaxis()->SetLabelSize(0.0);
   Graph_Graph01->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph01->GetXaxis()->SetTitleFont(42);
   Graph_Graph01->GetYaxis()->SetLabelFont(42);
   Graph_Graph01->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph01->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph01->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph01->GetYaxis()->SetTitleFont(42);
   Graph_Graph01->GetZaxis()->SetLabelFont(42);
   Graph_Graph01->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph01->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph01->GetZaxis()->SetTitleFont(42);
   graph1->SetHistogram(Graph_Graph01);
   graph1->Draw("p");
   graph2->SetMarkerColor(kRed);
   graph2->SetMarkerSize(0.8);
   graph2->Draw("p");

   Canvas_1_n2->cd(2);
   gPad->SetGrid();
   resoHisto_1->SetLineColor(ci);
   resoHisto_1->Draw("");

   graph1_->SetName("Graph1_");
   graph1_->SetTitle("Graph");
   graph1_->SetFillStyle(1000);
   graph1_->SetMarkerColor(kBlue);
   graph1_->SetMarkerStyle(22);
   //   graph1_->SetMarkerSize(1.1);
   TH1F *Graph_Graph02 = new TH1F("Graph_Graph02","Graph",100,0,554.4);
   Graph_Graph02->SetMinimum(-540.4823);
   Graph_Graph02->SetMaximum(5940.616);
   Graph_Graph02->SetDirectory(0);
   Graph_Graph02->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph02->SetLineColor(ci);
   Graph_Graph02->GetXaxis()->SetLabelFont(42);
   if(xaxis_pt==false)
     Graph_Graph02->GetXaxis()->SetLabelSize(0.035);
   else if(xaxis_pt==true)
     Graph_Graph02->GetXaxis()->SetLabelSize(0.0);
   Graph_Graph02->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph02->GetXaxis()->SetTitleFont(42);
   Graph_Graph02->GetYaxis()->SetLabelFont(42);
   Graph_Graph02->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph02->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph02->GetYaxis()->SetTitleOffset(0);
   Graph_Graph02->GetYaxis()->SetTitleFont(42);
   Graph_Graph02->GetZaxis()->SetLabelFont(42);
   Graph_Graph02->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph02->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph02->GetZaxis()->SetTitleFont(42);
   graph1->SetHistogram(Graph_Graph02);
   graph1_->Draw("p");
   graph2_->SetMarkerColor(kRed);
   graph2_->Draw("p");

   // TLine *line = new TLine(1.2273,0,498.0851,0);
   Canvas_1_n2->cd(1);    
   TLine *line;
   if (xaxis_pt==false)
     line = new TLine(0,0,500,0);
   else if(xaxis_pt==true)
     line = new TLine(0,0,100,0);
     
   line->SetLineColor(2);
   line->SetLineWidth(2);
   line->Draw();
   //Canvas_1_n2->Modified();
   //   Canvas_1_n2->cd();
   //
   //Canvas_1_n2->SetSelected(Canvas_1_n2);


   // TLegend* legends = new TLegend(0.44, 0.7, 0.9, 0.9,"","brNDC"); // the numbers determine the position of the box 
   TLegend* legends = new TLegend(0.35, 0.75, 0.9, 0.9,"","brNDC"); // the numbers determine the position of the box 
   legends->SetFillColor(0); 
   legends->SetHeader(legendname,"C"); 

   legends->AddEntry(graph1,"After E dep. calbitations)","P");
   legends->AddEntry(graph2,"Raw (no calbitations)","P");//(name of hist,what you want it called in legend, l=line, p=polymarker, f=boxy thing ) 

   //legends->AddEntry(graph2,"corr E (For Run3)","P");//(name of hist,what you want it called in legend, l=line, p=polymarker, f=boxy thing )
   // legends->AddEntry(graph1,"corr E (trial param. + Run3 GT)","P");
   //   legends->AddEntry(graph2,"corr E (UL2018 param. + Run3 GT)","P");

   legends->SetTextSize(0.04);
    //   legends->SetMarkerStyle(1);
   legends->Draw();
   Canvas_1_n2->SaveAs(pdf);
   Canvas_1_n2->SaveAs(png);
   Canvas_1_n2->SaveAs(gif);

}
