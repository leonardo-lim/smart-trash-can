<?php
    $conn = mysqli_connect("localhost", "root", "", "smart-trash-can");
    $sql = mysqli_query($conn, "SELECT * FROM sensor");
    $data = mysqli_fetch_array($sql);
    $capacity = $data["capacity"];
    $status = $data["status"];
?>