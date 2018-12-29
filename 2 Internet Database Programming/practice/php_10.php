<?php
  if (isset($_POST["height"]) && isset($_POST["weight"]))
  {
    $h = $_POST["height"];
    $w = $_POST["weight"];
    $bmi=(float)(10000*$w)/($h*$h);
    $idw=(float)$h*$h*0.0022;
    if($bmi>=35)
      $message="重度肥胖";
    else if($bmi>=30)
      $message="中度肥胖";
    else if($bmi>=27)
      $message="輕度肥胖";
    else if($bmi>=24)
      $message="過重";
    else if($bmi>=18.5)
      $message="正常範圍";
    else 
      $message="體重過輕";
  }
  
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>無標題文件</title>
<style type="text/css">
<!--
.style1 {
	color: #0033FF
}
-->
</style>
</head>

<body>
<form id="form1" name="form1" method="post" action="">
  <table width="300" border="0">
    <tr>
      <td><div align="center"></div></td>
      <td><div align="center">BMI指數計算</div></td>
    </tr>
    <tr>
      <td><div align="center">身高(公分)</div></td>
      <td><div align="center">
        <label>
        <input type="text" name="height" id="height" />
        </label>
      </div></td>
    </tr>
    <tr>
      <td><div align="center">體重(公斤)</div></td>
      <td><div align="center">
        <label>
        <input type="text" name="weight" id="weight" />
        </label>
      </div></td>
    </tr>
    <tr>
      <td><div align="left"></div></td>
      <td><label>
        <div align="center">
          <input type="submit" name="button" id="button" value="開始診斷" />
        </div>
      </label></td>
    </tr>
        
     <tr>
      <td>&nbsp;&nbsp;
      <?php if(isset($_POST["height"]) && isset($_POST["weight"]))
       echo "指數"
      ?>      
      </div></td>
      <td><div class="style1">&nbsp;&nbsp;&nbsp;&nbsp;
      <?php if(isset($_POST["height"]) && isset($_POST["weight"]))
       echo $bmi
      ?> 
      </div></td>
    </tr>
    
    <tr>
      <td>&nbsp;&nbsp;
      <?php if(isset($_POST["height"]) && isset($_POST["weight"]))
       echo "診斷結果"
	   ?> 
      </div></td>
      <td><div  class="style1">&nbsp;&nbsp;&nbsp;&nbsp;
      <?php if(isset($_POST["height"]) && isset($_POST["weight"]))
       echo $message;
	   ?> 
      </div></td>
    </tr>
    
    <tr>
      <td>&nbsp;&nbsp;
      <?php if(isset($_POST["height"]) && isset($_POST["weight"]))
       echo "理想體重" 
	   ?> 
      </div></td>
      <td><div  class="style1">&nbsp;&nbsp;&nbsp;&nbsp;
      <?php if(isset($_POST["height"]) && isset($_POST["weight"]))
       echo $idw."公斤";
	   ?> 
      </div></td>
    </tr>
  
  </table>
 </form>
</body>
</html>
