<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>MP3 Player</title>
  <!-- Bootstrap CSS -->
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
  <!-- Font Awesome for icons -->
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css">
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.0/css/all.css"></link>
</head>
<body>

    <form action="" method="POST">
        <button class="btn btn-primary btn-playlist" type="submit" name="neck0do">Góc 0 độ</button>
        <button class="btn btn-primary btn-playlist" type="submit" name="neck45do">Góc 45 độ</button>
        <button class="btn btn-primary btn-playlist" type="submit" name="neck90do">Góc 90 độ</button>
        <button class="btn btn-primary btn-playlist" type="submit" name="neck135do">Góc 135 độ</button>
        <button class="btn btn-primary btn-playlist" type="submit" name="neck180do">Góc 180 độ</button>
		<button  class="btn btn-danger btn-playlist" type="submit" name="stop">Auto</button>


			<p class="text-success"><b>Đầu</b></p>
      <button style="margin-right: 5px;" class="btn btn-success btn-playlist col-sm-3" type="submit" name="head0">Góc 0 </button>

		<button style="margin-right: 5px;" class="btn btn-success btn-playlist col-sm-3" type="submit" name="head45">Góc 45 </button>
		<button style="margin-right: 5px;" class="btn btn-success btn-playlist col-sm-3" type="submit" name="head90">Góc 90 </button>
		<button style="margin-right: 5px;" class="btn btn-success btn-playlist col-sm-3" type="submit" name="head135">Góc 135 </button>
    <button style="margin-right: 5px;" class="btn btn-success btn-playlist col-sm-3" type="submit" name="head180">Góc 180 </button>
      </form>




  <!-- Bootstrap JS -->
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>
</html>



<?php

$server 	= "localhost:3306";	// Change this to correspond with your database port
$username 	= "root";			// Change if use webhost online
$password 	= "";
$DB 		= "robot";			// database name


$update = new mysqli($server, $username, $password, $DB);	// Check database connection
			if ($update->connect_error) {
				die("Connection failed: " . $update->connect_error);
			} 
		

if(isset($_POST['stop']))			
{							
	$sql = "UPDATE head_neck SET neck = '001'";	
	if ($update->query($sql) === TRUE) {	
	} 
}		
			
if(isset($_POST['neck0do']))			//
{	
	$sql = "UPDATE head_neck SET neck = '000'";	
	if ($update->query($sql) === TRUE) {	
	} 
}

if(isset($_POST['neck90do']))		
{						
	$sql = "UPDATE head_neck SET neck = '090'";	
	if ($update->query($sql) === TRUE) {	
	} 
}			

if(isset($_POST['neck45do']))		
{						
	$sql = "UPDATE head_neck SET neck = '045'";	
	if ($update->query($sql) === TRUE) {	
	} 
}			
			
if(isset($_POST['neck135do']))		
{	
	$sql = "UPDATE head_neck SET neck = '135'";
	if ($update->query($sql) === TRUE) {	
	} 	
}
if(isset($_POST['neck180do']))			
{	
	$sql = "UPDATE head_neck SET neck = '180'";	
	if ($update->query($sql) === TRUE) {	
	} 
}
if(isset($_POST['head0']))			
{	
	$sql = "UPDATE head_neck SET head = '000'";	
	if ($update->query($sql) === TRUE) {	
	} 
}	
if(isset($_POST['head45']))			
{	
	$sql = "UPDATE head_neck SET head = '045'";	
	if ($update->query($sql) === TRUE) {	
	} 
}
if(isset($_POST['head90']))			
{	
	$sql = "UPDATE head_neck SET head = '090'";	
	if ($update->query($sql) === TRUE) {	
	} 
}
if(isset($_POST['head135']))			
{	
	$sql = "UPDATE head_neck SET head = '135'";	
	if ($update->query($sql) === TRUE) {	
	} 
}
if(isset($_POST['head180']))			
{	
	$sql = "UPDATE head_neck SET head = '180'";	
	if ($update->query($sql) === TRUE) {	
	} 
}
?>
