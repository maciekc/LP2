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
    ;% Auto data (Helikopter_new_P)
    ;%
      section.nData     = 64;
      section.data(64)  = dumData; %prealloc
      
	  ;% Helikopter_new_P.K_lqr
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Helikopter_new_P.L
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Helikopter_new_P.lin_A
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Helikopter_new_P.lin_B
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 15;
	
	  ;% Helikopter_new_P.lin_C
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 18;
	
	  ;% Helikopter_new_P.lin_alpha_v
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 21;
	
	  ;% Helikopter_new_P.lin_w_v
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 22;
	
	  ;% Helikopter_new_P.wsp_V
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 23;
	
	  ;% Helikopter_new_P.SliderGain2_gain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 25;
	
	  ;% Helikopter_new_P.SliderGain_gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 26;
	
	  ;% Helikopter_new_P.Normal_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 27;
	
	  ;% Helikopter_new_P.Reset_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 28;
	
	  ;% Helikopter_new_P.Saturation_UpperSat
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 29;
	
	  ;% Helikopter_new_P.Saturation_LowerSat
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 30;
	
	  ;% Helikopter_new_P.Gain6_Gain
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 31;
	
	  ;% Helikopter_new_P.Encoder_P1_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 32;
	
	  ;% Helikopter_new_P.Encoder_P1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 34;
	
	  ;% Helikopter_new_P.Encoder_P2_Size
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 35;
	
	  ;% Helikopter_new_P.Encoder_P2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 37;
	
	  ;% Helikopter_new_P.Encoder1024PPR_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 38;
	
	  ;% Helikopter_new_P.Converttorad_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 39;
	
	  ;% Helikopter_new_P.AnalogInput_P1_Size
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 40;
	
	  ;% Helikopter_new_P.AnalogInput_P1
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 42;
	
	  ;% Helikopter_new_P.AnalogInput_P2_Size
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 43;
	
	  ;% Helikopter_new_P.AnalogInput_P2
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 45;
	
	  ;% Helikopter_new_P.AnalogInput_P3_Size
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 47;
	
	  ;% Helikopter_new_P.AnalogInput_P3
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 49;
	
	  ;% Helikopter_new_P.AnalogInput_P4_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 51;
	
	  ;% Helikopter_new_P.AnalogInput_P4
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 53;
	
	  ;% Helikopter_new_P.ConverttoRPM1_Gain
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 54;
	
	  ;% Helikopter_new_P.Constant_Value
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 55;
	
	  ;% Helikopter_new_P.Gain5_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 56;
	
	  ;% Helikopter_new_P.Integrator_IC
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 57;
	
	  ;% Helikopter_new_P.AzimuthCtrl_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 60;
	
	  ;% Helikopter_new_P.Constant11_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 61;
	
	  ;% Helikopter_new_P.PitchCtrl1_Value
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 62;
	
	  ;% Helikopter_new_P.Saturation_UpperSat_a
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 63;
	
	  ;% Helikopter_new_P.Saturation_LowerSat_o
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 64;
	
	  ;% Helikopter_new_P.PWM_P1_Size
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 65;
	
	  ;% Helikopter_new_P.PWM_P1
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 67;
	
	  ;% Helikopter_new_P.PWM_P2_Size
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 68;
	
	  ;% Helikopter_new_P.PWM_P2
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 70;
	
	  ;% Helikopter_new_P.ResetEncoder_P1_Size
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 71;
	
	  ;% Helikopter_new_P.ResetEncoder_P1
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 73;
	
	  ;% Helikopter_new_P.ResetEncoder_P2_Size
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 74;
	
	  ;% Helikopter_new_P.ResetEncoder_P2
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 76;
	
	  ;% Helikopter_new_P.BitstreamVersion_P1_Size
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 77;
	
	  ;% Helikopter_new_P.BitstreamVersion_P1
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 79;
	
	  ;% Helikopter_new_P.BitstreamVersion_P2_Size
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 80;
	
	  ;% Helikopter_new_P.BitstreamVersion_P2
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 82;
	
	  ;% Helikopter_new_P.ThermStatus_P1_Size
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 83;
	
	  ;% Helikopter_new_P.ThermStatus_P1
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 85;
	
	  ;% Helikopter_new_P.ThermStatus_P2_Size
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 86;
	
	  ;% Helikopter_new_P.ThermStatus_P2
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 88;
	
	  ;% Helikopter_new_P.PWMPrescalerSource_Value
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 89;
	
	  ;% Helikopter_new_P.PWMPrescaler_P1_Size
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 91;
	
	  ;% Helikopter_new_P.PWMPrescaler_P1
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 93;
	
	  ;% Helikopter_new_P.PWMPrescaler_P2_Size
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 94;
	
	  ;% Helikopter_new_P.PWMPrescaler_P2
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 96;
	
	  ;% Helikopter_new_P.ThermFlagSource_Value
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 97;
	
	  ;% Helikopter_new_P.ThermFlag_P1_Size
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 99;
	
	  ;% Helikopter_new_P.ThermFlag_P1
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 101;
	
	  ;% Helikopter_new_P.ThermFlag_P2_Size
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 102;
	
	  ;% Helikopter_new_P.ThermFlag_P2
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 104;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Helikopter_new_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Helikopter_new_P.ManualSwitch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 65;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Helikopter_new_P.ResetEncoders_CurrentSetting
	  section.data(3).logicalSrcIdx = 66;
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
    ;% Auto data (Helikopter_new_B)
    ;%
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% Helikopter_new_B.Encoder
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Helikopter_new_B.Converttorad
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Helikopter_new_B.AnalogInput
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Helikopter_new_B.ConverttoRPM1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% Helikopter_new_B.Gain5
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Helikopter_new_B.Sum3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Helikopter_new_B.Sum5
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% Helikopter_new_B.Sum4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% Helikopter_new_B.Sum14
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% Helikopter_new_B.Integrator
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% Helikopter_new_B.Sum15
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 16;
	
	  ;% Helikopter_new_B.Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% Helikopter_new_B.Sum16
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% Helikopter_new_B.Sum17
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% Helikopter_new_B.Sum9
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 20;
	
	  ;% Helikopter_new_B.SliderGain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% Helikopter_new_B.ResetEncoders
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 22;
	
	  ;% Helikopter_new_B.SliderGain_l
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 23;
	
	  ;% Helikopter_new_B.Sum7
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 24;
	
	  ;% Helikopter_new_B.Saturation
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 27;
	
	  ;% Helikopter_new_B.PWM
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 29;
	
	  ;% Helikopter_new_B.ResetEncoder
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 31;
	
	  ;% Helikopter_new_B.BitstreamVersion
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 33;
	
	  ;% Helikopter_new_B.ThermStatus
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 34;
	
	  ;% Helikopter_new_B.PWMPrescalerSource
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 36;
	
	  ;% Helikopter_new_B.PWMPrescaler
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 38;
	
	  ;% Helikopter_new_B.ThermFlagSource
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 40;
	
	  ;% Helikopter_new_B.ThermFlag
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 42;
	
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
    ;% Auto data (Helikopter_new_DW)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Helikopter_new_DW.Angles_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Helikopter_new_DW.RPMs_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Helikopter_new_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Helikopter_new_DW.Scope5_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Helikopter_new_DW.Scope6_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Helikopter_new_DW.Scope7_PWORK.LoggedData
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


  targMap.checksum0 = 1696475679;
  targMap.checksum1 = 2786502830;
  targMap.checksum2 = 2461680667;
  targMap.checksum3 = 1217827392;

