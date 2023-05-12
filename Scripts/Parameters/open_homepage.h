open_homepage{
	lr_start_transaction("open_homepage");
	
	web_reg_find("Text/IC=Welcome to the Web Tours site.",
		LAST);
	

/*Correlation comment - Do not change!  Original value='136348.65654111HAVDtDtpAcAiDDDDtcAiApzAtVcf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
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
		
	lr_end_transaction("open_homepage", LR_AUTO);
}