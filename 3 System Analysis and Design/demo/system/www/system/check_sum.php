<?php
	$account = $_GET['account'];
	
	$conn = mysql_connect('127.0.0.1', 'account','password');
	mysql_select_db('system');
	
	
	$rs = mysql_query("SELECT money FROM member WHERE account='{$account}'");
	while ( $row = mysql_fetch_array($rs))
	{
		echo $row['money'];
	}
	
?>

