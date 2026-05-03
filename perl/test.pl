print "hallow world";

$x = "hallow world
bash
c
java \n
";

print "$x";

@hinder = ("hinder",1,1,2,3);

print "\@hinder = @hinder[0]\n";

%hinder_hash = ('hash',1,'lash',2,"xash",3);

print "\$hinder_hash{'hash'} = $hinder_hash{'hash'}\n";

print "\$hinder_hash{'xash'} = $hinder_hash{'xash'}\n";

$size = @hinder;

@hinder_3 = @hinder[2..4];

print "$size\n";

print "@hinder_3\n";

print <<EOF;

I like this language;

simple and effictive and proty;

EOF

print "file"  . __FILE__."\n";

print "line"  .__LINE__."\n";

print "package"  . __PACKAGE__ ."\n";

@core = qw/
google
bing
baidu
/;

print "did you like $core[0] or $core[1]?\n";

print "@core\n";

$max_index = $#hinder;

print "$max_index\n";

@resort = sort(@hallow);

print "@resort\n";

# 定义数组
@sites = qw(google taobao runoob facebook);
print "排序前: @sites\n";
 
# 对数组进行排序
@sites = sort(@sites);
print "排序后: @sites\n";

$name = "菜鸟教程";
$favorite = 10;    
$have = ($favorite>90)?"1":"0";
print "$name - $have\n";

foreach $a (@sites){
    print "$a\n";
}

$timenow = localtime();

print "time : $localtime\n";

sub hellowk{
    print "hallow world!!!\n";
}
hellowk();

sub PeintList{
    my @list = @_;
    print "list is :@list\n";
}

@a=(1,2,3,4,5,6);
@b=(41,22,"hollow!");
PeintList(@a,@b);

sub Average{
    $n=scalar(@_);
    $sum=0;
    foreach $item(@_){
        $sum+=$item;
    }
    $average = $sum /$n;
    print '传入的参数为 : ',"@_\n";           # 打印整个数组
    print "第一个参数值为 : $_[0]\n";         # 打印第一个参数
    print "传入参数的平均值为 :  $average\n";  # 打印平均值
}
Average(12,13,15,16,19);

sub add_a_b{
    $_[0]+$_[1];
    #@_
}
print add_a_b(5,6);

$string = "Hello, World!";
 
sub PrintRunoob{
   # PrintHello 函数私有变量
   local $string;
   $string = "Hello, Runoob!";
   # 子程序调用的子程序
   PrintMe();
   print "PrintRunoob 函数内字符串值：$string\n";
}
sub PrintMe{
   print "PrintMe 函数内字符串值：$string\n";
}
 
sub PrintHello{
   print "PrintHello 函数内字符串值：$string\n";
}
 
# 函数调用
PrintRunoob();
PrintHello();
print "函数外部字符串值：$string\n";

my $av = [
    [1, 4, 6],
    [3, 4, 5],
    [1, 9, 5],
];

# Dereference the array of arrays
my @X = @$av;

# Iterate over each sub-array in @X
foreach my $a (@X) {
    # $a is a reference to an array, so we need to dereference it
    print join(", ", @$a) . "\n";
}
