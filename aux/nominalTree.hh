//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Oct  5 13:53:48 2016 by ROOT version 6.04/14
// from TTree nominal/nominal
// found on file: /projecta/projectdirs/atlas/atlaslocalgroupdisk/rucio/user/nshalimo/fa/d8/user.nshalimo.9005884._000021.tree.root
//////////////////////////////////////////////////////////

#ifndef nominalTree_h
#define nominalTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
using namespace std;
class nominalTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   bool m_isMC = false;
   // Declaration of leaf types
   Int_t           runNumber;
   Long64_t        eventNumber;
   Int_t           lumiBlock;
   Int_t           bcid;
   UInt_t          coreFlags;
   Int_t           mcEventNumber;
   Int_t           mcChannelNumber;
   Float_t         mcEventWeight;
   Float_t         weight_xs;
   Float_t         weight;
   UInt_t          timeStamp;
   UInt_t          timeStampNSOffset;
   Bool_t          TileError;
   Bool_t          SCTError;
   Bool_t          LArError;
   UInt_t          TileFlags;
   UInt_t          SCTFlags;
   UInt_t          LArFlags;
   Float_t         weight_pileup;
   Int_t           NPV;
   Float_t         actualInteractionsPerCrossing;
   Float_t         averageInteractionsPerCrossing;
   Int_t           passL1;
   Int_t           passHLT;
   vector<string>  *passedTriggers;
   vector<float>   *triggerPrescales;
   Int_t           njets;
   vector<float>   *jet_E;
   vector<float>   *jet_pt;
   vector<float>   *jet_phi;
   vector<float>   *jet_eta;
   vector<float>   *jet_Timing;
   vector<float>   *jet_LArQuality;
   vector<float>   *jet_HECQuality;
   vector<float>   *jet_NegativeE;
   vector<float>   *jet_AverageLArQF;
   vector<float>   *jet_BchCorrCell;
   vector<float>   *jet_N90Constituents;
   vector<float>   *jet_LArBadHVEFracnergyFrac;
   vector<int>     *jet_LArBadHVNCell;
   vector<float>   *jet_OotFracClusters5;
   vector<float>   *jet_OotFracClusters10;
   vector<float>   *jet_LeadingClusterPt;
   vector<float>   *jet_LeadingClusterSecondLambda;
   vector<float>   *jet_LeadingClusterCenterLambda;
   vector<float>   *jet_LeadingClusterSecondR;
   vector<int>     *jet_clean_passLooseBad;
   vector<int>     *jet_clean_passLooseBadUgly;
   vector<int>     *jet_clean_passTightBad;
   vector<int>     *jet_clean_passTightBadUgly;
   vector<float>   *jet_HECFrac;
   vector<float>   *jet_EMFrac;
   vector<float>   *jet_CentroidR;
   vector<float>   *jet_FracSamplingMax;
   vector<float>   *jet_FracSamplingMaxIndex;
   vector<float>   *jet_LowEtConstituentsFrac;
   vector<float>   *jet_GhostMuonSegmentCount;
   vector<float>   *jet_Width;
   vector<float>   *jet_emScalePt;
   vector<float>   *jet_constScalePt;
   vector<float>   *jet_pileupScalePt;
   vector<float>   *jet_originConstitScalePt;
   vector<float>   *jet_etaJESScalePt;
   vector<float>   *jet_gscScalePt;
   vector<float>   *jet_insituScalePt;
   vector<float>   *jet_SV0;
   vector<float>   *jet_SV1;
   vector<float>   *jet_IP3D;
   vector<float>   *jet_SV1IP3D;
   vector<float>   *jet_MV1;
   vector<float>   *jet_MV2c00;
   vector<float>   *jet_MV2c10;
   vector<float>   *jet_MV2c20;
   vector<int>     *jet_HadronConeExclTruthLabelID;
   Int_t           njets_Fix60;
   vector<int>     *jet_isFix60;
   vector<vector<float> > *jet_SFFix60;
   vector<float>   *weight_jet_SFFix60;
   Int_t           njets_Fix70;
   vector<int>     *jet_isFix70;
   vector<vector<float> > *jet_SFFix70;
   vector<float>   *weight_jet_SFFix70;
   Int_t           njets_Fix77;
   vector<int>     *jet_isFix77;
   vector<vector<float> > *jet_SFFix77;
   vector<float>   *weight_jet_SFFix77;
   Int_t           njets_Fix85;
   vector<int>     *jet_isFix85;
   vector<vector<float> > *jet_SFFix85;
   vector<float>   *weight_jet_SFFix85;
   Int_t           njets_Flt60;
   vector<int>     *jet_isFlt60;
   vector<vector<float> > *jet_SFFlt60;
   vector<float>   *weight_jet_SFFlt60;
   Int_t           njets_Flt70;
   vector<int>     *jet_isFlt70;
   vector<vector<float> > *jet_SFFlt70;
   vector<float>   *weight_jet_SFFlt70;
   Int_t           njets_Flt77;
   vector<int>     *jet_isFlt77;
   vector<vector<float> > *jet_SFFlt77;
   vector<float>   *weight_jet_SFFlt77;
   Int_t           njets_Flt85;
   vector<int>     *jet_isFlt85;
   vector<vector<float> > *jet_SFFlt85;
   vector<float>   *weight_jet_SFFlt85;
   vector<int>     *jet_ConeTruthLabelID;
   vector<int>     *jet_TruthCount;
   vector<float>   *jet_TruthLabelDeltaR_B;
   vector<float>   *jet_TruthLabelDeltaR_C;
   vector<float>   *jet_TruthLabelDeltaR_T;
   vector<int>     *jet_PartonTruthLabelID;
   vector<float>   *jet_GhostTruthAssociationFraction;
   vector<float>   *jet_truth_E;
   vector<float>   *jet_truth_pt;
   vector<float>   *jet_truth_phi;
   vector<float>   *jet_truth_eta;
   Int_t           nfatjets;
   vector<float>   *fatjet_E;
   vector<float>   *fatjet_m;
   vector<float>   *fatjet_pt;
   vector<float>   *fatjet_phi;
   vector<float>   *fatjet_eta;
   vector<float>   *fatjet_Split12;
   vector<float>   *fatjet_Split23;
   vector<float>   *fatjet_Split34;
   vector<float>   *fatjet_tau1_wta;
   vector<float>   *fatjet_tau2_wta;
   vector<float>   *fatjet_tau3_wta;
   vector<float>   *fatjet_tau21_wta;
   vector<float>   *fatjet_tau32_wta;
   vector<float>   *fatjet_ECF1;
   vector<float>   *fatjet_ECF2;
   vector<float>   *fatjet_ECF3;
   vector<float>   *fatjet_C2;
   vector<float>   *fatjet_D2;
   vector<float>   *fatjet_NTrimSubjets;

   // List of branches
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_lumiBlock;   //!
   TBranch        *b_bcid; //!
   TBranch        *b_coreFlags;   //!
   TBranch        *b_mcEventNumber;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_mcEventWeight;   //!
   TBranch        *b_weight_xs;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_timeStamp;   //!
   TBranch        *b_timeStampNSOffset;   //!
   TBranch        *b_TileError;   //!
   TBranch        *b_SCTError;   //!
   TBranch        *b_LArError;   //!
   TBranch        *b_TileFlags;   //!
   TBranch        *b_SCTFlags;   //!
   TBranch        *b_LArFlags;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_NPV;   //!
   TBranch        *b_actualInteractionsPerCrossing;   //!
   TBranch        *b_averageInteractionsPerCrossing;   //!
   TBranch        *b_passL1;   //!
   TBranch        *b_passHLT;   //!
   TBranch        *b_passedTriggers;   //!
   TBranch        *b_triggerPrescales;   //!
   TBranch        *b_njets;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_Timing;   //!
   TBranch        *b_jet_LArQuality;   //!
   TBranch        *b_jet_HECQuality;   //!
   TBranch        *b_jet_NegativeE;   //!
   TBranch        *b_jet_AverageLArQF;   //!
   TBranch        *b_jet_BchCorrCell;   //!
   TBranch        *b_jet_N90Constituents;   //!
   TBranch        *b_jet_LArBadHVEFracnergyFrac;   //!
   TBranch        *b_jet_LArBadHVNCell;   //!
   TBranch        *b_jet_OotFracClusters5;   //!
   TBranch        *b_jet_OotFracClusters10;   //!
   TBranch        *b_jet_LeadingClusterPt;   //!
   TBranch        *b_jet_LeadingClusterSecondLambda;   //!
   TBranch        *b_jet_LeadingClusterCenterLambda;   //!
   TBranch        *b_jet_LeadingClusterSecondR;   //!
   TBranch        *b_jet_clean_passLooseBad;   //!
   TBranch        *b_jet_clean_passLooseBadUgly;   //!
   TBranch        *b_jet_clean_passTightBad;   //!
   TBranch        *b_jet_clean_passTightBadUgly;   //!
   TBranch        *b_jet_HECFrac;   //!
   TBranch        *b_jet_EMFrac;   //!
   TBranch        *b_jet_CentroidR;   //!
   TBranch        *b_jet_FracSamplingMax;   //!
   TBranch        *b_jet_FracSamplingMaxIndex;   //!
   TBranch        *b_jet_LowEtConstituentsFrac;   //!
   TBranch        *b_jet_GhostMuonSegmentCount;   //!
   TBranch        *b_jet_Width;   //!
   TBranch        *b_jet_emScalePt;   //!
   TBranch        *b_jet_constScalePt;   //!
   TBranch        *b_jet_pileupScalePt;   //!
   TBranch        *b_jet_originConstitScalePt;   //!
   TBranch        *b_jet_etaJESScalePt;   //!
   TBranch        *b_jet_gscScalePt;   //!
   TBranch        *b_jet_insituScalePt;   //!
   TBranch        *b_jet_SV0;   //!
   TBranch        *b_jet_SV1;   //!
   TBranch        *b_jet_IP3D;   //!
   TBranch        *b_jet_SV1IP3D;   //!
   TBranch        *b_jet_MV1;   //!
   TBranch        *b_jet_MV2c00;   //!
   TBranch        *b_jet_MV2c10;   //!
   TBranch        *b_jet_MV2c20;   //!
   TBranch        *b_jet_HadronConeExclTruthLabelID;   //!
   TBranch        *b_njets_Fix60;   //!
   TBranch        *b_jet_isFix60;   //!
   TBranch        *b_jet_SFFix60;   //!
   TBranch        *b_weight_jet_SFFix60;   //!
   TBranch        *b_njets_Fix70;   //!
   TBranch        *b_jet_isFix70;   //!
   TBranch        *b_jet_SFFix70;   //!
   TBranch        *b_weight_jet_SFFix70;   //!
   TBranch        *b_njets_Fix77;   //!
   TBranch        *b_jet_isFix77;   //!
   TBranch        *b_jet_SFFix77;   //!
   TBranch        *b_weight_jet_SFFix77;   //!
   TBranch        *b_njets_Fix85;   //!
   TBranch        *b_jet_isFix85;   //!
   TBranch        *b_jet_SFFix85;   //!
   TBranch        *b_weight_jet_SFFix85;   //!
   TBranch        *b_njets_Flt60;   //!
   TBranch        *b_jet_isFlt60;   //!
   TBranch        *b_jet_SFFlt60;   //!
   TBranch        *b_weight_jet_SFFlt60;   //!
   TBranch        *b_njets_Flt70;   //!
   TBranch        *b_jet_isFlt70;   //!
   TBranch        *b_jet_SFFlt70;   //!
   TBranch        *b_weight_jet_SFFlt70;   //!
   TBranch        *b_njets_Flt77;   //!
   TBranch        *b_jet_isFlt77;   //!
   TBranch        *b_jet_SFFlt77;   //!
   TBranch        *b_weight_jet_SFFlt77;   //!
   TBranch        *b_njets_Flt85;   //!
   TBranch        *b_jet_isFlt85;   //!
   TBranch        *b_jet_SFFlt85;   //!
   TBranch        *b_weight_jet_SFFlt85;   //!
   TBranch        *b_jet_ConeTruthLabelID;   //!
   TBranch        *b_jet_TruthCount;   //!
   TBranch        *b_jet_TruthLabelDeltaR_B;   //!
   TBranch        *b_jet_TruthLabelDeltaR_C;   //!
   TBranch        *b_jet_TruthLabelDeltaR_T;   //!
   TBranch        *b_jet_PartonTruthLabelID;   //!
   TBranch        *b_jet_GhostTruthAssociationFraction;   //!
   TBranch        *b_jet_truth_E;   //!
   TBranch        *b_jet_truth_pt;   //!
   TBranch        *b_jet_truth_phi;   //!
   TBranch        *b_jet_truth_eta;   //!
   TBranch        *b_nfatjets;   //!
   TBranch        *b_fatjet_E;   //!
   TBranch        *b_fatjet_m;   //!
   TBranch        *b_fatjet_pt;   //!
   TBranch        *b_fatjet_phi;   //!
   TBranch        *b_fatjet_eta;   //!
   TBranch        *b_fatjet_Split12;   //!
   TBranch        *b_fatjet_Split23;   //!
   TBranch        *b_fatjet_Split34;   //!
   TBranch        *b_fatjet_tau1_wta;   //!
   TBranch        *b_fatjet_tau2_wta;   //!
   TBranch        *b_fatjet_tau3_wta;   //!
   TBranch        *b_fatjet_tau21_wta;   //!
   TBranch        *b_fatjet_tau32_wta;   //!
   TBranch        *b_fatjet_ECF1;   //!
   TBranch        *b_fatjet_ECF2;   //!
   TBranch        *b_fatjet_ECF3;   //!
   TBranch        *b_fatjet_C2;   //!
   TBranch        *b_fatjet_D2;   //!
   TBranch        *b_fatjet_NTrimSubjets;   //!

   nominalTree(TTree *tree=0);
   virtual ~nominalTree();
  bool isMC(){ return m_isMC; }
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef nominalTree_cxx
nominalTree::nominalTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/projecta/projectdirs/atlas/atlaslocalgroupdisk/rucio/user/nshalimo/fa/d8/user.nshalimo.9005884._000021.tree.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/projecta/projectdirs/atlas/atlaslocalgroupdisk/rucio/user/nshalimo/fa/d8/user.nshalimo.9005884._000021.tree.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/projecta/projectdirs/atlas/atlaslocalgroupdisk/rucio/user/nshalimo/fa/d8/user.nshalimo.9005884._000021.tree.root:/outTree");
      dir->GetObject("nominal",tree);

   }
   Init(tree);
}

