#!/usr/bin/env sh

xrdb -merge "$HOME/.Xresources"

xcompmgr &
dunst &

/usr/libexec/xdg-desktop-portal-gtk &
/usr/libexec/polkit-gnome-authentication-agent-1 &

SESSION="dwm"

case "$SESSION" in
	"dwm")
		"$HOME/.suckless/dwm/status" &
		exec dwm ;;
esac

