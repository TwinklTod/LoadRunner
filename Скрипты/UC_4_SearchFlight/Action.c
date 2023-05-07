Action()
{
	lr_start_transaction("UC_4_SearchFlight");
	open_homepage();
	login();
	click_Flights();
	find_Flights();
	choose_Flights();
	logout();
	lr_end_transaction("UC_4_SearchFlight", LR_AUTO);
}
