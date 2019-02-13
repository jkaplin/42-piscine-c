#!/usr/bin/env perl
		use strict;
		use warnings;
		use feature 'say';
		
		my $program = './work/ex00/main';

		


		my $output = `./work/ex00/main`;
		my $expected;
		die "work/ex00/main failed to run: $?" if $?;
	
		$expected = "asdf\n0x0\n";

		


		if ($output eq $expected) {
			say 'work/ex00/main good!';
		} else {
			say "!!!! ERROR in work/ex00/main: '$output'";
			say "!!!! EXPECTED: '$expected'" if defined $expected;
		}
	
	