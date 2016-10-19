//安装git
//配置git
git config --global user.name "Ycoronene"
git config --global user.email "1040091229@qq.com"
//为git添加ssh key(要先安装ssh)
ssh-keygen -t rsa -b 4096 -C "1040091229@qq.com"

//安装vim
//配置vim(需要先安装curl)
sh <(curl https://j.mp/spf13-vim3 -L)
或者 
curl https://j.mp/spf13-vim3 -L > spf13-vim.sh && sh spf13-vim.sh

//安装zsh
//配置zsh
sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
或者
sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"

UBUNTU下(有一些可能在其他系统也可以用)
    //添加额外的解码器
    sudo apt-get install ubuntu-restricted-extras
    //安装VLC播放器看字幕
    sudo apt-get install install vlc
    //电源管理TLP
    sudo add-apt-repository ppa:linrunner/tlp
    sudo apt-get update
    sudo apt-get install tlp tlp-rdw
    sudo tlp start
    //将 Ubuntu 16.04 LTS 的 Unity 启动器移动到桌面底部命令：
    gsettings set com.canonical.Unity.Launcher launcher-position Bottom

//jekyll博客本地调试
sudo apt-get install ruby ruby-dev
sudo sources --add https://ruby.taobao.org/ --remove https://rubygems.org/
sudo gem install jekyll
sudo gem install wdm

//安装中文man pages
sudo apt-get install manpages-zh
//之后将文件/etc/manpath.config中的/usr/share/man改为/usr/share/man/zh_CN即可


