function WatchInterface(block)
% Level-2 M file S-Function for interface demo.
%   Copyright 1990-2004 The MathWorks, Inc.
%   $Revision: 1.1.6.1 $ 

  setup(block);
  
%endfunction

function setup(block)
  global watchbutton
  global swatchbutton
  global alarmbutton
  global timerbutton
  global plusbutton
  global minusbutton
  global startbutton
  global stopbutton
  
  

  %% Register dialog parameters: No parameters for this block 
  block.NumDialogPrms = 0;
  %% Register number of input and output ports
  block.NumInputPorts  = 9;

  %% Setup functional port properties to dynamically
  %% inherited.
  block.SetPreCompInpPortInfoToDynamic;                    % port inherits sample rates

  %% Input 1 is for hours
  block.InputPort(1).Complexity   = 'Real'; 
  block.InputPort(1).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(1).SamplingMode = 'Sample';
  block.InputPort(1).Dimensions   = 1;
  block.InputPort(1).DirectFeedthrough   = 0;
  
  %% Input 2 is for minutes
  block.InputPort(2).Complexity   = 'Real'; 
  block.InputPort(2).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(2).SamplingMode = 'Sample';
  block.InputPort(2).Dimensions   = 1;
  block.InputPort(2).DirectFeedthrough   = 0;
  
  %% Input 3 is for seconds
  block.InputPort(3).Complexity   = 'Real'; 
  block.InputPort(3).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(3).SamplingMode = 'Sample';
  block.InputPort(3).Dimensions   = 1;
  block.InputPort(3).DirectFeedthrough   = 0;
  
  %% Input 4 is for tenths
  block.InputPort(4).Complexity   = 'Real'; 
  block.InputPort(4).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(4).SamplingMode = 'Sample';
  block.InputPort(4).Dimensions   = 1;
  block.InputPort(4).DirectFeedthrough   = 0;
  
  %% Input 5 is for mode
  block.InputPort(5).Complexity   = 'Real'; 
  block.InputPort(5).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(5).SamplingMode = 'Sample';
  block.InputPort(5).Dimensions   = 1;
  block.InputPort(5).DirectFeedthrough   = 0;
  
  %% Input 6 is for swatchrun
  block.InputPort(6).Complexity   = 'Real'; 
  block.InputPort(6).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(6).SamplingMode = 'Sample';
  block.InputPort(6).Dimensions   = 1;
  block.InputPort(6).DirectFeedthrough   = 0;
  
  %% Input 7 is for watchset
  block.InputPort(7).Complexity   = 'Real'; 
  block.InputPort(7).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(7).SamplingMode = 'Sample';
  block.InputPort(7).Dimensions   = 1;
  block.InputPort(7).DirectFeedthrough   = 0;
  
  %% Input 8 is for alarm_exp
  block.InputPort(8).Complexity   = 'Real'; 
  block.InputPort(8).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(8).SamplingMode = 'Sample';
  block.InputPort(8).Dimensions   = 1;
  block.InputPort(8).DirectFeedthrough   = 0;
  
  %% Input 9 is for timer_exp
  block.InputPort(9).Complexity   = 'Real'; 
  block.InputPort(9).DataTypeId   = 3;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.InputPort(9).SamplingMode = 'Sample';
  block.InputPort(9).Dimensions   = 1;
  block.InputPort(9).DirectFeedthrough   = 0;
  
  block.NumOutputPorts = 8;

  %% Setup functional port properties to dynamically
  %% inherited.
  block.SetPreCompOutPortInfoToDynamic;

  %% buttons
  block.OutputPort(1).Complexity   = 'Real'; 
  block.OutputPort(1).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(1).SamplingMode = 'Sample';
  block.OutputPort(1).Dimensions   = 1;

  block.OutputPort(2).Complexity   = 'Real'; 
  block.OutputPort(2).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(2).SamplingMode = 'Sample';
  block.OutputPort(2).Dimensions   = 1;

  block.OutputPort(3).Complexity   = 'Real'; 
  block.OutputPort(3).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(3).SamplingMode = 'Sample';
  block.OutputPort(3).Dimensions   = 1;

  block.OutputPort(4).Complexity   = 'Real'; 
  block.OutputPort(4).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(4).SamplingMode = 'Sample';
  block.OutputPort(4).Dimensions   = 1;

  block.OutputPort(5).Complexity   = 'Real'; 
  block.OutputPort(5).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(5).SamplingMode = 'Sample';
  block.OutputPort(5).Dimensions   = 1;
  
  block.OutputPort(6).Complexity   = 'Real'; 
  block.OutputPort(6).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(6).SamplingMode = 'Sample';
  block.OutputPort(6).Dimensions   = 1;

  block.OutputPort(7).Complexity   = 'Real'; 
  block.OutputPort(7).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(7).SamplingMode = 'Sample';
  block.OutputPort(7).Dimensions   = 1;

  block.OutputPort(8).Complexity   = 'Real'; 
  block.OutputPort(8).DataTypeId   = 8;                     % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  block.OutputPort(8).SamplingMode = 'Sample';
  block.OutputPort(8).Dimensions   = 1;

  %% Register methods
  block.RegBlockMethod('SetInputPortSamplingMode',@SetInputPortSamplingMode);
  block.RegBlockMethod('Start',                   @Start);  
  %   block.RegBlockMethod('WriteRTW',                @WriteRTW);
  block.RegBlockMethod('Outputs',                 @Outputs);

  watchbutton = 0;
  swatchbutton = 0;
  alarmbutton = 0;
  timerbutton = 0;
  plusbutton = 0;
  minusbutton = 0;
  startbutton = 0;
  stopbutton = 0;
  
 
  %endfunction

 function SetInputPortSamplingMode(block, idx, fd)
   block.InputPort(idx).SamplingMode = fd;

