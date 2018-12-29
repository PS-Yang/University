<?php
	$account = $_GET['account'];
	$money = $_GET['money'];
	
	$conn = mysql_connect('127.0.0.1', 'account','password');
	mysql_select_db('system');
	
	
	$sql = mysql_query("UPDATE member SET money='{$money}' WHERE account='{$account}'");
	mysql_query($sql);
	
?>

