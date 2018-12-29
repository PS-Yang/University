<?php
	$account   = $_GET['account'];
	/*$doub      = $_GET['doub'];
	$four      = $_GET['four'];
	$eight     = $_GET['eight'];
	$playground= $_GET['playground'];
	$food      = $_GET['food'];
	$sounvir   = $_GET['sounvir'];*/
	

	$sql = "INSERT INTO orders (account,doub,four,eight,playground,food,sounvir) VALUES ('{$account}','0','0','0','0','0','0')";
	$conn = mysql_connect('127.0.0.1', 'root','123456');
	mysql_select_db('system');
	mysql_query($sql);
    echo QQ;
?>
