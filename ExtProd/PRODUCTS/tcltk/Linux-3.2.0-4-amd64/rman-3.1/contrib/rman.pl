#!/usr/local/bin/perl
# Copyright 1994 Alexander Gagin (gagin@cvxct0.jinr.dubna.su)
# http://www.jinr.dubna.su/~gagin
# CGI form interface to RosettaMan program, which is available as
# ftp://ftp.cs.berkeley.edu:/ucb/people/phelps/tcltk/rman.tar.Z
# The most recent version of this program available as
# http://thsun1.jinr.dubna.su/~gagin/rman.pl
#
# $Id: rman.pl,v 1.3 1994/08/18 10:30:27 gagin Exp $
#---------------------------------------------------------------------
# 	Copyright conditions:
# Permission to copy, distribute and use this software as part of any 
# educational, research and non-profit organization's WWW-server, 
# without fee, and without a written agreement is hereby granted, 
# provided that the above copyright notice and this paragraph appear 
# in all copies.
# This software comes with no warranty, express or implied, but with 
# the hope that someone may find it useful.
# Comments, improvements and suggestions are welcomed.
#---------------------------------------------------------------------
# Request form: rman.pl?topic=SOMETOPIC&section=SECTION[&keyword=on]
# SOMETOPIC is man topic
# For SunOS and Linux SECTION is one of follows:
#			    all			or	nothing, or anything,
#							doesn't containing
#							"&keyword=on" text
#			    user+commands	or	1
#			    system+calls	or	2
#			    subroutines		or	3
#			    devices		or	4
#			    file+formats	or	5
#			    games		or	6
#			    miscellanious	or	7
#			    sys.+admin.		or	8
# If &keyword=on absent, I assume no keywprd search. If it present,
# SECTION don't make any sense.	
# Program was "Quick'n'Dirty", so here can be unefficient and stupid 
# code.
# Program was developed for NCSA httpd 1.3, working on SunOS 4.1.1
#---------------------------------------------------------------------
$ENV{'MANPATH'}='/usr/man:/usr/share/man:/usr/local/man:/usr/local/gnu/man';
$ENV{'PATH'}='/usr/bin:/usr/local/bin:/usr/local/gnu/bin';
# Stuff to change 
# path to man program
$man='/usr/bin/man';
# path to RosettaMan program. "-b" is not nessesary
$rman='/usr/local/bin/rman -b -f html';
# URL to this program
$rmanpl='http://forrest.cso.uiuc.edu/cgi-bin/rman.cgi';
# First part of title. Will be smth like "Man page on man(1)"
$manon='Man page on';
# if man produced number of lines less then follows, 
# I assume that request failed
#$emptyman=5;
$emptyman=0;
# tail of every produced html document
$tail="<HR><A HREF=http://forrest.cso.uiuc.edu/>Back</a> to Forrest's homepage.
<p><A HREF=http://forrest.cso.uiuc.edu/hp_project/>Back</a> to HP Special 
Project Page\n <p> <a href=http://forrest.cso.uiuc.edu/scripts/rman.cgi.txt>See the code</a> for this page";
# temporary file prefix
$tmp='/tmp/rman.pl_tmp';
# end changable things
#----------------------------------------------------------------------
$form='
<center><h1>HP-UX 10.10 Man Page Gateway</h1></center> <hr> <h1>Select which man page you want to see:</h1> <FORM METHOD="GET"> Search for
<INPUT SIZE=10 NAME="topic"> in
<SELECT NAME="section"> <OPTION> all
<OPTION>user commands 1
<OPTION>system admin. 1m
<OPTION>system calls 2
<OPTION>library functions 3
<OPTION>file formats 4
<OPTION>miscellaneous 5
<OPTION>devices 7
<OPTION>glossary 9
</SELECT> section(s).
<P><INPUT TYPE="checkbox" NAME="keyword">Search only for keyword
(section will be ignored then)
<P><INPUT TYPE="submit" VALUE="Do search"> <INPUT TYPE="reset" VALUE="Clear Form"> </FORM> ';
$type="Content-type: text/html\n\n";
$string=$ENV{QUERY_STRING};
if($string eq ""){print $type;
                  print "<title>Which man page do you want to see?</title>\n";
                  print $form;
                  print $tail;
		  exit;}
