<?php
	$id = $_GET['id'];
	$pass = $_GET['password'];
	$name = $_GET['name'];
	$mail= $_GET['mail'];
	$pro= $_GET['pro'];
	
	$sql = "INSERT INTO member(account,password,name,mail,pro,money) VALUES ('{$id}','{$pass}','{$name}','{$mail}','{$pro}',10000)";
	
	$conn = mysql_connect('127.0.0.1', 'account','password');
	mysql_select_db('system');
	mysql_query($sql);
?>
