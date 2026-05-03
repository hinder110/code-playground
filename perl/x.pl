#!/usr/bin/perl
use strict;
use warnings;
use LWP::UserAgent;
use JSON;
use URI;

print "url:";
my $url = <STDIN>;
chomp($url);

my $ua = LMP::UserAgent->new();
my $response = $ua->get($ual);

if($response->is_success){
    my $content = $response->decoded_content;
    print "date:\n$content\n";
}else{
    print "no:".$response->status_line."\n";
    
}

# DeepSeek API 配置
my $api_key = "sk-cb13a64145c54e0fa4db016b0677ff9f";  # 替换为你的 DeepSeek API Key
my $base_url = "https://api.deepseek.com/v1";  # DeepSeek API 的基础 URL

# 创建 UserAgent 对象
my $ua = LWP::UserAgent->new;

# 设置请求头
my $headers = {
    'Content-Type'  => 'application/json',
    'Authorization' => "Bearer $api_key",
};

# 构造请求体
my $request_body = {
    model    => "deepseek-chat",  # 模型名称
    messages => [
        { role => "system", content => "You are a helpful assistant" },  # 系统消息
        { role => "user",   content => "Hello" },  # 用户消息
    ],
    stream => \0,  # 禁用流式响应
};

# 发送 POST 请求
my $response = $ua->post(
    "$base_url/chat/completions",  # API 端点
    headers => $headers,
    Content => encode_json($request_body),
);

# 处理响应
if ($response->is_success) {
    my $response_data = decode_json($response->content);
    my $assistant_reply = $response_data->{choices}[0]{message}{content};  # 提取助手回复
    print "DeepSeek: $assistant_reply\n";
} else {
    print "请求失败: " . $response->status_line . "\n";
    print "响应内容: " . $response->content . "\n";  # 打印错误详情
}