Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../favicon.ico", "Referer=", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("click_SignUpNow");

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_SignUpNow",LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("complete_profile");

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=RobbStark", ENDITEM, 
		"Name=password", "Value=Wolf", ENDITEM, 
		"Name=passwordConfirm", "Value=Wolf", ENDITEM, 
		"Name=firstName", "Value=Robb", ENDITEM, 
		"Name=lastName", "Value=Stark", ENDITEM, 
		"Name=address1", "Value=Winterfell", ENDITEM, 
		"Name=address2", "Value=The North", ENDITEM, 
		"Name=register.x", "Value=56", ENDITEM, 
		"Name=register.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("complete_profile",LR_AUTO);

	lr_start_transaction("click_Continue");

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_Continue",LR_AUTO);

	lr_start_transaction("Logout");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	return 0;
}