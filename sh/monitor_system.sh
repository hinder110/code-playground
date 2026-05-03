#!/bin/bash

# 获取CPU使用率
get_cpu_usage() {
    cpu_usage=$(wmic cpu get loadpercentage | grep -Eo '[0-9]+')
    echo "CPU 使用率: $cpu_usage%"
}
# 获取内存使用情况
get_memory_usage() {
    total_memory=$(wmic OS get TotalVisibleMemorySize | grep -Eo '[0-9]+')
    free_memory=$(wmic OS get FreePhysicalMemory | grep -Eo '[0-9]+')
    used_memory=$((total_memory - free_memory))
    memory_usage=$((used_memory * 100 / total_memory))
    echo "内存 使用率: $memory_usage%"
    echo "总内存: $((total_memory / 1024)) MB"
    echo "已用内存: $((used_memory / 1024)) MB"
    echo "空闲内存: $((free_memory / 1024)) MB"
}

# 主循环
while true; do
    clear
    echo "系统资源监控 (按 Ctrl+C 退出)"
    echo "---------------------------------"
    get_cpu_usage
    echo "---------------------------------"
    get_memory_usage
    echo "---------------------------------"
    sleep 2
done