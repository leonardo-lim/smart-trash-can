<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Smart Trash Can</title>
    <link rel="stylesheet" href="style.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Atkinson+Hyperlegible&display=swap" rel="stylesheet">
</head>
<body>
    <div class="container my-lg-0 my-5">
        <div class="row min-vh-100 pt-5 d-flex align-items-center text-black">
            <div class="col-lg-6 col-12">
                <img src="img/throw_away.svg" class="w-100" alt="Throw Away">
            </div>
            <div class="col-lg-6 col-12">
                <h1 class="text-white text-huge">Smart Trash Can</h1>
                <hr class="text-white">

                <?php include('fetch.php') ?>

                <h5 class="text-white">Capacity</h5>

                <div class="bar w-100 m-auto">
                    <div class="percent-bar" style="width: <?= $capacity . '%' ?>;">
                        <span id="percent-bar-text"><?= $capacity . '%' ?></span>
                    </div>
                </div>

                <br>

                <h5 class="text-white mb-3">Lid Status</h5>

                <?php if ($status) { ?>
                    <h5 class="status bg-success text-center text-white w-100 p-3"><?= 'Opened' ?></h5>
                <?php } else { ?>
                    <h5 class="status bg-danger text-center text-white w-100 p-3"><?= 'Closed' ?></h5>
                <?php } ?>
            </div>
        </div>
    </div>

    <script>
        window.setInterval(() => {
            window.location.reload();
        }, 1000);
    </script>
</body>
</html>