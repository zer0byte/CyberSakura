<html>
<head>
	<title>level1</title>
    <link rel='stylesheet' href='style.css' type='text/css'>
</head>
<body>
	<?php
		require 'flag.php';

		if (isset($_GET['name']) and isset($_GET['password'])) {
			if ($_GET['name'] == $_GET['password'])
				print 'Your password can not be your name.';
			else if (sha1($_GET['name']) === sha1($_GET['password']))
			  die('Flag: '.$flag);
			else
				print '<p class="alert">Invalid password.</p>';
		}
	?>

	<section class="login">
		<div class="title">
			<a href="./index.txt">Level 1</a>
		</div>

		<form method="get">
			<input type="text" required name="name" placeholder="Name"/><br/>
			<input type="text" required name="password" placeholder="Password" /><br/>
			<input type="submit"/>
		</form>
	</section>
</body>
</html>