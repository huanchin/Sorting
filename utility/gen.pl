#!/usr/bin/perl

$number = $ARGV[0];
$scope = $ARGV[1];
open(OUTPUT,"> $number.ac.in");

print OUTPUT "# $number data points\n";
print OUTPUT "# index number\n";

$count = 0;
while($count < $number) {
    $data = int(rand($scope));
    print OUTPUT "$count $data\n";
    $count++;
}
close(OUTPUT);
