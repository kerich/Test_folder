#! /usr/bin/perl
use strict;
use warnings;

#################################################
### set count down (sec) for shutdown windows ###
#################################################
my $passed_sec = 1*60; # 1 min
#################################################



sub count_down_by_sec {
    my $num_arguments_passed = @_;
    if ($num_arguments_passed != 1) {
        print "pass number of argument to \"count_down\" is not equal 1\n";
        exit;
    }
    my ($sec) = @_;
    while ($sec) {
        print "$sec\n";
        sleep 1;
        $sec--;
    }
}

count_down_by_sec($passed_sec);

#Below line is reboot windows (execute the script on windows).
#system('shutdown /r');


#Below line is shutdown windows (execute the script on windows).
system('shutdown /s');
