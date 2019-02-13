#!/usr/bin/env perl
		use strict;
		use warnings;
		use feature 'say';
		
		my $program = './work/ex07/main';

		


		my $output = `./work/ex07/main`;
		my $expected;
		die "work/ex07/main failed to run: $?" if $?;
	
		$expected = "0x0\n0x0\n0x0\nasdf\n0x0\nasdf\nqwer\nzxcv\nuiop\nhjkl\n0x0\n0x0\n";

		


		if ($output eq $expected) {
			say 'work/ex07/main good!';
		} else {
			say "!!!! ERROR in work/ex07/main: '$output'";
			say "!!!! EXPECTED: '$expected'" if defined $expected;
		}
	
	