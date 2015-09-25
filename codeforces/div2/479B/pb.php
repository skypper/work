<?php
$input = explode(" ", trim(fgets(STDIN)));
$n = $input[0];
$k = $input[1];
$input = explode(" ", trim(fgets(STDIN)));
for ($i = 0; $i < $n; $i++) {
	$a[$i][0] = $input[$i];
	$a[$i][1] = $i + 1;
}
$m = 0;
$j = 0;
for ($i = 0; $i < $k; $i++) {
	sort($a);
	if ($a[$n - 1][0] - $a[0][0] > 1) {
		$a[$n - 1][0]--;
		$a[0][0]++;
		$b[$j][0] = $a[$n - 1][1];
		$b[$j][1] = $a[0][1];
		$j++;
	}
}
sort($a);
printf("%d %d\n", $a[$n - 1][0] - $a[0][0], $j);
for ($i = 0; $i < $j; $i++) {
	printf("%d %d\n", $b[$i][0], $b[$i][1]);
}
?>
