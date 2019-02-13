#!/usr/bin/env perl
		use strict;
		use warnings;
		use feature 'say';
		
		my $program = './work/ex02/main';

		


		my $output = `./work/ex02/main`;
		my $expected;
		die "work/ex02/main failed to run: $?" if $?;
	
		$expected = "asdf,\nzxcv,qwer,asdf,\nhjkl,uiop,\n";

		


		if ($output eq $expected) {
			say 'work/ex02/main good!';
		} else {
			say "!!!! ERROR in work/ex02/main: '$output'";
			say "!!!! EXPECTED: '$expected'" if defined $expected;
		}
	
	