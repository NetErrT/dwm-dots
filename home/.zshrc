#!/usr/bin/zsh

source "$HOME/.zprofile"

autoload -Uz compinit promptinit

# Compinit
compinit

zstyle ":completion:*" menu select

# Prompt
promptinit

PROMPT="%n:%m %~> "

# History
HISTFILE=".zhistfile"
HISTSIZE=100

# Options
setopt PROMPT_SUBST

