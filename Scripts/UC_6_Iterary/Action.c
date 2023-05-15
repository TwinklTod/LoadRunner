Action()
{
	lr_start_transaction("UC_6_Itinerary");
	
	open_homepage();
	
	lr_think_time(5);
	
	login();
	
	click_itinerary();
	
	logout();
	
	lr_end_transaction("UC_6_Itinerary", LR_AUTO);
}
