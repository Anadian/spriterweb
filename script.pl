#!/opt/local/bin/perl
use strict;
use warnings;

use IO::All;
use autodie;

sub check_visible{
	if($_ =~ /^[^.]/){
		return true;
	else{
		return false;
	}
}
	

print("This script is running.\n");
print("Getting source list.\n");
my @sourcefiles = io->dir->filter(check_visible)->all;
for(my $i = 0; $i < @sourcefiles; $i++){
	print($i, ":", @sourcefiles[$i]->filename, "\n");
}
print("Getting header list.\n");
my @headerfiles = io->dir('INCLUDE')->all;