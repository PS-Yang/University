<?php
	$account   = $_GET['account'];
	
	$conn = mysql_connect('127.0.0.1', 'account','password');
	mysql_select_db('system');
	
	
	$sql = mysql_query("UPDATE orders SET doub='0' ,four='0' ,eight='0' ,playground='0', food='0', sounvir='0' WHERE account='{$account}'");
	mysql_query($sql);
	
	echo $account;   
?>
