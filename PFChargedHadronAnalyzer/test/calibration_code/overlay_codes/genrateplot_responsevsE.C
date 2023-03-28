#include <stdio.h>
// #include<conio.h>
void genrateplot_responsevsE(TString legendname, TString plot_name)
{
  TString hname,pdf="plots/pdf/"+plot_name+".pdf",gif="plots/gif/"+plot_name+".gif",png="plots/png/"+plot_name+".png";
  bool xaxis_pt=false;
  TString path_root1="raw/response/";
  if(xaxis_pt==false){
    hname= path_root1+"resp_reso_"+plot_name+".root";

  }
  else if(xaxis_pt==true){
    hname= path_root1+"resp_reso_"+plot_name+".root";


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
   TGraph* graph1 = (TGraph*) inputfile1 -> Get("response;1");
   TH2F *respHisto__1 = (TH2F*) inputfile1 -> Get("respHisto");
   TGraph* graph2 = (TGraph*) inputfile1 -> Get("resolution;1");
   TH2F *respHisto__2 = (TH2F*) inputfile1 -> Get("resoHisto");

   // respHisto__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");

   Canvas_1_n2->cd(1);
   gPad->SetGrid();
   //   Canvas_1_n2->SetGridy();

   respHisto__1->SetLineColor(ci);
   respHisto__1->Draw("");
   
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

   Canvas_1_n2->cd(2);
   gPad->SetGrid();
   respHisto__2->SetLineColor(ci);
   respHisto__2->Draw("");

   graph2->SetName("Graph2");
   graph2->SetTitle("Graph");
   graph2->SetFillStyle(1000);
   graph2->SetMarkerColor(kBlue);
   graph2->SetMarkerStyle(22);
   graph2->SetMarkerSize(1.1);
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
   graph2->SetHistogram(Graph_Graph02);
   graph2->Draw("p");

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
   TLegend* legends = new TLegend(0.44, 0.8, 0.9, 0.9,"","brNDC"); // the numbers determine the position of the box 
   legends->SetFillColor(0); 
   legends->SetHeader(legendname); 
   legends->AddEntry(graph1,"Raw (For Run3)","P");//(name of hist,what you want it called in legend, l=line, p=polymarker, f=boxy thing ) 
   legends->SetTextSize(0.04);
    //   legends->SetMarkerStyle(1);
   legends->Draw();
   Canvas_1_n2->SaveAs(pdf);
   Canvas_1_n2->SaveAs(png);
   Canvas_1_n2->SaveAs(gif);

}
