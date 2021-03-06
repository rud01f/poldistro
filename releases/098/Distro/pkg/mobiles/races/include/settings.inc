//$Id: settings.inc 546 2006-07-04 04:32:21Z austinheilman $

/*===============================================================
* Current Version
* SETTINGS.INC - v1.0
* Updated 7/2/2006 5:25PM
*
* -- Revision v1.0 --
* Austin:
*  Created include file
===============================================================*/

use uo;
use os;

/*
 * RACE_GetSettingsCfgFile(engine_name)
 *
 * Purpose
 * Reads in :damage:configs/settings.cfg
 *
 * Parameters
 *
 * Return value
 * A config file reference.
 *
 */
function RACE_GetSettingsCfgFile()
	var cfg := ReadConfigFile(":races:settings");

	if ( cfg.errortext )
		SysLog("Error::RACE_GetSettingsCfgFile() - Unable to open [:races:settings.cfg] ->"+cfg.errortext);
	endif

	return cfg;
endfunction

/*
 * RACE_GetSettingsCfgElem(elem_name, cfg_file)
 *
 * Purpose
 * Retrieves an elem from a config file.
 *
 * Parameters
 * elem_name:	A string matching the elem name to be retrieved.
 * cfg_file:	Optional parameter - reference to a config already read in by RACE_GetSettingsCfgFile()
 *
 * Return value
 * A config file elem reference.
 *
 */
function RACE_GetSettingsCfgElem(elem_name, byref cfg_file:=0)
	if ( !cfg_file )
		cfg_file := RACE_GetSettingsCfgFile();
	endif

	var elem := cfg_file[elem_name];

	if ( elem.errortext )
		SysLog("Error::RACE_GetSettingsCfgElem() - Unable to find elem ["+elem_name+"] ->"+elem.errortext);
	endif

	return elem;
endfunction
