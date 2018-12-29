<?php 

$a = @$_POST["a"];
$b = @$_POST["b"];
$s = $a+$b;
//echo "<span class=\"style2\">" . $a . "</span> + <span class=\"style2\">" . $b . "</span> = <span class=\"style1\">" . $s."</span>";

if($a>$b)
$msg="A大於B";
else if($a==$b)
$msg="A等於B";
else
$msg="A小於B";


?> 
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>無標題文件</title>
<style type="text/css">
<!--
.style1 {
	color: #FF0000;
	font-size: 20px;
}
.style2 {color: #0000FF}
-->
</style>
</head>


<body>
<form id="form1" name="form1" method="post" action="">
  A=
  <label>
  <input type="text" name="a" id="a" />
  <br />
  B= 
  <input type="text" name="b" id="b" /> 
  <br />
  <input type="submit" name="button" id="button" value="送出" />
  </label>
</form>

<p><span class="style2"> 
  <?=$a?> 
  </span>+<span class="style2"> 
  <?=$b?> 
  </span>=<span class="style1"> 
  <?=$s?>
</span></p>
<p>
<span class="style2"> 
  <?=$msg?>   
</p>
<p>
<?php 
for($i=$a ; $i<=$b ;$i++)
{
 echo "<span class=\"style2\">".$i." </span>";
}
?>

</p>
</body>
</html>
