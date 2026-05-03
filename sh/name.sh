#!/bin/bash

# 提示用户输入名字
read -p "请输入文章的名字: " post_name

# 检查输入是否为空
if [ -z "$post_name" ]; then
    echo "错误：名字不能为空！"
    exit 1
fi

# 切换到 Hexo 项目目录
cd /f/Hexo-Blog/blog-demo

# 检查是否切换成功
if [ $? -ne 0 ]; then
    echo "错误：无法切换到 Hexo 项目目录！"
    exit 1
fi

# 执行 hexo new 命令
hexo new "$post_name"

# 检查命令是否成功执行
if [ $? -eq 0 ]; then
    echo "文章 '$post_name' 创建成功！"
else
    echo "文章创建失败，请检查 hexo 是否安装并配置正确。"
fi