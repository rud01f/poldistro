/*
        Maintened by *Edwards

        2009-10-20
*/
use uo;
use os;

function AmountInContainer( container, properties )

	if( Lower( TypeOf( properties )) != "dictionary" )
		return error{"errortext":="Property list must be a dictionary."};
	endif

	var amount := 0;

	MAIN: foreach item in ( EnumerateItemsInContainer( container ))
		foreach property in ( properties.Keys() )
			if( item.Get_Member( property ) != properties[property] )
				continue MAIN;
			endif
			SleepMS(2);
		endforeach

		amount += item.amount;

		SleepMS(2);
	endforeach

	return amount;
endfunction

function FindMatchesInContainer( container, properties )

	if( Lower( TypeOf( properties )) != "dictionary" )
		return error{"errortext":="Property list must be a dictionary."};
	endif

	var item_list := array{};

	MAIN: foreach item in ( EnumerateItemsInContainer( container ))
		foreach property in ( properties.Keys() )
			if( item.Get_Member( property ) != properties[property] )
				continue MAIN;
			endif
			SleepMS(2);
		endforeach

		item_list.Append( item );

		SleepMS(2);
	endforeach

	return item_list;
endfunction

function ListRootItemsInContainer( container )

	var item_list := array{};

        foreach item in ( EnumerateItemsInContainer( container ))
		if( item.container == container )
			item_list.Append( item );
		endif
		SleepMS(2);
	endforeach

	return item_list;
endfunction

function CreateLockID()

	var lock_id := GetGlobalProperty( "NextLockID" );
	if( !lock_id || lock_id.errortext )
		lock_id := 1;
	endif
 
	SetGlobalProperty( "NextLockID", lock_id+1 );
 
	return lock_id;
endfunction
