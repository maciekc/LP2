  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Helikopter_new_LQI_P)
    ;%
      section.nData     = 70;
      section.data(70)  = dumData; %prealloc
      
	  ;% Helikopter_new_LQI_P.K_lqi
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Helikopter_new_LQI_P.L
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Helikopter_new_LQI_P.lin_A
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 7;
	
	  ;% Helikopter_new_LQI_P.lin_B
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 16;
	
	  ;% Helikopter_new_LQI_P.lin_C
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 19;
	
	  ;% Helikopter_new_LQI_P.lin_alpha_v
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 22;
	
	  ;% Helikopter_new_LQI_P.lin_w_v
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 23;
	
	  ;% Helikopter_new_LQI_P.wsp_V
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 24;
	
	  ;% Helikopter_new_LQI_P.SliderGain2_gain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 26;
	
	  ;% Helikopter_new_LQI_P.SliderGain_gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 27;
	
	  ;% Helikopter_new_LQI_P.Normal_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 28;
	
	  ;% Helikopter_new_LQI_P.Reset_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 29;
	
	  ;% Helikopter_new_LQI_P.Gain15_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 30;
	
	  ;% Helikopter_new_LQI_P.Encoder_P1_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 31;
	
	  ;% Helikopter_new_LQI_P.Encoder_P1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 33;
	
	  ;% Helikopter_new_LQI_P.Encoder_P2_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 34;
	
	  ;% Helikopter_new_LQI_P.Encoder_P2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 36;
	
	  ;% Helikopter_new_LQI_P.Encoder1024PPR_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 37;
	
	  ;% Helikopter_new_LQI_P.Converttorad_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 38;
	
	  ;% Helikopter_new_LQI_P.Gain7_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 39;
	
	  ;% Helikopter_new_LQI_P.AnalogInput_P1_Size
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 40;
	
	  ;% Helikopter_new_LQI_P.AnalogInput_P1
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 42;
	
	  ;% Helikopter_new_LQI_P.AnalogInput_P2_Size
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 43;
	
	  ;% Helikopter_new_LQI_P.AnalogInput_P2
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 45;
	
	  ;% Helikopter_new_LQI_P.AnalogInput_P3_Size
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 47;
	
	  ;% Helikopter_new_LQI_P.AnalogInput_P3
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 49;
	
	  ;% Helikopter_new_LQI_P.AnalogInput_P4_Size
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 51;
	
	  ;% Helikopter_new_LQI_P.AnalogInput_P4
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 53;
	
	  ;% Helikopter_new_LQI_P.ConverttoRPM1_Gain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 54;
	
	  ;% Helikopter_new_LQI_P.Constant4_Value
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 55;
	
	  ;% Helikopter_new_LQI_P.Gain5_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 56;
	
	  ;% Helikopter_new_LQI_P.Gain17_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 57;
	
	  ;% Helikopter_new_LQI_P.Integrator_IC
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 58;
	
	  ;% Helikopter_new_LQI_P.Integrator4_IC
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 61;
	
	  ;% Helikopter_new_LQI_P.PitchCtrl1_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 62;
	
	  ;% Helikopter_new_LQI_P.Saturation_UpperSat
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 63;
	
	  ;% Helikopter_new_LQI_P.Saturation_LowerSat
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 64;
	
	  ;% Helikopter_new_LQI_P.Gain_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 65;
	
	  ;% Helikopter_new_LQI_P.Gain16_Gain
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 66;
	
	  ;% Helikopter_new_LQI_P.AzimuthCtrl_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 67;
	
	  ;% Helikopter_new_LQI_P.Constant11_Value
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 68;
	
	  ;% Helikopter_new_LQI_P.Integrator5_IC
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 69;
	
	  ;% Helikopter_new_LQI_P.Saturation_UpperSat_a
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 70;
	
	  ;% Helikopter_new_LQI_P.Saturation_LowerSat_o
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 71;
	
	  ;% Helikopter_new_LQI_P.PWM_P1_Size
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 72;
	
	  ;% Helikopter_new_LQI_P.PWM_P1
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 74;
	
	  ;% Helikopter_new_LQI_P.PWM_P2_Size
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 75;
	
	  ;% Helikopter_new_LQI_P.PWM_P2
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 77;
	
	  ;% Helikopter_new_LQI_P.ResetEncoder_P1_Size
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 78;
	
	  ;% Helikopter_new_LQI_P.ResetEncoder_P1
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 80;
	
	  ;% Helikopter_new_LQI_P.ResetEncoder_P2_Size
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 81;
	
	  ;% Helikopter_new_LQI_P.ResetEncoder_P2
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 83;
	
	  ;% Helikopter_new_LQI_P.BitstreamVersion_P1_Size
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 84;
	
	  ;% Helikopter_new_LQI_P.BitstreamVersion_P1
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 86;
	
	  ;% Helikopter_new_LQI_P.BitstreamVersion_P2_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 87;
	
	  ;% Helikopter_new_LQI_P.BitstreamVersion_P2
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 89;
	
	  ;% Helikopter_new_LQI_P.ThermStatus_P1_Size
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 90;
	
	  ;% Helikopter_new_LQI_P.ThermStatus_P1
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 92;
	
	  ;% Helikopter_new_LQI_P.ThermStatus_P2_Size
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 93;
	
	  ;% Helikopter_new_LQI_P.ThermStatus_P2
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 95;
	
	  ;% Helikopter_new_LQI_P.PWMPrescalerSource_Value
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 96;
	
	  ;% Helikopter_new_LQI_P.PWMPrescaler_P1_Size
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 98;
	
	  ;% Helikopter_new_LQI_P.PWMPrescaler_P1
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 100;
	
	  ;% Helikopter_new_LQI_P.PWMPrescaler_P2_Size
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 101;
	
	  ;% Helikopter_new_LQI_P.PWMPrescaler_P2
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 103;
	
	  ;% Helikopter_new_LQI_P.ThermFlagSource_Value
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 104;
	
	  ;% Helikopter_new_LQI_P.ThermFlag_P1_Size
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 106;
	
	  ;% Helikopter_new_LQI_P.ThermFlag_P1
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 108;
	
	  ;% Helikopter_new_LQI_P.ThermFlag_P2_Size
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 109;
	
	  ;% Helikopter_new_LQI_P.ThermFlag_P2
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 111;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Helikopter_new_LQI_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Helikopter_new_LQI_P.ManualSwitch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 71;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Helikopter_new_LQI_P.ResetEncoders_CurrentSetting
	  section.data(3).logicalSrcIdx = 72;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Helikopter_new_LQI_B)
    ;%
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% Helikopter_new_LQI_B.Encoder
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Helikopter_new_LQI_B.Converttorad
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Helikopter_new_LQI_B.Gain7
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Helikopter_new_LQI_B.AnalogInput
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Helikopter_new_LQI_B.ConverttoRPM1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% Helikopter_new_LQI_B.Gain5
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Helikopter_new_LQI_B.Sum3
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% Helikopter_new_LQI_B.Sum5
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% Helikopter_new_LQI_B.Sum4
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% Helikopter_new_LQI_B.Gain17
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% Helikopter_new_LQI_B.Sum33
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% Helikopter_new_LQI_B.Integrator
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% Helikopter_new_LQI_B.Sum34
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% Helikopter_new_LQI_B.Gain6
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% Helikopter_new_LQI_B.Sum16
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 20;
	
	  ;% Helikopter_new_LQI_B.Sum17
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% Helikopter_new_LQI_B.SliderGain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 22;
	
	  ;% Helikopter_new_LQI_B.Add1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 23;
	
	  ;% Helikopter_new_LQI_B.Sum9
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 24;
	
	  ;% Helikopter_new_LQI_B.ResetEncoders
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 25;
	
	  ;% Helikopter_new_LQI_B.SliderGain_l
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 26;
	
	  ;% Helikopter_new_LQI_B.Sum7
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 27;
	
	  ;% Helikopter_new_LQI_B.Saturation
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 30;
	
	  ;% Helikopter_new_LQI_B.PWM
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 32;
	
	  ;% Helikopter_new_LQI_B.ResetEncoder
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 34;
	
	  ;% Helikopter_new_LQI_B.BitstreamVersion
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 36;
	
	  ;% Helikopter_new_LQI_B.ThermStatus
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 37;
	
	  ;% Helikopter_new_LQI_B.PWMPrescalerSource
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 39;
	
	  ;% Helikopter_new_LQI_B.PWMPrescaler
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 41;
	
	  ;% Helikopter_new_LQI_B.ThermFlagSource
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 43;
	
	  ;% Helikopter_new_LQI_B.ThermFlag
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Helikopter_new_LQI_DW)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Helikopter_new_LQI_DW.Angles_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Helikopter_new_LQI_DW.RPMs_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Helikopter_new_LQI_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Helikopter_new_LQI_DW.Scope5_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Helikopter_new_LQI_DW.Scope6_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Helikopter_new_LQI_DW.Scope7_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3169174699;
  targMap.checksum1 = 49029839;
  targMap.checksum2 = 32804628;
  targMap.checksum3 = 679928057;

