#!/usr/bin/env bash
cd ./keyboards/crkbd/keymaps/jcelaya775/ || exit
tmux new-window
cd ../../
tmux new-window
tmux select-window -t 0

tmux select-window -t 1 && tmux send-keys "nvim keymap.c" ENTER
tmux select-window -t 2 && tmux send-keys "nvim rules.mk" ENTER
tmux select-window -t 0