function ButtonDown(hObj,evnt)
  global watchbutton
  global swatchbutton
  global alarmbutton
  global timerbutton
  global plusbutton
  global minusbutton
  global startbutton
  global stopbutton
 

  pos = get(hObj,'CurrentPoint');
  
  %% borders: (pos(2) > SCREEN_HEIGHT - (IMG_POS_Y + IMG_HEIGHT)) &&
  %%          (pos(2) < SCREEN_HEIGHT - IMG_POS_Y) &&
  %%          (pos(1) > IMG_POS_X) && (pos(1) < IMG_POS_X + IMG_WIDTH)
  
  if ((pos(2) > 240-(45)) && (pos(2) < 240) && (pos(1) > 0) && (pos(1) < (80)))
      watchbutton = 1;
  end;
  
  if ((pos(2) > 240-(45)) && (pos(2) < 240) && (pos(1) > 80) && (pos(1) < (160)))
      swatchbutton = 1;
  end;
  
  if ((pos(2) > 240-(45)) && (pos(2) < 240) && (pos(1) > 160) && (pos(1) < (240)))
      alarmbutton = 1;
  end;
  
  if ((pos(2) > 240-(45)) && (pos(2) < 240) && (pos(1) > 240) && (pos(1) < (320)))
      timerbutton = 1;
  end;
  
  if ((pos(2) > 240-(160+40)) && (pos(2) < 240 - 160) && (pos(1) > 30) && (pos(1) < (30 + 100)))
         %% swatch mode or alarm mode or timer mode
          startbutton = 1;
  end;
  
  if ((pos(2) > 240-(160+40)) && (pos(2) < 240 - 160) && (pos(1) > 190) && (pos(1) < (190 + 100)))
        %% swatch mode or alarm mode or timer mode
          stopbutton = 1;
  end;
  
  if ((pos(2) > 240-(125+35)) && (pos(2) < 240 - 125) && (pos(1) > 142) && (pos(1) < (142 + 35)))
         %% alarm mode or timer mode
        plusbutton = 1;
   
  end;
  
  if ((pos(2) > 240-(196+35)) && (pos(2) < 240 - 196) && (pos(1) > 142) && (pos(1) < (142 + 35)))
         %% alarm mode or timer mode
        minusbutton = 1;
      
  end;
        
      

