Action()
{

	lr_start_transaction("UC_1_Booking");
	
	open_homepage();
	
	lr_think_time(5);
	
	login();
	
	click_flight();
	
	lr_think_time(5);
	
	find_flights();
		
	choose_flight();
	
	lr_think_time(5);

	lr_start_transaction("Payment_Details");
	
	web_reg_find("Text/IC=<B>Thank you for booking through Web Tours.</B>",
		LAST);
	
	web_reg_find("Text/IC=leaves {depart_city}  for {arrive_city}.<br>",
		LAST);
		
	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		
		"Name=firstName", "Value={first_Name}", ENDITEM, 
		"Name=lastName", "Value={last_Name}", ENDITEM, 
		"Name=address1", "Value={street}", ENDITEM, 
		"Name=address2", "Value={city}", ENDITEM,
		"Name=pass1", "Value={pass_Name}", ENDITEM,
		"Name=pass2", "Value={pass_Name}", ENDITEM,
		"Name=pass3", "Value={pass_Name}", ENDITEM,		
		"Name=creditCard", "Value={credit_card}", ENDITEM, 
		"Name=expDate", "Value={exp_date}", ENDITEM, 
		"Name=oldCCOption", "Value=on", ENDITEM, 
		"Name=numPassengers", "Value={count_pass}", ENDITEM, 
		"Name=seatType", "Value={seat_type}", ENDITEM, 
		"Name=seatPref", "Value={seat_pref}", ENDITEM, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value={returnFlight}", ENDITEM,		 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=48", ENDITEM, 
		"Name=buyFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("Payment_Details",LR_AUTO);
		
	click_itinerary();
	
	lr_end_transaction("UC_1_Booking", LR_AUTO);

	return 0;
}