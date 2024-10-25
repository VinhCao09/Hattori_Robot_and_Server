<?php

$server = "localhost:3306";    // Change this to correspond with your database port
$username = "root";            // Change if use webhost online
$password = "";
$DB = "robot";                 // Database name

$conn = new mysqli($server, $username, $password, $DB);    // Check database connection
if ($conn->connect_error) 
{
    die("Connection failed: " . $conn->connect_error);
}

$query = "SELECT neck, head FROM head_neck";    // Select data from table "status_neck"
$result = $conn->query($query);

while($row = $result->fetch_assoc()) 
{
    echo "neck:" . $row["neck"] . "head:" . $row["head"];    // Echo data , equivalent with send data to esp
}

// while($row = $result->fetch_assoc()) 
// {
//     echo $row["neck"];    // Echo data , equivalent with send data to esp
// }

