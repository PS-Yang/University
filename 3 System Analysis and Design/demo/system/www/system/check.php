<?php
	$id = $_GET['id'];
	$pass = $_GET['password'];

    $conn = mysql_connect('127.0.0.1', 'account','password');
	mysql_select_db('system');
	
	$result="false";
	$rs = mysql_query("SELECT account,password FROM member");
	while ( $row = mysql_fetch_array($rs))
	{
		if ($row['account']==$id && $row['password']==$pass)
		$result="true";
	   
	}
	echo $result;
?>