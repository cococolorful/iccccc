#!/bin/bash

# 函数定义：print_color
print_color() {
    printf "$1$2$RESET\n"
}

# 颜色定义
YELLOW='\033[1;33m'
CYAN='\033[1;36m'
RED='\033[1;31m'

RESET='\033[0m'

# print_color  $YELLOW "This is a yellow message."
print_color  $CYAN "开始拉取镜像."
docker run -ti --rm verilator/verilator:latest --version

# 获取当前脚本的路径
script_path=$(dirname "$(realpath "$0")")
# echo "当前脚本的路径是: $script_path"
print_color  $CYAN "设置verilator-docker快捷命令."

sudo cp $script_path/verilator-docker /usr/local/bin/verilator-docker
sudo chmod +x /usr/local/bin/verilator-docker

if verilator-docker --version | grep -q "Verilator"; then
    # 如果 verilator-docker 输出版本信息符合预期，则输出成功消息
    print_color $YELLOW "安装Verilator成功."
else
    # 如果 verilator-docker 输出版本信息不符合预期，则输出错误信息
    print_color $RED "安装Verilator失败"
fi