Action()
{
	lr_start_transaction("UC_4_SearchFlight");
	open_homepage();
	login();
	click_flight();
	find_flights();
	choose_flight();
	logout();
	lr_end_transaction("UC_4_SearchFlight", LR_AUTO);
}
