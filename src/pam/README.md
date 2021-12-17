# Howdy PAM module

## Build

```sh
meson setup build
meson compile -C build
```

## Install

```sh
sudo meson install -C build
```

Change PAM config line to:

```pam
auth  sufficient  pam_howdy.so
```