nominalTree::~nominalTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t nominalTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t nominalTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void nominalTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   passedTriggers = 0;
   triggerPrescales = 0;
   jet_E = 0;
   jet_pt = 0;
   jet_phi = 0;
   jet_eta = 0;
   jet_Timing = 0;
   jet_LArQuality = 0;
   jet_HECQuality = 0;
   jet_NegativeE = 0;
   jet_AverageLArQF = 0;
   jet_BchCorrCell = 0;
   jet_N90Constituents = 0;
   jet_LArBadHVNCell = 0;
   jet_OotFracClusters5 = 0;
   jet_OotFracClusters10 = 0;
   jet_LeadingClusterPt = 0;
   jet_LeadingClusterSecondLambda = 0;
   jet_LeadingClusterCenterLambda = 0;
   jet_LeadingClusterSecondR = 0;
   jet_clean_passLooseBad = 0;
   jet_clean_passLooseBadUgly = 0;
   jet_clean_passTightBad = 0;
   jet_clean_passTightBadUgly = 0;

   jet_emScalePt = 0;
   jet_constScalePt = 0;
   jet_pileupScalePt = 0;
   jet_originConstitScalePt = 0;
   jet_etaJESScalePt = 0;
   jet_gscScalePt = 0;
   jet_insituScalePt = 0;

   jet_MV2c00 = 0;
   jet_MV2c10 = 0;
   jet_MV2c20 = 0;
   jet_HadronConeExclTruthLabelID = 0;
   jet_isFix60 = 0;
   jet_SFFix60 = 0;
   weight_jet_SFFix60 = 0;
   jet_isFix70 = 0;
   jet_SFFix70 = 0;
   weight_jet_SFFix70 = 0;
   jet_isFix77 = 0;
   jet_SFFix77 = 0;
   weight_jet_SFFix77 = 0;
   jet_isFix85 = 0;
   jet_SFFix85 = 0;
   weight_jet_SFFix85 = 0;
   jet_isFlt60 = 0;
   jet_SFFlt60 = 0;
   weight_jet_SFFlt60 = 0;
   jet_isFlt70 = 0;
   jet_SFFlt70 = 0;
   weight_jet_SFFlt70 = 0;
   jet_isFlt77 = 0;
   jet_SFFlt77 = 0;
   weight_jet_SFFlt77 = 0;
   jet_isFlt85 = 0;
   jet_SFFlt85 = 0;
   weight_jet_SFFlt85 = 0;
   jet_ConeTruthLabelID = 0;
   jet_TruthCount = 0;
   jet_TruthLabelDeltaR_B = 0;
   jet_TruthLabelDeltaR_C = 0;
   jet_TruthLabelDeltaR_T = 0;
   jet_PartonTruthLabelID = 0;
   jet_GhostTruthAssociationFraction = 0;
   jet_truth_E = 0;
   jet_truth_pt = 0;
   jet_truth_phi = 0;
   jet_truth_eta = 0;
   fatjet_E = 0;
   fatjet_m = 0;
   fatjet_pt = 0;
   fatjet_phi = 0;
   fatjet_eta = 0;
   fatjet_Split12 = 0;
   fatjet_Split23 = 0;
   fatjet_Split34 = 0;
   fatjet_tau1_wta = 0;
   fatjet_tau2_wta = 0;
   fatjet_tau3_wta = 0;
   fatjet_tau21_wta = 0;
   fatjet_tau32_wta = 0;
   fatjet_ECF1 = 0;
   fatjet_ECF2 = 0;
   fatjet_ECF3 = 0;
   fatjet_C2 = 0;
   fatjet_D2 = 0;
   fatjet_NTrimSubjets = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("lumiBlock", &lumiBlock, &b_lumiBlock);
   fChain->SetBranchAddress("coreFlags", &coreFlags, &b_coreFlags);
   if(fChain->GetListOfBranches()->Contains("mcChannelNumber")){
     m_isMC = true;
     fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
     fChain->SetBranchAddress("mcEventWeight", &mcEventWeight, &b_mcEventWeight);
     //     fChain->SetBranchAddress("weight_xs", &weight_xs, &b_weight_xs);
     //     fChain->SetBranchAddress("weight", &weight, &b_weight);
     fChain->SetBranchAddress("jet_SFFix60", &jet_SFFix60, &b_jet_SFFix60);
     if(fChain->GetListOfBranches()->Contains("weight_jetSFFix60")){
       fChain->SetBranchAddress("weight_jetSFFix60", &weight_jet_SFFix60, &b_weight_jet_SFFix60);
       fChain->SetBranchAddress("weight_jetSFFix70", &weight_jet_SFFix70, &b_weight_jet_SFFix70);
       fChain->SetBranchAddress("weight_jetSFFix77", &weight_jet_SFFix77, &b_weight_jet_SFFix77);
       fChain->SetBranchAddress("weight_jetSFFix85", &weight_jet_SFFix85, &b_weight_jet_SFFix85);
       fChain->SetBranchAddress("weight_jetSFFlt60", &weight_jet_SFFlt60, &b_weight_jet_SFFlt60);
       fChain->SetBranchAddress("weight_jetSFFlt70", &weight_jet_SFFlt70, &b_weight_jet_SFFlt70);
       fChain->SetBranchAddress("weight_jetSFFlt77", &weight_jet_SFFlt77, &b_weight_jet_SFFlt77);
       fChain->SetBranchAddress("weight_jetSFFlt85", &weight_jet_SFFlt85, &b_weight_jet_SFFlt85);
     }
     else{
       fChain->SetBranchAddress("weight_jet_SFFix60", &weight_jet_SFFix60, &b_weight_jet_SFFix60);
       fChain->SetBranchAddress("weight_jet_SFFix70", &weight_jet_SFFix70, &b_weight_jet_SFFix70);
       fChain->SetBranchAddress("weight_jet_SFFix77", &weight_jet_SFFix77, &b_weight_jet_SFFix77);
       fChain->SetBranchAddress("weight_jet_SFFix85", &weight_jet_SFFix85, &b_weight_jet_SFFix85);
       fChain->SetBranchAddress("weight_jet_SFFlt60", &weight_jet_SFFlt60, &b_weight_jet_SFFlt60);
       fChain->SetBranchAddress("weight_jet_SFFlt70", &weight_jet_SFFlt70, &b_weight_jet_SFFlt70);
       fChain->SetBranchAddress("weight_jet_SFFlt77", &weight_jet_SFFlt77, &b_weight_jet_SFFlt77);
       fChain->SetBranchAddress("weight_jet_SFFlt85", &weight_jet_SFFlt85, &b_weight_jet_SFFlt85);
     }
     fChain->SetBranchAddress("jet_SFFix70", &jet_SFFix70, &b_jet_SFFix70);
     fChain->SetBranchAddress("jet_SFFix77", &jet_SFFix77, &b_jet_SFFix77);
     fChain->SetBranchAddress("jet_SFFix85", &jet_SFFix85, &b_jet_SFFix85);
     fChain->SetBranchAddress("jet_SFFlt60", &jet_SFFlt60, &b_jet_SFFlt60);
     fChain->SetBranchAddress("jet_SFFlt70", &jet_SFFlt70, &b_jet_SFFlt70);
     fChain->SetBranchAddress("jet_SFFlt77", &jet_SFFlt77, &b_jet_SFFlt77);
     fChain->SetBranchAddress("jet_SFFlt85", &jet_SFFlt85, &b_jet_SFFlt85);
     fChain->SetBranchAddress("jet_PartonTruthLabelID", &jet_PartonTruthLabelID, &b_jet_PartonTruthLabelID);
     fChain->SetBranchAddress("jet_ConeTruthLabelID", &jet_ConeTruthLabelID, &b_jet_ConeTruthLabelID);
     fChain->SetBranchAddress("jet_TruthCount", &jet_TruthCount, &b_jet_TruthCount);
     fChain->SetBranchAddress("jet_TruthLabelDeltaR_B", &jet_TruthLabelDeltaR_B, &b_jet_TruthLabelDeltaR_B);
     fChain->SetBranchAddress("jet_TruthLabelDeltaR_C", &jet_TruthLabelDeltaR_C, &b_jet_TruthLabelDeltaR_C);
     fChain->SetBranchAddress("jet_TruthLabelDeltaR_T", &jet_TruthLabelDeltaR_T, &b_jet_TruthLabelDeltaR_T);
     fChain->SetBranchAddress("jet_GhostTruthAssociationFraction", &jet_GhostTruthAssociationFraction, &b_jet_GhostTruthAssociationFraction);
     fChain->SetBranchAddress("jet_truth_E", &jet_truth_E, &b_jet_truth_E);
     fChain->SetBranchAddress("jet_truth_pt", &jet_truth_pt, &b_jet_truth_pt);
     fChain->SetBranchAddress("jet_truth_phi", &jet_truth_phi, &b_jet_truth_phi);
     fChain->SetBranchAddress("jet_truth_eta", &jet_truth_eta, &b_jet_truth_eta);
   }
   else{
     fChain->SetBranchAddress("bcid", &bcid, &b_bcid);
   }
   fChain->SetBranchAddress("timeStamp", &timeStamp, &b_timeStamp);
   fChain->SetBranchAddress("timeStampNSOffset", &timeStampNSOffset, &b_timeStampNSOffset);
   fChain->SetBranchAddress("TileError", &TileError, &b_TileError);
   fChain->SetBranchAddress("SCTError", &SCTError, &b_SCTError);
   fChain->SetBranchAddress("LArError", &LArError, &b_LArError);
   fChain->SetBranchAddress("TileFlags", &TileFlags, &b_TileFlags);
   fChain->SetBranchAddress("SCTFlags", &SCTFlags, &b_SCTFlags);
   fChain->SetBranchAddress("LArFlags", &LArFlags, &b_LArFlags);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("NPV", &NPV, &b_NPV);
   fChain->SetBranchAddress("actualInteractionsPerCrossing", &actualInteractionsPerCrossing, &b_actualInteractionsPerCrossing);
   fChain->SetBranchAddress("averageInteractionsPerCrossing", &averageInteractionsPerCrossing, &b_averageInteractionsPerCrossing);
   fChain->SetBranchAddress("passL1", &passL1, &b_passL1);
   fChain->SetBranchAddress("passHLT", &passHLT, &b_passHLT);
   fChain->SetBranchAddress("passedTriggers", &passedTriggers, &b_passedTriggers);
   fChain->SetBranchAddress("triggerPrescales", &triggerPrescales, &b_triggerPrescales);

   fChain->SetBranchAddress("njet", &njets, &b_njets);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_Timing", &jet_Timing, &b_jet_Timing);
   fChain->SetBranchAddress("jet_LArQuality", &jet_LArQuality, &b_jet_LArQuality);
   fChain->SetBranchAddress("jet_HECQuality", &jet_HECQuality, &b_jet_HECQuality);
   fChain->SetBranchAddress("jet_NegativeE", &jet_NegativeE, &b_jet_NegativeE);
   fChain->SetBranchAddress("jet_AverageLArQF", &jet_AverageLArQF, &b_jet_AverageLArQF);
   fChain->SetBranchAddress("jet_BchCorrCell", &jet_BchCorrCell, &b_jet_BchCorrCell);
   fChain->SetBranchAddress("jet_N90Constituents", &jet_N90Constituents, &b_jet_N90Constituents);

   fChain->SetBranchAddress("jet_LArBadHVNCell", &jet_LArBadHVNCell, &b_jet_LArBadHVNCell);
   fChain->SetBranchAddress("jet_OotFracClusters5", &jet_OotFracClusters5, &b_jet_OotFracClusters5);
   fChain->SetBranchAddress("jet_OotFracClusters10", &jet_OotFracClusters10, &b_jet_OotFracClusters10);
   fChain->SetBranchAddress("jet_LeadingClusterPt", &jet_LeadingClusterPt, &b_jet_LeadingClusterPt);
   fChain->SetBranchAddress("jet_LeadingClusterSecondLambda", &jet_LeadingClusterSecondLambda, &b_jet_LeadingClusterSecondLambda);
   fChain->SetBranchAddress("jet_LeadingClusterCenterLambda", &jet_LeadingClusterCenterLambda, &b_jet_LeadingClusterCenterLambda);
   fChain->SetBranchAddress("jet_LeadingClusterSecondR", &jet_LeadingClusterSecondR, &b_jet_LeadingClusterSecondR);
   fChain->SetBranchAddress("jet_clean_passLooseBad", &jet_clean_passLooseBad, &b_jet_clean_passLooseBad);
   fChain->SetBranchAddress("jet_clean_passLooseBadUgly", &jet_clean_passLooseBadUgly, &b_jet_clean_passLooseBadUgly);
   fChain->SetBranchAddress("jet_clean_passTightBad", &jet_clean_passTightBad, &b_jet_clean_passTightBad);
   fChain->SetBranchAddress("jet_clean_passTightBadUgly", &jet_clean_passTightBadUgly, &b_jet_clean_passTightBadUgly);
   fChain->SetBranchAddress("jet_emScalePt", &jet_emScalePt, &b_jet_emScalePt);
   fChain->SetBranchAddress("jet_constScalePt", &jet_constScalePt, &b_jet_constScalePt);
   fChain->SetBranchAddress("jet_pileupScalePt", &jet_pileupScalePt, &b_jet_pileupScalePt);
   fChain->SetBranchAddress("jet_originConstitScalePt", &jet_originConstitScalePt, &b_jet_originConstitScalePt);
   fChain->SetBranchAddress("jet_etaJESScalePt", &jet_etaJESScalePt, &b_jet_etaJESScalePt);
   fChain->SetBranchAddress("jet_gscScalePt", &jet_gscScalePt, &b_jet_gscScalePt);
   fChain->SetBranchAddress("jet_insituScalePt", &jet_insituScalePt, &b_jet_insituScalePt);
   fChain->SetBranchAddress("jet_MV2c00", &jet_MV2c00, &b_jet_MV2c00);
   fChain->SetBranchAddress("jet_MV2c10", &jet_MV2c10, &b_jet_MV2c10);
   fChain->SetBranchAddress("jet_MV2c20", &jet_MV2c20, &b_jet_MV2c20);
   fChain->SetBranchAddress("jet_HadronConeExclTruthLabelID", &jet_HadronConeExclTruthLabelID, &b_jet_HadronConeExclTruthLabelID);
   fChain->SetBranchAddress("njets_Fix60", &njets_Fix60, &b_njets_Fix60);
   fChain->SetBranchAddress("jet_isFix60", &jet_isFix60, &b_jet_isFix60);
   fChain->SetBranchAddress("njets_Fix70", &njets_Fix70, &b_njets_Fix70);
   fChain->SetBranchAddress("jet_isFix70", &jet_isFix70, &b_jet_isFix70);
   fChain->SetBranchAddress("njets_Fix77", &njets_Fix77, &b_njets_Fix77);
   fChain->SetBranchAddress("jet_isFix77", &jet_isFix77, &b_jet_isFix77);
   fChain->SetBranchAddress("njets_Fix85", &njets_Fix85, &b_njets_Fix85);
   fChain->SetBranchAddress("jet_isFix85", &jet_isFix85, &b_jet_isFix85);
   fChain->SetBranchAddress("njets_Flt60", &njets_Flt60, &b_njets_Flt60);
   fChain->SetBranchAddress("jet_isFlt60", &jet_isFlt60, &b_jet_isFlt60);
   fChain->SetBranchAddress("njets_Flt70", &njets_Flt70, &b_njets_Flt70);
   fChain->SetBranchAddress("jet_isFlt70", &jet_isFlt70, &b_jet_isFlt70);

   fChain->SetBranchAddress("njets_Flt77", &njets_Flt77, &b_njets_Flt77);
   fChain->SetBranchAddress("jet_isFlt77", &jet_isFlt77, &b_jet_isFlt77);

   fChain->SetBranchAddress("njets_Flt85", &njets_Flt85, &b_njets_Flt85);
   fChain->SetBranchAddress("jet_isFlt85", &jet_isFlt85, &b_jet_isFlt85);

   if(fChain->GetListOfBranches()->Contains("nfatjets")){
     fChain->SetBranchAddress("nfatjets", &nfatjets, &b_nfatjets);
     fChain->SetBranchAddress("fatjet_E", &fatjet_E, &b_fatjet_E);
     fChain->SetBranchAddress("fatjet_m", &fatjet_m, &b_fatjet_m);
     fChain->SetBranchAddress("fatjet_pt", &fatjet_pt, &b_fatjet_pt);
     fChain->SetBranchAddress("fatjet_phi", &fatjet_phi, &b_fatjet_phi);
     fChain->SetBranchAddress("fatjet_eta", &fatjet_eta, &b_fatjet_eta);
     fChain->SetBranchAddress("fatjet_Split12", &fatjet_Split12, &b_fatjet_Split12);
     fChain->SetBranchAddress("fatjet_Split23", &fatjet_Split23, &b_fatjet_Split23);
     fChain->SetBranchAddress("fatjet_Split34", &fatjet_Split34, &b_fatjet_Split34);
     fChain->SetBranchAddress("fatjet_tau1_wta", &fatjet_tau1_wta, &b_fatjet_tau1_wta);
     fChain->SetBranchAddress("fatjet_tau2_wta", &fatjet_tau2_wta, &b_fatjet_tau2_wta);
     fChain->SetBranchAddress("fatjet_tau3_wta", &fatjet_tau3_wta, &b_fatjet_tau3_wta);
     fChain->SetBranchAddress("fatjet_tau21_wta", &fatjet_tau21_wta, &b_fatjet_tau21_wta);
     fChain->SetBranchAddress("fatjet_tau32_wta", &fatjet_tau32_wta, &b_fatjet_tau32_wta);
     fChain->SetBranchAddress("fatjet_ECF1", &fatjet_ECF1, &b_fatjet_ECF1);
     fChain->SetBranchAddress("fatjet_ECF2", &fatjet_ECF2, &b_fatjet_ECF2);
     fChain->SetBranchAddress("fatjet_ECF3", &fatjet_ECF3, &b_fatjet_ECF3);
     fChain->SetBranchAddress("fatjet_C2", &fatjet_C2, &b_fatjet_C2);
     fChain->SetBranchAddress("fatjet_D2", &fatjet_D2, &b_fatjet_D2);
     fChain->SetBranchAddress("fatjet_NTrimSubjets", &fatjet_NTrimSubjets, &b_fatjet_NTrimSubjets);
   }
   else{
     fChain->SetBranchAddress("nAntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib", &nfatjets, &b_nfatjets);
     //     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_E", &fatjet_E, &b_fatjet_E);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_m", &fatjet_m, &b_fatjet_m);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_pt", &fatjet_pt, &b_fatjet_pt);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_phi", &fatjet_phi, &b_fatjet_phi);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_eta", &fatjet_eta, &b_fatjet_eta);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_Split12", &fatjet_Split12, &b_fatjet_Split12);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_Split23", &fatjet_Split23, &b_fatjet_Split23);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_Split34", &fatjet_Split34, &b_fatjet_Split34);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_tau1_wta", &fatjet_tau1_wta, &b_fatjet_tau1_wta);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_tau2_wta", &fatjet_tau2_wta, &b_fatjet_tau2_wta);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_tau3_wta", &fatjet_tau3_wta, &b_fatjet_tau3_wta);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_tau21_wta", &fatjet_tau21_wta, &b_fatjet_tau21_wta);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_tau32_wta", &fatjet_tau32_wta, &b_fatjet_tau32_wta);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_ECF1", &fatjet_ECF1, &b_fatjet_ECF1);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_ECF2", &fatjet_ECF2, &b_fatjet_ECF2);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_ECF3", &fatjet_ECF3, &b_fatjet_ECF3);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_C2", &fatjet_C2, &b_fatjet_C2);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_D2", &fatjet_D2, &b_fatjet_D2);
     fChain->SetBranchAddress("AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsCalib_NTrimSubjets", &fatjet_NTrimSubjets, &b_fatjet_NTrimSubjets);
   }
   Notify();
}

Bool_t nominalTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void nominalTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t nominalTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef nominalTree_cxx
