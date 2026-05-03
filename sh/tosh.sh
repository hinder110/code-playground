cd /f/code/sh

if [ $? -ne 0 ]; then
    echo "错误：无法切换到 .sh 项目目录！"
    exit 1
fi
echo $"hallow to shell"