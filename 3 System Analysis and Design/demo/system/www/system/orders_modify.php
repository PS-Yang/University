<?php
	$account   = $_GET['account'];
	$doub      = $_GET['doub'];
	$four      = $_GET['four'];
	$eight     = $_GET['eight'];
	$playground= $_GET['playground'];
	$food      = $_GET['food'];
	$sounvir   = $_GET['sounvir'];
	
	
	$conn = mysql_connect('127.0.0.1', 'account','password');
	mysql_select_db('system');
	$rs =mysql_query("SELECT doub,four,eight,playground,food,sounvir FROM orders WHERE account='{$account}'");
	while ( $row = mysql_fetch_array($rs))
	{
		$doub=$doub+$row['doub'];
		$four=$four+$row['four'];
		$eight=$eight+$row['eight'];
		$playground=$playground+$row['playground'];
		$food=$food+$row['food'];
		$sounvir=$sounvir+$row['sounvir'];
	   
	}
	
	
	

	$sql =mysql_query(" UPDATE orders SET doub='{$doub}' ,four='{$four}' ,eight='{$eight}' ,playground='{$playground}', food='{$food}', sounvir='{$sounvir}' WHERE account='{$account}'");
	mysql_query($sql);
    echo modify;
?>
