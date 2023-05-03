# PFCalibration  
For Single Pion sample Generation:

(For bash)
```
cmsrel CMSSW_12_6_4
cd CMSSW_12_6_4/src
git clone -b Run3with_126XGT https://github.com/kdlong/PFCalibration.git
scram b -j 8
cd PFCalibration/PFChargedHadronAnalyzer/test/
cmsenv
```

Using centerally generated Single pion reco sample for Run 3:
```  
cmsRun myEDAna.py 

(for Crab job submission)
source /cvmfs/cms.cern.ch/crab3/crab.sh
crab submit crab_step_analyser.py
```
For PFcalibration use `PFChargedHadronAnalyzer/test/calibration_code/Main_calib.cc`
See [dedicated README](PFChargedHadronAnalyzer/test/calibration_code/README.md) for instructions.
