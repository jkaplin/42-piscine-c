#!/usr/bin/env perl
		use strict;
		use warnings;
		use feature 'say';
		
		my $program = './work/ex04/main';

		


		my $output = `./work/ex04/main`;
		my $expected;
		die "work/ex04/main failed to run: $?" if $?;
	
		$expected = "0x0\nasdf\nzxcv\nuiop\nhjkl\n";

		


		if ($output eq $expected) {
			say 'work/ex04/main good!';
		} else {
			say "!!!! ERROR in work/ex04/main: '$output'";
			say "!!!! EXPECTED: '$expected'" if defined $expected;
		}
	
	