choose_Flight{
lr_start_transaction("Choose_Flight");
	
	web_reg_find("Text/IC=<b>Payment Details</font></b>",
		LAST);

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=returnFlight", "Value={returnFlight}", ENDITEM,		
		"Name=numPassengers", "Value={countpass}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=49", ENDITEM, 
		"Name=reserveFlights.y", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("Choose_Flight",LR_AUTO);
	}