function ButtonUp(hObj,evnt)
  global watchbutton
  global swatchbutton
  global alarmbutton
  global timerbutton
  global plusbutton
  global minusbutton
  global startbutton
  global stopbutton
 

  pos = get(hObj,'CurrentPoint');

  % borders: (pos(2) > SCREEN_HEIGHT - (IMG_POS_Y + IMG_HEIGHT)) &&
  %          (pos(2) < SCREEN_HEIGHT - IMG_POS_Y) &&
  %          (pos(1) > IMG_POS_X) && (pos(1) < IMG_POS_X + IMG_WIDTH)
  
  if ((pos(2) > 240-(45)) && (pos(2) < 240) && (pos(1) > 0) && (pos(1) < (80)))
      watchbutton = 0;
  end;
  
  if ((pos(2) > 240-(45)) && (pos(2) < 240) && (pos(1) > 80) && (pos(1) < (160)))
      swatchbutton = 0;
  end;
  
  if ((pos(2) > 240-(45)) && (pos(2) < 240) && (pos(1) > 160) && (pos(1) < (240)))
      alarmbutton = 0;
  end;
  
  if ((pos(2) > 240-(45)) && (pos(2) < 240) && (pos(1) > 240) && (pos(1) < (320)))
      timerbutton = 0;
  end;
  
  if ((pos(2) > 240-(160+45)) && (pos(2) < 240 - 160) && (pos(1) > 30) && (pos(1) < (30 + 100)))
       %% swatch mode or alarm mode or timer mode
          startbutton = 0;
     
  end;
  
  if ((pos(2) > 240-(160+45)) && (pos(2) < 240 - 160) && (pos(1) > 190) && (pos(1) < (190 + 100)))
        %% swatch mode or alarm mode or timer mode
          stopbutton = 0;
    
  end;
  
  if ((pos(2) > 240-(125+35)) && (pos(2) < 240 - 125) && (pos(1) > 142) && (pos(1) < (142 + 35)))
       %% alarm mode or timer mode
        plusbutton = 0;
    
  end;
  
  if ((pos(2) > 240-(196+35)) && (pos(2) < 240 - 196) && (pos(1) > 142) && (pos(1) < (142 + 35)))
        %% alarm mode or timer mode
        minusbutton = 0;
      
  end;


function Start(block) 

  global IM
  global FH
  global watch_mode_hnd;
  global swatch_mode_hnd;
  global alarm_mode_hnd;
  global timer_mode_hnd;
  global but_start_hnd;
  global but_stop_hnd;
  global but_set_hnd;
  global but_reset_hnd;
  global but_plus_hnd;
  global but_minus_hnd;
  global timer_exp_hnd;
  global alarm_exp_hnd;
  
  global hrs_digits;
  global min_digits;
  global sec_digits;
  global ten_digits;
 
  global watch_mode;
  global swatch_mode;
  global alarm_mode;
  global timer_mode;
  global but_start;
  global but_stop;
  global but_set;
  global but_reset;
  global but_plus;
  global but_minus;
  global timer_exp_icon;
  global alarm_exp_icon;
  
  global sep1;
  global sep2;
  global sep3;
  
  IM = imread('img/bkg_wb.bmp');
  watch_mode = imread('img/b_watch_on.bmp');
  swatch_mode = imread('img/b_swatch_on.bmp');
  alarm_mode = imread('img/b_alarm_on.bmp');
  timer_mode = imread('img/b_timer_on.bmp');
  but_start = imread('img/b_start.bmp');
  but_stop = imread('img/b_stop.bmp');
  but_set = imread('img/b_set.bmp');
  but_reset = imread('img/b_reset.bmp');
  but_plus = imread('img/b_plus.bmp');
  but_minus = imread('img/b_minus.bmp');
  timer_exp_icon = imread('img/timer_exp_on.bmp');
  alarm_exp_icon = imread('img/alarm_exp_on.bmp');
  

  bhD = @ButtonDown;
  bhU = @ButtonUp;

% background image 

  FH = figure('Toolbar', 'none', 'Menubar', 'none', 'Name', 'MyWatch', 'WindowButtonDownFcn', bhD, 'WindowButtonUpFcn', bhU, 'Resize', 'off');
  scrsz = get(0,'ScreenSize');
  set(FH, 'Units','pixels');
  set(FH, 'Position',[1 scrsz(4)-500 320 240]);
  hax = axes('Units', 'pixels', 'Position', [1, 1, 320, 240], 'Visible', 'off');
  image(IM)
  axis off

% text output 

