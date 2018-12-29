<?php
	$account   = $_GET['account'];
	
	$conn = mysql_connect('127.0.0.1', 'account','password');
	mysql_select_db('system');
	mysql_query($sql);
	
	$sql = mysql_query("SELECT account,doub,four,eight,playground,food,sounvir FROM orders WHERE account='{$account}'");
	   if($row = mysql_fetch_array($sql))
	  { 
		echo  $row['doub']."¥|".$row['four']."¤K".$row['eight']."¹C".$row['playground']."­¹".$row['food']."¬ö".$row['sounvir'];
	  }
?>
