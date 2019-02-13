#!/usr/bin/env perl
		use strict;
		use warnings;
		use feature 'say';
		
		my $program = './work/ex05/main';

		

my %tests;

		%tests = (
	"$program" => "$program,\n",
	"$program asdf" => "asdf,$program,\n",
	"$program asdf qwer" => "qwer,asdf,$program,\n",
	"$program asdf qwer zxcv" => "zxcv,qwer,asdf,$program,\n",
	"$program ''" => ",$program,\n",
	"$program 15 '' 25" => "25,,15,$program,\n",
	"$program wat" => "wat,$program,\n",
);

		


		my $errors = 0;
		foreach my $test (sort keys %tests) {
			my $output = `$test`;
			my $expected = $tests{$test};
			if ($output ne $expected) {
				say "!!!! ERROR in work/ex05/main test `$test`: '$output'";
				say "!!!! EXPECTED: '$expected'" if defined $expected;
				$errors++;
			}
			# else { say "debug good: $output"; }
		}
		if ($errors == 0) {
			say 'work/ex05/main good!';
		}
	
	