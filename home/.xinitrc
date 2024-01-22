#!/usr/bin/env sh

[[ -f "$HOME/.Xresources" ]] && xrdb -merge "$HOME/.Xresources"

hsetroot -solid "#080503"

xcompmgr &
dunst &

/usr/libexec/xdg-desktop-portal-gtk &
/usr/libexec/polkit-gnome-authentication-agent-1 &

SESSION="dwm"

case "$SESSION" in
	"dwm")
		[[ -f "$HOME/.suckless/dwm/status" ]] && "$HOME/.suckless/dwm/status" &
		exec dwm ;;
esac

