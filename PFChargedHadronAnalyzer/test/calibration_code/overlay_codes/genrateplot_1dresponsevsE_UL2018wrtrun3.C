#include <stdio.h>
// #include<conio.h>
void genrateplot_1dresponsevsE_UL2018wrtrun3(TString legendname, TString plot_name, TString plot_name2, TString legendname_,int nbin_=15)
{
  TString hname,hname1,pdf,png,gif;
  bool xaxis_pt=false;
  TString path_root2="usingRun3/1d_response/";
  path_root2="../../Run3/trial2/1D_response/";
  path_root2="noPU/1d_response/";
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

  int n[69],m[69];
  n[0]=0;
  n[1]=2;
  m[0]=0;

  for(int i=2; i<69; i++)
    {
      if (n[i-1]<12)
        n[i]=n[i-1]+2;
      else if (n[i-1]>=12 && n[i-1]<104)
        n[i]=n[i-1]+4;
      else
        n[i]=n[i-1]+10;

    }

  for(int i=1; i<69; i++)
    {
      if (n[i]<10)
	m[i]=0;
      else if (n[i]<100)
	m[i]=1;
      else
	m[i]=2;
      
    }

 
  //  for(int i=1; i<69;i++)
    {
      int i=nbin_;
      //if(legendname_=="EH_ec_out" && i<3) continue; 
      char* hist_name1 = new char[200];
      char* hist_name = new char[200];
      char* stat_name = new char[200];

      //      TString hist_name="histcorhybrid";//+n[i];
      sprintf(hist_name1,"histcorhybrid%d_%d",m[i],n[i]);
      sprintf(hist_name,"histcorhybrid%d",n[i]);
      sprintf(stat_name,"E_{true} =  {%d GeV - %d GeV}",n[i],n[i+1]);
      //      cout<<"hist name --> "<<hist_name<<n[i]<<endl;
      
      //      pdf="trial3/plotsv2/Oldwrttrial3/Old_"+plot_name+".pdf";gif="trial3/plotsv2/Oldwrttrial3/Old_"+plot_name+".gif";png="trial3/plotsv2/Oldwrttrial3/Old_"+plot_name+".png";

      pdf="trial3/plotsv2/Oldwrttrial3/1D_response/"+legendname_+"/"+hist_name1+"_v2.pdf";
      png="trial3/plotsv2/Oldwrttrial3/1D_response/"+legendname_+"/"+hist_name1+"_v2.png";
      gif="trial3/plotsv2/Oldwrttrial3/1D_response/"+legendname_+"/"+hist_name1+"_v2.gif";

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


      TPaveStats *ptstats2 = new TPaveStats(0.66,0.47,0.9,0.67,"brNDC");
      ptstats2->SetBorderSize(1);
      ptstats2->SetFillColor(0);
      ptstats2->SetLineColor(kBlue);
      ptstats2->AddText("Raw");
      ptstats2->SetTextAlign(12);
      ptstats2->SetTextColor(kBlue);
      ptstats2->SetTextFont(42);
      ptstats2->SetTextSize(0.0315317);
      ptstats2->SetOptStat(1110);
      ptstats2->SetOptFit(00000);
      //ptstats2->SetOptStat(1111);
      //ptstats2->SetOptFit(10001);
      //   ptstats2->Draw();                                                                                                                                                   
      graph1->GetListOfFunctions()->Add(ptstats2);
      ptstats2->SetParent(graph1);

      TPaveStats *ptstats3 = new TPaveStats(0.66,0.27,0.9,0.47,"brNDC");
      ptstats3->SetBorderSize(1);
      ptstats3->SetFillColor(0);
      ptstats3->SetLineColor(kRed);
      ptstats3->SetTextAlign(12);
      ptstats3->SetTextColor(kRed);
      ptstats3->SetTextFont(42);
      ptstats3->SetTextSize(0.0315317);
      ptstats3->SetOptStat(1110);
      ptstats3->SetOptFit(00000);
   //   ptstats3->Draw();                                                                                                                                                   
      graph2->GetListOfFunctions()->Add(ptstats3);
      ptstats3->SetParent(graph2);

      graph2->Scale(1.0/graph2->Integral());
      graph1->Scale(1.0/graph1->Integral());

      double ymax;
      double y1=graph1->GetMaximum();
      double y2=graph2->GetMaximum();
      if (y1>y2)
	ymax=y1 + 0.02;
      else
	ymax=y2 + 0.02;
      
      cout<<"ymax    "<<ymax<<endl;

      graph1->GetXaxis()->SetRangeUser(-2 , 2);
      graph1->GetYaxis()->SetRangeUser(0 , ymax);
      graph2->GetYaxis()->SetRangeUser(0 , ymax);

      
      graph1->SetLineColor(kBlue);
      graph1->SetMarkerColor(kBlue);
      graph1->SetMarkerStyle(22);
      graph1->SetMarkerSize(0.8);   
      

      graph1->Draw("hist");
      graph2->SetMarkerColor(kRed);
      graph2->SetLineColor(kRed);
      graph2->SetMarkerStyle(22);
      graph2->SetMarkerSize(0.8);


      graph2->Draw("hist sames");

      gPad->SetGrid();
      TLegend* legend1 = new TLegend(0.1, 0.85, 0.5, 0.9,"","brNDC");      
      legend1->SetFillColor(0);
      legend1->SetHeader(stat_name,"C");
      legend1->SetTextSize(0.03);
      legend1->Draw();

      TLegend* legends = new TLegend(0.52, 0.75, 0.9, 0.9,"","brNDC"); // the numbers determine the position of the box 
      legends->SetFillColor(0); 
      legends->SetHeader(legendname,"C"); 
      //      legends->AddEntry(graph1,"UL2018 calib + Run3 GT","l");
      //      legends->AddEntry(graph2,"Run3 calib + Run3 GT","l");
      //      legends->AddEntry(graph1,"New calib (Run3v2 with PU)","l");
      //      legends->AddEntry(graph2,"Old calib (Run3)","l");

      //      legends->AddEntry(graph1,"New calib on Run3v2PU sample","P");
      //legends->AddEntry(graph2,"Old calib(Run3) on Run3 sample","P");
      legends->AddEntry(graph1,"Raw (Run3v2 with PU)","P");
      legends->AddEntry(graph2,"Raw (Run3v2 no PU)","P");

      legends->SetTextSize(0.032);
   //   legends->SetMarkerStyle(1);
      legends->Draw();
      Canvas_1_n2->SaveAs(pdf);
      Canvas_1_n2->SaveAs(png);
      Canvas_1_n2->SaveAs(gif);
    }
}