if($string =~ /topic=(\S*)&section=(\S*)/)
 {
 $topic=$1;
 if ($topic eq "")
	{
	print $type;
	print "<title>Topic for man search needed</title>\n";
	print "<strong>Request failed:</strong> <code>Topic for man search needed</code><hr>\n";
	print $form;
	print $tail;
	exit;
	}
 if ($2=~/(\S*)&keyword=on/)
	{
	open(TMPHTML,"$man -k $topic 2>/dev/null |") || die "can't open pipe \"$man -k $topic |\": $!\n";
	print $type;
	print "<title>Keyword search results for $topic</title>\n";
	print "<h1>Keyword search results for $topic</h1>\n";
        while(<TMPHTML>)
		{
		if (/^(.+) \((\S+)\)\s+- (.+)$/) {@topics=split(/, /,$1); 
                		                  $section=$2; 
                                		  print "<h2>$3:</h2>\n";
                                 		  print "<UL>\n";
                                 		  for $topic (@topics)
                                        		{
                                       			 print "<li><A HREF=\"$rmanpl?topic=$topic&section=$section\">$topic($section)</a>\n";
		                                        }                                  
						  print "</UL>\n";
						 }
		}
	print "<hr>\n";
	print $tail;
	exit;
	}
 if ($2 eq "user+commands+1"){$section=1;}
 elsif ($2 eq "1"){$section=1;}
 #elsif ($2 eq "system+admin.+1m"){$section='1m';}
 #elsif ($2 eq "1m"){$section=1m;}
 elsif ($2 eq "system+calls+2"){$section=2;}
 elsif ($2 eq "2"){$section=2;}
 elsif ($2 eq "library+functions+3"){$section=3;}
 elsif ($2 eq "3"){$section=3;}
 elsif ($2 eq "file+formats+4"){$section=4;}
 elsif ($2 eq "4"){$section=4;}
 elsif ($2 eq "miscellaneous+5"){$section=5;}
 elsif ($2 eq "5"){$section=5;} 
 elsif ($2 eq "devices+7"){$section=7;}
 elsif ($2 eq "7"){$section=7;}
 elsif ($2 eq "glossary+9"){$section=9;}
 elsif ($2 eq "9"){$section=9;}
 else {$string=$topic;}
 if(defined($section)){$string="$section $topic";}
 }
for ($i=0;-e "$tmp$i";$i++){;}
system("$man $string 2>/dev/null 1> $tmp$i");
open(TMPHTML,"<$tmp$i") || die "$rmanpl: can't open $tmp$i: $!\n";
$counter=0;
while(<TMPHTML>){$counter++;}
close TMPHTML;
if ($counter < $emptyman) 
	{print $type;
 	print"<strong>Request failed:</strong>\n<code>";
	open(TMPHTML,"<$tmp$i") || die "$rmanpl: can't open $tmp$i: $!\n";
	while(<TMPHTML>){print;}
	print "</code><hr>\n";
	print $form; 
	print $tail;
	unlink "$tmp$i";
	exit;}
for ($j=0;-e "$tmp$j";$j++){;}
if (defined($section))
   {system("$rman -r \"$rmanpl?topic=%s&section=%s\" -l \"$manon $topic($section)\"< $tmp$i > $tmp$j");}
   else {system("$rman -r \"$rmanpl?topic=%s&section=%s\" -l \"$manon $string\"< $tmp$i > $tmp$j");}
print $type; 
open(TMPHTML,"<$tmp$j") || die "$rmanpl: can't open $tmp$j: $!\n";
while(<TMPHTML>){print;}
print "<hr>\n";
print $tail;
unlink "$tmp$i";
unlink "$tmp$j";
