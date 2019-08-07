#!/bin/bash
[ -d "$1" ] || exit 1
cd "$1"
shift
find -H "$@" -type l -printf '%p -> %l\n' -o -printf '%p (%U/%G/%#m)\n' | sort
find -H "$@" -type f -print0 | sort -z | xargs -0 cat
