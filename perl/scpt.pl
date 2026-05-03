#!/usr/bin/perl
use strict;
use warnings;
use LWP::UserAgent;

print "请输入目标URL: ";
my $url = <STDIN>;
chomp($url);

my $ua = LWP::UserAgent->new;
my $response = $ua->get($url);

if ($response->is_success) {
    print "网页内容:\n" . $response->decoded_content;
} else {
    print "请求失败: " . $response->status_line . "\n";
}