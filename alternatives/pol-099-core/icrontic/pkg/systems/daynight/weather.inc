function ChangeWeather()

wstuff := GetGlobalProperty("Weather");
var pweather := wstuff[7];
var season := wstuff[8];
var incdec := RandomInt(4);

case(season)
	0: incdec := incdec - 1;
	1: incdec := incdec;
	2: incdec := incdec + 1;
	3: incdec := incdec;
endcase

if (incdec <= 1)
	pweather := pweather - 1;
	if (pweather < 0)
		pweather := 0;
	endif
endif
if (incdec = 2)
	return;
endif
if (incdec >= 3)
	pweather := pweather + 1;
	if (pweather >4)
		pweather := 4;
	endif
endif

var pweathercheck := wstuff[7];

If (pweathercheck = pweather)
	If (doonce = 1)
		return;
	endif
endif

doonce := 1;

wstuff[7] := pweather;

case(pweather)
	0: SetSunny();
	1: SetOvercast();
	2: SetCloudy();
	3: SetRain();
	4: SetThunder();
endcase

SetGlobalProperty("Weather", wstuff);

endfunction

function SetSunny()

wstuff[4] := 0;
Broadcast("The skies are clear");
If (day = 1)
	SetRegionLightLevel( "Background" , 0);
	wstuff[6] := 0;
endif

endfunction

function SetOvercast()

wstuff[4] := 2;
Broadcast("The skies are overcast");
if (day = 1)
	SetRegionLightLevel( "Background", 2);
	wstuff[6] := 2;
endif

endfunction

function SetCloudy()

wstuff[4] := 4;
SetRegionWeatherLevel( "Background", 0, 0, 1, -1);
Broadcast("The skies blacken, but at least it's not raining");
if (day = 1)
	SetRegionLightLevel( "Background", 4);
	wstuff[4] := 4;
endif

endfunction

function SetRain()

wstuff[4] := 6;
broadcast("Don't you just love getting wet?");
if (day = 1)
	SetRegionLightLevel("Background", 6);
	wstuff[6] := 6;
endif

start_script( "snowrain", 15);

endfunction				

function SetThunder()

wstuff[4] := 8;
Broadcast("A storm rages overhead");
if (day = 1)
	SetRegionLightLevel("Background", 8);
	wstuff[6] := 8;
endif

start_script( "weffect" );
start_script( "snowrain", 30);


endfunction
	