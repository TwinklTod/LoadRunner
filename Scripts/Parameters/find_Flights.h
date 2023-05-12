find_Flights{
lr_start_transaction("Find_Flight");
	
	web_reg_find("Text/IC=Flight departing from <B>{depart_city}</B> to <B>{arrive_city}</B> on <B>{depart_date}<",
		LAST);

	
	web_reg_save_param("outboundFlight",
		"LB/IC=name=\"outboundFlight\" value=\"",
		"RB/IC=\"",
		"ORD=random",
		LAST);
	
	web_reg_save_param("returnFlight",
		"LB/IC=name=\"returnFlight\" value=\"",
		"RB/IC=\"",
		"ORD=random",
		LAST);
	
	
	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart_city}", ENDITEM, 
		"Name=departDate", "Value={depart_date}", ENDITEM, 
		"Name=arrive", "Value={arrive_city}", ENDITEM, 
		"Name=returnDate", "Value={return_date}", ENDITEM, 
		"Name=numPassengers", "Value={count_pass}", ENDITEM,
		"Name=roundtrip", "Value={round_trip}", ENDITEM, 		
		"Name=seatPref", "Value={seat_pref}", ENDITEM,
		"Name=seatType", "Value={seat_type}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=74", ENDITEM, 
		"Name=findFlights.y", "Value=14", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_end_transaction("Find_Flight",LR_AUTO);
	}