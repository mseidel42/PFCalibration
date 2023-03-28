#include <stdio.h>
// #include<conio.h>
void genrateplot_1dresponsevsE_rawwrtcorrE(TString legendname, TString plot_name="barrel_corrEndcapEcalHcal", TString plot_name2="barrel_corrEndcapEcalHcal", TString legendname_="EH_barrel")
{
  TString hname,hname1,pdf,png,gif;
  bool xaxis_pt=false;
  //  TString path_root1="raw/1d_response/";
  //TString path_root2="Ecorr/1d_response/";
  //  TString path_root2="usingUL2018/1d_response/";
  TString path_root2="trial3/1d_response/";
  TString path_root1="trial3/1d_response/";

  if(xaxis_pt==false){
    hname= path_root1+"projections_"+plot_name+".root";
    hname1= path_root2+"projections_"+plot_name2+".root";

  }
  else if(xaxis_pt==true){
    hname= path_root1+"projections_"+plot_name+".root";
    hname1= path_root2+"projections_"+plot_name2+".root";
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
  for(int i=1; i<69;i++)
    {//  int i=2;
  
    //      if(legendname_=="EH_ec_out" && i<3) continue; 
      char* hist_name = new char[200];
      char* stat_name = new char[200];

      //      TString hist_name="histcorhybrid";//+n[i];
      sprintf(hist_name,"histcorhybrid%d",n[i]);
      sprintf(stat_name,"E_{true} =  {%d GeV - %d GeV}",n[i],n[i+1]);
      //      cout<<"hist name --> "<<hist_name<<n[i]<<endl;
      
      /*
      pdf="trial2/plots/pdf/Rawwrttrial2/"+legendname_+"/"+hist_name+"_v2.pdf";
      png="trial2/plots/png/Rawwrttrial2/"+legendname_+"/"+hist_name+"_v2.png";
      gif="trial2/plots/gif/Rawwrttrial2/"+legendname_+"/"+hist_name+"_v2.gif";
      */
      pdf="trial3/plotsv2/Rawwrttrial3/1D_response/"+legendname_+"/"+hist_name+"_v2.pdf";
      png="trial3/plotsv2/Rawwrttrial3/1D_response/"+legendname_+"/"+hist_name+"_v2.png";
      gif="trial3/plotsv2/Rawwrttrial3/1D_response/"+legendname_+"/"+hist_name+"_v2.gif";

      TCanvas *Canvas_1_n2 = new TCanvas("Canvas_1_n2", "Canvas_1_n2",600,600);

      Canvas_1_n2->SetFillColor(0);
      Canvas_1_n2->SetBorderMode(0);
      Canvas_1_n2->SetBorderSize(2);
      Canvas_1_n2->SetFrameBorderMode(0);
      Canvas_1_n2->SetFrameBorderMode(0);
      TFile * inputfile1 = new TFile(hname,"READ");
      TFile * inputfile2 = new TFile(hname1,"READ");
      TH1D* graph1 = (TH1D*)inputfile1->Get(hist_name);
      TH1D* graph2 = (TH1D*)inputfile2->Get(hist_name);
      TF1* ga2 = (TF1*)graph1->GetFunction("gaus");
      ga2->Delete();
      TF1* ga3 = (TF1*)graph2->GetFunction("gaus");
      ga3->Delete();


      TPaveStats *ptstats2 = new TPaveStats(0.60,0.47,0.9,0.67,"brNDC");
      ptstats2->SetBorderSize(1);
      ptstats2->SetFillColor(0);
      ptstats2->SetLineColor(kRed);
      ptstats2->AddText("Raw");
      ptstats2->SetTextAlign(12);
      ptstats2->SetTextColor(kRed);
      ptstats2->SetTextFont(42);
      ptstats2->SetTextSize(0.0315317);
      ptstats2->SetOptStat(1111);
      ptstats2->SetOptFit(10001);
      //   ptstats2->Draw();                                                                                                                                                   
      graph1->GetListOfFunctions()->Add(ptstats2);
      ptstats2->SetParent(graph1);

      TPaveStats *ptstats3 = new TPaveStats(0.60,0.27,0.9,0.47,"brNDC");
      ptstats3->SetBorderSize(1);
      ptstats3->SetFillColor(0);
      ptstats3->SetLineColor(kBlue);
      ptstats3->SetTextAlign(12);
      ptstats3->SetTextColor(kBlue);
      ptstats3->SetTextFont(42);
      ptstats3->SetTextSize(0.0315317);
      ptstats3->SetOptStat(1111);
      ptstats3->SetOptFit(10001);
   //   ptstats3->Draw();                                                                                                                                                   
      graph2->GetListOfFunctions()->Add(ptstats3);
      ptstats3->SetParent(graph2);
      double ymax;
      double y1=graph1->GetMaximum();
      double y2=graph2->GetMaximum();
      if (y1>y2)
	ymax=y1 + 1000;
      else
	ymax=y2 + 1000;
      
      cout<<"ymax    "<<ymax<<endl;

      //      resp->GetXaxis()->SetRangeUser(xmin , xmax);
      graph1->GetYaxis()->SetRangeUser(0 , ymax);
      graph2->GetYaxis()->SetRangeUser(0 , ymax);

      
      graph1->SetLineColor(kRed);
      graph1->SetLineWidth(3);
      graph1->SetMarkerStyle(22);
      graph1->SetMarkerSize(1.1);   
      

      graph1->Draw();
      
      graph2->SetLineColor(kBlue);
      graph2->SetLineWidth(3);
      graph2->SetMarkerStyle(22);
      graph2->SetMarkerSize(1.1);


      graph2->Draw("sames");

      gPad->SetGrid();
      TLegend* legend1 = new TLegend(0.1, 0.85, 0.45, 0.9,"","brNDC");      
      legend1->SetFillColor(0);
      legend1->SetHeader(stat_name,"C");
      legend1->SetTextSize(0.03);
      legend1->Draw();

      TLegend* legends = new TLegend(0.52, 0.75, 0.9, 0.9,"","brNDC"); // the numbers determine the position of the box 
      legends->SetFillColor(0); 
      legends->SetHeader(legendname,"C"); 
      legends->AddEntry(graph1,"Without calibration","l");//(name of hist,what you want it called in legend, l=line, p=polymarker, f=boxy thing ) 
      legends->AddEntry(graph2,"After Energy calibration","l");
      legends->SetTextSize(0.03);
   //   legends->SetMarkerStyle(1);
      legends->Draw();
      Canvas_1_n2->SaveAs(pdf);
      Canvas_1_n2->SaveAs(png);
      Canvas_1_n2->SaveAs(gif);
    }
}
