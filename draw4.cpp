void draw4()
{ 

  TCanvas* c1 = new TCanvas("c1","",900,900);
  TGraph *g1 = new TGraph("cos.txt");
  g1->Draw("A*");
  TF1 *f1 = new TF1("f1","cos(x)*cos(x)",0,90);
  g1->Fit(f1);
  f1 = g1->GetFunction("f1");
  f1->SetLineWidth(1);  

} 
