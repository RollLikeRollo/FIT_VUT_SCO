#!/usr/bin/env sh

echo "SUIDify: chmod +s ls_root; chown root ls_root"
sudo chown root:root get_root
sudo chmod +xs get_root
ls -l


