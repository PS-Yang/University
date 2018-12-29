<?php
	$id = $_GET['id'];
	
	$conn = mysql_connect('127.0.0.1', 'account','password');
	mysql_select_db('system');
	
	
	$rs = mysql_query("SELECT pro FROM member WHERE account='{$account}'");
	while ( $row = mysql_fetch_array($rs))
	{
		if ($row['pro']=="0")
		$result="0";
	    if($row['pro']=="1")
	    $result="1";
	}
	echo $result;
?>

