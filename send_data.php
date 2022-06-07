<?php
    $conn = mysqli_connect("localhost", "root", "", "smart-trash-can");
    $capacity = $_GET["capacity"];
    $status = $_GET["status"];

    if ($status) {
        mysqli_query($conn, "UPDATE sensor SET status='$status';");
    } else {
        mysqli_query($conn, "UPDATE sensor SET capacity='$capacity', status='$status';");
    }
?>