Action()
{
	lr_start_transaction("UC_4_SearchFlight");
	open_homepage();
	
	lr_think_time(5);
	
	login();
	
	click_flight();
	
	lr_think_time(5);
	
	find_flights();
	
	choose_flight();
	
	logout();
	
	lr_end_transaction("UC_4_SearchFlight", LR_AUTO);
}
