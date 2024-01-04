#!/usr/bin/env sh

session="dwm"

[[ -f "$HOME/.Xresources" ]] && xrdb -merge "$HOME/.Xresources"

hsetroot -solid "#080503"

xcompmgr &
dunst &

/usr/libexec/xdg-desktop-portal-gtk &
/usr/libexec/polkit-gnome-authentication-agent-1 &

case "$session" in
	"dwm")
		"$HOME/.suckless/dwm/status" &
		exec dwm ;;
esac
