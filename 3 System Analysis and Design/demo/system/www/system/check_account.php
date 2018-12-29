<?php
	$id = $_GET['id'];
	
	$conn = mysql_connect('127.0.0.1', 'account','password');
	mysql_select_db('system');
	
	$result="false";
	$rs = mysql_query("SELECT account FROM member");
	while ( $row = mysql_fetch_array($rs))
	{
		if ($row['account']==$id)
		$result="true";
	   
	}
	echo $result;
?>

