#!/usr/bin/env sh

bin_dirs=("$HOME/.local/bin" "$HOME/.luals/bin" "$HOME/.nodejs/bin")

for bin_dir in "$bin_dirs[@]"; do
	export PATH="$PATH:$bin_dir"
done

export GOOGLE_API_KEY="no"
export GOOGLE_DEFAULT_CLIENT_ID="no"
export GOOGLE_DEFAULT_CLIENT_SECRET="no"