% skipping Arial

  hrs_digits = text(33 + 30, 240-75,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 40);
  set(hrs_digits, 'Color',[1 1 1]);
  set(hrs_digits, 'VerticalAlignment','top');
  set(hrs_digits, 'FontName', 'Arial');

  sep1 = text(78 + 30, 240-75,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 40);
  set(sep1, 'Color',[1 1 1]);
  set(sep1, 'VerticalAlignment','top');
  set(sep1, 'FontName', 'Arial');
  set(sep1, 'string', ':');

  min_digits = text(89 + 30, 240-75,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 40);
  set(min_digits, 'Color',[1 1 1]);
  set(min_digits, 'VerticalAlignment','top');
  set(min_digits, 'FontName', 'Arial');

  sep2 = text(134 + 30, 240-75,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 40);
  set(sep2, 'Color',[1 1 1]);
  set(sep2, 'VerticalAlignment','top');
  set(sep2, 'FontName', 'Arial');
  set(sep2, 'string', ':');

  sec_digits = text(145 + 30, 240-75,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 40);
  set(sec_digits, 'Color',[1 1 1]);
  set(sec_digits, 'VerticalAlignment','top');
  set(sec_digits, 'FontName', 'Arial');

  sep3 = text(188 + 30, 240-75,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 40);
  set(sep3, 'Color',[1 1 1]);
  set(sep3, 'VerticalAlignment','top');
  set(sep3, 'FontName', 'Arial');
  set(sep3, 'string', '.');

  ten_digits = text(199 + 30, 240-75,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 40);
  set(ten_digits, 'Color',[1 1 1]);
  set(ten_digits, 'VerticalAlignment','top');
  set(ten_digits, 'FontName', 'Arial');

  %% watch button image
  hax = axes('Units', 'pixels', 'Position', [0, 240-45, 80, 45], 'Visible', 'off');
  watch_mode_hnd = image(watch_mode, 'Visible', 'off');
  axis off;
  
  %% swatch button image
  hax = axes('Units', 'pixels', 'Position', [80, 240-45, 80, 45], 'Visible', 'off');
  swatch_mode_hnd = image(swatch_mode, 'Visible', 'off');
  axis off;
  
  %% alarm button image
  hax = axes('Units', 'pixels', 'Position', [160, 240-45, 80, 45], 'Visible', 'off');
  alarm_mode_hnd = image(alarm_mode, 'Visible', 'off');
  axis off;
  
  %% timer button image
  hax = axes('Units', 'pixels', 'Position', [240, 240-45, 80, 45], 'Visible', 'off');
  timer_mode_hnd = image(timer_mode, 'Visible', 'off');
  axis off;
  
  %% start button image
  hax = axes('Units', 'pixels', 'Position', [30, 240-(160+45), 100, 45], 'Visible', 'off');
  but_start_hnd = image(but_start, 'Visible', 'off');
  axis off;
  
  %% stop button image
  hax = axes('Units', 'pixels', 'Position', [190, 240-(160+45), 100, 45], 'Visible', 'off');
  but_stop_hnd = image(but_stop, 'Visible', 'off');
  axis off;
  
  %% set button image
  hax = axes('Units', 'pixels', 'Position', [30, 240-(160+45), 100, 45], 'Visible', 'off');
  but_set_hnd = image(but_set, 'Visible', 'off');
  axis off;
  
  %% reset button image
  hax = axes('Units', 'pixels', 'Position', [190, 240-(160+45), 100, 45], 'Visible', 'off');
  but_reset_hnd = image(but_reset, 'Visible', 'off');
  axis off;
  
  %% plus button image
  hax = axes('Units', 'pixels', 'Position', [142, 240-(125+35), 35, 35], 'Visible', 'off');
  but_plus_hnd = image(but_plus, 'Visible', 'off');
  axis off;
  
  %% minus button image
  hax = axes('Units', 'pixels', 'Position', [142, 240-(196+35), 35, 35], 'Visible', 'off');
  but_minus_hnd = image(but_minus, 'Visible', 'off');
  axis off;
  
  %% alarm expired image
  hax = axes('Units', 'pixels', 'Position', [61, 240-(114+38), 38, 38], 'Visible', 'off');
  alarm_exp_hnd = image(alarm_exp_icon, 'Visible', 'off');
  axis off;
  
  %% timer expired image
  hax = axes('Units', 'pixels', 'Position', [221, 240-(114+38), 38, 38], 'Visible', 'off');
  timer_exp_hnd = image(timer_exp_icon, 'Visible', 'off');
  axis off;
  
%%endfunction

function con_str = convertDto2S(dig)
  shw_val = mod(dig, 100);
  con_str = int2str(shw_val);
  if shw_val < 10 
      con_str = strcat('0',con_str);
  end
%endfunction

function con_str = convertDto1S(dig)
  shw_val = mod(dig, 10);
  con_str = int2str(shw_val);
%endfunction

function Outputs(block)
  
   global watchbutton
   global swatchbutton
   global alarmbutton
   global timerbutton
   global plusbutton
   global minusbutton
   global startbutton
   global stopbutton
 
   global watch_mode_hnd;
   global swatch_mode_hnd;
   global alarm_mode_hnd;
   global timer_mode_hnd;
   global but_start_hnd;
   global but_stop_hnd;
   global but_set_hnd;
   global but_reset_hnd;
   global but_plus_hnd;
   global but_minus_hnd; 
   global alarm_exp_hnd;
   global timer_exp_hnd;
 
   global hrs_digits;
   global min_digits;
   global sec_digits;
   global ten_digits;
   
   global sep2;
   global sep3;

