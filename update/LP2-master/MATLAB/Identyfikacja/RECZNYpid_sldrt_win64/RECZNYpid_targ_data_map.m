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
    ;% Auto data (RECZNYpid_P)
    ;%
      section.nData     = 73;
      section.data(73)  = dumData; %prealloc
      
	  ;% RECZNYpid_P.wsp_V
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RECZNYpid_P.PIDController1_D
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% RECZNYpid_P.PIDController_D
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% RECZNYpid_P.PIDController_I
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% RECZNYpid_P.PIDController1_I
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% RECZNYpid_P.PIDController_Kb
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% RECZNYpid_P.PIDController1_LowerSaturationL
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% RECZNYpid_P.PIDController_LowerSaturationLi
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% RECZNYpid_P.PIDController1_N
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% RECZNYpid_P.PIDController_N
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% RECZNYpid_P.PIDController1_P
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11;
	
	  ;% RECZNYpid_P.PIDController_P
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 12;
	
	  ;% RECZNYpid_P.PIDController1_UpperSaturationL
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 13;
	
	  ;% RECZNYpid_P.PIDController_UpperSaturationLi
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 14;
	
	  ;% RECZNYpid_P.SliderGain_gain
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 15;
	
	  ;% RECZNYpid_P.Gain_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 16;
	
	  ;% RECZNYpid_P.Normal_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 17;
	
	  ;% RECZNYpid_P.Reset_Value
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 18;
	
	  ;% RECZNYpid_P.Encoder_P1_Size
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 19;
	
	  ;% RECZNYpid_P.Encoder_P1
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 21;
	
	  ;% RECZNYpid_P.Encoder_P2_Size
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 22;
	
	  ;% RECZNYpid_P.Encoder_P2
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% RECZNYpid_P.Encoder1024PPR_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% RECZNYpid_P.Converttorad_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% RECZNYpid_P.Constant_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 27;
	
	  ;% RECZNYpid_P.AnalogInput_P1_Size
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 28;
	
	  ;% RECZNYpid_P.AnalogInput_P1
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 30;
	
	  ;% RECZNYpid_P.AnalogInput_P2_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31;
	
	  ;% RECZNYpid_P.AnalogInput_P2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 33;
	
	  ;% RECZNYpid_P.AnalogInput_P3_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 35;
	
	  ;% RECZNYpid_P.AnalogInput_P3
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 37;
	
	  ;% RECZNYpid_P.AnalogInput_P4_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 39;
	
	  ;% RECZNYpid_P.AnalogInput_P4
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 41;
	
	  ;% RECZNYpid_P.ConverttoRPM1_Gain
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 42;
	
	  ;% RECZNYpid_P.Integrator_IC
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 43;
	
	  ;% RECZNYpid_P.Filter_IC
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 44;
	
	  ;% RECZNYpid_P.Switch1_Threshold
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 45;
	
	  ;% RECZNYpid_P.Integrator_IC_p
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 46;
	
	  ;% RECZNYpid_P.Filter_IC_a
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 47;
	
	  ;% RECZNYpid_P.Switch_Threshold
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 48;
	
	  ;% RECZNYpid_P.Constant1_Value
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 49;
	
	  ;% RECZNYpid_P.Saturation_UpperSat
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 50;
	
	  ;% RECZNYpid_P.Saturation_LowerSat
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 51;
	
	  ;% RECZNYpid_P.Constant3_Value
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 52;
	
	  ;% RECZNYpid_P.AzimuthCtrl_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 53;
	
	  ;% RECZNYpid_P.Saturation_UpperSat_k
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 54;
	
	  ;% RECZNYpid_P.Saturation_LowerSat_k
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 55;
	
	  ;% RECZNYpid_P.PWM_P1_Size
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 56;
	
	  ;% RECZNYpid_P.PWM_P1
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 58;
	
	  ;% RECZNYpid_P.PWM_P2_Size
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 59;
	
	  ;% RECZNYpid_P.PWM_P2
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 61;
	
	  ;% RECZNYpid_P.ResetEncoder_P1_Size
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 62;
	
	  ;% RECZNYpid_P.ResetEncoder_P1
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 64;
	
	  ;% RECZNYpid_P.ResetEncoder_P2_Size
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 65;
	
	  ;% RECZNYpid_P.ResetEncoder_P2
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 67;
	
	  ;% RECZNYpid_P.BitstreamVersion_P1_Size
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 68;
	
	  ;% RECZNYpid_P.BitstreamVersion_P1
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 70;
	
	  ;% RECZNYpid_P.BitstreamVersion_P2_Size
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 71;
	
	  ;% RECZNYpid_P.BitstreamVersion_P2
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 73;
	
	  ;% RECZNYpid_P.ThermStatus_P1_Size
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 74;
	
	  ;% RECZNYpid_P.ThermStatus_P1
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 76;
	
	  ;% RECZNYpid_P.ThermStatus_P2_Size
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 77;
	
	  ;% RECZNYpid_P.ThermStatus_P2
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 79;
	
	  ;% RECZNYpid_P.PWMPrescalerSource_Value
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 80;
	
	  ;% RECZNYpid_P.PWMPrescaler_P1_Size
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 82;
	
	  ;% RECZNYpid_P.PWMPrescaler_P1
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 84;
	
	  ;% RECZNYpid_P.PWMPrescaler_P2_Size
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 85;
	
	  ;% RECZNYpid_P.PWMPrescaler_P2
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 87;
	
	  ;% RECZNYpid_P.ThermFlagSource_Value
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 88;
	
	  ;% RECZNYpid_P.ThermFlag_P1_Size
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 90;
	
	  ;% RECZNYpid_P.ThermFlag_P1
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 92;
	
	  ;% RECZNYpid_P.ThermFlag_P2_Size
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 93;
	
	  ;% RECZNYpid_P.ThermFlag_P2
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 95;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% RECZNYpid_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RECZNYpid_P.ResetEncoders_CurrentSetting
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 1;
	
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
    ;% Auto data (RECZNYpid_B)
    ;%
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% RECZNYpid_B.Encoder
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RECZNYpid_B.Converttorad
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% RECZNYpid_B.Constant
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% RECZNYpid_B.AnalogInput
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% RECZNYpid_B.ConverttoRPM1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% RECZNYpid_B.Add
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% RECZNYpid_B.ProportionalGain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% RECZNYpid_B.DerivativeGain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% RECZNYpid_B.FilterCoefficient
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% RECZNYpid_B.Abs
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% RECZNYpid_B.ProportionalGain_m
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% RECZNYpid_B.DerivativeGain_n
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% RECZNYpid_B.FilterCoefficient_c
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% RECZNYpid_B.Saturation
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% RECZNYpid_B.ManualSwitch
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% RECZNYpid_B.IntegralGain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% RECZNYpid_B.SumI1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% RECZNYpid_B.IntegralGain_o
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
	  ;% RECZNYpid_B.ResetEncoders
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% RECZNYpid_B.SliderGain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% RECZNYpid_B.Saturation_j
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% RECZNYpid_B.PWM
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 26;
	
	  ;% RECZNYpid_B.ResetEncoder
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 28;
	
	  ;% RECZNYpid_B.BitstreamVersion
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 30;
	
	  ;% RECZNYpid_B.ThermStatus
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 31;
	
	  ;% RECZNYpid_B.PWMPrescalerSource
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 33;
	
	  ;% RECZNYpid_B.PWMPrescaler
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 35;
	
	  ;% RECZNYpid_B.ThermFlagSource
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 37;
	
	  ;% RECZNYpid_B.ThermFlag
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 39;
	
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
    ;% Auto data (RECZNYpid_DW)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% RECZNYpid_DW.Angles_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% RECZNYpid_DW.RPMs_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% RECZNYpid_DW.Scope_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% RECZNYpid_DW.Scope1_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% RECZNYpid_DW.Scope2_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% RECZNYpid_DW.Scope3_PWORK.LoggedData
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


  targMap.checksum0 = 3116290505;
  targMap.checksum1 = 1747840451;
  targMap.checksum2 = 596291950;
  targMap.checksum3 = 1953715243;

