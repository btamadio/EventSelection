#include "eventSelection.hh"
int main (int argc, char **argv){
  if (argc < 2){
      printf("\nUsage: %s *.root\n\n",argv[0]);
      exit(0);
  }
		 
  int const ind = argc - 1; 
  TString *path = new TString[ind];
  TChain *chain = new TChain("outTree/nominal");
  for ( int j = 0; j < argc-1; j++){
      path[j] = (argv[j+1]);
      ifstream file_to_read((TString)"./files/"+path[j]);
      if(file_to_read.is_open() != 1 )
	{
	  cout << "The input file " << "./files/"<< path[j]  << " does not exist." << endl;
	  exit(1);
	}

      while(!file_to_read.eof())
	{
	  TString path_to_the_file ;
	  file_to_read >> path_to_the_file ;
	  if (path_to_the_file == "") continue;
	  cout<<"path_to_the_file = "<<path_to_the_file<<endl;
	  chain->Add(path_to_the_file);
	}
    }
  
  //		 cout<<"path[0] = "<<path[0]<<endl;
  if(path[0].Contains("data2015")) m_GRLFileName = "../GRL/data15_13TeV.periodAllYear_DetStatus-v79-repro20-02_DQDefects-00-02-02_PHYS_StandardGRL_All_Good_25ns.xml";
  if(path[0].Contains("data2016")) m_GRLFileName = "../GRL/data16_13TeV.periodAllYear_DetStatus-v83-pro20-15_DQDefects-00-02-04_PHYS_StandardGRL_All_Good_25ns.xml";
  cout<<"Using GRL "<<m_GRLFileName<<endl;
  p = new nominalTree(chain);
  //  cout<<"Setting branch addresses"<<endl;
  p -> fChain ->SetBranchStatus("*",0);
  p -> fChain ->SetBranchStatus("runNumber",1);
  p -> fChain ->SetBranchStatus("eventNumber",1);
  p -> fChain ->SetBranchStatus("averageInteractionsPerCrossing",1);
  p -> fChain ->SetBranchStatus("lumiBlock",1);
  p -> fChain ->SetBranchStatus("TileError",1);
  p -> fChain ->SetBranchStatus("SCTError",1);
  p -> fChain ->SetBranchStatus("LArError",1);

  p -> fChain ->SetBranchStatus("jet_pt",1);
  p -> fChain ->SetBranchStatus("jet_eta",1);
  p -> fChain ->SetBranchStatus("jet_phi",1);
  p -> fChain ->SetBranchStatus("jet_E",1);
  if(p->fChain->GetListOfBranches()->Contains("nAntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib")){
    p -> fChain ->SetBranchStatus("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_pt",1);
    p -> fChain ->SetBranchStatus("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_eta",1);
    p -> fChain ->SetBranchStatus("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_phi",1);
    p -> fChain ->SetBranchStatus("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_m",1);
    p -> fChain ->SetBranchStatus("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_NTrimSubjets",1);
  }
  else{
    p -> fChain ->SetBranchStatus("fatjet_pt",1);
    p -> fChain ->SetBranchStatus("fatjet_eta",1);
    p -> fChain ->SetBranchStatus("fatjet_phi",1);
    p -> fChain ->SetBranchStatus("fatjet_m",1);
    p -> fChain ->SetBranchStatus("fatjet_NTrimSubjets",1);
  }

  p -> fChain ->SetBranchStatus("passedTriggers",1);
  p -> fChain ->SetBranchStatus("jet_clean_passLooseBad",1);
  if (p->isMC()){
    p -> fChain ->SetBranchStatus("mcChannelNumber",1);
    //    p -> fChain ->SetBranchStatus("weight",1);	
    p -> fChain ->SetBranchStatus("mcEventWeight",1);	
    if(p->fChain->GetListOfBranches()->Contains("weight_jetSFFix60")){    
      p -> fChain -> SetBranchStatus("weight_jetSFFix60",1);
      p -> fChain -> SetBranchStatus("weight_jetSFFix70",1);
      p -> fChain -> SetBranchStatus("weight_jetSFFix77",1);
      p -> fChain -> SetBranchStatus("weight_jetSFFix85",1);

    }
    else{
      p -> fChain -> SetBranchStatus("weight_jet_SFFix60",1);
      p -> fChain -> SetBranchStatus("weight_jet_SFFix70",1);
      p -> fChain -> SetBranchStatus("weight_jet_SFFix77",1);
      p -> fChain -> SetBranchStatus("weight_jet_SFFix85",1);
    }
    p -> fChain -> SetBranchStatus("jet_PartonTruthLabelID",1);
  }
  p -> fChain ->SetBranchStatus("jet_isFix60",1);
  p -> fChain ->SetBranchStatus("jet_isFix70",1);
  p -> fChain ->SetBranchStatus("jet_isFix77",1);
  p -> fChain ->SetBranchStatus("jet_isFix85",1);
  p -> fChain ->SetBranchStatus("jet_isFlt60",1);
  p -> fChain ->SetBranchStatus("jet_isFlt70",1);
  p -> fChain ->SetBranchStatus("jet_isFlt77",1);
  p -> fChain ->SetBranchStatus("jet_isFlt85",1);

  //  cout<<"creating cutflow histogram"<<endl;

  TH1F *h_cutflow = new TH1F("h_cutflow","Cutflow",8,-0.5,7.5);
  h_cutflow->GetXaxis()->SetBinLabel(1,"Total events");
  h_cutflow->GetXaxis()->SetBinLabel(2,"GRL");
  h_cutflow->GetXaxis()->SetBinLabel(3,"SCT/Tile/LAr");
  h_cutflow->GetXaxis()->SetBinLabel(4,"HT1000 trigger");
  h_cutflow->GetXaxis()->SetBinLabel(5,"njet == 2");
  h_cutflow->GetXaxis()->SetBinLabel(6,"njet == 3");
  h_cutflow->GetXaxis()->SetBinLabel(7,"njet == 4");
  h_cutflow->GetXaxis()->SetBinLabel(8,"njet >= 5");

  //miniTree
  TFile f("miniTree.root","recreate");
  TTree *mini = new TTree("miniTree","miniTree");

  int mini_runNumber,mini_mcChannelNumber=-1,mini_lumiBlock,mini_njet,mini_nbjet_fix60,mini_nbjet_fix70,mini_nbjet_fix77,mini_nbjet_fix85,mini_nbjet_flt60,mini_nbjet_flt70,mini_nbjet_flt77,mini_nbjet_flt85,mini_njet_ak4, mini_njet_soft;
  Long64_t mini_eventNumber;
  bool mini_isMC;
  double mini_HT, mini_MJall,mini_wt, mini_dEta,mini_mu, mini_MJ4, mini_m3j, mini_mmj, mini_bSF60, mini_bSF70, mini_bSF77, mini_bSF85;
  double mini_dPhi12, mini_dPhi23, mini_dPhi13;
  vector<double> *mini_jet_pt = 0;
  vector<double> *mini_jet_eta= 0;
  vector<double> *mini_jet_phi = 0;
  vector<double> *mini_jet_m =0;
  vector<int> *mini_jet_qmatched = 0;
  vector<int> *mini_jet_gmatched = 0;
  vector<int> *mini_jet_bmatched_fix60 =0;
  vector<int> *mini_jet_bmatched_fix70 =0;
  vector<int> *mini_jet_bmatched_fix77 =0;
  vector<int> *mini_jet_bmatched_fix85 =0;
  vector<int> *mini_jet_bmatched_flt60 =0;
  vector<int> *mini_jet_bmatched_flt70 =0;
  vector<int> *mini_jet_bmatched_flt77 =0;
  vector<int> *mini_jet_bmatched_flt85 =0;
  vector<int> *mini_jet_NTrimSubjets = 0;
  mini->Branch("runNumber",&mini_runNumber);
  mini->Branch("mcChannelNumber",&mini_mcChannelNumber);
  mini->Branch("eventNumber",&mini_eventNumber);
  mini->Branch("lumiBlock",&mini_lumiBlock);
  mini->Branch("mu",&mini_mu);
  mini->Branch("isMC",&mini_isMC);
  mini->Branch("weight",&mini_wt);
  mini->Branch("bSF_60",&mini_bSF60);
  mini->Branch("bSF_70",&mini_bSF70);
  mini->Branch("bSF_77",&mini_bSF77);
  mini->Branch("bSF_85",&mini_bSF85);

  mini->Branch("njet",&mini_njet);
  mini->Branch("njet_soft",&mini_njet_soft);
  mini->Branch("njet_ak4",&mini_njet_ak4);
  mini->Branch("nbjet_Fix60",&mini_nbjet_fix60);
  mini->Branch("nbjet_Fix70",&mini_nbjet_fix70);
  mini->Branch("nbjet_Fix77",&mini_nbjet_fix77);
  mini->Branch("nbjet_Fix85",&mini_nbjet_fix85);
  mini->Branch("nbjet_Flt60",&mini_nbjet_flt60);
  mini->Branch("nbjet_Flt70",&mini_nbjet_flt70);
  mini->Branch("nbjet_Flt77",&mini_nbjet_flt77);
  mini->Branch("nbjet_Flt85",&mini_nbjet_flt85);
  mini->Branch("jet_pt",&mini_jet_pt);
  mini->Branch("jet_eta",&mini_jet_eta);
  mini->Branch("jet_phi",&mini_jet_phi);
  mini->Branch("jet_m",&mini_jet_m);
  mini->Branch("jet_qmatched",&mini_jet_qmatched);
  mini->Branch("jet_gmatched",&mini_jet_gmatched);
  mini->Branch("jet_bmatched_Fix60",&mini_jet_bmatched_fix60);
  mini->Branch("jet_bmatched_Fix70",&mini_jet_bmatched_fix70);
  mini->Branch("jet_bmatched_Fix77",&mini_jet_bmatched_fix77);
  mini->Branch("jet_bmatched_Fix85",&mini_jet_bmatched_fix85);

  mini->Branch("jet_bmatched_Flt60",&mini_jet_bmatched_flt60);
  mini->Branch("jet_bmatched_Flt70",&mini_jet_bmatched_flt70);
  mini->Branch("jet_bmatched_Flt77",&mini_jet_bmatched_flt77);
  mini->Branch("jet_bmatched_Flt85",&mini_jet_bmatched_flt85);
  mini->Branch("jet_NTrimSubjets",&mini_jet_NTrimSubjets);
  mini->Branch("dEta",&mini_dEta);
  mini->Branch("HT",&mini_HT);
  mini->Branch("MJ",&mini_MJ4);
  mini->Branch("m3j",&mini_m3j);
  mini->Branch("mmj",&mini_mmj);
  mini->Branch("MJall",&mini_MJall);
  mini->Branch("dPhi12",&mini_dPhi12);
  mini->Branch("dPhi23",&mini_dPhi23);
  mini->Branch("dPhi13",&mini_dPhi13);
		
  int numev = p->fChain->GetEntries();
  //		 numev = 10;
  int pass_evt_counter = 0;
  bool isMC = false;
  isMC = p->isMC();
  if(!isMC) readGRL();
  cout<<"Processing "<<numev<<" events."<<endl;

  for( int i = 0 ; i < numev; i ++ ){
      get_event(i) ;
      if( i%10000 == 0 ) cout << i << " events processed " << endl;
      //      cout<<"Event "<<i<<endl;
      int check_run = p->runNumber;
      int check_lumi = p->lumiBlock;
      //             long int check_event = p->eventNumber;
      //      cout<<"    check_run = "<<check_run<<endl;
      double wt=1;
      mini_bSF60=1;
      mini_bSF70=1;
      mini_bSF77=1;
      mini_bSF85=1;
      if(isMC) {
	wt = 1e6*RPV_xsec(p->mcChannelNumber)*p->mcEventWeight/Nevent(p->mcChannelNumber);
	//	wt = 1e6*(p->weight)/Nevent(p->mcChannelNumber);
	mini_bSF60 = p->weight_jet_SFFix60->at(0);
	mini_bSF70 = p->weight_jet_SFFix70->at(0);
	mini_bSF77 = p->weight_jet_SFFix77->at(0);
	mini_bSF85 = p->weight_jet_SFFix85->at(0);
      }
      //check good run list
      h_cutflow->Fill(0.0,wt);
      if(!isMC && !passGRL(check_run,check_lumi)) continue;
      h_cutflow->Fill(1.0,wt);

      //check SCT/Tile/LAr
      if(!isMC && (p->LArError || p->TileError || p->SCTError)) continue;
      h_cutflow->Fill(2.0,wt);

      //Loop over small R jets
      int njet = (int)(*p->jet_pt).size();
      int ak4_counter=0;

      //TODO: Fix this code using TLorentzVectors
      int bjet_counter_fix60=0,bjet_counter_fix70 = 0,bjet_counter_fix77=0,bjet_counter_fix85=0;
      int bjet_counter_flt60=0,bjet_counter_flt70 = 0,bjet_counter_flt77=0,bjet_counter_flt85=0;

      vector<double> bjet_flt60_eta;
      vector<double> bjet_flt70_eta;
      vector<double> bjet_flt77_eta;
      vector<double> bjet_flt85_eta;

      vector<double> bjet_fix60_eta;
      vector<double> bjet_fix70_eta;
      vector<double> bjet_fix77_eta;
      vector<double> bjet_fix85_eta;

      vector<double> bjet_flt60_phi;
      vector<double> bjet_flt70_phi;
      vector<double> bjet_flt77_phi;
      vector<double> bjet_flt85_phi;

      vector<double> bjet_fix60_phi;
      vector<double> bjet_fix70_phi;
      vector<double> bjet_fix77_phi;
      vector<double> bjet_fix85_phi;
      
      vector<TLorentzVector> qjet_fourMom;
      vector<TLorentzVector> gjet_fourMom;
      //      cout<<"    Loop over small-R jets"<<endl;
      for( int k = 0 ; k < njet ; k ++ ){
	//	cout<<"        jet number "<<k<<endl;
	//	cout<<"            pt = "<<p->jet_pt->at(k)<<" eta = "<<p->jet_eta->at(k)<<" clean = "<<p->jet_clean_passLooseBad->at(k)<<endl;
	if( fabs(p->jet_eta->at(k)) > 2.8 ) continue ;
	if( p->jet_pt->at(k) < 50 ) continue ;
	if( p->jet_clean_passLooseBad->at(k) == 0) continue;   
	//	cout<<"            good jet"<<endl;
	TLorentzVector thisJetFourMom;
	thisJetFourMom.SetPtEtaPhiE(p->jet_pt->at(k)/1000.,p->jet_eta->at(k),p->jet_phi->at(k),p->jet_E->at(k)/1000.);
	if( p->isMC() ){
	  if( p->jet_PartonTruthLabelID->at(k) == 21 ){
	    gjet_fourMom.push_back(thisJetFourMom);
	  }
	  if( abs(p->jet_PartonTruthLabelID->at(k)) >= 1 && abs(p->jet_PartonTruthLabelID->at(k)) <= 8){
	    qjet_fourMom.push_back(thisJetFourMom);
	  }
	}
	ak4_counter++;
	if(p->jet_isFix60->at(k)) {
	  bjet_counter_fix60++;
	  //save kinematics to match to largeR jet
	  bjet_fix60_eta.push_back((*p->jet_eta)[k]);
	  bjet_fix60_phi.push_back((*p->jet_phi)[k]);
	}
	if((*p->jet_isFix70)[k]) {
	  bjet_counter_fix70++;
	  //save kinematics to match to largeR jet
	  bjet_fix70_eta.push_back((*p->jet_eta)[k]);
	  bjet_fix70_phi.push_back((*p->jet_phi)[k]);
	}
	if((*p->jet_isFix77)[k]) {
	  bjet_counter_fix77++;
	  //save kinematics to match to largeR jet
	  bjet_fix77_eta.push_back((*p->jet_eta)[k]);
	  bjet_fix77_phi.push_back((*p->jet_phi)[k]);
	}
	if((*p->jet_isFix85)[k]) {
	  bjet_counter_fix85++;
	  //save kinematics to match to largeR jet
	  bjet_fix85_eta.push_back((*p->jet_eta)[k]);
	  bjet_fix85_phi.push_back((*p->jet_phi)[k]);
	}

	if((*p->jet_isFlt60)[k]) {
	  bjet_counter_flt60++;
	  //save kinematics to match to largeR jet
	  bjet_flt60_eta.push_back((*p->jet_eta)[k]);
	  bjet_flt60_phi.push_back((*p->jet_phi)[k]);
	}
	if((*p->jet_isFlt70)[k]) {
	  bjet_counter_flt70++;
	  //save kinematics to match to largeR jet
	  bjet_flt70_eta.push_back((*p->jet_eta)[k]);
	  bjet_flt70_phi.push_back((*p->jet_phi)[k]);
	}
	if((*p->jet_isFlt77)[k]) {
	  bjet_counter_flt77++;
	  //save kinematics to match to largeR jet
	  bjet_flt77_eta.push_back((*p->jet_eta)[k]);
	  bjet_flt77_phi.push_back((*p->jet_phi)[k]);
	}
	if((*p->jet_isFlt85)[k]) {
	  bjet_counter_flt85++;
	  //save kinematics to match to largeR jet
	  bjet_flt85_eta.push_back((*p->jet_eta)[k]);
	  bjet_flt85_phi.push_back((*p->jet_phi)[k]);
	}
      }

      //Loop over fat jets
      int nfatjet = p->fatjet_pt->size();
      //cout<<"nfatjet = "<<nfatjet<<endl;
      int max_ind ;
      vector<double> jet_pt;
      vector<double> jet_eta;
      vector<double> jet_phi;
      vector<double> jet_m;
      vector<int> jet_NTrimSubjets;
      mini_HT = 0; mini_MJall = 0; mini_MJ4 = 0; mini_m3j = 0; mini_mmj = 0;
      mini_dPhi12=0; mini_dPhi23=0; mini_dPhi13=0;
      int NsoftJet = 0;
      double dummy_m;
      for(int l = 0; l < nfatjet; l++){
	if(p->fatjet_pt->at(l) > 100 && p->fatjet_pt->at(l) < 200 && fabs(p->fatjet_eta->at(l)) < 2.0 ) NsoftJet++;
	//cout<<"p->fatjet_pt->at(l) = "<<p->fatjet_pt->at(l)<<"\t p->fatjet_eta->at(l)"<<p->fatjet_eta->at(l)<<endl;
	if( fabs(p->fatjet_eta->at(l)) > 2.0 ) continue ;
	if(p->fatjet_pt->at(l) < 200 ) continue ;
	TLorentzVector thisfatjet ;
	thisfatjet.SetPtEtaPhiM(p->fatjet_pt->at(l), p->fatjet_eta->at(l),p->fatjet_phi->at(l),p->fatjet_m->at(l));
	if( thisfatjet.M()/thisfatjet.Pt() > 1.0) continue;

	jet_pt.push_back(thisfatjet.Pt()/1000.);
	jet_eta.push_back(thisfatjet.Eta());
	jet_phi.push_back(thisfatjet.Phi());
	jet_NTrimSubjets.push_back((*p->fatjet_NTrimSubjets)[l]);
	dummy_m = thisfatjet.M()/1000;
	if(dummy_m < 0) dummy_m = 0;
	jet_m.push_back(dummy_m);
	mini_HT += thisfatjet.Pt()/1000;
      }
      mini_njet = jet_pt.size();
      //      cout<<mini_njet<<endl;
      mini_njet_soft = NsoftJet;
      //      cout<<"mini_njet = "<<mini_njet<<endl;
      if(mini_njet==0){ continue; }
      //Sort by pt
      sort(jet_pt.begin(),jet_pt.end(),greater<double>());
      vector<int> idx = sort_indices(jet_pt);
      reorder(jet_eta,idx);
      reorder(jet_phi,idx);
      reorder(jet_m,idx);
      reorder(jet_NTrimSubjets,idx);
      TLorentzVector threeJetFourMom;
      TLorentzVector multiJetFourMom;
      threeJetFourMom.SetPtEtaPhiM(0,0,0,0);
      multiJetFourMom.SetPtEtaPhiM(0,0,0,0);
      vector<TLorentzVector> fatJetFourMom;
      if (jet_pt.size() >= 3){
	for(int ii = 0; ii < 3; ii++){
	  TLorentzVector thisFatJet;
	  thisFatJet.SetPtEtaPhiM(jet_pt.at(ii),jet_eta.at(ii),jet_phi.at(ii),jet_m.at(ii));
	  threeJetFourMom += thisFatJet;
	  fatJetFourMom.push_back(thisFatJet);
	}
	mini_dPhi12 = fatJetFourMom.at(0).DeltaPhi(fatJetFourMom.at(1));
	mini_dPhi23 = fatJetFourMom.at(1).DeltaPhi(fatJetFourMom.at(2));
	mini_dPhi13 = fatJetFourMom.at(0).DeltaPhi(fatJetFourMom.at(2));
      }
      for(unsigned int ii=0;ii<jet_pt.size();ii++){
	TLorentzVector thisFatJet;
	thisFatJet.SetPtEtaPhiM(jet_pt.at(ii),jet_eta.at(ii),jet_phi.at(ii),jet_m.at(ii));
	multiJetFourMom += thisFatJet;
      }
      mini_m3j = threeJetFourMom.M();
      mini_mmj = multiJetFourMom.M();
      //match to ak4 bjets
      double dEta, dPhi, dR;
      vector<int> jet_qmatched;
      vector<int> jet_gmatched;
      vector<int> jet_bmatched_fix60;
      vector<int> jet_bmatched_fix70;
      vector<int> jet_bmatched_fix77;
      vector<int> jet_bmatched_fix85;

      vector<int> jet_bmatched_flt60;
      vector<int> jet_bmatched_flt70;
      vector<int> jet_bmatched_flt77;
      vector<int> jet_bmatched_flt85;

      bool matched = false;
      for(int k = 0; k < mini_njet; k++){
	//q-jets
	TLorentzVector thisFatJetFourMom;
	thisFatJetFourMom.SetPtEtaPhiM(jet_pt.at(k),jet_eta.at(k),jet_phi.at(k),jet_m.at(k));
	//Find deltaR to nearest q-jet and nearest g-jet
	float QdR = 999;
	float GdR = 999;
	for(unsigned int l = 0; l < qjet_fourMom.size(); l++){
	  if(qjet_fourMom.at(l).DeltaR(thisFatJetFourMom) < 1.0 && qjet_fourMom.at(l).DeltaR(thisFatJetFourMom) < QdR){
	    QdR = qjet_fourMom.at(l).DeltaR(thisFatJetFourMom);
	  }
	}
	for(unsigned int l = 0; l < gjet_fourMom.size(); l++){
	  if(gjet_fourMom.at(l).DeltaR(thisFatJetFourMom) < 1.0 && gjet_fourMom.at(l).DeltaR(thisFatJetFourMom) < GdR){
	    GdR = gjet_fourMom.at(l).DeltaR(thisFatJetFourMom);
	  }
	}
	bool qMatched = false;
	bool gMatched = false;

	if (QdR > 1.0 && GdR > 1.0){
	  qMatched = false;
	  gMatched = false;
	}
	else{
	  if(QdR < GdR){ qMatched = true; }
	  if(GdR < QdR){ gMatched = true; }
	  if(GdR == QdR ) { gMatched = true; }
	}
	//	cout<<QdR<<"\t"<<GdR<<"\t"<<qMatched<<"\t"<<gMatched<<endl;;
	jet_qmatched.push_back((int)qMatched);
	jet_gmatched.push_back((int)gMatched);
	//fix60
	matched = false;
	for(int l = 0; l < bjet_counter_fix60; l++){
	  dPhi = fabs(jet_phi[k] - bjet_fix60_phi[l]);
	  if(dPhi > 3.141) dPhi = 2*3.141 - dPhi;
	  dEta = fabs(jet_eta[k] - bjet_fix60_eta[l]);
	  dR = sqrt(dEta*dEta + dPhi*dPhi);
	  if(dR < 1.0) matched = true;
	}
	jet_bmatched_fix60.push_back((int)matched);

	//fix70
	matched = false;
	for(int l = 0; l < bjet_counter_fix70; l++){
	  dPhi = fabs(jet_phi[k] - bjet_fix70_phi[l]);
	  if(dPhi > 3.141) dPhi = 2*3.141 - dPhi;
	  dEta = fabs(jet_eta[k] - bjet_fix70_eta[l]);
	  dR = sqrt(dEta*dEta + dPhi*dPhi);
	  if(dR < 1.0) matched = true;
	}
	jet_bmatched_fix70.push_back((int)matched);

	//fix77
	matched = false;
	for(int l = 0; l < bjet_counter_fix77; l++){
	  dPhi = fabs(jet_phi[k] - bjet_fix77_phi[l]);
	  if(dPhi > 3.141) dPhi = 2*3.141 - dPhi;
	  dEta = fabs(jet_eta[k] - bjet_fix77_eta[l]);
	  dR = sqrt(dEta*dEta + dPhi*dPhi);
	  if(dR < 1.0) matched = true;
	}
	jet_bmatched_fix77.push_back((int)matched);

	//fix85
	matched = false;
	for(int l = 0; l < bjet_counter_fix85; l++){
	  dPhi = fabs(jet_phi[k] - bjet_fix85_phi[l]);
	  if(dPhi > 3.141) dPhi = 2*3.141 - dPhi;
	  dEta = fabs(jet_eta[k] - bjet_fix85_eta[l]);
	  dR = sqrt(dEta*dEta + dPhi*dPhi);
	  if(dR < 1.0) matched = true;
	}
	jet_bmatched_fix85.push_back((int)matched);

	//flt60
	matched = false;
	for(int l = 0; l < bjet_counter_flt60; l++){
	  dPhi = fabs(jet_phi[k] - bjet_flt60_phi[l]);
	  if(dPhi > 3.141) dPhi = 2*3.141 - dPhi;
	  dEta = fabs(jet_eta[k] - bjet_flt60_eta[l]);
	  dR = sqrt(dEta*dEta + dPhi*dPhi);
	  if(dR < 1.0) matched = true;
	}
	jet_bmatched_flt60.push_back((int)matched);
	//flt70
	matched = false;
	for(int l = 0; l < bjet_counter_flt70; l++){
	  dPhi = fabs(jet_phi[k] - bjet_flt70_phi[l]);
	  if(dPhi > 3.141) dPhi = 2*3.141 - dPhi;
	  dEta = fabs(jet_eta[k] - bjet_flt70_eta[l]);
	  dR = sqrt(dEta*dEta + dPhi*dPhi);
	  if(dR < 1.0) matched = true;
	}
	jet_bmatched_flt70.push_back((int)matched);
	//flt77
	matched = false;
	for(int l = 0; l < bjet_counter_flt77; l++){
	  dPhi = fabs(jet_phi[k] - bjet_flt77_phi[l]);
	  if(dPhi > 3.141) dPhi = 2*3.141 - dPhi;
	  dEta = fabs(jet_eta[k] - bjet_flt77_eta[l]);
	  dR = sqrt(dEta*dEta + dPhi*dPhi);
	  if(dR < 1.0) matched = true;
	}
	jet_bmatched_flt77.push_back((int)matched);
	//flt85
	matched = false;
	for(int l = 0; l < bjet_counter_flt85; l++){
	  dPhi = fabs(jet_phi[k] - bjet_flt85_phi[l]);
	  if(dPhi > 3.141) dPhi = 2*3.141 - dPhi;
	  dEta = fabs(jet_eta[k] - bjet_flt85_eta[l]);
	  dR = sqrt(dEta*dEta + dPhi*dPhi);
	  if(dR < 1.0) matched = true;
	}
	jet_bmatched_flt85.push_back((int)matched);


      }
      for(int ii =0; ii < mini_njet; ii++) mini_MJall += jet_m[ii]; 
      max_ind = 4;

      if(mini_njet < 4){
	max_ind = mini_njet;
      }

      for(int ii =0; ii < max_ind; ii++){
	mini_MJ4 += jet_m.at(ii); 
      }

      //Calculate dEta
      mini_dEta = fabs(jet_eta[0]-jet_eta[1]);

      bool trigger = false;
      for( unsigned int k = 0 ; k <  (*p->passedTriggers).size()  ;  k ++ ){
	TString pass_trigger = (*p->passedTriggers)[k];
	if(pass_trigger.Contains("HLT_ht1000_L1J100")){
	    trigger=true;
	}
      }
      if(trigger == false) continue;
      h_cutflow->Fill(3.0,wt);

      //cutflows
      if (mini_njet < 2) continue;
      if (mini_njet == 2 and jet_pt[0] < 0.4) continue;
      if(mini_njet==2) h_cutflow->Fill(4.0,wt);
      if(mini_njet==3) h_cutflow->Fill(5.0,wt);
      if(mini_njet==4) h_cutflow->Fill(6.0,wt);
      if(mini_njet>=5) h_cutflow->Fill(7.0,wt);


      mini_runNumber = p->runNumber;
      mini_eventNumber = p->eventNumber;
      mini_lumiBlock = p->lumiBlock;
      mini_mu = p->averageInteractionsPerCrossing;
      if(isMC) mini_mcChannelNumber = p->mcChannelNumber;
      mini_isMC = isMC;
      mini_wt = wt;
		     
      mini_njet_ak4 = ak4_counter;
      mini_nbjet_flt60 = bjet_counter_flt60;
      mini_nbjet_flt70 = bjet_counter_flt70;
      mini_nbjet_flt77 = bjet_counter_flt77;
      mini_nbjet_flt85 = bjet_counter_flt85;
      mini_nbjet_fix60 = bjet_counter_fix60;
      mini_nbjet_fix70 = bjet_counter_fix70;
      mini_nbjet_fix77 = bjet_counter_fix77;
      mini_nbjet_fix85 = bjet_counter_fix85;
      mini_jet_pt = &jet_pt;
      mini_jet_eta = &jet_eta;
      mini_jet_phi = &jet_phi;
      mini_jet_m = &jet_m;
      mini_jet_bmatched_flt60 = &jet_bmatched_flt60;
      mini_jet_bmatched_flt70 = &jet_bmatched_flt70;
      mini_jet_bmatched_flt77 = &jet_bmatched_flt77;
      mini_jet_bmatched_flt85 = &jet_bmatched_flt85;

      mini_jet_qmatched = &jet_qmatched;
      mini_jet_gmatched = &jet_gmatched;

      mini_jet_bmatched_fix60 = &jet_bmatched_fix60;
      mini_jet_bmatched_fix70 = &jet_bmatched_fix70;
      mini_jet_bmatched_fix77 = &jet_bmatched_fix77;
      mini_jet_bmatched_fix85 = &jet_bmatched_fix85;
      mini_jet_NTrimSubjets = &jet_NTrimSubjets;
      mini->GetEntry(pass_evt_counter);
      mini->Fill();

      pass_evt_counter++;

    }

  mini->Write();
  h_cutflow->Write();
  f.Close();

  return 0 ; 
}







