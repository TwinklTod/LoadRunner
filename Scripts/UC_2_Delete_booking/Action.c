Action()
{
	lr_start_transaction("UC_2_Delete_booking");
	
	open_homepage();
	
	lr_think_time(5);

	login();
	
	web_reg_find("SaveCount=NoBooking",
		"Text/IC=<H3>No flights have been reserved.</H3>",
		LAST);
	
		web_reg_save_param("flightID",
		"LB/IC=flightID\" value=\"",
		"RB/IC=\"",
		"Ord=ALL",
		"NotFound=WARNING",
		LAST);
	
		web_reg_save_param("checkbox",
		"LB/IC=checkbox\" name=\"",
		"RB/IC=\"",
		"Ord=ALL",
		"NotFound=WARNING",
		LAST);
			
	click_itinerary();
	
	lr_think_time(5);
	
	
		                
	if (atoi(lr_eval_string("{NoBooking}")) == 1) {
		
	    logout();
	    
	    }
	
	else {
		
	lr_save_string(lr_paramarr_random("checkbox"), "rnd_checkbox");
	 			
	lr_start_transaction("cancel_booking");
	
	web_reg_find("Fail=Found",
		"Text/IC={rnd_flightID}",
		LAST);
	
	lr_save_string(
		lr_paramarr_idx("flightID", atoi(lr_paramarr_random("checkbox"))),
		"rnd_flightID");
	
	web_submit_form("itinerary.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name={rnd_checkbox}", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=55", ENDITEM,
		"Name=removeFlights.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("cancel_booking",LR_AUTO);
	
	
	logout();
	
	}
	
	lr_end_transaction("UC_2_Delete_booking", LR_AUTO);

	return 0;
}