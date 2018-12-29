<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>乘法運算</title>
<style type="text/css">
<!--
.style3 {color: #3333FF}
-->
</style>
</head>

<body>
<form id="form1" name="form1" method="post" action="">
  請輸入一個數字：
  <label>
  <input type="text" name="num" id="num" />
  <input type="submit" name="button" id="button" value="送出" />
  </label>
  <table width="300" border="1">
  <?php
  $n = @$_POST["num"];
   for($i=1;$i<=9;$i++)
   {
     $num=$n*$i;
    echo"<tr><td><div align=\"center\">".$n."</td><td><div align=\"center\">".$i."</td><td bgcolor=\"#FF99FF\"><div align=\"center\">    <span class=\"style3\">".$num."</td></tr>";
   }
  
  ?>
  </table>
</form>