#include <stdio.h>
// #include<conio.h>
void genrateplot_1dresponsevsE(TString legendname, TString plot_name, TString legendname_)
{
  TString hname,pdf,png,gif;
  bool xaxis_pt=false;
  TString path_root1="raw/1d_response/";
  if(xaxis_pt==false){
    hname= path_root1+"projections_"+plot_name+".root";

  }
  else if(xaxis_pt==true){
    hname= path_root1+"projections_"+plot_name+".root";


  }
        
  cout<<"file name --> "<<hname<<endl;

  int n[69];
  n[0]=0;
  n[1]=2;
  for(int i=2; i<69; i++)
    {
      if (n[i-1]<12)
        n[i]=n[i-1]+2;
      else if (n[i-1]>=12 && n[i-1]<104)
        n[i]=n[i-1]+4;
      else
        n[i]=n[i-1]+10;
    }
  for(int i=15; i<16;i++)
    {
      if(legendname_=="EH_ec_out" && i<3) continue;
      char* hist_name = new char[200];
      char* stat_name = new char[200];

      //      TString hist_name="histcorhybrid";//+n[i];
      sprintf(hist_name,"histcorhybrid%d",n[i]);
      sprintf(stat_name,"E_{true} =  {%d GeV - %d GeV}",n[i],n[i+1]);
      //      cout<<"hist name --> "<<hist_name<<n[i]<<endl;
      
      pdf="raw_plots/plots/pdf/"+legendname_+"/"+hist_name+".pdf";
      png="raw_plots/plots/png/"+legendname_+"/"+hist_name+".png";
      gif="raw_plots/plots/gif/"+legendname_+"/"+hist_name+".gif";

      TCanvas *Canvas_1_n2 = new TCanvas("Canvas_1_n2", "Canvas_1_n2",600,400);

      Canvas_1_n2->SetFillColor(0);
      Canvas_1_n2->SetBorderMode(0);
      Canvas_1_n2->SetBorderSize(2);
      Canvas_1_n2->SetFrameBorderMode(0);
      Canvas_1_n2->SetFrameBorderMode(0);
      TFile * inputfile1 = new TFile(hname,"READ");
      TH1D* graph1 = (TH1D*)inputfile1->Get(hist_name);


      graph1->SetMarkerColor(kBlue);
      graph1->SetMarkerStyle(22);
      graph1->SetMarkerSize(0.8);   
      

      graph1->Draw("p");
      

      gPad->SetGrid();
      TLegend* legend1 = new TLegend(0.1, 0.82, 0.4, 0.9,"","brNDC");      
      legend1->SetFillColor(0);
      legend1->SetHeader(stat_name,"C");
      legend1->SetTextSize(0.04);
      legend1->Draw();

      TLegend* legends = new TLegend(0.64, 0.55, 0.9, 0.7,"","brNDC"); // the numbers determine the position of the box 
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
}
