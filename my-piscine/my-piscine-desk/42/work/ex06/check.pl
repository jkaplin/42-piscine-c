#!/usr/bin/env perl
		use strict;
		use warnings;
		use feature 'say';
		
		my $program = './work/ex06/main';

		


		my $output = `./work/ex06/main`;
		my $expected;
		die "work/ex06/main failed to run: $?" if $?;
	
		$expected = "is null? 0x0\naddress good? 1,1,1\n";

		


		if ($output eq $expected) {
			say 'work/ex06/main good!';
		} else {
			say "!!!! ERROR in work/ex06/main: '$output'";
			say "!!!! EXPECTED: '$expected'" if defined $expected;
		}
	
	