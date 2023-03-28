

<<EOF
for i in png pdf gif
do
    rm trial3/plots/._*
    rm -rf trial3/plots/${i}/*
    mkdir trial3/plots/${i}
    cp -r res index.php trial3/plots/${i}/.
    for j in Run3wrttrial3 Rawwrttrial3
    do
	mkdir trial3/plots/${i}/${j}/
	cp -r res index.php  trial3/plots/${i}/${j}/.
	for k in EH_barrel EH_ec_in EH_ec_out H_barrel H_ec_in H_ec_out
	do
	    mkdir trial3/plots/${i}/${j}/${k}
	    cp -r res index.php trial3/plots/${i}/${j}/${k}/.
	done
    done
done
EOF


mkdir trial3/plotsv2
cp -r res index.php trial3/plotsv2/.
for j in Oldwrttrial3 Rawwrttrial3
do
    mkdir trial3/plotsv2/${j}
    cp -r res index.php trial3/plotsv2/${j}/.
    mkdir trial3/plotsv2/${j}/1D_response
    cp -r res index.php	trial3/plotsv2/${j}/1D_response/.
    for k in EH_barrel EH_ec_in EH_ec_out H_barrel H_ec_in H_ec_out
    do
	mkdir trial3/plotsv2/${j}/1D_response/${k}
	cp -r res index.php  trial3/plotsv2/${j}/1D_response/${k}/.
    done
done

root -l -q 'codes/genrateplot_1dresponsevsE_rawwrtcorrE.C("EH hadrons (0 < |#eta| <1.55)","barrel_corrEtaBarrelEcalHcal","barrel_corrEtaBarrelEcalHcal","EH_barrel")'
root -l -q 'codes/genrateplot_1dresponsevsE_rawwrtcorrE.C("H hadrons (0 < |#eta| <1.55)","barrel_corrEtaBarrelHcal","barrel_corrEtaBarrelHcal","H_barrel")'
root -l -q 'codes/genrateplot_1dresponsevsE_rawwrtcorrE.C("EH hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_corrEtaEndcapEcalHcal","EC_within_tracker_corrEtaEndcapEcalHcal","EH_ec_in")'
root -l -q 'codes/genrateplot_1dresponsevsE_rawwrtcorrE.C("H hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_corrEtaEndcapHcal","EC_within_tracker_corrEtaEndcapHcal","H_ec_in")'
root -l -q 'codes/genrateplot_1dresponsevsE_rawwrtcorrE.C("EH hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_corrEtaEndcapEcalHcal","EC_outside_tracker_corrEtaEndcapEcalHcal","EH_ec_out")'
root -l -q 'codes/genrateplot_1dresponsevsE_rawwrtcorrE.C("H hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_corrEtaEndcapHcal","EC_outside_tracker_corrEtaEndcapHcal","H_ec_out")'

root -l -q 'codes/genrateplot_responsevsE_rawwrtcorrE.C("EH (0 < |#eta| <1.55)","barrel_corrEtaBarrelEcalHcal","barrel_corrEtaBarrelEcalHcal","trial3/")'
root -l -q 'codes/genrateplot_responsevsE_rawwrtcorrE.C("H hadrons (0 < |#eta| <1.55)","barrel_corrEtaBarrelHcal","barrel_corrEtaBarrelHcal","trial3/")'
root -l -q 'codes/genrateplot_responsevsE_rawwrtcorrE.C("EH hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_corrEtaEndcapEcalHcal","EC_within_tracker_corrEtaEndcapEcalHcal","trial3/")'
root -l -q 'codes/genrateplot_responsevsE_rawwrtcorrE.C("H hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_corrEtaEndcapHcal","EC_within_tracker_corrEtaEndcapHcal","trial3/")'
root -l -q 'codes/genrateplot_responsevsE_rawwrtcorrE.C("EH hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_corrEtaEndcapEcalHcal","EC_outside_tracker_corrEtaEndcapEcalHcal","trial3/")'
root -l -q 'codes/genrateplot_responsevsE_rawwrtcorrE.C("H hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_corrEtaEndcapHcal","EC_outside_tracker_corrEtaEndcapHcal","trial3/")'

root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("EH hadrons","hcorrEtaDependenceEH_wrtEta","hcorrEtaDependenceEH_wrtEta","trial3/")'
root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("EH hadrons","corrEtaDependenceEH_wrtEta","corrEtaDependenceEH_wrtEta","trial3/")'
root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("H hadrons","hcorrEtaDependenceH_wrtEta","hcorrEtaDependenceH_wrtEta","trial3/")'
root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("H hadrons","corrEtaDependenceH_wrtEta","corrEtaDependenceH_wrtEta","trial3/")'



root -l -q 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("EH hadrons (0 < |#eta| <1.55)","barrel_corrEtaBarrelEcalHcal","barrel_corrEtaBarrelEcalHcal","EH_barrel")'
root -l -q 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("H hadrons (0 < |#eta| <1.55)","barrel_corrEtaBarrelHcal","barrel_corrEtaBarrelHcal","H_barrel")'
root -l -q 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("EH hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_corrEtaEndcapEcalHcal","EC_within_tracker_corrEtaEndcapEcalHcal","EH_ec_in")'
root -l -q 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("H hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_corrEtaEndcapHcal","EC_within_tracker_corrEtaEndcapHcal","H_ec_in")'
root -l -q 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("EH hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_corrEtaEndcapEcalHcal","EC_outside_tracker_corrEtaEndcapEcalHcal","EH_ec_out")'
root -l -q 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("H hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_corrEtaEndcapHcal","EC_outside_tracker_corrEtaEndcapHcal","H_ec_out")'

root -l -q 'codes/genrateplot_responsevspt_UL2018wrtrun3.C("EH (0 < |#eta| <1.55)","barrel_corrEtaBarrelEcalHcal","barrel_corrEtaBarrelEcalHcal")'
root -l -q 'codes/genrateplot_responsevspt_UL2018wrtrun3.C("H hadrons (0 < |#eta| <1.55)","barrel_corrEtaBarrelHcal","barrel_corrEtaBarrelHcal")'
root -l -q 'codes/genrateplot_responsevspt_UL2018wrtrun3.C("EH hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_corrEtaEndcapEcalHcal","EC_within_tracker_corrEtaEndcapEcalHcal")'
root -l -q 'codes/genrateplot_responsevspt_UL2018wrtrun3.C("H hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_corrEtaEndcapHcal","EC_within_tracker_corrEtaEndcapHcal")'
root -l -q 'codes/genrateplot_responsevspt_UL2018wrtrun3.C("EH hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_corrEtaEndcapEcalHcal","EC_outside_tracker_corrEtaEndcapEcalHcal")'
root -l -q 'codes/genrateplot_responsevspt_UL2018wrtrun3.C("H hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_corrEtaEndcapHcal","EC_outside_tracker_corrEtaEndcapHcal")'

root -l -q 'codes/genrateplot_responsevsE_UL2018wrtrun3.C("EH (0 < |#eta| <1.55)","barrel_corrEtaBarrelEcalHcal","barrel_corrEtaBarrelEcalHcal")'
root -l -q 'codes/genrateplot_responsevsE_UL2018wrtrun3.C("H hadrons (0 < |#eta| <1.55)","barrel_corrEtaBarrelHcal","barrel_corrEtaBarrelHcal")'
root -l -q 'codes/genrateplot_responsevsE_UL2018wrtrun3.C("EH hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_corrEtaEndcapEcalHcal","EC_within_tracker_corrEtaEndcapEcalHcal")'
root -l -q 'codes/genrateplot_responsevsE_UL2018wrtrun3.C("H hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_corrEtaEndcapHcal","EC_within_tracker_corrEtaEndcapHcal")'
root -l -q 'codes/genrateplot_responsevsE_UL2018wrtrun3.C("EH hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_corrEtaEndcapEcalHcal","EC_outside_tracker_corrEtaEndcapEcalHcal")'
root -l -q 'codes/genrateplot_responsevsE_UL2018wrtrun3.C("H hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_corrEtaEndcapHcal","EC_outside_tracker_corrEtaEndcapHcal")'



#root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("EH hadrons","rawEtaDependenceEH_wrtEta","hcorrEtaDependenceEH_wrtEta","trial2","trial3/")'
root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("EH hadrons","hcorrEtaDependenceEH_wrtEta","corrEtaDependenceEH_wrtEta","trial3/")'
#root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("H hadrons","rawEtaDependenceH_wrtEta","hcorrEtaDependenceH_wrtEta","trial2","trial3/")'
root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("H hadrons","hcorrEtaDependenceH_wrtEta","corrEtaDependenceH_wrtEta","trial3/")'

root -l -q 'codes/genrateplot_responsevsEta_UL2018wrtrun3.C("EH hadrons","hcorrEtaDependenceEH_wrtEta","hcorrEtaDependenceEH_wrtEta")'
root -l -q 'codes/genrateplot_responsevsEta_UL2018wrtrun3.C("EH hadrons","corrEtaDependenceEH_wrtEta","corrEtaDependenceEH_wrtEta")'
root -l -q 'codes/genrateplot_responsevsEta_UL2018wrtrun3.C("H hadrons","hcorrEtaDependenceH_wrtEta","hcorrEtaDependenceH_wrtEta")'
root -l -q 'codes/genrateplot_responsevsEta_UL2018wrtrun3.C("H hadrons","corrEtaDependenceH_wrtEta","corrEtaDependenceH_wrtEta")'


<<EOF

root -l 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("EH hadrons (0 < |#eta| <1.55)","barrel_rawBarrelEcalHcal","barrel_rawBarrelEcalHcal","EH_barrel")'
root -l 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("H hadrons (0 < |#eta| <1.55)","barrel_rawBarrelHcal","barrel_rawBarrelHcal","EH_barrel")'
root -l 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("EH hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_rawEndcapEcalHcal","EC_outside_tracker_rawEndcapEcalHcal","EH_ec_out")'
root -l 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("EH hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_rawEndcapEcalHcal","EC_within_tracker_rawEndcapEcalHcal","EH_ec_in")'
root -l 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("H hadrons (1.55 < |#eta| <2.5)","EC_within_tracker_rawEndcapHcal","EC_within_tracker_rawEndcapHcal","H_ec_in")'
root -l 'codes/genrateplot_1dresponsevsE_UL2018wrtrun3.C("H hadrons (2.5 < |#eta| <2.75)","EC_outside_tracker_rawEndcapHcal","EC_outside_tracker_rawEndcapHcal","H_ec_out")'
root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("EH hadrons","rawEtaDependenceEH_wrtEta","hcorrEtaDependenceEH_wrtEta","trial2")'
root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("EH hadrons","hcorrEtaDependenceEH_wrtEta","corrEtaDependenceEH_wrtEta","trial2")'
#root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("H hadrons","rawEtaDependenceH_wrtEta","hcorrEtaDependenceH_wrtEta","trial2")'                                  
root -l -q 'codes/genrateplot_responsevsEta_rawwrtcorrE.C("H hadrons","hcorrEtaDependenceH_wrtEta","corrEtaDependenceH_wrtEta","trial2")'



#root -l 'genrateplot_responsevsE_rawwrtcorrE.C("EH (2.5 < |#eta| <2.75)","EC_outside_tracker_rawEndcapEcalHcal","EC_outside_tracker_corrEndcapEcalHcal")'
