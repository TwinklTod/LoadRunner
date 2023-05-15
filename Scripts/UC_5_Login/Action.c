Action()
{
	lr_start_transaction("UC_5_Login");
	
	open_homepage();
	
	lr_think_time(5);
	
	login();
	
	logout();
	
	lr_end_transaction("UC_5_Login", LR_AUTO);

	return 0;
}