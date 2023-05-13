Action()
{
	lr_start_transaction("UC_2_Delete_booking");
	
	open_homepage();

	login();
	
	web_reg_find("SaveCount=NoBooking",
		"Text/IC=<H3>No flights have been reserved.</H3>",
		LAST);

	click_itinerary();

	                
	if (atoi(lr_eval_string("{NoBooking}")) == 1) {
	    logout();
	    }
	else {
	 			
	lr_start_transaction("cancel_booking");
	
	web_reg_find("Fail=Found",
		"Text/IC={flightID}",
		LAST);
	
	web_submit_form("itinerary.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=55", ENDITEM,
		"Name=removeFlights.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("cancel_booking",LR_AUTO);
	logout();
	    }
	lr_end_transaction("UC_2_Delete_booking", LR_AUTO);

	return 0;
}