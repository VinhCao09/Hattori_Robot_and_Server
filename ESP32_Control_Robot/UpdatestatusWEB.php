<html>
<head> 

 
<body>
<form action="" method="POST">
<div class="wrapper">
<h1>vinhcao</h1>
<button class="button btnon" type="submit" name = "ON" >ON</button><br>	
<button class="button btnoff"  type="submit" name = "OFF" >OFF</button>
</div>

</body>
	
</html>


<?php

$server 	= "localhost:3306";	// Change this to correspond with your database port
$username 	= "root";			// Change if use webhost online
$password 	= "";
$DB 		= "qlda";			// database name


$update = new mysqli($server, $username, $password, $DB);	// Check database connection
			if ($update->connect_error) {
				die("Connection failed: " . $update->connect_error);
			} 
			
			
if(isset($_POST['ON']))			// If press ON
{	
			
			$sql = "UPDATE status SET status = 1";	// Update present status to database
			// If don't put this If , we can't change the value in database
			if ($update->query($sql) === TRUE) {	// Because it's been a long time , so i forgot
				//$_GET[] = 1;						// why i have to put this line but it still run when it's commented
			} 
}

if(isset($_POST['OFF']))		// If press OFF
{					
					
			$sql = "UPDATE status SET status = 0";	// Update present status to database
			// Echo "0" , equivalent with send data to App to toast OFF
			if ($update->query($sql) === TRUE) {	// Because it's been a long time , so i forgot
				//$_GET[] = 0;						// why i have to put this line but it still run when it's commented
			} 
	
	
}			
			

	
?>
