Action()
{

	lr_start_transaction("UC_0_SignUp");

	lr_start_transaction("open_homepage");

	web_reg_find("Text/IC=If you haven't registered yet, <A href=\"/cgi-bin/login.pl?username=&amp;password=&amp;getInfo=true\" ><B>sign up now</B></A> to get access to all our resources.",
		LAST);

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
	lr_end_transaction("open_homepage", LR_AUTO);

	lr_start_transaction("click_SignUpNow");
	
	web_reg_find("Text/IC=><B>First time registering? Please complete the form below.</B>",
		LAST);

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
	web_reg_find("Text/IC=Thank you, <b>{username}</b>, for registering and welcome to the Web Tours family.",
		LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=passwordConfirm", "Value={password}", ENDITEM, 
		"Name=firstName", "Value={first_Name}", ENDITEM, 
		"Name=lastName", "Value={last_Name}", ENDITEM, 
		"Name=address1", "Value={street}", ENDITEM, 
		"Name=address2", "Value={city}", ENDITEM, 
		"Name=register.x", "Value=56", ENDITEM, 
		"Name=register.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("complete_profile",LR_AUTO);

	lr_start_transaction("click_Continue");
	
	web_reg_find("Text/IC=Welcome, <b>{username}</b>, to the Web Tours reservation pages.",
		LAST);

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
	
	web_reg_find("Text/IC=Welcome to the Web Tours site.",
		LAST);

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
	lr_end_transaction("UC_0_SignUp", LR_AUTO);

	return 0;
}