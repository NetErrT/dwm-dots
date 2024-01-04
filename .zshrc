#!/usr/bin/env zsh

source "$HOME/.zprofile"

setopt PROMPT_SUBST

autoload -Uz compinit promptinit vcs_info
compinit
promptinit

precmd_functions+=( vcs_info )

prompt mytheme

zstyle ':completion:*' menu select
zstyle ':vcs_info:git:*' formats '%b'

