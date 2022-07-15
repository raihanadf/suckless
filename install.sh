#!/bin/bash

DWM_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SLOCK_DIR="$DWM_DIR/slock"
SPT_DIR="$DWM_DIR/slock"

// install dwm
clear && echo "compiling and installing dwm..." && sleep 1
cd $DWM_DIR
sudo make && sudo make clean install

// install slock
clear && echo "compiling and installing slock..." && sleep 1
cd $SLOCK_DIR
sudo make && sudo make clean install

// install spt / pomo
clear && echo "compiling and installing spt..." && sleep 1
cd $SPT_DIR
sudo make && sudo make clean install