%Update graphics based on input ports

%% Need to transform block.InputPort(1).Data value into string of 2 chars
  set(hrs_digits, 'string',  convertDto2S(block.InputPort(1).Data))
%% Need to transform block.InputPort(2).Data value into string of 2 chars
  set(min_digits, 'string', convertDto2S(block.InputPort(2).Data))
%% Need to transform block.InputPort(3).Data value into string of 2 chars

% Swatch mode digits handling
if block.InputPort(5).Data == 1
    set(ten_digits, 'Visible', 'on')
    set(ten_digits, 'string', convertDto1S(block.InputPort(4).Data))
    set(sep3, 'Visible', 'on')
else
    set(ten_digits, 'Visible', 'off')
    set(sep3, 'Visible', 'off')
end;

% If i'm not in alarm mode, i want to see the seconds
if (block.InputPort(5).Data ~= 2) 
    set(sec_digits, 'Visible', 'on')
    set(sec_digits, 'string', convertDto2S(block.InputPort(3).Data))
    set(sep2, 'Visible', 'on')
else
    set(sec_digits, 'Visible', 'off')
    set(sep2, 'Visible', 'off')
end;

% Alarm expred icon handling
if block.InputPort(8).Data == 1
    set(alarm_exp_hnd, 'Visible', 'on');
else
    set(alarm_exp_hnd, 'Visible', 'off');
end;

% Timer expired icon handling
if block.InputPort(9).Data == 1
    set(timer_exp_hnd, 'Visible', 'on');
else
    set(timer_exp_hnd, 'Visible', 'off');
end;

% Watch mode button handling
if block.InputPort(5).Data == 0
    if block.InputPort(7).Data == 1
        set(but_plus_hnd, 'Visible', 'on')
        set(but_minus_hnd, 'Visible', 'on')
    else
        set(but_plus_hnd, 'Visible', 'off')
        set(but_minus_hnd, 'Visible', 'off')
    end;
    set(watch_mode_hnd, 'Visible', 'on')
    set(but_start_hnd, 'Visible', 'off')
    set(but_stop_hnd, 'Visible', 'off')
    set(but_reset_hnd, 'Visible', 'off')
    set(but_set_hnd, 'Visible', 'off')
else
    set(watch_mode_hnd, 'Visible', 'off')
end;

% Swatch mode button handling
if block.InputPort(5).Data == 1              
    set(swatch_mode_hnd, 'Visible', 'on')
    set(but_start_hnd, 'Visible', 'on')
    set(but_set_hnd, 'Visible', 'off')
    set(but_plus_hnd, 'Visible', 'off')
    set(but_minus_hnd, 'Visible', 'off')
    if (block.InputPort(6).Data <= 1)
        % Swatch not started yet
        set(but_stop_hnd, 'Visible', 'on')
        set(but_reset_hnd, 'Visible', 'off')
    else
        % Swatch started
        set(but_reset_hnd, 'Visible', 'on')
        set(but_stop_hnd, 'Visible', 'off')
    end;
else
    set(swatch_mode_hnd, 'Visible', 'off')
end;

% Alarm mode and Timer mode button handling
if (block.InputPort(5).Data == 2 || block.InputPort(5).Data == 3) 
    set(but_set_hnd, 'Visible', 'on')
    set(but_reset_hnd, 'Visible', 'on')
    set(but_plus_hnd, 'Visible', 'on')
    set(but_minus_hnd, 'Visible', 'on')
    if block.InputPort(5).Data == 2
        % Alarm mode
        set(timer_mode_hnd, 'Visible', 'off')
        set(alarm_mode_hnd, 'Visible', 'on')
    else
        %Timer mode
        set(alarm_mode_hnd, 'Visible', 'off')
        set(timer_mode_hnd, 'Visible', 'on')
    end;
else
    set(timer_mode_hnd, 'Visible', 'off')
    set(alarm_mode_hnd, 'Visible', 'off')
end;

 
%Update output ports

  block.OutputPort(1).Data = boolean(watchbutton);
  block.OutputPort(2).Data = boolean(swatchbutton);
  block.OutputPort(3).Data = boolean(alarmbutton);
  block.OutputPort(4).Data = boolean(timerbutton);
  block.OutputPort(5).Data = boolean(plusbutton);
  block.OutputPort(6).Data = boolean(minusbutton);
  block.OutputPort(7).Data = boolean(startbutton);
  block.OutputPort(8).Data = boolean(stopbutton);
  
%endfunction

