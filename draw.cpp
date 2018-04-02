void draw(TString fname="minsuck_histo.txt") 
{ //define txt file name
  gStyle->SetOptFit(1); // draw fit result on canvas
 
  ifstream in1;
  float xxx[1000], yyy[1000]; //define variable
  Int_t nline=0;
  in1.open(fname); //open txt file
  while(1) 
    {
    in1 >> xxx[nline] >> yyy[nline]; //read numbers from txt file
    nline++;
    if(!in1.good()) break; //if there are no more inforamtion "while" is stop
    }
  in1.close();  //close file
  cout << nline << endl;

  TCanvas* c1 = new TCanvas("c1","",900,900); //define canvas
  TGraph *g1 = new TGraph(nline-1, xxx, yyy); //define graph
  g1->SetMarkerStyle(2); 
  g1->SetMarkerSize(1); 
  g1->Draw("AP"); //draw

  //Fitting Example

  TF1* gaus = new TF1("gaus", "gaus",0,500);  
  //gaus->SetParNames("Constant", "Mean", "Sigma");
  //gaus->SetParameters(5,5,5); //Change the paramter
  g1->Fit(gaus);
  gaus->Draw("same");

}
