image: pedbap/libzip-fuzz
duration: 3000
project: zip
target: libzip-fuzz
cmds:
  - cmd: /zipentry_fuzz @@
    afl: true

